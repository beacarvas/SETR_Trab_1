#include <stdio.h>
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
        return TRUE;
    }
    else
    {   
        return FALSE;
    }
    
}
