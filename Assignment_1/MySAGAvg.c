#include <stdio.h>
#include "functions.h"

int MySAGAvg(int N, int *stream)
{
    int sum = 0;
    float avg = 0;

    for(int i=0; i<N; i++)
    {
        sum = sum + stream[i];  // faz a soma de todos os elementos em cada iteração
    }

    avg = sum / N;       // calcula a média do elementos da stream

    return avg;
}