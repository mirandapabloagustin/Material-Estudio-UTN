#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct elemento{
    char categoria[20];
    char nombre[20];
    int puntaje;
}regElemento;

typedef struct {
    char nombre[20];
    int puntaje;
}elemento;


typedef struct {
    elemento e;
    struct nodo *sig;
}nodo;

typedef struct {
    char categoria[20];
    nodo * listaElementos;
}catalogo;



int main(){
    catalogo * arregloCatalogo;
    arregloCatalogo = (catalogo*)malloc(sizeof(catalogo)*cantArchivo());
    int validos;
    return 0;
}

nodo * crearNodo(elemento e){
    nodo * nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->e = e;
    nuevo->sig = NULL;
    return nuevo;
}

elemento crearElemento(char nombre[20], int puntaje){
    elemento nuevo;
    strcpy(nuevo.nombre,nombre);
    nuevo.puntaje = puntaje;
    return nuevo;
}

catalogo crearCatalogo(char categoria[20]){
    catalogo nuevo;
    strcpy(nuevo.categoria,categoria);
    nuevo.listaElementos = NULL;
    return nuevo;
}


int cantArchivo(){
    FILE * archi = fopen("elementos.bin","rb");
    int aux = 0;
    if (archi)
    {
        fseek(archi,0,SEEK_END);
        aux = ftell(archi)/sizeof(regElemento);
        fclose(archi);
    }
    return aux;
}

void insertarFinal(nodo ** lista, elemento e){
    nodo * nuevo = crearNodo(e);
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else{
        nodo * aux = *lista;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }

}

void insertarOrden(nodo ** lista, elemento e){
    nodo * nuevo = crearNodo(e);
    nodo * aux;
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else{
        if ((*lista)->e.puntaje < e.puntaje)
        {
            nuevo->sig = *lista;
            *lista = nuevo;
        }
        else{
            nodo* ant = *lista;
            nodo * act= (*lista)->sig;
            while (act != NULL && act->e.puntaje > e.puntaje);
            {
                ant = act;
                act = act->sig;
            }
            ant->sig = nuevo;
            nuevo->sig = act;
        }
        
    }
}

int insertarOrdArreglo(catalogo * arregloCatalogo, catalogo catalogoDato, int ultPos){
    int i = ultPos;
    while (i >= 0 && strcmpi(arregloCatalogo[i].categoria, catalogoDato.categoria)>0)
    {
        arregloCatalogo[i+1] = arregloCatalogo[i];
        i--;
    }
    arregloCatalogo[i+1] = catalogoDato;
    return i+1;
}


int verificar(catalogo * arreglo, char categoria[20], int validos){
    int i = 0;
    int aux = -1;
    while (i < validos)
    {
        if (strcmpi(arreglo[i].categoria,categoria)>0)
        {
            aux = i;
        }
        i++;
    }
    return aux;
}



void leerArchivo(catalogo * arreglo, int * validos){
    FILE * archi = fopen("test.bin","rb");
    regElemento auxReg;
    catalogo auxCat;
    elemento auxEle;
    int i;
    if (archi != NULL)
    {
        while (fread(&auxReg,sizeof(regElemento),1,archi)>0)
        {
            i = verificar(arreglo,auxReg.categoria,*validos);
            auxEle = crearElemento(auxReg.nombre,auxReg.puntaje);
            if (i == -1)
            {
                auxCat = crearCatalogo(auxReg.categoria);
                int pos = insertarOrdArreglo(arreglo,auxCat,*validos-1);
                (*validos)++;
                insertarFinal(arreglo[pos].listaElementos,auxEle);
            }
            else{
            insertarFinal(arreglo[i].listaElementos,auxEle);
            }
        }
        fclose(archi);
    }
    
}