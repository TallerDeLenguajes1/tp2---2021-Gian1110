#include <stdio.h>
#include <stdlib.h>
//definicion de estructura
typedef struct compu{
    int velocidad; //entre 1 y 3 GHz
    int anio;// entre 200 y 2017
    int cantidad; //entre 1 y 4
    char *tipo_cpu;// valores del arreglo tipos
}PC;
//definicion de funciones
struct compu armadoPC(PC, char [6][10]);
void listado(PC *,int);
void mostrarPC(PC);
void vieja(PC *,int);
void armarlista(PC *,int);
void velocidad(PC *,int);

//menu principal
int main()
{
    int cantidad=4;
    PC *punteroLista,lista[10]; 
    punteroLista = &lista[0];
    armarlista(punteroLista,cantidad);
    listado(punteroLista,cantidad);
    printf("\n\n\n\n\n\n\n");
    vieja(punteroLista,cantidad);
    velocidad(punteroLista,cantidad);
return 0;
}


struct compu armadoPC(PC computadora,char cpu[6][10])
{
    computadora.velocidad = (int) rand() % 5 +1;
    computadora.anio = (int) rand() %18 +2000;
    computadora.cantidad = (int) rand() % 4 +1;
    computadora.tipo_cpu = &cpu[(int) rand() % 5 +1][10];
    return computadora;  
}
void armarlista(PC *Lista, int cantidad)
{
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    PC computadora;
    for (int i = 0; i < cantidad; i++)
    {
        *(Lista+i)=armadoPC(computadora,tipos);
    }
    
}

void listado(PC *listado,int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        mostrarPC((PC)*(listado+i));
    }
}
void mostrarPC(PC computadora)
{
    printf("velocidad: %d\n",computadora.velocidad);
    printf("anio: %d\n",computadora.anio);
    printf("nucleos: %d\n",computadora.cantidad);
    printf("tipo de cpu: %s\n",computadora.tipo_cpu);
}

void vieja(PC *listado,int cantidad)
{
    PC menor;
    for (int i = 0; i < cantidad; i++)
    {
        PC aux = (PC)*(listado+i);
        if(menor.anio>aux.anio)
        {
            menor = aux;
        }
    }
    mostrarPC(menor);
}
void velocidad(PC *listado,int cantidad)
{
    PC veloc;
    for (int i = 0; i < cantidad; i++)
    {
        PC aux = (PC)*(listado+i);
        if(veloc.velocidad<aux.velocidad)
        {
            veloc = aux;
        }
    }
    mostrarPC(veloc);
}