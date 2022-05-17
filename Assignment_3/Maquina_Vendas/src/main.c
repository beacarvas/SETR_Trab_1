/** @file main.c
 * @brief Descrição da main().
 * 
 * 	Este ficheiro contém a main(), função principal do nosso trabalho e as funções de 
 *  configuração dos botões utilizados. \n
 *  O nosso trabalho consiste em criar uma máquina de vendas que aceita
*   um conjunto de moedas e permite que o utilizador navegue pelo menu de produtos
*   disponíveis, compre um produto e devolva o crédito final. \n.
 *  Esta máquina de vendas será implementada através de uma máquina de estados com sete 
 *  estados inerentes. A explicação mais detalhada de cada estado é apresentada na 
 *  descrição da main() \n
 *    
 * @author Beatriz Carvas \n Dário Fernandes \n Guilherme Cajeira
 * @date 17 de maio de 2022
 * @bug Não há bugs 
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <sys/printk.h>
#include <sys/__assert.h>
#include <string.h>
#include <timing/timing.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/** @brief Label GPIO0
 */
#define GPIO0_NID DT_NODELABEL(gpio0) 

/** @brief Botão 1 que corresponde a 10 cent.
 */
#define BOARDBUT1 11    // Pin at which BUT1 is connected

/** @brief Botão 2 que corresponde a 20 cent.
 */
#define BOARDBUT2 12    // Pin at which BUT2 is connected

/** @brief Botão 3 que corresponde a 50 cent.
 */
#define BOARDBUT3 24    // Pin at which BUT3 is connected

/** @brief Botão 4 que corresponde a 1 EUR.
 */
#define BOARDBUT4 25    // Pin at which BUT4 is connected

/** @brief Botão UP que corresponde a andar para cima no menu dos produtos.
 */
#define BUTUP     3     // Pin at which BUTUP (P0.03) is connected

/** @brief Botão DOWN que corresponde a andar para baixo no menu dos produtos.
 */
#define BUTDOWN   4     // Pin at which BUTDOWN (P0.04) is connected

/** @brief Botão SELECT que corresponde a escolher um produto.
 */
#define BUTSELECT 28    // Pin at which BUTSELECT (P0.28) is connected

/** @brief Botão RETURN que corresponde a receber o crédito atual.
 */
#define BUTRETURN 29    // Pin at which BUTRETURN (P0.29) is connected


/** @brief Estado onde são introduzidas as moedas (estado "IDLE").
 */
#define WAIT_FOR_COIN   0

/** @brief Estado onde o produto é escolhido e selecionado.
 */
#define CHOICE_PROD     1

/** @brief Estado onde é verificado se o cliente tem crédito suficiente tendo em conta o produto que este selecionou.
 */
#define COMPARE_CREDIT  2

/** @brief EEstado onde o cliente recebe o troco.
 */
#define RETURN_CREDIT   5 // valor passou de 2 para 5 so para nao entrar em 
                          // conflito com os define dos pinos

/** @brief Estado onde é dispensada a cerveja e descontado o respetivo valor do produto ao crédito total.
 */
#define BEER            6

/** @brief Estado onde é dispensada a sandes de atum e descontado o respetivo valor do produto ao crédito total.
 */
#define TUNA            7

/** @brief Estado onde é dispensado o café e descontado o respetivo valor do produto ao crédito total.
 */
#define COFFEE          8

const struct device *gpio0_dev;          /* Pointer to GPIO device structure */

/* Int related declarations */
static struct gpio_callback but1_cb_data; /* Callback structure */
static struct gpio_callback but2_cb_data; /* Callback structure */

volatile double coin = 0.0;

volatile int up = 0; 
volatile int down = 0; 
volatile int select_prod = 0; 
volatile int return_credit = 0; 

int ret = 0;
void configure_pins_board(void);
void configure_pins_external(void);

/** 
 * @brief Descrição da função de configuração but1press_cbfunction()
 * 
 * Função que implementa a ação realizada ao premir cada um dos botões que fazem parte do kit da Nordic e que foram 
 * implementados neste projeto.
 * 
 */

void but1press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins) 
{
    
    if(BIT(BOARDBUT1) & pins) {
      coin = 0.1;
    }

    if(BIT(BOARDBUT2) & pins) {
      coin = 0.2;
    }

    if(BIT(BOARDBUT3) & pins) {
      coin = 0.5;
    }

    if(BIT(BOARDBUT4) & pins) {
      coin = 1;
    }

}

/** 
 * @brief Descrição da função de configuração but2press_cbfunction()
 * 
 * Função que implementa a ação realizada ao premir cada um dos botões ligados externamente e que foram 
 * implementados neste projeto.
 * 
 */

void but2press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins) 
{
    
    if(BIT(BUTUP) & pins) {
      up = 1;
    }

    if(BIT(BUTDOWN) & pins) {
      down = 1;
    }

    if(BIT(BUTSELECT) & pins) {
      select_prod = 1;
    }

    if(BIT(BUTRETURN) & pins) {
      return_credit = 1;
    }

}

/** 
 * @brief Descrição da main()
 * 
 * Inicialmente é apresentado um menu com os produtos disponíveis, assim como uma breve descrição do funcionamento da máquina de vendas. \n
 * A máquina de vendas é constituída por sete estados, tais como: \n
 *  - WAIT_FOR_COIN: Estado onde são introduzidas as moedas (estado "IDLE"); \n
 *  - CHOICE_PROD: Estado onde o produto é escolhido e selecionado; \n
 *  - COMPARE_CREDIT: Estado onde é verificado se o cliente tem crédito suficiente tendo em conta o produto que este selecionou; \n
 *  - RETURN_CREDIT:  Estado onde o cliente recebe o troco; \n
 *  - BEER: Estado onde é dispensada a cerveja e descontado o respetivo valor do produto ao crédito total; \n
 *  - TUNA: Estado onde é dispensada a sandes de atum e descontado o respetivo valor do produto ao crédito total; \n
 *  - COFFEE: Estado onde é dispensado o café e descontado o respetivo valor do produto ao crédito total. \n
 * 
 * 
 * @return Return.
 * 
 */


/* Main function */
void main(void) {
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
    configure_pins_external();    

    printk("Configures done \n\n\r");

    

    // Initialization variables
    int state = 0;
    double credit = 0.0;
    int index_prod = 0;
    char *products[3] = {"Cerveja","Sandes de Atum","Cafe"};
    double price_product[3] = {1.5, 1, 0.5};

    printk("------------------------------------------------------------------------- \n\r");
    printk(" MENU \n\r");
    printk("  - Cerveja: 1.5 EUR \n\r");
    printk("  - Sandes de Atum: 1 EUR \n\r");
    printk("  - Cafe: 0.5 EUR \n\r");
    printk("------------------------------------------------------------------------- \n\r");
    printk(" ORDEM DO PROCESSO \n\r");
    printk("  1- Inserir moedas ate ao valor desejado (botoes das moedas) \n\r");
    printk("  2- Escolher o produto desejado (botoes up/down e depois select_prod) \n\r");
    printk("  3- Se tiver dinheiro suficiente e dispensado o produto \n\r");
    printk("  4- Se desejar receber o credito atual, carregar no botao return_credit \n\r");
    printk("------------------------------------------------------------------------- \n\r");
    printf("Credito atual: %d.%d EUR \n\n\r",(int)credit,(int)((credit-(int)credit)*10));
    printk("Insira moeda: ");

    while(1) {
      switch(state) {
        case WAIT_FOR_COIN:
          index_prod = 0;
          k_msleep(200);        // delay de 200 ms para evitar erros na leitura do botao e o seu respetivo valor
          credit += coin;       // variavel credit acumula o valor da moeda inserida ao que ja tinha anteriormente
          

          if(coin != 0) {       // quando e novamente inserida uma moeda
            
            printf("%d.%d EUR \n\r",(int)coin,(int)((coin-(int)coin)*10));  // print do valor da moeda inserida

            coin = 0;           // voltar a colocar a variavel coin a 0 para esperar que volte a ser inserida uma nova moeda

            printf("Credito atual: %d.%d EUR \n\n\r",(int)credit,(int)((credit-(int)credit)*10));   // print do credito atual

            printk("Insira moeda: ");
          }

          if(up == 0 && down == 0)        // condicao para se manter no mesmo estado
            state = WAIT_FOR_COIN;        // o next_state sera o mesmo estado

          if(up == 1 || down == 1) {      // condicao para mudar para o estado "CHOICE_PROD"
            state = CHOICE_PROD;          // o next_state e o estado "CHOICE_PROD"
            printk("\n-- Escolha o produto -- \n\r");  
          }

          if(return_credit == 1)          // condicao para mudar para o estado "RETURN_CREDIT"
            state = RETURN_CREDIT;        // o next_state e o estado "RETURN_CREDIT"

          if(select_prod == 1) {          // no caso do botao select_prod ser premido
            state = WAIT_FOR_COIN;        // mantem-se no mesmo estado, pois este botao nao e um evento no estado "WAIT_FOR_COIN"
            select_prod = 0;              // e necessario voltar a colocar a variavel select_prod a 0, senao ela fica com o valor logico '1'
                                          // guardado e, apesar de nao afetar neste estado, afeta nos seguintes em que e um evento
          }

          break;

        
        case CHOICE_PROD:
         if(select_prod == 0) {     // se o botao para selecionar o producao nao for premido
            if(up == 1) {               // se o botao up for premido  
              index_prod++;             // a selecao passa para o produto acima do atual
              if(index_prod > 2)        // condicao necessaria para o caso de chegar ao ultimo produto do menu, tem de voltar ao primeiro
                index_prod = 0;

              printk("Produto a selecionar: %s \n\r",products[index_prod]);   // print do produto que esta em selecao no presente momento
              up = 0;                   // voltar a colocar a variavel up a 0 
            }
            else if(down == 1) {        // se o botao down for premido
              index_prod--;             // a selecao passa para o produto abaixo do atual
              if(index_prod < 0)        // condicao necessaria para o caso de chegar ao primeiro produto do menu, tem de voltar ao ultimo
                index_prod = 2;

              printk("Produto a selecionar: %s \n\r",products[index_prod]);   // print do produto que esta em selecao no presente momento
              down = 0;
            }

            state = CHOICE_PROD;
          }

          else if(select_prod == 1)   // se o botao para selecionar o produto for premido- condicao para mudar para o estado "COMPARE_CREDIT"
            state = COMPARE_CREDIT;   // o next_state e o estado "COMPARE_CREDIT"
        
          if(return_credit == 1)      // condicao para mudar para o estado "RETURN_CREDIT"
            state = RETURN_CREDIT;    // o next_state e o estado "RETURN_CREDIT"

          if(coin != 0)               // se neste estado for premido algum dos botoes das moedas
            coin = 0;                 // o valor da variavel coin deve voltar a ter o valor 0 para nao afetar o valor do credit, no caso de 
                                      // voltarmos ao estado "WAIT_FOR_COIN"
          
          break;


        case COMPARE_CREDIT:
          select_prod = 0;                          // forcar variavel do botao "select_prod" a zero
          if(credit >= price_product[index_prod])   // Comparacao entre o credito disponivel e o preco do produto
          {
            if(index_prod == 0)                     // condicao para mudar para o estado "BEER"
              state = BEER;                         // o next_state e o estado "BEER"
            else if(index_prod == 1)                // condicao para mudar para o estado "TUNA"
              state = TUNA;                         // o next_state e o estado "TUNA"
            else if(index_prod == 2)                // condicao para mudar para o estado "COFFEE"
              state = COFFEE;                       // o next_state e o estado "COFFEE"
          }
          else                                     // caso credito nao seja suficiente, volta para o estado WAIT_FOR_COIN (introducao de moedas)
          {
            state = WAIT_FOR_COIN;                 // o next_state e o estado "WAIT_FOR_COIN" 
            printk("\nSaldo Insuficiente!!!\n");
            printk("\nInsira moeda: ");
          }

          break;


        case RETURN_CREDIT:
          return_credit = 0;                                                              // forcar variavel do botao "return_credit" a zero
          printf("TROCO: %d.%d EUR \n\n\r",(int)credit,(int)((credit-(int)credit)*10));   // print do troco
          credit = 0;                                                                     // reset da variavel credito
          
          printk("------------------------------------------------------------------------- \n\r");
          printk(" MENU \n\r");
          printk("  - Cerveja: 1.5 EUR \n\r");
          printk("  - Sandes de Atum: 1 EUR \n\r");
          printk("  - Cafe: 0.5 EUR \n\r");
          printk("------------------------------------------------------------------------- \n\r");
          printk(" ORDEM DO PROCESSO \n\r");
          printk("  1- Inserir moedas ate ao valor desejado (botoes das moedas) \n\r");
          printk("  2- Escolher o produto desejado (botoes up/down e depois select_prod) \n\r");
          printk("  3- Se tiver dinheiro suficiente e dispensado o produto \n\r");
          printk("  4- Se desejar receber o credito atual, carregar no botao return_credit \n\r");
          printk("------------------------------------------------------------------------- \n\r");
          printf("Credito atual: %d.%d EUR \n\n\r",(int)credit,(int)((credit-(int)credit)*10));
          printk("Insira moeda: ");

          state = WAIT_FOR_COIN;                                                                 // o next_state e o estado "WAIT_FOR_COIN"

          break;

        
        case BEER:
          credit -= price_product[index_prod];                                                    // calculo do troco e atualizacao do credito
          printk("\nCerveja dispensada!\n\r");
          printf("Credito atual: %d.%d EUR \n\n\r",(int)credit,(int)((credit-(int)credit)*10));   // print do credito atual
          printk("Escolha outro produto\n");

          state = WAIT_FOR_COIN;                                                                  // o next_state e o estado "WAIT_FOR_COIN"

          break;

        case TUNA:
          credit -= price_product[index_prod];                                                    // calculo do troco e atualizacao do credito
          printk("\nSandes de Atum dispensada!\n\r");
          printf("Credito atual: %d.%d EUR \n\n\r",(int)credit,(int)((credit-(int)credit)*10));   // print do credito atual
          printk("Escolha outro produto\n");

          state = WAIT_FOR_COIN;                                                                  // o next_state e o estado "WAIT_FOR_COIN"
          break;

        case COFFEE:
          credit -= price_product[index_prod];                                                    // calculo do troco e atualizacao do credito
          printk("\nCafe dispensado!\n\r");
          printf("Credito atual: %d.%d EUR \n\n\r",(int)credit,(int)((credit-(int)credit)*10));   // print do credito atual
          printk("Escolha outro produto\n");

          state = WAIT_FOR_COIN;                                                                  // o next_state e o estado "WAIT_FOR_COIN"
          break;
          

      }
    }


    return;

 }


/** 
 * @brief Descrição da função de configuração configure_pins_board()
 * 
 * Função de configuração dos 4 botões que fazem parte do kit da Nordic, que inclui a configuração do pino de cada botão
 * respetivo, a configuração da interrupção de cada pino e por último a inicialização da estrtura callback associada aos 
 * 4 botões e a sua aplicação.
 * 
 */

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

/** 
 * @brief Descrição da função de configuração configure_pins_external()
 * 
 * Função de configuração dos 4 botões ligados externamente, que inclui a configuração do pino de cada botão
 * respetivo, a configuração da interrupção de cada pino e por último a inicialização da estrtura callback associada aos 
 * 4 botões e a sua aplicação. 
 * 
 */

void configure_pins_external(void) {
    // Configure External Buttons
    ret = gpio_pin_configure(gpio0_dev, BUTUP, GPIO_INPUT | GPIO_PULL_UP);
    ret = gpio_pin_configure(gpio0_dev, BUTDOWN, GPIO_INPUT | GPIO_PULL_UP);
    ret = gpio_pin_configure(gpio0_dev, BUTSELECT, GPIO_INPUT | GPIO_PULL_UP);
    ret = gpio_pin_configure(gpio0_dev, BUTRETURN, GPIO_INPUT | GPIO_PULL_UP);

    // Set interrupt External Buttons - which pin and event generate interrupt 
    ret = gpio_pin_interrupt_configure(gpio0_dev, BUTUP, GPIO_INT_EDGE_TO_INACTIVE);
    ret = gpio_pin_interrupt_configure(gpio0_dev, BUTDOWN, GPIO_INT_EDGE_TO_INACTIVE);
    ret = gpio_pin_interrupt_configure(gpio0_dev, BUTSELECT, GPIO_INT_EDGE_TO_INACTIVE);
    ret = gpio_pin_interrupt_configure(gpio0_dev, BUTRETURN, GPIO_INT_EDGE_TO_INACTIVE);

    /* Set callback */
    gpio_init_callback(&but2_cb_data, but2press_cbfunction, BIT(BUTUP)| BIT(BUTDOWN)| BIT(BUTSELECT) | BIT(BUTRETURN));
    gpio_add_callback(gpio0_dev, &but2_cb_data);
}






