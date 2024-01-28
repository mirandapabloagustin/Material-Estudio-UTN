#include "TDApila.h"


// incia pila

void iniciaPila(stPila ** pila)
{
    *pila = NULL;

}

// agrega un elemento

stPila * crearPila(int dato)
{
    stPila * nodoAuxiliar =(stPila*)malloc(sizeof(stPila));
    nodoAuxiliar->dato = dato;
    nodoAuxiliar->siguiente = NULL;
    return nodoAuxiliar;
}

// apilar en la pila con doble puntero

void apilarPila(stPila ** pila, int dato)
{
    stPila * nodoAuxiliar = crearPila(dato);
    if(*pila == NULL)
    {
        *pila = nodoAuxiliar;
    }
    else
    {
        nodoAuxiliar->siguiente = *pila;
        *pila = nodoAuxiliar;
    }
}

// borra el tope de la pila y devuelve el dato

int desapilarPila(stPila ** pila)
{
    int datoAuxiliar = (*pila)->dato;
    stPila * eliminar = *pila;
    if((*pila)->siguiente == NULL)
    {
        iniciaPila(&(*pila));
    }else
    {
        *pila = (*pila)->siguiente;
        free(eliminar);
    }
    return datoAuxiliar;
}

// borra el primer nodo

void borrarPrimerNodo(stPila ** pila)
{
    if(*pila != NULL)
    {
        stPila * nodoAuxiliar = *pila;
        *pila = (*pila)->siguiente;
        free(nodoAuxiliar);
    }
}

// muestra el tope de la pila

int tope(stPila ** pila)
{
    int datoAuxiliar;
    if(*pila != NULL)
    {
        datoAuxiliar = (*pila)->dato;
    }
    return datoAuxiliar;
}

// retorna 1 si la pila esta vacia

int pilaVacia(stPila ** pila)
{
    int flag = 1;
    if(*pila != NULL)
    {
        flag = 0;
    }
    return flag;
}

// lee un dato y lo guarda en una pila

void leerDato(stPila ** pila)
{
    int dato;
    printf("Ingrese un Dato: ");
    fflush(stdin);
    scanf("%d",&dato);
    apilarPila(&(*pila),dato);
}

// muestra la pila

void mostrarPila(stPila * pila)
{
    printf("%s%c%c  TOPE  %c%c%s\n",VERDE,218,180,195,191,NORMAL);
    while(pila != NULL)
    {
        printf("%s %d %s\n",APERTURA,pila->dato,CERRADO);
        pila = pila->siguiente;
    }
    printf("%s--  BASE  --%s\n\n",VERDE,NORMAL);
}


































