/** @file main.c
 * @brief Descrição da main()
 * 
 * Este programa foi desenvolvido por forma a implementar um sistema de controlo de iluminação de um LED. O controlo do LED tem dois modos: manual e automático.
 * No modo manual é ajustado o brilho do led manualmente pelo utiizador, aumentando ou diminuindo o brilho através dos botões da PIC. \n
 * No modo automático é feita a programação do brilho do led ao longo de um dia (cada hora, de 0-23h, é programável). O ajuste do brilho para uma dada hora será
 * feito através de um controlador P que irá calcular o erro entre o valor definido pelo utilizador para uma dada hora e o brilho atual do led, medido pelo 
 * fototransistor. \n
 * O Sistema foi implementado através de threads, sendo a comunicação entre processos feita através de FIFOs. \n
 * Foi ainda implementado o módulo de ADC para a leitura dos valores do fototransistor, com uma frequência de amostragem de 1Hz. \n
 * O sinal PWM gerado para alterar o brilho do LED foi implementado com uma frequência de 10KHz.
 *    
 * @author Beatriz Carvas \n Dário Fernandes \n Guilherme Cajeira
 * @date 21 de junho de 2022
 * @bug O controlo do brilho no modo automático não está a funcionar em condições.
 */

#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
#include <drivers/adc.h>
#include <drivers/uart.h>
#include <timing/timing.h>
#include <sys/printk.h>
#include <sys/__assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <drivers/pwm.h>
#include <console/console.h>


/** 
 * @brief Flag que quando ativada (block_print = 1) bloqueia todos os prints enquanto são introduzidos valores na thread thread_Insert_Value_code().
 * 
 */
int block_print = 0;   
/**
 * @brief Sinal de controlo do controlador P.
 * 
 */
volatile int u = 0;    
/**
 * @brief Variável do controlador com o valor introduzido pelo utilizador para o brilho do LED.
 * 
 */
volatile int setpoint = -1; 
/**
 * @brief Valor introduzido pelo utilizador para o Brilho.
 * 
 */
int Brilho = 0;
/**
 * @brief Valor introduzido pelo utilizador para a hora.
 * 
 */
int Hora = 0;       
/**
 * @brief Valor a incrementar/decrementar ao duty-cycle no modo manual.
 * 
 */
volatile int luz = 0;
/**
 * @brief Flag que indica quando o modo automático é ativado (auto_flag = 1 quando o modo é selecionado).
 * 
 */
volatile int auto_flag = 0;
/**
 * @brief Flag que indica quando o modo manual é ativado (man_flag = 1 quando modo é selecionado).
 * 
 */
volatile int man_flag = 0;

/*
*********************** UART Configurations *****************************************
*/
#define MAIN_SLEEP_TIME_MS 10 /* Time between main() activations */ 

#define FATAL_ERR -1 /* Fatal error return code, app terminates */

#define UART_NID DT_NODELABEL(uart0)    /* UART Node label, see dts */
#define RXBUF_SIZE 60                   /* RX buffer size */
#define TXBUF_SIZE 60                   /* TX buffer size */
#define RX_TIMEOUT 1000                 /* Inactivity period after the instant when last char was received that triggers an rx event (in us) */

/* Struct for UART configuration (if using default valuies is not needed) */
const struct uart_config uart_cfg = {
		.baudrate = 115200,
		.parity = UART_CFG_PARITY_NONE,
		.stop_bits = UART_CFG_STOP_BITS_1,
		.data_bits = UART_CFG_DATA_BITS_8,
		.flow_ctrl = UART_CFG_FLOW_CTRL_NONE
};

/* UAR related variables */
const struct device *uart_dev;          /* Pointer to device struct */ 
static uint8_t rx_buf[RXBUF_SIZE];      /* RX buffer, to store received data */
static uint8_t rx_chars[RXBUF_SIZE];    /* chars actually received  */
volatile int uart_rx_rdy_flag;          /* Flag to signal main() that a message is available */

/* UART callback function prototype */
static void uart_cb(const struct device *dev, struct uart_event *evt, void *user_data);

uint8_t welcome_mesg[] = "UART demo: Type a few chars in a row and then pause for a little while ...\n\r"; 
int err = 0;
uint8_t rep_mesg[TXBUF_SIZE];
void configure_uart(void);


/*
*********************** Threads Configurations *****************************************
*/

/* Size of stack area used by each thread (can be thread specific, if necessary)*/
#define STACK_SIZE 1024

/* Thread scheduling priority */
#define thread_ADC_Sample_prio 1
#define thread_PWM_DutyCycle_prio 1
#define thread_Insert_Value_prio 1
#define thread_ControladorP_prio 1
#define thread_Calendario_prio 1

/* Therad periodicity (in ms)*/
#define SAMP_PERIOD_MS 1000   
#define SAMP_PERIOD_C  30000                      // periodo de 1 min  

/* Create thread stack space */ 
K_THREAD_STACK_DEFINE(thread_ADC_Sample_stack, STACK_SIZE);
K_THREAD_STACK_DEFINE(thread_PWM_DutyCycle_stack, STACK_SIZE);
K_THREAD_STACK_DEFINE(thread_Insert_Value_stack, STACK_SIZE);
K_THREAD_STACK_DEFINE(thread_ControladorP_stack, STACK_SIZE);
K_THREAD_STACK_DEFINE(thread_Calendario_stack, STACK_SIZE);
  
/* Create variables for thread data */
struct k_thread thread_ADC_Sample_data;
struct k_thread thread_PWM_DutyCycle_data;
struct k_thread thread_Insert_Value_data;
struct k_thread thread_ControladorP_data;
struct k_thread thread_Calendario_data;

/* Create task IDs */
k_tid_t thread_ADC_Sample_tid;
k_tid_t thread_PWM_DutyCycle_tid;
k_tid_t thread_Insert_Value_tid;
k_tid_t thread_ControladorP_tid;
k_tid_t thread_Calendario_tid;

/* Create fifos*/
struct k_fifo fifo_ADC_PWM;
struct k_fifo fifo_PWM_P;
//VER FIFOOS ANALISARRRRRR
struct k_fifo fifo_Calendario;

/* Create fifo data structure and variables */
struct data_item_t {
    void *fifo_reserved;    /* 1st word reserved for use by FIFO */
    uint16_t data;          /* Actual data */
};

/* Thread code prototypes */
void thread_ADC_Sample_code(void *, void *, void *);
void thread_PWM_DutyCycle_code(void *, void *, void *);
void thread_Insert_Value_code(void *, void *, void *);
void thread_ControladorP_code(void *, void *, void *);
void thread_Calendario_code(void *, void *, void *);

/* Refer to dts file */
#define GPIO0_NID DT_NODELABEL(gpio0) 
#define BOARDBUT1 11 /* Pin at which BUT1 is connected. Addressing is direct (i.e., pin number) */
#define BOARDBUT2 12 /* Pin at which BUT2 is connected. Addressing is direct (i.e., pin number) */
#define BOARDBUT3 24 /* Pin at which BUT3 is connected. Addressing is direct (i.e., pin number) */
#define BOARDBUT4 25 /* Pin at which BUT4 is connected. Addressing is direct (i.e., pin number) */

const struct device *gpio0_dev;          /* Pointer to GPIO device structure */

/* Int related declarations */
static struct gpio_callback but1_cb_data; /* Callback structure */

int ret = 0;
void configure_pins_board(void);

void but1press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins) 
{
    
    if(BIT(BOARDBUT1) & pins) {
      auto_flag = 0;
      man_flag = 1;
    }

    if(BIT(BOARDBUT2) & pins) {
      auto_flag = 1;
      man_flag = 0; 
    }

    if(man_flag == 1)
    {
      if(BIT(BOARDBUT3) & pins) {
        printk("Diminuir luminosidade \r\n");
        luz = luz - 50 ;
      }

      if(BIT(BOARDBUT4) & pins) {
        printk("Aumentar luminosidade \r\n");
        luz = luz + 50;
      }
    }
}

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
 * @param ret Indicação da ocorrência de erro na leitura da ADC. 
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
#define PWM0_NID DT_NODELABEL(pwm0)                               
#define BOARDLED_PIN DT_PROP(PWM0_NID, ch0_pin)           // LED 1



/** 
 * @brief Descrição da main()
 * 
 * Criação e inicialização das threads: \n 
 *      - thread_ADC_Sample: Thread periódica onde é feita a leitura da tensão na ADC (Período de amostragem = 1seg); \n
 *      - thread_PWM_DutyCycle: Thread esporádica onde é alterado o Duty-cycle do sinal PWM; \n
 *      - thread_Insert_Value: Thread esporádica onde são introduzidos os valores para programar o brilho do LED no modo automático (Hora e Intensidade do brilho); \n
 *      - thread_ControladorP: Thread esporádica onde é ajustado o brilho do LED para um certo valor através de um controlador P; \n
 *      - thread_Calendario: Thread periódica onde é implementado o calendário (neste caso horário diário). Aqui é definido qual o valor do brilho a que o LED deve
 *      estar, consoante os valores introduzidos na thread_Insert_Value. A cada hora é alterado o valor do brilho definido, que será depois lido no controlador
 *      (Período = 30seg). \n
 * 
 * @return Return.
 * 
 */

void main(void)
{
    /* Bind to GPIO 0 */
    gpio0_dev = device_get_binding(DT_LABEL(GPIO0_NID));
    if (gpio0_dev == NULL) {
        printk("Failed to bind to GPIO0\n\r");        
	return;
    }
    else {
        printk("Bind to GPIO0 successfull \n\r");        
    }
    
    configure_pins_board();

    /* Bind to UART */
    uart_dev= device_get_binding(DT_LABEL(UART_NID));
    if (uart_dev == NULL) {
        printk("device_get_binding() error for device %s!\n\r", DT_LABEL(UART_NID));
        return;
    }
    else {
        printk("UART binding successful\n\r");
    }

    configure_uart();
    
    /* Init console service */
    console_init();

    /* Welcome message */
    printk("\n\r Illustration of the use of FIFO\n\r");
    
    /* Create and init semaphores */
    k_fifo_init(&fifo_ADC_PWM);
    k_fifo_init(&fifo_PWM_P);
    k_fifo_init(&fifo_Calendario);
    
    
    /* Create tasks */
    thread_ADC_Sample_tid = k_thread_create(&thread_ADC_Sample_data, thread_ADC_Sample_stack,
        K_THREAD_STACK_SIZEOF(thread_ADC_Sample_stack), thread_ADC_Sample_code,
        NULL, NULL, NULL, thread_ADC_Sample_prio, 0, K_NO_WAIT);

    thread_PWM_DutyCycle_tid = k_thread_create(&thread_PWM_DutyCycle_data, thread_PWM_DutyCycle_stack,
        K_THREAD_STACK_SIZEOF(thread_PWM_DutyCycle_stack), thread_PWM_DutyCycle_code,
        NULL, NULL, NULL, thread_PWM_DutyCycle_prio, 0, K_NO_WAIT);

     thread_Insert_Value_tid = k_thread_create(&thread_Insert_Value_data, thread_Insert_Value_stack,
        K_THREAD_STACK_SIZEOF(thread_Insert_Value_stack), thread_Insert_Value_code,
        NULL, NULL, NULL, thread_Insert_Value_prio, 0, K_NO_WAIT);

    thread_ControladorP_tid = k_thread_create(&thread_ControladorP_data, thread_ControladorP_stack,
        K_THREAD_STACK_SIZEOF(thread_ControladorP_stack), thread_ControladorP_code,
        NULL, NULL, NULL, thread_ControladorP_prio, 0, K_NO_WAIT);

    thread_Calendario_tid = k_thread_create(&thread_Calendario_data, thread_Calendario_stack,
        K_THREAD_STACK_SIZEOF(thread_Calendario_stack), thread_Calendario_code,
        NULL, NULL, NULL, thread_Calendario_prio, 0, K_NO_WAIT);

    return;
}


/*
****************************** Thread code implementation *****************************************
*/


/** 
 * @brief Descrição da thread_ADC_Sample_code() 
 * 
 * Função da thread periódica para a obtenção das amostras da ADC. \n
 * 
 * @param fifo_ADC_PWM Fifo da thread onde é escrito o valor da ADC lida.
 * @param data_ADC_PWM Variável que escreve o valor da ADC no fifo da thread.
 * 
 * @return Return.
 * 
 */
void thread_ADC_Sample_code(void *argA , void *argB, void *argC)
{
    /* Timing variables to control task periodicity */
    int64_t fin_time=0, release_time=0;
    
    /* Other variables */
    struct data_item_t data_ADC_PWM;

    printk("Thread ADC_Sample init (periodic)\n");

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
    
    /* It is recommended to calibrate the SAADC at least once before use, and whenever the ambient temperature has changed by more than 10 ?C */
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
                data_ADC_PWM.data = adc_sample_buffer[0];
                if(block_print == 0)
                  printk("\n\n\rLeitura da ADC: %4u  \n\r", data_ADC_PWM.data);
            }
        }

        k_fifo_put(&fifo_ADC_PWM, &data_ADC_PWM);

        /* Wait for next release instant */ 
        fin_time = k_uptime_get();
        if( fin_time < release_time) {
            k_msleep(release_time - fin_time);
            release_time += SAMP_PERIOD_MS;

        }
    }

}


/** 
 * @brief Descrição da thread_PWM_DutyCycle_code()
 * 
 * Função da thread esporádica onde é feita a conversão do valor da ADC para duty-cycle. Este valor de duty-cycle é, de seguida, atualizado no sinal de saída
 * PWM, ajustando o brilho do LED. \n
 * Nesta thread é feito ainda a escolha do modo do sistema: modo manual ou automático. Com base no modo escolhido, o duty-cycle do sinal PWM pode ser alterado
 * através de dois dos botões da placa (modo manual), ou escolhendo o brilho desejado através do terminal, sendo o valor do duty-cycle ajustado através de um 
 * controlador (modo automático). \n
 * 
 * @param fifo_ADC_PWM Fifo de onde é recebido o valor da ADC lido.
 * @param fifo_PWM_P Fifo onde será escrito o valor atual do duty-cycle do sinal PWM, apenas no modo automático, para ser lido na thread do controlador.
 * @param data_ADC_PWM Variável que recebe o valor do FIFO_ADC_PWM com o valor da ADC.
 * @param data_PWM_P Variável com o valor de duty-cycle a ser escrito no fifo fifo_PWM_P.
 * @param aux Soma do valor atual do duty-cyle com o valor de 'luz' no modo manual.
 * 
 * @return Return.
 * 
 */

void thread_PWM_DutyCycle_code(void *argA , void *argB, void *argC)
{
    /* Local variables */
    struct data_item_t *data_ADC_PWM;
    struct data_item_t data_PWM_P;
    
    /* Other variables */
    const struct device *gpio0_dev;         /* Pointer to GPIO device structure */
    const struct device *pwm0_dev;          /* Pointer to PWM device structure */
    int ret=0;                              /* Generic return value variable */
  
    unsigned int pwmPeriod_us = 100;       /* PWM priod in us */
    unsigned int aux = 0;

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

    while(1) {
              
        data_ADC_PWM = k_fifo_get(&fifo_ADC_PWM, K_FOREVER);    // Leitura do valor da ADC
        
        if(man_flag == 1)
        {
          printk("Modo Manual ON \r\n");  

          aux = data_ADC_PWM->data + luz;
          if(aux < 0){
            aux = data_ADC_PWM->data;
            luz = 0;
            printk("Nao pode diminuir mais a luz, esta no valor minimo \r\n");
          }
          else if(aux > 1023){
            aux = data_ADC_PWM->data;
            luz = 0;
            printk("Nao pode aumentar mais a luz, esta no valor maximo \r\n");
          }
          printk("Valor pretendido: %u \r\n",aux);
          
          data_PWM_P.data = ((1023-aux) *100)/1023;         // calculo do duty cycle

        }
        else if(auto_flag == 1 && block_print == 0) {
          printk("Modo Manual OFF \r\n");

          data_PWM_P.data = ((1023-data_ADC_PWM->data) *100)/1023 + u;         // calculo do duty cycle
          if(data_PWM_P.data < 0)
            data_PWM_P.data = 0;
          else if(data_PWM_P.data >100)
            data_PWM_P.data = 100;
       }

        if(block_print == 0)
          printk("valor PWM = %u %\n\r",100-data_PWM_P.data);

        ret = pwm_pin_set_usec(pwm0_dev, BOARDLED_PIN,pwmPeriod_us,(unsigned int)((pwmPeriod_us*data_PWM_P.data)/100),PWM_POLARITY_NORMAL);
      
        if (ret) {
                printk("Error %d: failed to set pulse width\n", ret);
		return;
        }

        if(auto_flag == 1)
        {
          k_fifo_put(&fifo_PWM_P, &data_PWM_P); 
        }
   
  }
}


/** 
 * @brief Descrição da função de configuraçãoo thread_Insert_Value_code()
 * 
 * Função da thread esporádica onde é inserida a hora à qual se deseja alterar o brilho do LED, assim como o brilho desejado. \n
 * Para entrar no menu que mudança de brilho do led, selecionar 'b'. De seguida, introduzir a hora (entre 0 e 23h) e o brilho desejado (0 a 100%). \n
 * 
 * @param c Variável que recebe o caractér introduzido no terminal.
 * @param H Variável com a hora introduzida pelo utilizador.
 * @param New_DutyCycle Variável com o valor do brilho introduzido pelo utilizador.
 * @param i Variável para o ciclo while de introdução de valores.
 * 
 * @return Return.
 */
void thread_Insert_Value_code(void *argA , void *argB, void *argC)
{
    int c;
    int H;
    int New_DutyCycle;
    int i;
  
    while(1) {   
        {     
            printf("------------------------------------------------------------------------- \n\r");
            printf(" MENU \n\r");
            printf("Para alterar o brilho, introduza 'b'\n\r");

            c = console_getchar();
            if(c == 'b') {                    // Verificar se foi introduzido o character correto
              block_print = 1;                // Bloqueia prints das outras threads
          
              printf("Introduza uma hora entre 0 e 23h:\t");

              i = 0;
              while(i<2)
              {
                c = console_getchar() - 48;   // Espera pela introdução de caractéres (-48 para passar de ascii para inteiro)
                if(c>=0 && c<10)              // Apenas quando é introduzido um número
                {
                  H = H*10 + c;               // Construção do valor da hora
                  i++;
                }
                else                          // Ignora caractér
                  i++;
              }

              if(H >= 0 && H <= 23)           // Verificar se é um valor válido
              {
                printk("%d h \n\r", H);
                Hora = H;
              }
              else
                printf("Valor da Hora Invalido!!\n\r");

              ////////////////////////////////////////////////////////////////////////////////////////////////////////////
          
              printf("Introduza um valor entre 0 e 100% para o brilho:\t");

              i = 0;
              while(i<3)
              {
                c = console_getchar() - 48;                 // Espera pela introdução de caractéres (-48 para passar de ascii para inteiro)
                if(c>=0 && c<10)                            // Apenas quando é introduzido um número
                {
                  New_DutyCycle = New_DutyCycle*10 + c;     // Construção do valor para o novo duty-cycle desejado
                  i++;
                }
                else                                        // Ignora caractér
                  i++;
              }

              if(New_DutyCycle >= 0 && New_DutyCycle <= 100) // Verificar se é um valor válido
              {
                printk("%d % \n\r", New_DutyCycle);
                Brilho = New_DutyCycle;
              }
              else
                printf("Valor do Brilho Invalido!!\n\r");
            }
            block_print = 0;                                // Desbloqueia prints das outras threads
        
            /* Reset variável */
            H = 0;                      
            New_DutyCycle = 0;
        }
    }
}


/** 
 * @brief Descrição da thread_Calendario_code() 
 * 
 * Função da thread periódica para a criação do calendario. O calendario, neste caso, é um horário diário, de 0 a 23h. \n
 * 
 * @param Calendario Array de 24 posições, onde cada posição corresponde a uma hora do dia.
 * @param Hora_atual Variável que é incrementada a cada período da thread, simulando a passagem das horas.
 * 
 * @return Return.
 * 
 */
void thread_Calendario_code(void *argA , void *argB, void *argC)
{
    /* Timing variables to control task periodicity */
    int64_t fin_time=0, release_time=0;
    
    /* Other variables */
    int Calendario[24] = {0};
 
    printk("Thread Calendario init (periodic)\n");

    /* Compute next release instant */
    release_time = k_uptime_get() + SAMP_PERIOD_C;

    /* Thread loop */
    while(1) {
        Hora_atual = release_time/SAMP_PERIOD_C;
        Hora_atual = Hora_atual % 24;

        Calendario[Hora] = Brilho;

        if(auto_flag == 1)
        {
            setpoint = Calendario[Hora_atual];

            if(block_print == 0)
            {
              printk("\n\n\rHora %d \n\r", Hora_atual);
              printk("Brilho do led = %d \n\n\r", setpoint);
            }
        }    
            
        /* Wait for next release instant */ 
        fin_time = k_uptime_get();
        if( fin_time < release_time) {
            k_msleep(release_time - fin_time);
            release_time += SAMP_PERIOD_C;

        }

    }

}



/** 
 * @brief Descrição da função de configuração da thread_ControladorP_code()
 * 
 * Função da thread esporádica para a implementação do controlador P responsável por controlar o brilho do LED no modo automático, consoante o valor do brilho 
 * introduzido pelo utilizador para uma certa hora. \n
 * 
 * @param Kp Ganho proporcional do controlador P.
 * @param e Variável do erro entre o valor do brilho introduzido (setpoint) e o valor atual de duty-cycle do sinal PWM.
 * 
 * @return Return.
 */
void thread_ControladorP_code(void *argA , void *argB, void *argC)
{

    /* Local variables */
    struct data_item_t *data_PWM_P;

    double Kp = 0.543;      // Ganho Proporcional
    int e;                  // Erro
    
    while(1) {            
        data_PWM_P = k_fifo_get(&fifo_PWM_P, K_FOREVER);      // Leitura do valor Duty-cycle atual
        //data_PWM_P->data = 100 - data_PWM_P->data;          // Inverte valor de PWM
        
        if(setpoint == -1)
          e = 0;                                              // Enquanto não é introduzido nenhum valor para o brilho, mantém o controlador parado
        else
          e = setpoint - data_PWM_P->data;                    // Calculo do erro
        
        u = Kp*e;                                             // Update do sinal de controlo
  
        if(block_print == 0)
        {
          printf("Valor inserido pelo utilizador: %u\n\r", setpoint); 
          printf("Control Signal = %d\n\r", u);
          printf("Erro = %d\n\r", e);
          printf("Hora Atual = %d\n\n\r", Hora_atual);
        }
    }

}


void configure_pins_board(void) {
    // Configure Board Buttons
    ret = gpio_pin_configure(gpio0_dev, BOARDBUT1, GPIO_INPUT | GPIO_PULL_UP);
    ret = gpio_pin_configure(gpio0_dev, BOARDBUT2, GPIO_INPUT | GPIO_PULL_UP);
    ret = gpio_pin_configure(gpio0_dev, BOARDBUT3, GPIO_INPUT | GPIO_PULL_UP);
    ret = gpio_pin_configure(gpio0_dev, BOARDBUT4, GPIO_INPUT | GPIO_PULL_UP);

    // Set interrupt Board Buttons - which pin and event generate interrupt 
    ret = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT1, GPIO_INT_EDGE_TO_ACTIVE);
    ret = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT2, GPIO_INT_EDGE_TO_ACTIVE);
    ret = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT3, GPIO_INT_EDGE_TO_ACTIVE);
    ret = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT4, GPIO_INT_EDGE_TO_ACTIVE);
    
    /* Set callback */
    gpio_init_callback(&but1_cb_data, but1press_cbfunction, BIT(BOARDBUT1)| BIT(BOARDBUT2)| BIT(BOARDBUT3) | BIT(BOARDBUT4));
    gpio_add_callback(gpio0_dev, &but1_cb_data);
}

void configure_uart(void) {
    /* Configure UART */
    err = uart_configure(uart_dev, &uart_cfg);
    if (err == -ENOSYS) { /* If invalid configuration */
        printk("uart_configure() error. Invalid configuration\n\r");
        return; 
    }

    /* Register callback */
    err = uart_callback_set(uart_dev, uart_cb, NULL);
    if (err) {
        printk("uart_callback_set() error. Error code:%d\n\r",err);
        return;
    }
		
    /* Enable data reception */
    err =  uart_rx_enable(uart_dev ,rx_buf,sizeof(rx_buf),RX_TIMEOUT);
    if (err) {
        printk("uart_rx_enable() error. Error code:%d\n\r",err);
        return;
    }

    /* Send a welcome message */ 
    /* Last arg is timeout. Only relevant if flow controll is used */
    err = uart_tx(uart_dev, welcome_mesg, sizeof(welcome_mesg), SYS_FOREVER_MS);
    if (err) {
        printk("uart_tx() error. Error code:%d\n\r",err);
        return;
    }

}

