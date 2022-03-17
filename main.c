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

	// ------------------- 2ª FUNÇÃO -------------------
	float media = 0;

	media = vAvg(n,vect);		// Função que faz a média do vetor escolhido

	printf("A média do vetor é igual a %4.2f \n", media);
	// -------------------------------------------------

	// ------------------- 3ª FUNÇÃO -------------------
	/* vSum(n,vect); 		Chamada da função que soma os valores do vetor

	*/
	// -------------------------------------------------

	return 0;
} 
