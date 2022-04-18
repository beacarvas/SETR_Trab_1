/*
    Auth: Dário Fernandes
    NMec: 93135
    SETR

    This function will compute the sum of all values in the vector
*/

#include <stdio.h>
#include "funcoes.h"   // library with all the functions

int vSum(int n, int* vect)
{
    int sum = 0;

    for(int i=0; i<n; i++)
    {
        sum = sum + vect[i];  // faz a soma de todos os elementos em cada iteração
    }

    return sum;
}