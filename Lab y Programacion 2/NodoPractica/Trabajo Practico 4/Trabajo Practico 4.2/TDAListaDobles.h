#ifndef TDALISTADOBLES_H_INCLUDED
#define TDALISTADOBLES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include "TDAfila.h"
#define ESTUDIANTE "estudiante.bin"

#define CYAN "\033[0;36m"
#define VERDE "\033[4;32m"
#define NORMAL "\033[0m"
#define APERTURA "\033[0;36m[\033[0m"
#define CERRADO "\033[0;36m]\033[0m"

#endif // TDALISTADOBLES_H_INCLUDED

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


void iniciaNodoDoble(nodoDoble ** lista);
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
































