#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

#define CYAN "\033[4;36m"
#define VERDE "\033[4;32m"
#define NORMAL "\033[0m"
#define APERTURA "\033[0;36m[\033[0m"
#define CERRADO "\033[0;36m]\033[0m"

typedef struct
{
    int dato;
    struct stNodo * siguiente;
} stNodo;
stNodo * crearNodo(int dato);
stNodo * inicializador();

stNodo * agregarAlPrincipio(stNodo * lista, stNodo * nodoNuevo);
stNodo agregarAlPrincipio2(stNodo * lista, stNodo * nodoNuevo);
void mostrar(stNodo * lista);
stNodo * agregarAlFinal(stNodo * lista, stNodo *nuevoNodo);
stNodo * buscarUltimo(stNodo * lista);
stNodo * buscarUltimo (stNodo *lista);


int main()
{
    stNodo * lista;
    lista = inicializador();
    stNodo * nuevoDato = crearNodo(4);
    stNodo * nuevoDato2 = crearNodo(5);

    mostrar(lista);
    lista = agregarAlPrincipio(lista,nuevoDato);
    mostrar(lista);
    lista = agregarAlFinal(lista,nuevoDato2);
    mostrar(lista);




}

//{ FUNCION PARA INCIALIZAR NODOS
// Inicializamos como puntero ya que trabajamos desde punteros y lo igualamos a "NULL" para decir que este vacio.
stNodo * inicializador()
{
    return NULL;
}
//}

//{ FUNCION PARA CREAR UN NODO NUEVO

// apuntamos al puntero, solicitamos un tipo de dato para poder almacenarlo.
// 1) Creamos un puntero AUXILIAR de tipo dinamico.
// 2) Luego asiganos el "dato" al DATO AUXILIAR con flechita ya que lo pasamos con puntero.
// 3) Asignamos el "SIGUIENTE" del "DATO AUXILIAR" que esta solamente inicializado, lo apuntamos a "NULL".
// 4) Retornamos el "DATO AUXILIAR" para guardar todo en el "NODO NUEVO".

stNodo * crearNodo(int dato)
{
    stNodo * datoAuxliar = (stNodo*)malloc(sizeof(stNodo)); // 1)
    datoAuxliar->dato = dato; // 2)
    datoAuxliar->siguiente = NULL; // 3)
    return datoAuxliar; // 4)
}
//}

//{ FUNCION AGREGAR AL PRINCIPIO DE LA LISTA
/** MUY IMPORTANTE SABER QUE LA LISTA ES SOLO UN PUNTERO QUE APUNTA A LOS PUNTERO DE LOS NODOS QUE ALMACENAN LOS DATOS **/

//apuntamos por puntero a la "LISTA" y al "NUEVO NODO"
// 1) Comprobamos si la "LISTA" esta vacia (si lo esta igualamos la "LISTA" al "NUEVO NODO")
// 2) Si no esta vacia lo que hacemos es APUNTAR el "NODO NUEVO SIGUIENTE" a la "LISTA" ( osea al dato que esta
// apuntando la "LISTA" ) y luego la "LISTA" la apuntamos al "NUEVO NODO".


stNodo * agregarAlPrincipio(stNodo * lista, stNodo * nodoNuevo)
{
    if (lista == NULL) // 1)
    {
        lista = nodoNuevo; // 1)
    }
    else
    {
        nodoNuevo->siguiente = lista; // 2)
        lista = nodoNuevo; // 2)
    }
    return lista;
}

stNodo agregarAlPrincipio2(stNodo * lista, stNodo * nodoNuevo)
{
    if (lista == NULL) // 1)
    {
        lista = nodoNuevo; // 1)
    }
    else
    {
        nodoNuevo->siguiente = lista; // 2)
        lista = nodoNuevo; // 2)
    }
}
//}

//{ FUNCION BUSCAR EL ULTIMO NODO

// pedimos por parametro la "LISTA" en la cual vamos  a buscar el ultimo elemento.
// 1) Creamos una variable que va a "ITERAR" la lista (osea la igualamos a la misma).
// 2) Creamos un while que mientra "ITERADOR SIGUIENTE" sea diferente que "NULL" osea no alla llegado al final.
// 3) Igualamos al iterador al siguiente de iterador (osea que apunta al siguiente nodo de la "LISTA")
// 4) Retornamos el iterador que va a contener el ultimo de la lista.


stNodo * buscarUltimo (stNodo *lista)
{
    stNodo * iterator = lista; // 1)
    while (iterator->siguiente != NULL) //2)
    {
        iterator = iterator->siguiente; // 3)
    }
    return iterator; // 4)
}
//}

//{ FUNCION AGREGAR AL FINAL DE LA LISTA
// Pasamos por parametro la "LISTA" y el "NUEVO NODO" por patametro
// 1) Preguntamos si la "LISTA" tiene elementos, si es asi creamos una variable temporal
// que busca el puntero del ULTIMO NODO.
// 2) El "ULTIMO" va a apuntar al "NUEVO NODO".
// 3) Si esta vacia le decimos que la "LISTA" va a ser igual al "NUEVO NODO".
// 4) Retornamos la "LISTA" nueva.



stNodo * agregarAlFinal(stNodo * lista, stNodo *nuevoNodo)
{
    if(lista != NULL)
    {
        stNodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    else
    {
        lista = nuevoNodo;
    }
    return lista;
}
//}

//{ FUNCION BORRAR UN NODO BUSCADO
//se igual la funcion a la "LISTA" y se le pasa como parametro la lista y el dato buscado.
// 1) Creamos dos variables auxiliares nombradas "ANTERIOR" Y "AUXILIAR" la auxliar la igualamos a la "LISTA".
// 2) Si el elemeto esta al principio que lo comprobamos en el "IF" apuntamos la lista al siguiente puntero
// y liberamos el auxiliar que contenia guardo el dato buscado.
// 3) Si no encontra el dato al principio los buscamos en la "LISTA" con un "WHILE" el dato buscado,
// apuntando el "AUXILIAR" a su siguiente puntero y el anterior apuntado al dato que guardaba "AUXILIAR"
// hasta que lo entre lo cual va a adejar el "AUXILIAR" apuntando al siguiente dato que buscamos y el
// "ANTERIOR" va a querdar apuntado al dato anterior.
// 4) Si "AUXILIAR" es diferente de NULL va a asignar a "ANTERIOR SIGUIENTE" el puntero del que le sigue
// de "AUXILIAR". Luego lo borra , dejando la lista sin ese elemento.
// 5) Retornamos la lista.


stNodo * borrarNodoBuscado (stNodo * lista, int dato)
{
    stNodo * datoAuxiliar = lista; // 1)
    stNodo * datoAnterior; // 1)

    if((lista != NULL) && lista->dato == dato) // 2)
    {
        lista = lista->siguiente; // 2)
        free(datoAuxiliar); // 2)
    }
    else
    {
        while((datoAuxiliar != NULL) && datoAuxiliar->dato != dato) // 3)
        {
            datoAnterior = datoAuxiliar; // 3)
            datoAuxiliar = datoAuxiliar->siguiente; //3)
        }
        if(datoAuxiliar != NULL) // 4)
        {
            datoAnterior->siguiente = datoAuxiliar->siguiente; // 4)
            free(datoAuxiliar); // 4)
        }
    }
    return lista; // 5)
}
//}


void mostrar(stNodo * lista)
{
    printf(">Tope\n");
    if(lista != NULL)
    {
        printf("%d\n",lista->dato);
        lista=lista->siguiente;
    }
    printf(">Base\n");
}


//
//stNodo * buscarUltimo(stNodo * lista)
//{
//    stNodo * seg = lista;
//    if(seg != NULL)
//        while(seg->siguiente != NULL)
//        {
//            seg = seg->siguiente;
//        }
//    return seg;
//}






















































