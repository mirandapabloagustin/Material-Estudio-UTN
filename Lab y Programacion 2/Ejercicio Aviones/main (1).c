#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// NAZARENO RODRIGUEZ COM 105
typedef struct {
    char dni[9];
    char nombre[30];
    float pesoEquipaje;
    int edad;
    int idAvion;
    int idPasaje;
} registroPasajero;

typedef struct {
    char nombre[30];
    char dni[9];
    int edad;
} Persona;


typedef struct nodoPasajero {
    Persona p;
    int idPasaje;
    float pesoEquipaje;
    struct nodoPasajero* sig;
} nodoPasajero;

typedef struct nodoAvion {
    int idAvion;
    nodoPasajero* pasajeros;
    struct nodoAvion* sig;
} nodoAvion;


nodoPasajero * crearNodoPasajero(Persona dato, int idPasaje, float pesoEquipaje);
nodoAvion * crearNodoAvion(int idAvion);
void insertarOrdPasajeros(nodoPasajero ** lista, Persona dato, int idPasaje, float pesoEquipaje);
nodoAvion * insertarFinalAviones(nodoAvion ** lista, int idAvion);
nodoAvion * verificarAvion(nodoAvion * lista, int idAvion);
void leerArchivo(nodoAvion ** lista);
int idMasPasajeros(nodoAvion * lista);
int cantPasajeros(nodoPasajero* listaP);
float pesoTotal(nodoAvion * lista, int ID);
float contarPeso(nodoPasajero * lista);
void eliminarPasajeros(nodoPasajero ** lista);
void eliminarAvion(nodoAvion ** lista,  int idAvion);
void crearArchivo(nodoAvion * avion, char * id);
void mostrarPasajeros(nodoPasajero * pasajeros);
void mostrarAviones(nodoAvion * lista);
nodoAvion *insertarAlFinal(nodoAvion **lista, int idAvion);
void leerArchivoDos(nodoAvion **avion);

int main() {
    nodoAvion * lista = NULL;

    leerArchivo(&lista);

    mostrarAviones(lista);

    crearArchivo(lista,"3");
}

// Hacer una función main () que invoque a sus incisos y demuestre el correcto funcionamiento del programa.


nodoPasajero * crearNodoPasajero(Persona dato, int idPasaje, float pesoEquipaje) {
    nodoPasajero * nuevo = (nodoPasajero*)malloc(sizeof(nodoPasajero));
    nuevo->p = dato;
    nuevo->idPasaje = idPasaje;
    nuevo->pesoEquipaje = pesoEquipaje;
    nuevo->sig = NULL;
    return nuevo;
}


nodoAvion * crearNodoAvion(int idAvion) {
    nodoAvion * nuevo = (nodoAvion*)malloc(sizeof(nodoAvion));
    nuevo->idAvion = idAvion;
    nuevo->pasajeros = NULL;
    nuevo->sig = NULL;
    return nuevo;
}

void insertarOrdPasajeros(nodoPasajero ** lista, Persona dato, int idPasaje, float pesoEquipaje) {
    nodoPasajero * nuevo = crearNodoPasajero(dato,idPasaje,pesoEquipaje);
    nodoPasajero * ant;
    nodoPasajero * act;
    if (*lista == NULL) {
        *lista = nuevo;
    } else {
        if (strcmpi((*lista)->p.dni,dato.dni)>0) {
            nuevo->sig = *lista;
            *lista = nuevo;
        } else {
            ant = *lista;
            act = (*lista)->sig;
            while (act != NULL && strcmpi(act->p.dni,dato.dni)<0) {
                ant = act;
                act = act->sig;
            }
            ant->sig = nuevo;
            nuevo->sig = act;
        }
    }
}

nodoAvion *insertarAlFinal(nodoAvion **lista, int idAvion) {
    nodoAvion *nuevo = crearNodoAvion(idAvion);
    if (*lista == NULL) {
        *lista = nuevo;
    } else {
        nodoAvion *act = (*lista);
        nodoAvion *ant;
        while (act->sig != NULL) {
            ant = act;
            act = act->sig;
        }
        act->sig = nuevo;
    }
    return nuevo; //* este retorno es para tener la referencia de ese nodo
}

nodoAvion * verificarAvion(nodoAvion * lista, int idAvion) {
    while (lista != NULL) {
        if (lista->idAvion == idAvion) {
            return lista;
        }
        lista = lista->sig;
    }
    return NULL;
}

void leerArchivo(nodoAvion ** lista) {
    FILE * archi = fopen("pasajerosAviones.bin","rb");
    registroPasajero registro;
    Persona persona;
    nodoAvion * validar;
    if (archi != NULL) {
        while (fread(&registro, sizeof(registroPasajero), 1, archi) >0 ) {
            persona.edad = registro.edad;
            strcpy(persona.dni, registro.dni);
            strcpy(persona.nombre, registro.nombre);

            validar = verificarAvion(*lista,registro.idAvion);
            if (validar == NULL) {
                validar = insertarAlFinal(lista,registro.idAvion);
            }
            insertarOrdPasajeros(&validar->pasajeros,persona,registro.idPasaje,registro.pesoEquipaje);
        }
        fclose(archi);
    } else {
    }
}

int idMasPasajeros(nodoAvion * lista) {

    int cant = cantPasajeros(lista->pasajeros);
    int aux = lista->idAvion;

    int i = 0;

    if (lista == NULL) {
        return aux;
    }
    while (lista != NULL) {
        i = cantPasajeros(lista->pasajeros);
        if (cant <i) {
            cant = i;
            aux = lista->idAvion;
        }
        lista = lista->sig;
    }
    return aux;
}

int cantPasajeros(nodoPasajero* listaP) {
    int cont;
    while (listaP != NULL) {
        cont++;
        listaP = listaP->sig;
    }
    return cont;
}

float pesoTotal(nodoAvion * lista, int ID) {
    float aux;
    while (lista != NULL && lista->idAvion != ID) {
        lista = lista->sig;
    }
    if (lista != NULL) {
        aux = contarPeso(lista->pasajeros);
        return aux;
    } else {
        return 0;
    }
}

float contarPeso(nodoPasajero * lista) {
    float aux;

    while (lista != NULL) {
        aux = aux+ lista->pesoEquipaje;
        lista = lista->sig;
    }
    return aux;
}

void eliminarPasajeros(nodoPasajero ** lista) {
    nodoPasajero * ant;
    nodoPasajero * aux;
    nodoPasajero * act;
    if (*lista != NULL) {
        if (*lista != NULL && (*lista)->p.edad < 50) {
            aux = *lista;
            *lista = (*lista)->sig;
            free(aux);
        } else {
            ant = *lista;
            act = (*lista)->sig;
            while (act != NULL) {
                if (act->p.edad > 50) {
                    ant->sig = act->sig;
                    free(aux);
                    act = ant->sig;
                } else {
                    ant = act;
                    act = act->sig;
                }
            }

        }
    }

}

void eliminarAvion(nodoAvion ** lista,  int idAvion) {
    nodoAvion * aux;
    nodoAvion * elim;
    aux = *lista;
    while (*lista != NULL) {

        if (idAvion != aux->idAvion) {
            aux = aux->sig;
        }
        if (aux != NULL) {
            eliminarPasajeros(&(*lista)->pasajeros);
        }
        if ((*lista)->pasajeros == NULL) {
            elim = *lista;
            *lista = (*lista)->sig;
            free(elim);
        }
    }

}


void leerArchivoDos(nodoAvion **avion) {

    FILE *buff = fopen("pasajerosAviones.bin", "rb");
    registroPasajero registro;
    Persona persona = {0};

    nodoAvion *validar;

    nodoAvion *nuevo = NULL;

    if (buff) {
        while (fread(&registro, sizeof(registroPasajero), 1, buff) > 0) {
            persona.edad = registro.edad;
            strcpy(persona.nombre, registro.nombre);
            strcpy(persona.dni, registro.dni);
            //* Pasar los datos a la estructura

            //* verificar si existe el id de la lista principal
            validar = verificarAvion(*avion, registro.idAvion);

            //* si no existe, debemos crear un nuevo nodo, sino usar el que existe
            if (validar == NULL) { //* si no existe

                validar = insertarAlFinal(avion, registro.idAvion);
            }
            //* luego insertar los nodos de la sublissta
            insertarOrdPasajeros(&validar->pasajeros, persona, registro.idPasaje, registro.pesoEquipaje);
        }
        fclose(buff);
    }
}

void crearArchivo(nodoAvion * avion, char * id) {
    FILE * archi;
    Persona persona;
    char text[30] = "idAvion";
    strcat(text,id);
    strcat(text,".dat");
    int aux = atoi(id);
    archi = fopen(text,"wb");
}

void mostrarPasajeros(nodoPasajero * pasajeros) {
    while (pasajeros) {
        printf("  ID del pasaje     : %d\n", pasajeros->idPasaje);
        printf(" Peso  : %.2f\n\n", pasajeros->pesoEquipaje);
        printf(" Nombre        : %s\n", pasajeros->p.nombre);
        printf(" DNI: %s\n", pasajeros->p.dni);
        printf(" EDAD: %d\n\n", pasajeros->p.edad);
        pasajeros = pasajeros->sig;
    }
}

void mostrarAviones(nodoAvion * lista) {
    while (lista) {
        printf(" Avion ID : %d \n\n", lista->idAvion);
        mostrarPasajeros(lista->pasajeros);
        lista = lista->sig;
    }
}















