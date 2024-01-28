#ifndef TDALISTASIMPLE_H_INCLUDED
#define TDALISTASIMPLE_H_INCLUDED
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


#endif // TDALISTASIMPLE_H_INCLUDED


typedef struct nodoSimple
{
    int dato;
    struct nodoSimple * siguiente;
}nodoSimple;




nodoSimple * inicNodoSimple();

nodoSimple * crearNodoInt(int dato);

nodoSimple * cargarAlPrincipioNodoSimple(nodoSimple * lista, nodoSimple * nuevo); // ==> AGREGA AL PRINCIPIO DE LA LISTA

nodoSimple * buscarUltimoNodoSimple (nodoSimple * lista); // ==> RETORNA EL ULTIMO ELEMENTO

nodoSimple * agregarAlFinalNodoSimple(nodoSimple * lista, nodoSimple *nuevo); // ==> AGREGA AL FINAL DE LA LISTA

nodoSimple * borrarNodoSimpleBuscado (nodoSimple * lista, int dato);

void mostrarNodoSimple(nodoSimple * nodoMostrado);

void mostrarListaNodoSimple(nodoSimple * lista);

nodoSimple * menorBuscado(nodoSimple *lista);



