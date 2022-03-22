/*
* This is MySAGMax.c
* Version 1
*/

#include <stdio.h>
#include "functions.h"

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
