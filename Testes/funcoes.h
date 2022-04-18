/** @file funcoes.h
 * @brief Biblioteca das funções
 * 
 * Este ficheiro contém as 3 funções que são chamadas na main e a sua função é: \n
 *  1º- preencher o vetor com tamanho n, definido pelo utilizador \n
 *  2º- calcular a média de todos os números do vetor \n
 *  3º- calcular a soma de todos os números do vetor \n
 * 
 * @author Beatriz Carvas \n Dário Fernandes \n Guilherme Cajeira
 * @date 17 de março de 2022
 * @bug Não há bugs 
 */

#ifndef _FUNCOES_H
#define _FUNCOES_H

/**
 * @brief Preenchimento do vetor **vect** com números naturais
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
 
 void vInit(int n,int *vect);     // modificar caso necessário

/**
 * @brief Calcula a média do vetor **vect**
 * 
 * A função vAvg recebe o vetor e o valor do seu tamanho e calcula a média
 * de todos os valores, somando-os um a um e no fim divide pelo número de 
 * elementos do vetor **n**
 * 
 * @param n Representa o tamanho do vetor vect 
 * @param vect Representa o vetor
 * @return Retorna o valor da média calculada
 * 
 * @verbatim
   Autor:
    * Guilherme Cajeira, nº93138
    * Email: gcajeira@ua.pt @endverbatim
 */
float vAvg(int n,int *vect);

/**
 * @brief Calcula a soma dos valores do vetor **vect**
 * 
 * A função irá fazer a soma de todos os elementos do vetor **vect**.
 * 
 * @param n Representa o tamanho do vetor vect
 * @param vect Representa o vetor
 * @return Retorna o valor da soma de todos os valores do vetor
 * 
 * @verbatim
   Autor:
    * Dário Fernandes, nº93135
    * Email: d.fernandes15@ua.pt @endverbatim
 */
int vSum(int n,int *vect);       // modificar caso necessário

#endif

