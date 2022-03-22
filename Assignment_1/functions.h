/** @file functions.h
 * @brief Biblioteca das funções
 * 
 * Este ficheiro contém as 6 funções que são chamadas na main (test_app.c), sendo a sua função: \n
 *  1º- Criar e inicializar o módulo \n
 *  2º- Inserir elementos no módulo criado \n
 *  3º- Identificar o valor máximo contido no módulo \n
 *  4º- Identificar o valor mínimo contido no módulo \n
 *  5º- Calcular a média (arredondada às unidades) dos valores do módulo \n
 *  6º- Verificar o número de vezes que um certo valor foi inserido no módulo \n
 * 
 * @author Beatriz Carvas \n Dário Fernandes \n Guilherme Cajeira
 * @date 22 de março de 2022
 * @bug Não há bugs 
 */

#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#define MAXSIZE 100;  // Tamanho máximo do módolo admitido

/**
 * @brief Criação e inicialização do módulo **stream** com números naturais
 * 
 * A função vInit preenche um vetor de numeros naturais, com um tamanho escolhido pelo o utilizador.
 * 
 * @param n Representa o tamanho do vetor vect
 * @param vect Representa o vetor 
 * 
 * @verbatim
   Autor:
    * Beatriz Carvas, nº93209
    * Email: beatrizcarvas@ua.pt @endverbatim
 */
    void MySAGInit(int N,int *stream);


void MySAGInsert(int N,int *stream);
int MySAGMax(int N,int *stream);
int MySAGMin(int N,int *stream);
int MySAGAvg(int N,int *stream);
int MySAGFreq(int N,int *stream,int x);

#endif