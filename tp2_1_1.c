#include<stdio.h>
#define N 4
#define M 5

int main(){
    int f,c,d=1;
    double mt [N][M];

     for ( f = 0; f < N; f++)
    {
        for (c = 0; c < M; c++)
        {
             mt[f][c]=d;   
             d++;
        }
    }

    for ( f = 0; f < N; f++)
    {
        for (c = 0; c < M; c++)
        {
             printf("%.1f ",mt[f][c]);            
        }
        printf("\n");
    }
    
    return 0;
}