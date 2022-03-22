#include <stdio.h>
#include "functions.h"

void MySAGInsert(int N,int *stream)
{

    for (int i=0; i < N; i++ )
    {
        int num ;

        printf("Insira um numero natural \n" );
        scanf("%d", num);

        stream[i] = num ;
        
    }
}