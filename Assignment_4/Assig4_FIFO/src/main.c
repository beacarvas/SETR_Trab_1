/** @file main.c
 * @brief Descrição da main()
 * 
 * 	Este ficheiro contém a main(), função onde são criadas e inicializadas as threads do nosso trabalho, as configurações do módulo de ADC e de PWM
 *  necessárias e, ainda, as funções para cada thread. Neste caso, a comunicação entre threads é feita através de fifos. \n
 *  Inicialmente, é lida a tensão de entrada, usando o pino analógico A0 através do módulo ADC, sendo esta de seguida filtrada, onde
 *  são eliminadas as 10 últimas amostras com um desvio de 10% ou superior do valor médio e calculado o valor médio com as restantes amostras. 
 *  Por fim, é feito o ajuste do duty-cycle do sinal PWM, com base no valor medido, ajustando o brilho do LED 1. \n
 * 
 *    
 * @author Beatriz Carvas \n D�rio Fernandes \n Guilherme Cajeira
 * @date 31 de maio de 2022
 * @bug N�o h� bugs 
 */

#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
#include <drivers/adc.h>
#include <string.h>
#include <timing/timing.h>
#include <sys/printk.h>
#include <sys/__assert.h>
#include <stdlib.h>
#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
#include <drivers/adc.h>
#include <string.h>
#include <timing/timing.h>
#include <sys/printk.h>
#include <sys/__assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <drivers/pwm.h>

/*
*********************** Threads Configurations *****************************************
*/

/* Size of stack area used by each thread (can be thread specific, if necessary)*/
#define STACK_SIZE 1024

/* Thread scheduling priority */
#define thread_Sample_prio 1
#define thread_Filter_prio 1
#define thread_OutSignal_prio 1

/* Therad periodicity (in ms)*/
#define SAMP_PERIOD_MS 1000     

/* Create thread stack space */
K_THREAD_STACK_DEFINE(thread_Sample_stack, STACK_SIZE);
K_THREAD_STACK_DEFINE(thread_Filter_stack, STACK_SIZE);
K_THREAD_STACK_DEFINE(thread_OutSignal_stack, STACK_SIZE);
  
/* Create variables for thread data */
struct k_thread thread_Sample_data;
struct k_thread thread_Filter_data;
struct k_thread thread_OutSignal_data;

/* Create task IDs */
k_tid_t thread_Sample_tid;
k_tid_t thread_Filter_tid;
k_tid_t thread_OutSignal_tid;

/* Create fifos*/
struct k_fifo fifo_SF;
struct k_fifo fifo_FO;

/* Create fifo data structure and variables */
struct data_item_t {
    void *fifo_reserved;    /* 1st word reserved for use by FIFO */
    uint16_t data;          /* Actual data */
};

/* Thread code prototypes */
void thread_Sample_code(void *, void *, void *);
void thread_Filter_code(void *, void *, void *);
void thread_OutSignal_code(void *, void *, void *);


/*
***************************** ADC Configurations *******************************************
*/


/*ADC definitions and includes*/
#include <hal/nrf_saadc.h>
#define ADC_NID DT_NODELABEL(adc) 
#define ADC_RESOLUTION 10
#define ADC_GAIN ADC_GAIN_1_4
#define ADC_REFERENCE ADC_REF_VDD_1_4
#define ADC_ACQUISITION_TIME ADC_ACQ_TIME(ADC_ACQ_TIME_MICROSECONDS, 40)
#define ADC_CHANNEL_ID 1  

/* This is the actual nRF ANx input to use */
#define ADC_CHANNEL_INPUT NRF_SAADC_INPUT_AIN1 

#define BUFFER_SIZE 1

/* ADC channel configuration */
static const struct adc_channel_cfg my_channel_cfg = {
	.gain = ADC_GAIN,
	.reference = ADC_REFERENCE,
	.acquisition_time = ADC_ACQUISITION_TIME,
	.channel_id = ADC_CHANNEL_ID,
	.input_positive = ADC_CHANNEL_INPUT
};

/* Global vars */
const struct device *adc_dev = NULL;
static uint16_t adc_sample_buffer[BUFFER_SIZE];

/** 
 * @brief Descrição da adc_sample()
 * 
 * Função responsável pela leitura da ADC e registo das amostras num buffer.
 * 
 * @param ret Indicação a ocorrẽncia de erro na leitura da ADC. 
 * @param adc_sample_buffer Buffer onde são guardadas as amostras lidas da ADC.
 * 
 * @return ret.
 * 
 */
 
// Takes one sample 
static int adc_sample(void)
{
	int ret;
	const struct adc_sequence sequence = {
		.channels = BIT(ADC_CHANNEL_ID),
		.buffer = adc_sample_buffer,
		.buffer_size = sizeof(adc_sample_buffer),
		.resolution = ADC_RESOLUTION,
	};

	if (adc_dev == NULL) {
            printk("adc_sample(): error, must bind to adc first \n\r");
            return -1;
	}

	ret = adc_read(adc_dev, &sequence);
	if (ret) {
            printk("adc_read() failed with code %d\n", ret);
	}	

	return ret;
}

/*
***************************** PWM and LED Configurations *******************************************
*/
#define GPIO0_NID DT_NODELABEL(gpio0)       
#define PWM0_NID DT_NODELABEL(pwm0)                               
#define BOARDLED_PIN DT_PROP(PWM0_NID, ch0_pin)           // LED 1



/** 
 * @brief Descrição da main()
 * 
 * Criação e inicialização das threads: \n 
 *      - thread_Sample: Thread periódica onde é feita a leitura da tensão na entrada (Período de amostragem = 1seg); \n
 *      - thread_Filter: Thread esporádica onde são filtradas as amostras lidas; \n
 *      - thread_Outsignal: Thread esporádica onde é atualizado o duty_cycle do sinal PWM, ajustando o brilho do LED1.
 * 
 * @return Return.
 * 
 */

void main(void)
{
    /* Welcome message */
    printk("\n\r Illustration of the use of FIFO\n\r");
    
    /* Create and init semaphores */
    k_fifo_init(&fifo_SF);
    k_fifo_init(&fifo_FO);
    
    /* Create tasks */
    thread_Sample_tid = k_thread_create(&thread_Sample_data, thread_Sample_stack,
        K_THREAD_STACK_SIZEOF(thread_Sample_stack), thread_Sample_code,
        NULL, NULL, NULL, thread_Sample_prio, 0, K_NO_WAIT);

    thread_Filter_tid = k_thread_create(&thread_Filter_data, thread_Filter_stack,
        K_THREAD_STACK_SIZEOF(thread_Filter_stack), thread_Filter_code,
        NULL, NULL, NULL, thread_Filter_prio, 0, K_NO_WAIT);

    thread_OutSignal_tid = k_thread_create(&thread_OutSignal_data, thread_OutSignal_stack,
        K_THREAD_STACK_SIZEOF(thread_OutSignal_stack), thread_OutSignal_code,
        NULL, NULL, NULL, thread_OutSignal_prio, 0, K_NO_WAIT);

    
    return;
}


/*
****************************** Thread code implementation *****************************************
*/


/** 
 * @brief Descrição da thread_Sample_code()
 * 
 * Função da thread periódica para a obtenção das amostras da ADC. Cada amostra obtida é, de seguida, convertida em tensão (Volts). \n
 * 
 * @param adc_sample_buffer Buffer que contém as amostras lidas da ADC.
 * @param data_SF Resultado da conversão do valor da ADC em tensão.
 * @param fifo_SF Fifo onde é armazenado o valor da tensão calculada para ser lido pela thread de filtragem.
 * 
 * @return Return.
 * 
 */
void thread_Sample_code(void *argA , void *argB, void *argC)
{
    /* Timing variables to control task periodicity */
    int64_t fin_time=0, release_time=0;
    
    /* Other variables */
    struct data_item_t data_SF;

    printk("Thread Sample init (periodic)\n");

    /* Compute next release instant */
    release_time = k_uptime_get() + SAMP_PERIOD_MS;

    /* ADC setup: bind and initialize */
    int err=0;

    adc_dev = device_get_binding(DT_LABEL(ADC_NID));
    if (!adc_dev) {
        printk("ADC device_get_binding() failed\n");
    } 
    err = adc_channel_setup(adc_dev, &my_channel_cfg);
    if (err) {
        printk("adc_channel_setup() failed with error code %d\n", err);
    }
    
    /* It is recommended to calibrate the SAADC at least once before use, and whenever the ambient temperature has changed by more than 10 �C */
    NRF_SAADC->TASKS_CALIBRATEOFFSET = 1;

    /* Thread loop */
    while(1) {

       /* Get one sample, checks for errors and prints the values */
        err=adc_sample();
        if(err) {
            printk("\n\n\radc_sample() failed with error code %d\n\r",err);
        }
        else {
            if(adc_sample_buffer[0] > 1023) {
                printk("\n\n\radc reading out of range: raw:%4u\n\r",adc_sample_buffer[0]);
            }
            else {
                /* ADC is set to use gain of 1/4 and reference VDD/4, so input range is 0...VDD (3 V), with 10 bit resolution */
                data_SF.data = (uint16_t)(1000*adc_sample_buffer[0]*((float)3/1023)); // C�lculo da tens�o na entrada
                printk("\n\n\rLeitura da ADC:%4u / %4u mV: \n\r",adc_sample_buffer[0], data_SF.data);
            }
        }

        k_fifo_put(&fifo_SF, &data_SF);

        /* Wait for next release instant */ 
        fin_time = k_uptime_get();
        if( fin_time < release_time) {
            k_msleep(release_time - fin_time);
            release_time += SAMP_PERIOD_MS;

        }
    }

}


/** 
 * @brief Descrição da thread_Filter_code()
 * 
 * Função da thread esporádica que lê 10 amostras da ADC, calcula a sua média, filtra todos os valores iguais ou superiores a 10% em relação 
 * ao valor da média calculada e por último, calcula novamente a média das amostras filtradas \n
 * 
 * @param pre_filter Array que contém as 10 amostras lidas da ADC, antes do filtro
 * @param pos_filter Array que contém as amostras após a filtragem
 * @param cnt Variável que contém o número de amostras no fifo
 * @param data_FO Valor da média das amostras após a filtragem
 * @param fifo_FO Fifo onde é armazenado o valor da média das amostras para ser lido pela thread de saída
 * 
 * @return Return.
 * 
 */

void thread_Filter_code(void *argA , void *argB, void *argC)
{

    /* Local variables */
    struct data_item_t *data_SF;
    struct data_item_t data_FO;

    /* Other variables */
    int cnt = -1;
    int avg = 0, max_avg = 0, min_avg = 0;
    int sum = 0, out_range = 0;
    int pre_filter[10] = {};
    int pos_filter[10] = {};
    int N = 10;

    printk("Thread Filter init (sporadic, waits on a semaphore by task Sample)\n");
    while(1) {
        data_SF = k_fifo_get(&fifo_SF,  K_FOREVER);

        /*printk("Entrou na thread do Filtro: Tens�o = %d\n\r", data_SF->data * 10); // alterar aqui com o que a thread � suposto fazer
        
        data_FO.data = data_SF->data + 1; // atualiza valor para o fifo Filtro-PWM*/

        if(cnt < 0)
          cnt++;
        else if((cnt < N) && (cnt >= 0)) {
            pre_filter[cnt] = data_SF->data;
            printk("Ainda NAO CHEGOU as 10 amostras, tensao recebida: %d \n\r", data_SF->data);
            printk("Numero de amostras no filtro: %d mV\n\r", cnt+1);
            for(int i=0; i<N;i++) {
              printk("%d mV\n\r",pre_filter[i]);
            }
            data_FO.data = pre_filter[cnt];
            cnt++;
        }
        else {
            printk("CHEGOU as 10 amostras, numero de amostras no filtro: %d \n\r", cnt);
            for(int i=1; i<N;i++) {
               pre_filter[i-1] = pre_filter[i]; 

               sum = sum + pre_filter[i-1];
            }
            pre_filter[N-1] = data_SF->data;
            sum = sum + pre_filter[N-1];

            avg = sum / N;   
            printk("Valor medio antes da filtragem: %d mV\n\r", avg);
            sum = 0;

            max_avg = avg + avg*0.1;
            min_avg = avg - avg*0.1;
            for(int i=0; i<N;i++) {
               if((pre_filter[i] < min_avg) || (pre_filter[i] > max_avg))
                  out_range++;
               else {   
                  pos_filter[i-out_range] = pre_filter[i];
                  sum = sum + pre_filter[i];
               }
               
            }

            for(int i=0; i<N;i++) {
              printk("%d mV\n\r",pos_filter[i]);
              pre_filter[i] = pos_filter[i];
            }

            data_FO.data = sum / (N-out_range);
            printk("Valor medio apos a filtragem: %d mV\n\r", data_FO.data);

            cnt = cnt - out_range;
            sum = 0;
            avg = 0;
            out_range = 0;
        }



        k_fifo_put(&fifo_FO, &data_FO);  
   
  }
}

/** 
 * @brief Descrição da função de configuração thread_OutSignal_code()
 * 
 * Função onde é feita a leiura dos valores filtrados (através da função k_fifo_get ),  com estes valores são calculados os valores duty cycle para variar o sinal PWM, que será observado no LED 1.
 * 
 */
void thread_OutSignal_code(void *argA , void *argB, void *argC)
{

    /* Local variables */
    struct data_item_t *data_FO;
    const struct device *gpio0_dev;         /* Pointer to GPIO device structure */
    const struct device *pwm0_dev;          /* Pointer to PWM device structure */
    int ret=0;                              /* Generic return value variable */
  
    unsigned int pwmPeriod_us = 100;       /* PWM priod in us */
    unsigned int aux = 0;                   /* variavel auxiliar */

    /* Bind to GPIO 0 and PWM0 */
    gpio0_dev = device_get_binding(DT_LABEL(GPIO0_NID));
    if (gpio0_dev == NULL) {
        printk("Error: Failed to bind to GPIO0\n\r");        
	return;
    }
    else {
        printk("Bind to GPIO0 successfull \n\r");        
    }
    
    pwm0_dev = device_get_binding(DT_LABEL(PWM0_NID));
    if (pwm0_dev == NULL) {
	printk("Error: Failed to bind to PWM0\n r");
	return;
    }
    else  {
        printk("Bind to PWM0 successful\n\r");            
    }

    //printk("Thread OutSignal init (sporadic, waits on a semaphore by task Sample)\n");

    while(1) {
              
        data_FO = k_fifo_get(&fifo_FO, K_FOREVER);    // Leitura do valor filtrado 
       
       aux = (data_FO->data*0.001*100)/3;             // calculo do duty cycle

        printk("valor PWM = %u %\n\r",aux);

        ret = pwm_pin_set_usec(pwm0_dev, BOARDLED_PIN,pwmPeriod_us,(unsigned int)((pwmPeriod_us*aux)/100),PWM_POLARITY_NORMAL);
      
        if (ret) {
                printk("Error %d: failed to set pulse width\n", ret);
		return;
        }

  }
}


