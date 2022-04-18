/** @file main.c
 * @brief Descrição da main()
 * 
 * 	Este ficheiro contém a main, função principal do nosso trabalho. \n
 *  O nosso trabalho consiste em preencher um vetor com um tamanho 
 * que o utilizador escolhe e, após o preenchimento, calcula a média
 * e a soma dos valores desse vetor
 * 	Neste trabalho temos 3 funções para tornar o código mais organizado.
 * A explicação mais detalhada de cada função estão no ficheiro funcoes.h
 * 
 * @author Beatriz Carvas \n Dário Fernandes \n Guilherme Cajeira
 * @date 17 de março de 2022
 * @bug Não há bugs 
 */

// Includes
#include <stdio.h>
#include "funcoes.h"

/** 
 * @brief Descrição da main()
 * 
 * Inicialmente é definido pelo utilizador o tamanho **n** do vetor a trabalhar.
 * É inicializado o vetor **vect** e chamada a função vInit(), que preenche o vetor.
 * Depois são chamadas as funções vSum() e vAvg(), que calculam a soma e a média dos 
 * valores do vetor.
 * Por último, são feitos os prints dos resultados
 * 
 * @return Return 0 
 */

int main(void)
{
	int n = 0;		// tamanho do vetor, que é escolhido pelo utilizador

	printf("Qual o tamanho do vetor? ");
	scanf("%d",&n);

	int vect[n];	// vetor, inicialmente vazio com tamanho n

	// ------------------- 1ª FUNÇÃO -------------------
	vInit(n , vect);

	printf("Vetor = ");
	for(int i=0;i<n-1;i++)
	{
		printf("%d , ",vect[i]);
	}
	printf("%d",vect[n-1]);
	printf("\n");
	// --------------------------------------------------	

	// ------------------- 2ª FUNÇÃO -------------------
	int sum = vSum(n,vect); 		// Chamada da função que soma os valores do vetor

	printf("Soma de todos os valores é %d\n", sum);
	// -------------------------------------------------

	// ------------------- 3ª FUNÇÃO -------------------
	float media = 0;

	media = vAvg(n,vect);		// Função que faz a média do vetor escolhido

	printf("A média do vetor é igual a %4.2f \n", media);
	// -------------------------------------------------

	return 0;
} 
