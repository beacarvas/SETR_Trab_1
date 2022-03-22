


// Includes
#include <stdio.h>
#include "functions.h"

int main(void)
{
	int N = 0;



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
		printf("Não há nenhum número no módulo igual a %d",x);
	else 
		printf("O número %d existe %d vezes no módulo",x,freq);

    
	return 0;
} 
