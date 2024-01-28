#ifndef TDAFILA_H_INCLUDED
#define TDAFILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#define ESTUDIANTE "estudiante.bin"

#define CYAN "\033[0;36m"
#define VERDE "\033[4;32m"
#define NORMAL "\033[0m"
#define APERTURA "\033[0;36m[\033[0m"
#define CERRADO "\033[0;36m]\033[0m"


#endif // TDAFILA_H_INCLUDED






typedef struct
{
    char nombre[30];
    int edad;
}stPersona;


typedef struct nodoDoble
{
    stPersona humano;
    struct nodoDoble * siguiente;
    struct nodoDoble * anterior;

}nodoDoble;

typedef struct
{
    struct stFila * cabeza;
    struct stFila * cola;
}stFila;



nodoDoble * iniciaNodoDoble();
nodoDoble * crearNodoDoble(char nombre[],int edad);
void agregarAlPrincipioNodoDoble(nodoDoble ** lista, nodoDoble ** nuevo);
nodoDoble * buscarUltimoNodoDoble (nodoDoble ** lista);
void printfDato(nodoDoble * nodoMostrado);
void mostrarListaNodoDoble(nodoDoble * lista);
nodoDoble * agregarAlFinalNodoDoble(nodoDoble * lista, nodoDoble *nuevo);
nodoDoble * borrarNodoDobleBuscado(nodoDoble * lista, int edad);
nodoDoble * agregarNodoDobleOrden(nodoDoble * lista, nodoDoble * nodoNuevo);
void ordenarListaP(nodoDoble * lista);
nodoDoble * menorBuscado(nodoDoble *lista);



void inicFila(stFila * fila);
void mostrarFila(stFila * fila);
void agregarFila(stFila * fila, char nombre[] ,int edad);
stPersona verPrimero(nodoDoble * lista);
stPersona extraerDato(stFila * fila);









































