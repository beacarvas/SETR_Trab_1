#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void MySAGInsert(int N,int *stream)
{
   for (int i=0; i < N; i++)
   {
       stream[i] = i+1;
   }
}