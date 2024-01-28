#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "TDAarboles.h"


#define ROJO "\033[0;31m"
#define CYAN "\033[0;36m"
#define VERDE "\033[4;32m"
#define NORMAL "\033[0m"
#define APERTURA "\033[0;36m[\033[0m"
#define CERRADO "\033[0;36m]\033[0m"




stArbol * iniciarArbol()
{
    return NULL;
}

/// FUNCION QUE CREA UN NUEVO NODO TIPO ARBOL
stArbol * crearNodoArbol(int dato)
{
    stArbol * nodoAuxiliar = (stArbol*)malloc(sizeof(stArbol)); /// <--- Asigno Memoria Dinamica

    nodoAuxiliar->dato = dato; /// <---- Le asigno el dato ingresado por parametro al nuevo nodo.
    nodoAuxiliar->ramaDer = NULL; /// <--- Le asigno null para dejarlo preparado para poder enlazar nuevos elementos y no me tome basura.
    nodoAuxiliar->ramaIzq = NULL; /// <--- Lo mismo que el anterior.

    return nodoAuxiliar; /// <--- Retono el puntero del NODO Auxiliar
}


/// FUNCION INSERTA UN DATO EN EL ARBOL
stArbol * insertar (stArbol * arbol, int dato)
{
    if(arbol == NULL) /// <--- COMPROBAS si el arbol esta vacio.
    {
        arbol = crearNodoArbol(dato); /// <--- CREAMOS un nuevo nodo.
    }
    else /// <--- SINO
    {
        if( dato > arbol->dato) /// <--- Si el dato a ingresar es mas grande que el DATO que esta en la posicion actual
        {
            arbol->ramaDer = insertar(arbol->ramaDer, dato); /// <---
        }
        else
        {
            arbol->ramaIzq = insertar(arbol->ramaIzq, dato);
        }
    }
    return arbol;
}


///FUNCION QUE BUSCA UN NODO DENTRO DE UN ARBOL
stArbol * buscarDato(stArbol * arbol, int dato) /// <--- pasamos por parametro los dato buscados;
{
    stArbol * respuesta=NULL; /// <--- crweamos un NODO auxiliar para poder iterar entre los elementos
    if(arbol != NULL) /// <--- Comprobamos si el arbol tiene elementos
    {
        if(dato == arbol->dato) /// <--- si el dato es igual al arbol
        {
            respuesta = arbol; /// <--- DEVOLVEMOS el albol donde se encuentra el arbol
        }
        else /// <--- Sino
        {
            if(dato > arbol->dato) /// <--- Si el DATO es mayor que es DATO que se encuentra en el Arbol actual
            {
                respuesta = buscarDato(arbol->ramaDer,dato); /// <--- BUSCAMOS el DATO en la rama DERECHA
            }
            else
            {
                respuesta = buscarDato(arbol->ramaIzq,dato); /// <--- BUSCAMOS el DATO en la rama IZQUIERDA
            }
        }
    }
    return respuesta; /// <--- RETORNAMOS el puntero del DATO encontrado.
}


///FUNCION MUESTRA EL ARBOL POR EL PRIMERO LA RAMA IZQUIERDA
void preOrder (stArbol * arbol)
{
    if(arbol != NULL)
    {
        printf("DATO: %s%d%s",APERTURA,arbol->dato,CERRADO);
        preorder(arbol->ramaIzq);
        preorder(arbol->ramaDer);
    }
}

/// FUNCION QUE MUESTRA EL ARBOL EN EL ORDEN CORRESPONDIENTE
void inOrder (stArbol * arbol)
{
    if(arbol != NULL)
    {
        inorder(arbol->ramaIzq);
        printf("DATO: %s%d%s",APERTURA,arbol->dato,CERRADO);
        inorder(arbol->ramaDer);
    }
}

/// FUNCION QUE MUESTRA EL ARBOL

void postOrder (stArbol * arbol)
{
    if(arbol != NULL)
    {
        inorder(arbol->ramaIzq);
        inorder(arbol->ramaDer);
        printf("DATO: %s%d%s",APERTURA,arbol->dato,CERRADO);
    }
}


























































