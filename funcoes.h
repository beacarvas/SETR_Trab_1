/*
* This is funcoes.h
* Version is: 1 
*/ 

/** @file funcoes.h
 * @brief Pequena descrição do ficheiro
 * 
 * Este ficheiro contém as 3 funções que são chamadas na main e a sua função é:
 * 1º- preencher o vetor com tamanho n, definido pelo utilizador
 * 2º- calcular a média de todos os números do vetor
 * 3º- calcular a soma de todos os números do vetor
 * 
 * @author Guilherme Cajeira, Beatriz Carvas e Dário Fernandes
 * @date 17 de março de 2022
 * @bug Não há bugs 
 */

#ifndef _FUNCOES_H
#define _FUNCOES_H

/**
 * @brief Pequena descrição da função vInit
 * 
 * A função vInit preenche um vetor de numeros naturais, com um tamanho escolhido pelo o utilizador.
 * 
 * @param n Representa o tamanho do vetor vect
 * @param vect Representa o vetor
 * @return  
 * @author Beatriz Carvas
 */
 
 void vInit(int n,int *vect);     // modificar caso necessário

/**
 * @brief Pequena descrição da função vAvg
 * 
 * A função vAvg recebe o vetor e o valor do seu tamanho e calcula a média
 * de todos os valores, somando-os um a um e no fim divide pelo número de 
 * elementos do vetor (n)
 * 
 * @param n Representa o tamanho do vetor vect, 1º parâmetro da função
 * @param vect Representa o vetor, 2º parâmetro da função
 * @return Retorna o valor da media dos valores do vetor
 */
float vAvg(int n,int *vect);

/**
 * @brief Calcula a soma dos valores de vect 
 * 
 * A função irá fazer a soma de todos os elementos do vetor vect.
 * 
 * @param n Representa o tamanho do vetor vect, 1º parâmetro da função
 * @param vect Representa o vetor, 2º parâmetro da função
 * @return Retorna o valor da soma de todos os valores do vetor
 */
int vSum(int n,int *vect);       // modificar caso necessário

#endif

