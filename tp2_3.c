#include <stdio.h>
#include <stdlib.h>
#define filas 15
//declaracion de funciones
void cargarMatriz (double *,int);
void mostrarMatriz(double *, int);
int paresMatriz(double *);
void vectorDinamico(double *,int,int*);
void mostrarVector(int*);
//menu principal 
int main (){
    int *vector,vt[filas],columnas = (int) rand() % 11+5; //columnas random entre 10 y 15
    double *matriz,mt[filas][columnas]; //defino una matriz con filas y columanas y declaro un puntero
    vector=&vt[0];
    matriz=&mt[0][0];//asigno puntero a la matriz
    cargarMatriz (matriz,columnas); //llamado de funcion crearYCargarMatriz
    mostrarMatriz(matriz, columnas);//llamado de funcion mostrarMatriz
    vectorDinamico(matriz,columnas,vector); //llamado de funcion vectorDinamico
    mostrarVector(vector); //llamado de funcion mostrarVector
    return 0;
}
void cargarMatriz (double *matriz,int columnas)
{
    double *aux=matriz; //se usa un axiliar para no perder el primer espacio de memoria 
    for (int fila = 0; fila < filas; fila++)
    {
        for (int columna = 0; columna < columnas; columna++)
        {
            *aux = (int) rand() % 900 + 100;
            aux++;
        }
    }
}
void mostrarMatriz(double *matriz, int columnas)
{
    double *aux = matriz;//se usa un axiliar para no perder el primer espacio de memoria 
    for (int fila = 0; fila < filas; fila++)
    {
        for (int columna = 0; columna < columnas; columna++)
        {
            printf("%f",*aux);
            aux++;
        }
        printf("\n");
    }    
}
//la funcion devulve la cantidad de elementos pares
int paresMatriz(double *matriz)
{
    double *aux = matriz;//se usa un axiliar para no perder el primer espacio de memoria
    int cantidad=0;//para contar la cantida de elementos que se tiene
    for (int fila = 0; fila < filas; fila++)
    {
        if((int)*aux % 2 == 0) // si es par devuelve 0 e incrementa en 1 el contador
        {
            cantidad++; 
        }
        aux++;
    }
    return cantidad;
}

void vectorDinamico(double *matriz,int columnas,int *vector)
{
    double *aux = matriz;//se usa un axiliar para no perder el primer espacio de memoria de la matriz
    int *aux2 = vector;//se usa un axiliar para no perder el primer espacio de memoria del vector
    for (int columna = 0; columna < columnas; columna++)
    {
        *aux2 = (int) paresMatriz(aux);    // se llama a la funcion que te devuelve la cantidad de pares en una fila
        aux = aux + filas;
        aux2++;
    } 
}
void mostrarVector(int *vector)
{
    int *aux = vector;//se usa un axiliar para no perder el primer espacio de memoria del vector
    for (int i = 0; i < filas; i++)
    {
        printf("%d-",*aux);
        aux++;
    }
}