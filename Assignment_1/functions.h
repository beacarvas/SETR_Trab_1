/** @file functions.h
 * @brief Biblioteca das funções.
 * 
 * Este ficheiro contém as 6 funções que são chamadas na main (test_app.c), sendo a sua função: \n
 *  1º- Criar e inicializar o módulo; \n
 *  2º- Inserir elementos no módulo criado; \n
 *  3º- Identificar o valor máximo contido no módulo;\n
 *  4º- Identificar o valor mínimo contido no módulo; \n
 *  5º- Calcular a média (arredondada às unidades) dos valores do módulo; \n
 *  6º- Verificar o número de vezes que um certo valor foi inserido no módulo. \n
 * 
 * @author Beatriz Carvas \n Dário Fernandes \n Guilherme Cajeira
 * @date 22 de março de 2022
 * @bug Não há bugs.
 */

#include <stdbool.h>

#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H


/** @brief Tamanho máximo do módulo admitido.
 * 
 */

#define MAXSIZE 100  

/**
 * @brief Criação e inicialização do módulo **stream**.
 * 
 * A função MySAGInit cria e inicializa o módulo, com um tamanho escolhido pelo o utilizador. \n
 * O tamanho do módulo escolhido não deve exceder o limite máximo imposto **MAXSIZE**.
 * 
 * @param N Representa o tamanho do módulo.
 * @param stream Representa o módulo.
 * 
 * @verbatim
   Autor:
    * Beatriz Carvas, nº93209
    * Email: beatrizcarvas@ua.pt @endverbatim
 */
    bool MySAGInit(int N,int *stream);

/**
 * @brief Preenchimento do módulo **stream** com números naturais.
 * 
 * A função MySAGInsert é responsável por preencher o módulo criado de forma aleatória com números naturais.
 * 
 * @param N Representa o tamanho do módulo.
 * @param stream Representa o módulo.
 * 
 * @verbatim
   Autor:
    * Beatriz Carvas, nº93209
    * Email: beatrizcarvas@ua.pt @endverbatim
 */
    void MySAGInsert(int N,int *stream);

/**
 * @brief Devolve o valor máximo do módulo **stream**.
 * 
 * A função MySAGMax percorre todo o módulo e identifica o valor máximo presente.
 * 
 * @param N Representa o tamanho do módulo.
 * @param stream Representa o módulo.
 * @return Retorna o valor máximo presente no módulo.
 * 
 * @verbatim
   Autor:
    * Dário Fernandes, nº93135
    * Email: d.fernandes15@ua.pt @endverbatim
 */
    int MySAGMax(int N,int *stream);

/**
 * @brief Devolve o valor mínimo do módulo **stream**.
 * 
 * A função MySAGMax percorre todo o módulo e identifica o valor mínimo presente.
 * 
 * @param N Representa o tamanho do módulo.
 * @param stream Representa o módulo.
 * @return Retorna o valor mínimo presente no módulo.
 * 
 * @verbatim
   Autor:
    * Dário Fernandes, nº93135
    * Email: d.fernandes15@ua.pt @endverbatim
 */
    int MySAGMin(int N,int *stream);

/**
 * @brief Calcula a média do módulo **stream**.
 * 
 * A função MySAGAvg recebe o módulo e o valor do seu tamanho e calcula a média
 * de todos os valores, somando-os um a um e no fim divide pelo número de 
 * elementos do vetor **n**.
 * 
 * @param N Representa o tamanho do módulo.
 * @param stream Representa o módulo.
 * @return Retorna o valor da média calculada.
 * 
 * @verbatim
   Autor:
    * Guilherme Cajeira, nº93138
    * Email: gcajeira@ua.pt @endverbatim
 */
    int MySAGAvg(int N,int *stream);

/**
 * @brief Verificar o número de vezes que um certo valor foi inserido no módulo **stream**.
 * 
 * A função MySAGMax percorre todo o módulo e identifica o número de ocorrẽncias de um dado valor.
 * O contador é incrementado cada vez que uma ocorrência é observada.
 * 
 * @param N Representa o tamanho do módulo.
 * @param stream Representa o módulo.
 * @param x Representa o valor cuja frequência no módulo se pretende observar.
 * @return Retorna o número de vezes que um certo valor aparece no módulo.
 * 
 * @verbatim
   Autor:
    * Dário Fernandes, nº93135
    * Email: d.fernandes15@ua.pt @endverbatim
 */
int MySAGFreq(int N,int *stream,int x);

#endif