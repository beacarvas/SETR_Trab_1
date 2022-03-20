

#include <stdio.h>
#include "funcoes.h"

void vInit(int N,int *vect)
{
    for (int i=0; i < N; i++ )
    {
        vect[i] = i +1;
        
    }

}

/* para testar a função 
int main(){
    int N=5;
    int vect[N];
    vInit(N,vect);

    for (int i=0; i < N; i++ )
    {
        printf("%d\n",vect[i]);
    }
    return 0;
}

*/
