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

    soma = vSum(n,vect);

    media = soma / n;

    return media;
}