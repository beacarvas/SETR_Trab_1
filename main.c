/** @file main.c
 * @brief Pequena descrição do ficheiro
 * 
 * 	Este ficheiro contém a main, funcção principal do nosso trabalho
 *  O nossa trabalho consiste em preencher um vetor com um tamanho 
 * que o utilizador escolhe e, após o preenchimento, calcula a média
 * e a soma dos valores desse vetor
 * 	Neste trabalho temos 3 funções para tornar o código mais organizado.
 * A explicação mais detalhada de cada função estão no ficheiro funcoes.h
 * 
 * @author Guilherme Cajeira, Beatriz Carvas e Dário Fernandes
 * @date 17 de março de 2022
 * @bug Não há bugs 
 */

// Includes
#include <stdio.h>
#include "funcoes.h"

int main(void)
{
	int n = 0;		// tamanho do vetor, que é escolhido pelo utilizador

	printf("Qual o tamanho do vetor?");
	scanf("%d",&n);

	int vect[n];	// vetor, inicialmente vazio com tamanho n

	// ------------------- 1ª FUNÇÃO -------------------
	/* vInit(n,vect);		Chamada da função vInit que preenche o vetor

	-> Exemplo de preenchimento de um vetor (melhorar)
	for(int i=0;i<n;i++)
	{
		printf("Quais os números do vetor vect?");
		scanf("%d",&vect[i]);
	}
	*/
	// --------------------------------------------------

	vInit(n , &vect);
	
	// ------------------- 2ª FUNÇÃO -------------------
	float media = 0;

	media = vAvg(n,vect);		// Função que faz a média do vetor escolhido

	printf("A média do vetor é igual a %4.2f \n", media);
	// -------------------------------------------------

	// ------------------- 3ª FUNÇÃO -------------------
	int sum = vSum(n,vect); 		// Chamada da função que soma os valores do vetor

	printf("Soma de todos os valores é %d\n", sum);
	// -------------------------------------------------

	return 0;
} 
