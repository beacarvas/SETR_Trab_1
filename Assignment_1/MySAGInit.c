#include <stdio.h>
#include "functions.h"

//extern int N;
//extern int stream[N] ;


void MySAGInit(int N, int *stream)
{
    for (int i =0 ; i < N ; i++)
    {
         stream[i] = 0;
    }
    
    
}
