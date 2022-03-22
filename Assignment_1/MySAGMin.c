/*
* This is MySAGMin.c
* Version 1
*/

#include <stdio.h>
#include "functions.h"

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
