


// Includes
#include <stdio.h>
#include "functions.h"

extern int stream[];

int main(void)
{
	int N = 0;

	printf("Qual o tamanho do módulo? ");
	scanf("%d",&N);

	MySAGInit(N,stream);

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

    
	return 0;
} 
