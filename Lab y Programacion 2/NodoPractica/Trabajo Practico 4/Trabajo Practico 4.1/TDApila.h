#ifndef TDAPILA_H_INCLUDED
#define TDAPILA_H_INCLUDED
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CYAN "\033[4;36m"
#define VERDE "\033[4;32m"
#define NORMAL "\033[0m"
#define APERTURA "\033[0;36m[\033[0m"
#define CERRADO "\033[0;36m]\033[0m"
#endif // TDAPILA_H_INCLUDED


typedef struct stPila
{
    int dato;
    struct stPila * siguiente;
}stPila;


void iniciaPila(stPila ** pila);
void apilarPila(stPila ** pila, int dato);
stPila * crearPila(int dato);
void borrarPrimerNodo(stPila ** pila);
int desapilarPila(stPila ** pila);
int tope(stPila ** pila);
int pilaVacia(stPila ** pila);
void leerDato(stPila ** pila);





























