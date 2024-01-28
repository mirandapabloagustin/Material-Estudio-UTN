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



nodoDoble * comprobarCapiguar(nodoDoble * ultimo,nodoDoble * primero);
int contarElemento(nodoDoble * lista);
nodoDoble * buscarElementoPosicion(nodoDoble * lista, int posicion);
nodoDoble * borrarNodoMedioLista(nodoDoble * lista);



int main()
{
    system("cls");
    nodoDoble * lista;
    iniciaNodoDoble(&lista);
    nodoDoble * nuevo = crearNodoDoble("Jorge",34);
    nodoDoble * nuevo1 = crearNodoDoble("Rodrigo",18);
    nodoDoble * nuevo2 = crearNodoDoble("Agustin",27);
    nodoDoble * nuevo3 = crearNodoDoble("Ian",26);

//    agregarAlPrincipioNodoDoble(&lista,&nuevo);
//    agregarAlPrincipioNodoDoble(&lista,&nuevo1);
//    agregarAlPrincipioNodoDoble(&lista,&nuevo2);
//    agregarAlPrincipioNodoDoble(&lista,&nuevo3);

    mostrarListaNodoDoble(lista);
//
//    nodoDoble * menor = menorBuscado(lista);
//
//    stFila fila;
//
//    inicFila(&fila);
//
//    agregarFila(&fila,"Belen",25);
//    agregarFila(&fila,"Jorge",34);
//    agregarFila(&fila,"Agustin",27);
//    agregarFila(&fila,"Rodrigo",18);
//
//    mostrarFila(&fila);
//    stPersona humano = extraerDato(&fila);
//    printf("%s%s%s\n",APERTURA,humano.nombre,CERRADO);
//    printf("%s%d%s\n",APERTURA,humano.edad,CERRADO);
//    mostrarFila(&fila);
//











    return 0;
}

nodoDoble * comprobarCapiguar(nodoDoble * ultimo,nodoDoble * primero)
{
    int flag = 1;
    if(ultimo != NULL && primero != NULL)
    {

        if(primero->humano.edad == ultimo->humano.edad)
        {
            flag = comprobarCapiguar(ultimo->anterior,primero->siguiente);
        }
        else
        {
            flag = 0;
        }
    }
    return flag;
}

int contarElemento(nodoDoble * lista)
{
    int i = 0;
    while (lista != NULL)
    {
        lista = lista->siguiente;
        i++;
    }
    return i;
}

nodoDoble * buscarElementoPosicion(nodoDoble * lista, int posicion)
{
    int iterador = 1;
    if(lista != NULL)
    {
        while(posicion > iterador)
        {
            lista = lista->siguiente;
            iterador++;
        }
    }
    return lista;
}

nodoDoble * borrarNodoMedioLista(nodoDoble * lista)
{
    int mitad = (int)contarElemento(lista)/2;
    mitad++;
    nodoDoble * nodoBuscado = buscarElementoPosicion(lista, mitad);
    lista = borrarNodoDobleBuscado(lista,nodoBuscado->humano.edad);
    return lista;
}



































