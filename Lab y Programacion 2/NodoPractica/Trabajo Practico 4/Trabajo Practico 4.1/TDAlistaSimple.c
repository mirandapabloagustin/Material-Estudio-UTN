#include "TDAlistaSimple.h"


nodoSimple * inicNodoSimple()
{
    return NULL;
}


nodoSimple * crearNodoInt(int dato)
{
    nodoSimple * nodoAuxiliar = (nodoSimple*)malloc(sizeof(nodoSimple));
    nodoAuxiliar->dato = dato;
    nodoAuxiliar->siguiente = NULL;
    return nodoAuxiliar;
}


nodoSimple * cargarAlPrincipioNodoSimple(nodoSimple * lista, nodoSimple * nuevo) // ==> AGREGA AL PRINCIPIO DE LA LISTA
{
    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}


nodoSimple * buscarUltimoNodoSimple (nodoSimple * lista) // ==> RETORNA EL ULTIMO ELEMENTO
{
    nodoSimple * iterator = lista;
    if(lista != NULL)
    {
        while (iterator->siguiente != NULL)
        {
            iterator = iterator->siguiente;
        }
    }
    return iterator;
}

nodoSimple * agregarAlFinalNodoSimple(nodoSimple * lista, nodoSimple *nuevo) // ==> AGREGA AL FINAL DE LA LISTA
{
    if(lista != NULL)
    {
        nodoSimple * ultimo = buscarUltimoNodoSimple(lista);
        ultimo->siguiente = nuevo;
    }
    else
    {
        lista = nuevo;
    }
    return lista;
}


nodoSimple * borrarNodoSimpleBuscado (nodoSimple * lista, int dato)
{
    nodoSimple * nodoAuxiliar = lista; // 1)
    nodoSimple * datoAnterior; // 1)

    if((lista != NULL) && lista->dato == dato) // 2)
    {
        lista = lista->siguiente; // 2)
        free(nodoAuxiliar); // 2)
    }
    else
    {
        while((nodoAuxiliar != NULL) && (nodoAuxiliar->dato == dato)) // 3)
        {
            datoAnterior = nodoAuxiliar; // 3)
            nodoAuxiliar = nodoAuxiliar->siguiente; //3)
        }
        if(nodoAuxiliar != NULL) // 4)
        {
            datoAnterior->siguiente = nodoAuxiliar->siguiente; // 4)
            free(nodoAuxiliar); // 4)
        }
    }
    return lista; // 5)
}


void mostrarNodoSimple(nodoSimple * nodoMostrado)
{
    printf("%s%d%s\n",APERTURA,nodoMostrado->dato,CERRADO);
}


void mostrarListaNodoSimple(nodoSimple * lista)
{
    printf("%s%c%c  LISTA  %c%c%s\n",VERDE,218,180,195,191,NORMAL);
    while(lista != NULL)
    {
        mostrarNodoSimple(lista);
        lista=lista->siguiente;
    }
    printf("%s-----------------%s\n",VERDE,NORMAL);
}


nodoSimple * menorBuscado(nodoSimple *lista)
{
    nodoSimple * menor;
    nodoSimple * iterador = lista;
    menor = lista;
    while (iterador != NULL)
    {
        if(menor->dato > iterador->dato)
        {
            menor = iterador;
        }
        iterador = iterador->siguiente;
    }
    return menor;
}


















