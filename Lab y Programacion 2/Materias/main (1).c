#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registroArchivo{ 
    int nota; 
    int legajo;
    char nombreApe[40]; 
    char nomMateria[40]; 
    int idMateria;
}registroArchivo;

typedef struct notaAlumno{ 
    int nota; 
    int legajo;
    char nombreApe[40];
}notaAlumno;

typedef struct nodo{ 
    notaAlumno dato; 
   struct nodo *sig; 
} nodo;

typedef struct Materia{ 
    int idMateria;
    char nomMateria[40]; 
    nodo * listaDeNotas; 
}Materia; 

nodo * crearNodo(notaAlumno dato);
Materia crearMateria(int idMateria, char * nomMateria);
int cantArchivo();
int busquedaMateria(Materia * materias,int idMateria, int validos);
void insertarFinal(nodo ** lista, notaAlumno n);
notaAlumno crearNota(int legajo, char * nombreApe, int nota);
void cargaArreglo(Materia * materias, int * validos);
void eliminarNotasAlumnoLista(nodo ** lista, int legajo);
void eliminarNotasAlumno(Materia * materias, int idMateria, int legajo, int validos);
int mayorAseis(Materia * materias, int validos);
void mostrarUnaMateria(Materia materia);
void imprimirArregloNotas(Materia * materias, int validos);
void mostrarUnAlumno(notaAlumno dato);
void mostrarLista(nodo * lista);
void mostrarSublista(Materia * materias, int validos, int idMateria);
void materiasLegajo(Materia * materias, int legajo, int validos);
void pasarAarchivo(Materia * materias, int validos);
void crearArchivo(nodo *lista,char materia[],int id);
registroArchivo crearRegistro(notaAlumno a,char materia[],int id);
void verArchivo();
void pasarAArchivoMayoresSeis(Materia arreglo[],int validos);
void mostrarRegistro(registroArchivo aux);


int main(){
    Materia * materias;
    materias = (Materia*)malloc(sizeof(Materia)*cantArchivo());
    int validos = 0;
    cargaArreglo(materias,&validos);
    imprimirArregloNotas(materias,validos);
    for (int i = 0; i < validos; i++)
    {
        mostrarSublista(materias,validos,i);
    }
    
    
    //int x = mayorAseis(materias,validos);
    printf("=========");
    //printf("\n%d son los mayores a 6\n",x);
    printf("=========\n");

    materiasLegajo(materias,7519,validos);
    //pasarAarchivo(materias,validos);
    return 0;
}
// Utilizando la información en el archivo, realice las siguientes funciones:

//Para la inserción se debe tener en cuenta:
//La lista de notas debe estar ordenada por legajo ascendente.
//El arreglo de materias debe estar ordenado por idMateria ascendente.

nodo * crearNodo(notaAlumno dato){
    nodo * nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}

Materia crearMateria(int idMateria, char * nomMateria){
    Materia aux;
    aux.idMateria=idMateria;
    strcpy(aux.nomMateria,nomMateria);
    aux.listaDeNotas = NULL;
    return aux;
}


int cantArchivo(){
    int cant = 0;
    FILE * archi = fopen("notas.dat","rb");
    if (archi != NULL)
    {
        fseek(archi,0,SEEK_END);
        cant = ftell(archi)/sizeof(registroArchivo);
        fclose(archi);
    }
    return cant;
}

int busquedaMateria(Materia * materias,int idMateria, int validos){
    
    int i = 0;
    while (i < validos && materias[i].idMateria < idMateria)
    {
        i++;
    }
    return i;
    
    
}

int verificacion(Materia * materias, int idMateria, int validos){
    int i = 0;
    int rta = -1;
    while (i < validos)
    {
        if (materias[i].idMateria == idMateria)
        {
            rta = i;
        }
        i++;
    }
    return rta;
}

void insertarFinal(nodo ** lista, notaAlumno n){
    nodo * nuevo = crearNodo(n);
    nodo * aux;
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else{
        aux = *lista;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    
}


int insertarArregloOrd(Materia * arreglo, Materia materia, int ultPos){
    int i = ultPos;
    while (i >= 0 && arreglo[i].idMateria > materia.idMateria)
    {
        arreglo[i+1] = arreglo[i];
        i--;
    }
    arreglo[i+1] = materia;
    return i+1; // Este retorno sirve para tener el subindice donde voy a insertar mi primer nodo en la lista.
}
notaAlumno crearNota(int legajo, char * nombreApe, int nota){
    notaAlumno nuevo;
    nuevo.legajo = legajo;
    strcpy(nuevo.nombreApe,nombreApe);
    nuevo.nota = nota;
    return nuevo;
}

void cargaArreglo(Materia * materias, int * validos){
    registroArchivo aux;
    notaAlumno n;
    Materia auxmateria;
    int i;
    FILE * archi = fopen("notas.dat","rb");
    if (archi != NULL)
    {
        while (fread(&aux,sizeof(registroArchivo),1,archi)>0)
        {
            i = verificacion(materias,aux.idMateria,*validos);
            n = crearNota(aux.legajo,aux.nombreApe,aux.nota);
            if (i == -1)
            {
                auxmateria = crearMateria(aux.idMateria,aux.nomMateria);
                int pos = insertarArregloOrd(materias,auxmateria,*validos-1);
                (*validos)++;
                insertarFinal(&(materias[pos].listaDeNotas),n);
            }
            else{
                insertarFinal(&(materias[i].listaDeNotas),n);
            }
            
        }
        fclose(archi);
    }
}



void imprimirArregloNotas(Materia * materias, int validos){
    for (int i = 0; i < validos; i++)
    {
        mostrarUnaMateria(materias[i]);
    }
    
}

void mostrarUnaMateria(Materia materia){
    printf("ID Materia: %d\n",materia.idMateria);
    printf("Nombre materia: %s\n",materia.nomMateria);
    printf("-----\n");
}

void mostrarSublista(Materia * materias, int validos, int idMateria){
    int i = 0;
    int flag = 0;
    while (i<validos && flag == 0)
    {
        if (materias[i].idMateria == idMateria)
        {
            mostrarLista(materias[i].listaDeNotas);
            flag = 1;
        }
        i++;
    }
    
}


void mostrarLista(nodo * lista){
    while (lista != NULL)
    {
        mostrarUnAlumno(lista->dato);
        lista = lista->sig;
    }
}

void mostrarUnAlumno(notaAlumno dato){
    printf("=========\n");
    printf("Nombre y apellido: %s\n",dato.nombreApe);
    printf("Nota %d\n",dato.nota);
    printf("Legajo %d\n",dato.legajo);
    
}
/*
unaMateria=crearMateria(unRegistro); //cargo la materia
pos=insertarOrdenadoIdMateria(arregloMateria,(*validos)-1, unaMateria)
(*validos)++; //aumento validos del arreglo de alumnos, es decir, aviso que tengo una nueva materia cargada en el arreglo, una mas
notaAlumno unaNota=crearNota(unRegistro); //creo una nota de alumno
insertarOrdenadoLista(&(arregloMateria[pos].listaDeNotas),unaNota); //inserto al final de la lista la nota del alumno
*/

void eliminarNotasAlumnoLista(nodo ** lista, int legajo){
    nodo * aux;
    nodo * act;
    nodo * ant;
    if (*lista != NULL)
    {
        while (*lista && (*lista)->dato.legajo == legajo)
        {
            aux = *lista;
            *lista = (*lista)->sig;
            free(aux);
        }
        ant = *lista;
        act = (*lista)->sig;
        while (act != NULL && (*lista)->dato.legajo != legajo)
        {
            ant = act;
            act = act->sig; 
        }
        if (act)
        {
            aux = act;
            ant->sig = act->sig;
            act = act->sig;
            free(aux);
        }
        
    }
    
}


nodo * borrarNodoBuscado(int dato, nodo * lista)
{
    nodo * seg;
    nodo * ante;
    if((lista != NULL) && (lista->dato.legajo==dato))
    {
        nodo * aux = lista;
        lista = lista->sig;
        free(aux);
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (seg->dato.legajo!=dato))
        {
            ante = seg;
            seg = seg->sig;
        }

        if(seg!=NULL)
        {
            ante->sig = seg->sig;
            free(seg);
        }
    }
    return lista;
}


void eliminarNotasAlumno(Materia * materias, int idMateria, int legajo, int validos){
    int i = 0;
    while (i<validos && materias[i].idMateria != idMateria)
    {
        i++;
    }
    if (i < validos){
        eliminarNotasAlumnoLista(&(materias[i].listaDeNotas),legajo);
    }
}

int mayorAseis(Materia * materias, int validos){
    int cont = 0;
    for (int i = 0; i < validos; i++){
        while (materias[i].listaDeNotas != NULL)
        {
            if (materias[i].listaDeNotas->dato.nota > 6)
            {
                cont++;       
            }
            materias[i].listaDeNotas = materias[i].listaDeNotas->sig;
        }
    }
    return cont;
}


void materiasLegajo(Materia * materias, int legajo, int validos){
    
    for (int i = 0; i < validos; i++)
    {
        while (materias[i].listaDeNotas != NULL)
        {
            if (materias[i].listaDeNotas->dato.legajo == legajo)
            {
                printf("Esta inscripto en la materia: %s\n",materias[i].nomMateria);
            }
            materias[i].listaDeNotas = materias[i].listaDeNotas->sig;
        }
    }    
}

void pasarAArchivoMayoresSeis(Materia arreglo[],int validos){
    for(int i = 0; i < validos; i++){
        crearArchivo(arreglo[i].listaDeNotas,arreglo[i].nomMateria,arreglo[i].idMateria);
    }
}

void crearArchivo(nodo *lista,char materia[],int id){
    FILE *buffer = fopen("peron.dat", "ab");
    registroArchivo aux;
    while(lista != NULL){
        if(lista->dato.nota >= 6){
            aux = crearRegistro(lista->dato,materia,id);
            fwrite(&aux,sizeof(registroArchivo),1,buffer);
            lista = lista->sig;
        }
        lista = lista->sig;
    }
    fclose(buffer);
}

void verArchivo(){
    FILE *buffer = fopen("peron.dat","rb");
    registroArchivo aux;
    while(fread(&aux,sizeof(registroArchivo),1,buffer) > 0){
        mostrarRegistro(aux);
    }
    fclose(buffer);
}
void mostrarRegistro(registroArchivo aux){
    printf("------------------\n");
    printf("- %s -\n",aux.nombreApe);
    printf("legajo : %d \n",aux.legajo);
    printf("nota : %d\n",aux.nota);
    printf("materia : %s\n",aux.nomMateria);
    printf("Id %d\n",aux.idMateria);
    printf("------------------\n");
}

registroArchivo crearRegistro(notaAlumno a,char materia[],int id){
    registroArchivo nuevo;
    nuevo.idMateria = id;
    strcpy(nuevo.nomMateria,materia);
    nuevo.legajo = a.legajo;
    nuevo.nota = a.nota;
    strcpy(nuevo.nombreApe, a.nombreApe);    
    return nuevo; 
}