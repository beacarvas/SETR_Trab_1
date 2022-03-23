/** @file test_app.c
 * @brief Descrição da test_app()
 * 
 * 	Este ficheiro contém a main, função principal do nosso trabalho. \n
 *  O nosso trabalho consiste em inicializar um módulo com um tamanho 
 * que o utilizador escolhe e, após a inicialização, executa o seu preenchimento aleatório, 
 * calcula o valor máximo, o mínimo e a média do módulo. Além disso, determina o
 * número de vezes que um número está presente no módulo. \n
 * 	Neste trabalho temos 6 funções para tornar o código mais organizado.
 * A explicação mais detalhada de cada função estão no ficheiro funcoes.h
 * 
 * @author Beatriz Carvas \n Dário Fernandes \n Guilherme Cajeira
 * @date 22 de março de 2022
 * @bug Não há bugs 
 */

// Includes
#include <stdio.h>
#include "functions.h"

/** @brief Módulo de números inteiros.
 * 
 * O utilizador, após escolher o tamanho do módulo **stream**, este é preenchido
 * com valores random. \n
 * Este módulo **stream** é utilizado em todo o projeto.
 * 
 */
 
extern int stream[MAXSIZE];

/** 
 * @brief Descrição da test_app()
 * 
 * Inicialmente é definido pelo utilizador o tamanho **N** do módulo a trabalhar.
 * É inicializado o módulo **stream** e chamada a função MySAGInit() e MySAGInsert(), 
 * que inicializam e preenchem o módulo.
 * Depois são chamadas as funções MySAGMax(), MySAGMin() e MySAGAvg(), que calculam 
 * o valor máximo, mínimo e a média dos valores do módulo.
 * Por último, é pedido ao utilizador o número que quer saber quantas vezes está presente
 * no módulo e é chamada a função MySAGFreq(), que indica a frequência desse valor.
 * Após cada chamada das funções, são feitos os prints dos resultados.
 * 
 * @return Return 0
 * @exception ERROR- MAXSIZE foi ultrapassado.
 */

int main(void)
{
	int N = 0;

	printf("Qual o tamanho do módulo? ");
	scanf("%d",&N);

	int init = MySAGInit(N,stream);

	if (init == true)
	{
		MySAGInsert(N,stream);
		printf("Stream = ");
		for(int i=0;i<N-1;i++)
		{
			printf("%d , ",stream[i]);
		}
		printf("%d",stream[N-1]);
		printf("\n");

		// ------------------- MÁXIMO ----------------------
		int max = MySAGMax(N,stream);
		printf("O valor máximo do módulo é %d \n",max);

		// ------------------- MÍNIMO ----------------------
		int min = MySAGMin(N,stream);
		printf("O valor mínimo do módulo é %d \n",min);

		// ------------------- MÉDIA ----------------------
		int avg = MySAGAvg(N,stream);
		printf("A média do módulo é %d \n",avg);

		// ----------------- FREQUÊNCIA -------------------
		int x = 0;
		printf("Valor a ver o número de vezes que aparece: ");
		scanf("%d",&x);
		int freq = MySAGFreq(N,stream,x);
		if (freq == 0)
			printf("Não há nenhum número no módulo igual a %d \n",x);
		else 
			printf("O número %d existe %d vezes no módulo \n",x,freq);
	}
	else
		printf("ERROR- MAXSIZE foi ultrapassado \n");


	return 0;
} 