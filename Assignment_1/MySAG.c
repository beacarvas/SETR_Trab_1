#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "functions.h"

int stream[MAXSIZE];

bool MySAGInit(int N, int *stream)
{
    if (N <= MAXSIZE)
    {
        for (int i =0 ; i < N ; i++)
        {
            stream[i] = 0;
        }
        return true;
    }
    else
        return false;
}

void MySAGInsert(int N,int *stream)
{
   for(int i=0;i<N;i++)
   {
       stream[i] = rand() % (2*N);
   }
}

int MySAGMax(int N, int *stream)
{
    int max = stream[1];    // Initialize maximum value with the first value of stream

    for(int i=0; i<N; i++)
    {
        if(stream[i]>max)
        {
            max = stream[i];
        }
    }

    return max;
}

int MySAGMin(int N, int *stream)
{
    int min = stream[1];    // Initialize minimum value with the first value of stream

    for(int i=0; i<N; i++)
    {
        if(stream[i]<min)
        {
            min = stream[i];
        }
    }

    return min;
}

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

int MySAGFreq(int N, int *stream, int x)
{
    int count = 0;  // Counter for the number of times that value x exists in the stream
    
    for(int i=0; i<N; i++)
    {
        if(stream[i]==x)
        {
            count++;
        }
    }

    return count;
}