/*
* This is MySAGFreq.c
* Version 1
*/

#include <stdio.h>
#include "functions.h"

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
