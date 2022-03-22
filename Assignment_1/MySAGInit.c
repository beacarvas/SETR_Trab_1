#include <stdio.h>
#include "functions.h"

//extern int N;
//extern int stream[N] ;

int stream[MAXSIZE];

int MySAGInit(int N, int *stream)
{
    if (N <= MAXSIZE)
    {
        for (int i =0 ; i < N ; i++)
        {
            stream[i] = 0;
        }
        return 1;
    }
    else
    {   
        return -1;
    }
    
}
