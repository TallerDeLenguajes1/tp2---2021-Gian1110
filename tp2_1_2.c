#include<stdio.h>
#define N 4
#define M 5

int main(){
    int f,c,d=0;
    double mt [N][M],*punteroDoble;
    punteroDoble = &mt[0][0];

    for ( f = 0; f < N; f++)
    {
        for (c = 0; c < M; c++)
        {

             *(punteroDoble+d)=d;  
             d++;
        }
    }
    d=0;
    for ( f = 0; f < N; f++)
    {
        for (c = 0; c < M; c++)
        {
             printf("%.1f",*(punteroDoble+d));   
            d++;    
        }
         printf("\n");
    }
    
    return 0;
}