#include "TDAListaDobles.h"
#include "TDAfila.h"
#include <stdio.h>
#include <stdlib.h>


void iniciaNodoDoble(nodoDoble ** lista)
{
    *lista = NULL;
}

nodoDoble * crearNodoDoble(char nombre[],int edad)
{
    nodoDoble * nodoAuxiliar = (nodoDoble*)malloc(sizeof(nodoDoble));
    strcpy(nodoAuxiliar->humano.nombre,nombre);
    nodoAuxiliar->humano.edad = edad;
    nodoAuxiliar->siguiente = NULL;
    nodoAuxiliar->anterior = NULL;

}

void agregarAlPrincipioNodoDoble(nodoDoble ** lista, nodoDoble ** nuevo)
{
    (*nuevo)->siguiente = (*lista);
    if (*lista != NULL)
    {
        (*lista)->anterior = (*nuevo);
    }
    *lista = (*nuevo);
}

nodoDoble * buscarUltimoNodoDoble (nodoDoble ** lista) // ==> RETORNA EL ULTIMO ELEMENTO
{
    nodoDoble * iterator = lista;
    if(lista != NULL)
    {
        while (iterator->siguiente != NULL)
        {
            iterator = iterator->siguiente;
        }
    }
    return iterator;
}

void mostrarListaNodoDoble(nodoDoble * lista)
{
    printf("%s%c%c  LISTA  %c%c%s\n",VERDE,218,180,195,191,NORMAL);
    while(lista != NULL)
    {
        printfDato(lista);
        lista=lista->siguiente;
    }
    printf("%s-----------------%s\n",VERDE,NORMAL);
}

void printfDato(nodoDoble * nodoMostrado)
{
    printf("------------------\n");
    printf("Nombre: %s%s%s\n",APERTURA,nodoMostrado->humano.nombre,CERRADO);
    printf("Edad: %s%d%s\n",APERTURA,nodoMostrado->humano.edad,CERRADO);
}

nodoDoble * agregarAlFinalNodoDoble(nodoDoble * lista, nodoDoble *nuevo) // ==> AGREGA AL FINAL DE LA LISTA
{
    if(lista != NULL)
    {
        nodoDoble * ultimo = buscarUltimoNodoDoble(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }
    else
    {
        lista = nuevo;
    }
    return lista;
}

nodoDoble * borrarNodoDobleBuscado(nodoDoble * lista, int edad)
{
    nodoDoble * nodoAuxiliar = lista;
    nodoDoble * nodoAnterior;
    if(lista != NULL && lista->humano.edad == edad)
    {
        lista = lista->siguiente;
        free(nodoAuxiliar);
    }
    else
    {
        while(nodoAuxiliar != NULL && nodoAuxiliar->humano.edad != edad)
        {
            nodoAnterior = nodoAuxiliar;
            nodoAuxiliar = nodoAuxiliar->siguiente;
        }
        if(nodoAuxiliar->siguiente != NULL)
        {
            nodoAnterior->siguiente = nodoAuxiliar->siguiente;
            (nodoAuxiliar->siguiente)->anterior = nodoAnterior;
        }
        else
        {
            nodoAnterior->siguiente = NULL;
        }
        free(nodoAuxiliar);
    }
    return lista;
}

nodoDoble * buscarNodoDoble(nodoDoble * lista, char nombre[], int edad)
{
    nodoDoble * buscado = lista;
    if(lista->siguiente != NULL)
    {
        while(strcmpi(buscado->humano.nombre,nombre)!=0 || buscado->humano.edad != edad )
        {
            buscado = buscado->siguiente;
        }
        printfDato(buscado);
    }
    return buscado;

}

nodoDoble * agregarNodoDobleOrden(nodoDoble * lista, nodoDoble * nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else if (nuevoNodo->humano.edad < lista->humano.edad)
    {
        agregarAlPrincipioNodoDoble(&lista, &nuevoNodo);
    }
    else
    {

        nodoDoble * anterior = lista;
        nodoDoble * seguidor = lista->siguiente;

        while (seguidor != NULL && seguidor->humano.edad < nuevoNodo->humano.edad)
        {
            anterior = seguidor;
            seguidor = seguidor->siguiente;
        }

        anterior->siguiente = nuevoNodo;
        nuevoNodo->anterior = anterior;
        nuevoNodo->siguiente = seguidor;

        if (seguidor != NULL)
        {
            seguidor->anterior = nuevoNodo;
        }
    }
    return lista;
}


void ordenarListaP(nodoDoble * lista)
{
    nodoDoble *actual = NULL;
    nodoDoble *nodoIterador = NULL;
    nodoDoble * nodoAnterior;
    if (lista != NULL)
    {
        nodoIterador = lista;
        while (nodoIterador != lista->anterior)
        {
            actual = nodoIterador->siguiente;
            while (actual != NULL)
            {
                if (nodoIterador->humano.edad > actual->humano.edad)
                {
                    nodoAnterior = nodoIterador->humano.edad;
                    nodoIterador->humano.edad = actual->humano.edad;
                    actual->humano.edad = nodoAnterior;
                }
                actual = actual->siguiente;
            }
            nodoIterador = nodoIterador->siguiente;
        }
    }
}

nodoDoble * menorBuscado(nodoDoble *lista)
{
    nodoDoble * menor;
    nodoDoble * iterador = lista;
    menor = lista;
    while (iterador != NULL)
    {
        if(menor->humano.edad > iterador->humano.edad)
        {
            menor = iterador;
        }
        iterador = iterador->siguiente;
    }
    return menor;
}


