#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include "TDApila.h"
#include "TDAlistaSimple.h"

#define ESTUDIANTE "estudiante.bin"

#define CYAN "\033[0;36m"
#define VERDE "\033[4;32m"
#define NORMAL "\033[0m"
#define APERTURA "\033[0;36m[\033[0m"
#define CERRADO "\033[0;36m]\033[0m"

typedef struct stUsuario
{
    char nombre[30];
    char apellido[30];
    int login;
} stUsuario;

typedef struct stEstudiante
{
    char nombre[30];
    int edad;
    float promedio;

} stEstudiante;

typedef struct nodo
{
    int contador;
    stEstudiante alumno;
    struct nodo * siguiente;

} nodo;

/** PROTOTIPADO **/
//{ FUNCIONES ARCHIVO
void cargarArchivo(char nombreArchivo[]);
void cargarEstudiante(stEstudiante * alumno,char nombre[],int edad,float promedio);
void mostrarArchivo(char nombreArchivo[] );
void mostrarEstudiante(stEstudiante alumno);
void cargarArchivoAutmatico(char nombreArchivo[]);
void cargarUsuario(stUsuario * user,char * nombre[],char * apellido,int login);
void cargarEst(char nombreA[], char nombre[],char apellido[],int login);
//}


//{ FUNCIONES NODOS
nodo * inicializa();
nodo * cargarAlPrincipio(nodo * lista, nodo * nuevo);
nodo * crearNodo(char nombre[], int edad, float promedio, int contador);
nodo * cargarAlPrincipio(nodo * lista, nodo * nuevo); // ==> AGREGA AL PRINCIPIO DE LA LISTA
nodo * buscarUltimo (nodo * lista); // ==> RETORNA EL ULTIMO ELEMENTO
nodo * agregarAlFinal(nodo * lista, nodo *nuevo); // ==> AGREGA AL FINAL DE LA LISTA
void mostrarLista(nodo * lista);
void mostrarNodo(nodo * nodoMostrado);
//}


nodo * agregarListaDesdeArchivo(char nombreArchivo[],nodo * lista);
void ejercicio1();
nodo * ingresarListaElementosOrdenadosDesdeArchivo(char nombreArchivo[],nodo * lista);
nodo * agregarEnOrden(nodo * lista, nodo * elemento);
void ejercicio2();
int buscarElemento(nodo * lista,char nombreBuscado[]);
void ejercicio3();
nodo * ordenamientoLista(nodo * lista1,nodo * lista2, nodo * listaFinal);
void ejercicio4();
void ejercicio5();
nodo * invertirLista ( nodo * lista);
void ejercicio6();
nodoSimple * pasarParesLista( stPila * pila, nodoSimple * lista);
void ejercicio7();



int main()
{
    system("cls");
    ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio4();
    ejercicio5();
    ejercicio6();
    ejercicio7();

//    nodoSimple * lista;
//    lista = inicNodoSimple();
//
//    lista = cargarAlPrincipioNodoSimple(lista,crearNodoInt(30));
//    lista = cargarAlPrincipioNodoSimple(lista,crearNodoInt(7));
//    lista = cargarAlPrincipioNodoSimple(lista,crearNodoInt(2));
//    lista = cargarAlPrincipioNodoSimple(lista,crearNodoInt(20));
//    lista = cargarAlPrincipioNodoSimple(lista,crearNodoInt(44));
//
//    mostrarListaNodoSimple(lista);

//    mostrarNodoSimple(menor);









}

//{ FUNCIONES NODO
nodo * inicializa()
{
    return NULL;
}

nodo * crearNodo(char nombre[], int edad, float promedio, int contador)
{
    nodo * nodoAuxiliar = (nodo*)malloc(sizeof(nodo));
    strcpy(nodoAuxiliar->alumno.nombre,nombre);
    nodoAuxiliar->alumno.edad = edad;
    nodoAuxiliar->alumno.promedio = promedio;
    nodoAuxiliar->contador = contador;
    nodoAuxiliar->siguiente = NULL;
    return nodoAuxiliar;
}

nodo * cargarAlPrincipio(nodo * lista, nodo * nuevo) // ==> AGREGA AL PRINCIPIO DE LA LISTA
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

nodo * buscarUltimo (nodo * lista) // ==> RETORNA EL ULTIMO ELEMENTO
{
    nodo * iterator = lista;
    while (iterator->siguiente != NULL)
    {
        iterator = iterator->siguiente;
    }
    return iterator;
}

nodo * agregarAlFinal(nodo * lista, nodo *nuevo) // ==> AGREGA AL FINAL DE LA LISTA
{
    if(lista != NULL)
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }
    else
    {
        lista = nuevo;
    }
    return lista;
}

nodo * borrarNodoBuscado (nodo * lista, char nombre[])
{
    nodo * nodoAuxiliar = lista; // 1)
    nodo * datoAnterior; // 1)

    if((lista != NULL) && (strcmpi(lista->alumno.nombre,nombre) == 0)) // 2)
    {
        lista = lista->siguiente; // 2)
        free(nodoAuxiliar); // 2)
    }
    else
    {
        while((nodoAuxiliar != NULL) && (strcmpi(nodoAuxiliar->alumno.nombre,nombre) == 0)) // 3)
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

void mostrarNodo(nodo * nodoMostrado)
{
    puts("-------------------------");
    printf("Nombre: %s\n",nodoMostrado->alumno.nombre);
    printf("Edad: %d\n",nodoMostrado->alumno.edad);
    printf("Promedio: %.2f\n",nodoMostrado->alumno.promedio);
    printf("Numero Estudiante: %d\n",nodoMostrado->contador);
}

void mostrarLista(nodo * lista)
{
    printf("%s-- Datos Lista --%s\n",VERDE,NORMAL);
    while(lista != NULL)
    {
        mostrarNodo(lista);
        lista=lista->siguiente;
    }
    printf("%s-----------------%s\n",VERDE,NORMAL);
}

//}


//{ FUNCIONES ARCHIVO

void mostrarEstudiante(stEstudiante alumno)
{
    puts("===============================");
    printf("Nombre: %s %s %s\n",APERTURA,alumno.nombre,CERRADO);
    printf("Edad: %s %d %s\n",APERTURA,alumno.edad,CERRADO);
    printf("Promedio: %s %.2f %s \n",APERTURA,alumno.promedio,CERRADO);
}

void mostrarArchivo(char nombreArchivo[] )
{
    stEstudiante alumno;
    FILE * archivo = fopen(nombreArchivo,"rb");
    if(archivo)
    {
        printf("%sElementos ARCHIVO:%s\n",CYAN,NORMAL);
        while(fread(&alumno,sizeof(alumno),1,archivo)>0)
        {
            mostrarEstudiante(alumno);
        }
        fclose(archivo);
    }
    else
    {
        printf("\nArchivo no existe.");
    }
}

void cargarEstudiante(stEstudiante * alumno,char nombre[],int edad,float promedio)
{
    strcpy(alumno->nombre,nombre);
    alumno->edad = edad;
    alumno->promedio = promedio;
}

void cargarArchivo(char nombreArchivo[])
{
    stEstudiante alumno;
    FILE * archivo = fopen(nombreArchivo,"w+b");
    if(archivo)
    {
        char opcion;
        do
        {
            char nombre[30];
            int edad = 0;
            float promedio = 0;
            printf("Ingresar Datos:");
            printf("\nNombre: ");
            fflush(stdin);
            scanf("%s",&nombre);

            printf("Edad: ");
            fflush(stdin);
            scanf("%d",&edad);

            printf("Promedio: ");
            fflush(stdin);
            scanf("%f",&promedio);

            cargarEstudiante(&alumno,nombre,edad,promedio);

            fwrite(&alumno,sizeof(alumno),1,archivo);

            printf("\nDesea seguir (s/n): ");
            fflush(stdin);
            scanf("%s",&opcion);

        }
        while(opcion == 's');
        fclose(archivo);
    }
}

void cargarArchivoAutmatico(char nombreArchivo[])
{
    stEstudiante alumno;
    FILE * archivo = fopen(nombreArchivo,"w+b");
    if(archivo)
    {
        cargarEstudiante(&alumno,"Jorge",34,7.00);
        fwrite(&alumno,sizeof(alumno),1,archivo);
        cargarEstudiante(&alumno,"Agustin",27,8.00);
        fwrite(&alumno,sizeof(alumno),1,archivo);
        cargarEstudiante(&alumno,"Belen",25,8.00);
        fwrite(&alumno,sizeof(alumno),1,archivo);
        cargarEstudiante(&alumno,"Juan",31,9.00);
        fwrite(&alumno,sizeof(alumno),1,archivo);
        cargarEstudiante(&alumno,"German",22,9.00);
        fwrite(&alumno,sizeof(alumno),1,archivo);
        fclose(archivo);
    }
}

void cargarEst(char nombreA[], char nombre[],char apellido[],int login)
{
    stUsuario user;
    FILE * archivo = fopen(nombreA,"a+b");
    if(archivo)
    {
        cargarUsuario(&user,nombre,apellido,login);
        fwrite(&user,sizeof(user),1,archivo);
        fclose(archivo);
    }
}

void cargarUsuario(stUsuario * user,char * nombre[],char * apellido,int login)
{
    strcpy(user->nombre,nombre);
    strcpy(user->apellido,apellido);
    user->login = login;
}


//}



//{ FUNCIONES EJERCICIOS

//{ EJERCICIO 1
void ejercicio1()
{
    nodo * listaElementos = inicializa();
    cargarArchivoAutmatico(ESTUDIANTE);
    listaElementos = agregarListaDesdeArchivo(ESTUDIANTE,listaElementos);
    mostrarLista(listaElementos);
}

nodo * agregarListaDesdeArchivo(char nombreArchivo[],nodo * lista)
{
    stEstudiante alumno;
    FILE*archivo = fopen(nombreArchivo,"r+b");
    if(archivo)
    {
        int i = 0;
        while(fread(&alumno,sizeof(stEstudiante),1,archivo)>0)
        {
            nodo * nuevo = crearNodo(alumno.nombre,alumno.edad,alumno.promedio,i);
            lista = cargarAlPrincipio(lista, nuevo);
            i++;
        }
        fclose(archivo);
    }
    return lista;
}
//}

//{ EJERCICIO2

void ejercicio2()
{
    nodo * listaElementos = inicializa();
    listaElementos = ingresarListaElementosOrdenadosDesdeArchivo(ESTUDIANTE,listaElementos);
    mostrarLista(listaElementos);
}

nodo * agregarEnOrden(nodo * lista, nodo * elemento)
{
    if(lista == NULL)
    {
        lista = elemento;
    }
    else
    {
        if( strcmpi(elemento->alumno.nombre,lista->alumno.nombre)<0)
        {
            lista = cargarAlPrincipio(lista,elemento);
        }
        else
        {
            nodo * nodoAuxiliar = lista;
            nodo * nodoAnterior = lista;

            while((nodoAuxiliar != NULL) && strcmpi(elemento->alumno.nombre,nodoAuxiliar->alumno.nombre)>0)
            {
                nodoAnterior = nodoAuxiliar;
                nodoAuxiliar = nodoAuxiliar->siguiente;
            }

            nodoAnterior->siguiente = elemento;
            elemento->siguiente = nodoAuxiliar;
        }
    }
    return lista;
}

nodo * ingresarListaElementosOrdenadosDesdeArchivo(char nombreArchivo[],nodo * lista)
{
    stEstudiante alumno;
    FILE*archivo = fopen(nombreArchivo,"r+b");
    if(archivo)
    {
        int i = 0;
        while(fread(&alumno,sizeof(stEstudiante),1,archivo)>0)
        {
            nodo * nuevo = crearNodo(alumno.nombre,alumno.edad,alumno.promedio,i);
            lista = agregarEnOrden(lista, nuevo);
            i++;
        }
        fclose(archivo);
    }
    return lista;
}

//}

//{ EJERCICIO 3
void ejercicio3()
{
    nodo * listaElementos = inicializa();
    listaElementos = agregarListaDesdeArchivo(ESTUDIANTE,listaElementos);
    int valor = buscarElemento(listaElementos,"Jorge");
    printf("%d",valor);

}

int buscarElemento(nodo * lista,char nombreBuscado[])
{
    nodo * iterator = lista;
    int flag = 0;
    while(iterator != NULL && flag == 0)
    {
        if(strcmpi(nombreBuscado,iterator->alumno.nombre) == 0)
        {
            flag = 1;
        }
        iterator = iterator->siguiente;
    }
    return flag;
}

//}

//{ EJERCICIO 4
nodo * ordenamientoLista(nodo * lista1,nodo * lista2, nodo * listaFinal)
{
    nodo * punteroAuxiliar;
    int i =0;
    while(lista1 != NULL && lista2 != NULL)
    {
        if(lista1->alumno.edad < lista2->alumno.edad)
        {
            i++;
            punteroAuxiliar = lista1;
            lista1 = lista1->siguiente;
            punteroAuxiliar->siguiente = NULL;
            listaFinal = agregarAlFinal(listaFinal,punteroAuxiliar);
            listaFinal->contador = i;
        }
        else
        {
            i++;
            punteroAuxiliar = lista2;
            lista2 = lista2->siguiente;
            punteroAuxiliar->siguiente = NULL;
            listaFinal = agregarAlFinal(listaFinal,punteroAuxiliar);
            listaFinal->contador = i;
        }
    }
    if(lista1!= NULL)
    {
        listaFinal = agregarAlFinal(listaFinal,lista1);
    }
    if(lista2!= NULL)
    {
        listaFinal = agregarAlFinal(listaFinal,lista2);
    }

    return listaFinal;
}

void ejercicio4()
{
    nodo * lista1 = inicializa();
    nodo * lista2 = inicializa();
    nodo * listaCompleta = inicializa();

    printf("%sLista 1%s\n",APERTURA,CERRADO);
    cargarArchivo(ESTUDIANTE);
    lista1 = agregarListaDesdeArchivo(ESTUDIANTE,lista1);
    printf("%sELEMENTOS CARGADOS ... %s\n",APERTURA,CERRADO);
    system("pause");
    system("cls");

    printf("%sLista 2%s\n",APERTURA,CERRADO);
    cargarArchivo(ESTUDIANTE);
    lista2 = agregarListaDesdeArchivo(ESTUDIANTE,lista2);
    printf("%sELEMENTOS CARGADOS ... %s\n",APERTURA,CERRADO);
    system("pause");
    system("cls");

    printf("%sLista Cargadas%s\n",APERTURA,CERRADO);

    printf("%sLista 1%s\n",APERTURA,CERRADO);
    mostrarLista(lista1);
    printf("%sLista 2%s\n",APERTURA,CERRADO);
    mostrarLista(lista2);

    printf("%sLista Completa%s\n",APERTURA,CERRADO);
    listaCompleta = ordenamientoLista(lista1,lista2,listaCompleta);
    mostrarLista(listaCompleta);
}

//}

//{ EJERCICIO 5
void ejercicio5()
{
    printf("%sEjercicio 5:%s\n",VERDE,NORMAL);
    stPila * pila1;
    iniciaPila(&pila1);

    stPila * pila2;
    iniciaPila(&pila2);

    apilarPila(&pila1,5);

    apilarPila(&pila2,6);
    apilarPila(&pila2,2);
    apilarPila(&pila2,3);
    printf("PASAMOS LOS ELEMENTOS DE LA PILA 2 A LA PILA 1.\n");
    printf("%sPILA 2%s\n",APERTURA,CERRADO);
    mostrarPila(pila2);

    while(!pilaVacia(pila2))
    {
        printf("%sPILA 1%s\n",APERTURA,CERRADO);
        mostrarPila(pila1);
        Sleep(2000);
        apilarPila(&pila1,desapilarPila(&pila2));
    }

    printf("%sPILA 1%s\n",APERTURA,CERRADO);
    mostrarPila(pila1);
    Sleep(3000);
    system("cls");
    printf("AGREGAMOS UN ELEMENTO A LA PILA.\n");
    leerDato(&pila1);
    printf("%sPILA 1%s\n",APERTURA,CERRADO);
    mostrarPila(pila1);
}


//}

//{ EJERCICIO 6

nodo * invertirLista ( nodo * lista)
{
    if(lista != NULL)
    {

        nodo * iterador = lista;
        nodo * primero = lista;
        nodo * ultimo = buscarUltimo(lista);

        lista = lista->siguiente;

        primero->siguiente = NULL;

        while(lista->siguiente != NULL)
        {
            iterador = lista;
            lista = lista->siguiente;
            iterador->siguiente = primero;
            primero = iterador;
        }
        ultimo->siguiente = iterador;
    }
    return lista;
}

void ejercicio6()
{
    nodo * lista = inicializa();
    cargarArchivoAutmatico(ESTUDIANTE);
    lista = agregarListaDesdeArchivo(ESTUDIANTE,lista);
    mostrarLista(lista);
    lista = invertirLista(lista);
    printf("\n%sELEMENTOS LISTA INVERTIDA%s\n",APERTURA,CERRADO);
    mostrarLista(lista);


}

//}

//{ EJERCICIO 7
void ejercicio7()
{
    stPila * pila;
    iniciaPila(&pila);

    apilarPila(&pila,2);
    apilarPila(&pila,1);
    apilarPila(&pila,1);
    apilarPila(&pila,6);

    printf("%sPILA%s\n",APERTURA,CERRADO);
    mostrarPila(pila);

    nodoSimple * lista = inicNodoSimple();
    lista = pasarParesLista(&pila,lista);
    mostrarListaNodoSimple(lista);
}



nodoSimple * pasarParesLista( stPila * pila, nodoSimple * lista)
{
    stPila * pilaAuxiliar;
    iniciaPila(&pilaAuxiliar);

    while( !pilaVacia(&(*pila)) )
    {
        int ultimo = tope(&(*pila));
        apilarPila(&pilaAuxiliar,desapilarPila(pila));
        if(ultimo %2==0 && ultimo != 0)
        {
            lista = agregarAlFinalNodoSimple(lista,crearNodoInt(ultimo));
        }
    }
    while( !pilaVacia(&pilaAuxiliar) )
    {
        apilarPila(pila,desapilarPila(&pilaAuxiliar));
    }
    return lista;
}

//}


//}








