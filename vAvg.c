/*
* This is vAvg.c
* Version is: 1 
*/ 

#include <stdio.h>
#include "funcoes.h"

float vAvg(int n,int *vect)
{
    int soma = 0;
    float media = 0;

    for(int i=0;i<n;i++)
    {
        soma = soma + vect[i];
    }

    media = soma / n;

    return media;
}