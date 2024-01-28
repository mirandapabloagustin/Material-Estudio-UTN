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
#define AP "\033[36m[\033[0m"
#define CLO "\033[36m]\033[0m"

// control + j = abreviaciones
/**                 ----------------             PROTOTIPADO               -----------------                      **/
//  FUNCIONES ADICIONALES:
void mostrarArregloEntero(int arreglo[], int dimension);
//----------------------------------------------------------------------------------------------------------------
// EJERCICIO 1:
// PUNTO 1.a
void inciarArreglo(int arreglo[], int dimension);
// PUNTO 1.b
int captarNumero();
void cargaManual(int arreglo[], int dimension);
void mostrarArregloElementos(int arreglo[], int dimension);
// PUNTO 1.c
int sumarValorElementos(int arreglo[], int dimension);
// PUNTO 1.d
int contarElementosArreglo(int arreglo[], int dimension);
// PUNTO 1.e
float promedioTotal(int arreglo[], int dimension);
// PUNTO 1.f
void ejercicioUno();
//---------------------------------------------------------------------------------------------------------------
//  EJERCICIO 2:
// PUNTO 2.a
void ingresarElementosChar(char arreglo[], int dimension, int *validos);
// PUNTO 2.b
void invertirArreglo(char arreglo[], int validos);
// PUNTO 2.c
void mostrarArregloChar(char arreglo[], int dimension);
// PUNTO 2.d
void ejercicioDos();
//---------------------------------------------------------------------------------------------------------------
//  EJERCICIO 4:
int valorMaximoArreglo(int arreglo[], int dimension);
void ejercicioCuatro();
//---------------------------------------------------------------------------------------------------------------
// EJERCICIO 5:
// PUNTO 5.a
void mostrarMatriz(int matriz[][31], int dimension);
void iniciarMatrizValoresRandoms(int matriz[][31], int dimension);
// PUNTO 5.b
int determinarMaximoRangoDelMes(int matriz[][31], int mes);
// PUNTO 5.c
void cargarArregloConMaximos(int arreglo[], int dimension, int matriz[][31]);
// PUNTO 5.f
void ejercicioCinco();
//---------------------------------------------------------------------------------------------------------------
// EJERCICIO 6:
int polindromo(char arreglo[]);
void verificacionPolindromo(char palabra[]);
void verificacionPalabraPolindromo();
//---------------------------------------------------------------------------------------------------------------
// EJERCICIO 7:
void intercambio(int *variable1, int *variable2);
//---------------------------------------------------------------------------------------------------------------
// EJERCICIO 8:
void copiaArreglo(int arreglo[], int copiaArreglo[], int dimencion, int posicionCopia);
void pasajeArregloMayor(int arreglo1[], int arreglo2[], int arregloCopia[], int dimencion1, int dimencion2);
void ejercicioOcho();
//---------------------------------------------------------------------------------------------------------------
// EJERCICIO 9:
void mostrarArreglosParalelos(char arregloString[][30], int arreglo[], int dimension)
{
    printf("%sArreglo:%s\n", CYAN, NORMAL);

    for (int i = 0; i < dimension; i++)
    {
        printf("%s%s%s ->", APERTURA, arregloString[i], CERRADO);
        printf("%s%d%s\n", APERTURA, arreglo[i], CERRADO);
    }
    printf("\n");
}
void mostrarApellidoMayorEdad(char arregloString[][30], int arreglo[], int dimension)
{

    int posicionMayor = valorMaximoArreglo(arreglo, dimension);
    printf("Apellido: %s%s%s", APERTURA, arregloString[posicionMayor - 1], CERRADO);
    printf(" Edad: %s%d%s\n", APERTURA, arreglo[posicionMayor - 1], CERRADO);
}
void ejercicioNueve()
{
    printf("%sEjercicio 9%s\n\n", VERDE, NORMAL);
    puts("===========================================================================");

    int listaEdades[6] = {22, 17, 24, 27, 24, 21};
    char listaApellidos[6][30] = {"Perez", "Rodriguez", "Duarte", "Miranda", "Chenal", "Karp"};
    mostrarArreglosParalelos(listaApellidos, listaEdades, 6);

    printf("Apellido con Mayor EDAD:\n");
    mostrarApellidoMayorEdad(listaApellidos, listaEdades, 6);
    puts("===========================================================================");
}
//---------------------------------------------------------------------------------------------------------------
// EJERCICIO 10:

//---------------------------------------------------------------------------------------------------------------

int main()
{
    system("cls");
    srand(time(NULL));
    ejercicioNueve();
}

/** ------------------                EJERCICIO 1               -------------------------- **/

// 1. Se tiene un arreglo de n�meros enteros positivos. Se desea obtener el promedio de sus valores. Para ello se debe:
// a. Hacer una funci�n que inicialice las celdas del arreglo en �1.
void inciarArreglo(int arreglo[], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        arreglo[i] = -1;
    }
}
// b. Hacer una funci�n que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.
int captarNumero()
{
    int numero = 0;
    printf("Ingresar Valor:\n");
    fflush(stdin);
    scanf("%d", &numero);
    return numero;
}

void cargaManual(int arreglo[], int dimension)
{
    char opcion = 's';
    int numero = -1;
    for (int i = 0; i < dimension && opcion == 's'; i++)
    {
        while (numero < 0)
        {
            numero = captarNumero();
        }
        arreglo[i] = numero;
        printf("Desea continuar (s/n)\n");
        fflush(stdin);
        scanf("%c", &opcion);
        numero = -1;
    }
}

void mostrarArregloElementos(int arreglo[], int dimension)
{
    printf("%sARREGLO:%s ", CYAN, NORMAL);
    for (int i = 0; i < dimension && arreglo[i] >= 0; i++)
    {
        printf("%s%d%s", APERTURA, arreglo[i], CERRADO);
    }
    printf("\n");
}

// c. Hacer una funci�n que sume el contenido del arreglo y lo retorne.
int sumarValorElementos(int arreglo[], int dimension)
{
    int sumaTotal = 0;
    for (int i = 0; i < dimension && arreglo[i] > 0; i++)
    {
        sumaTotal += arreglo[i];
    }
    return sumaTotal;
}

// d. Hacer una funci�n que cuente la cantidad de valores ingresados.
int contarElementosArreglo(int arreglo[], int dimension)
{
    int contador = 0;
    for (int i = 0; i < dimension && arreglo[i] >= 0; i++)
    {
        contador++;
    }
    return contador;
}

// e. Hacer una funci�n que reciba como par�metro el arreglo ya cargado, calcule y retorne el valor promedio
// usando las funciones anteriores (c y d).
float promedioTotal(int arreglo[], int dimension)
{
    float promedio;
    int sumaTotal = contarElementosArreglo(arreglo, dimension);
    promedio = (float)sumarValorElementos(arreglo, dimension) / sumaTotal;
    return promedio;
}

// f. Hacer la funci�n main correspondiente
void ejercicioUno()
{

    printf("Ejercicio 1\n");
    printf("Punto A:\n\n");

    int dimension = 10;
    int listaNumeros[dimension];

    inciarArreglo(listaNumeros, dimension);
    mostrarArregloEntero(listaNumeros, dimension);
    puts("===========================================================================");
    printf("Punto B:\n\n");

    cargaManual(listaNumeros, dimension);
    mostrarArregloElementos(listaNumeros, dimension);
    puts("===========================================================================");
    printf("Punto C:\n\n");

    int sumaTotal = sumarValorElementos(listaNumeros, dimension);
    printf("Suma Total Elementos: | %d |\n", sumaTotal);
    puts("===========================================================================");
    printf("Punto D:\n\n");

    int cantElementos = contarElementosArreglo(listaNumeros, dimension);
    printf("Cantidad Total Elementos: | %d |\n", cantElementos);
    puts("===========================================================================");
    printf("Punto E:\n\n");

    float promedio = promedioTotal(listaNumeros, dimension);
    printf("Promedio de los Elementos: | %.2f |\n", promedio);

    puts("===========================================================================");
}

//  FUNCIONES ADICIONALES:
void mostrarArregloEntero(int arreglo[], int dimension)
{
    printf("%sARREGLO:%s ", CYAN, NORMAL);
    for (int i = 0; i < dimension; i++)
    {
        printf("%s%d%s", APERTURA, arreglo[i], CERRADO);
    }
    printf("\n");
}

/** ------------------                EJERCICIO 2               -------------------------- **/

// 2. Invertir el contenido de un arreglo de caracteres. Para ello se debe modularizar de la siguiente forma:
// a. Hacer una funci�n para la carga del arreglo.
void ingresarElementosChar(char arreglo[], int dimension, int *validos)
{
    int i = 0;
    char mander;
    do
    {
        printf("Ingrese un Caracter: \n");
        fflush(stdin);
        scanf("%c", &arreglo[i]);
        i++;
        if (i < dimension)
        {
            printf("Estas Seguro (s/n): \n");
            fflush(stdin);
            scanf("%c", &mander);
        }
        else
        {
            printf("\nNo se pueden cargar mas Elementos.\n");
        }
    } while (i < dimension && (mander == 's' || mander == 'S'));
    *validos = i;
}

// b. Hacer una funci�n para invertir el arreglo.
void invertirArreglo(char arreglo[], int validos)
{
    int j = validos - 1;
    char aux;
    for (int i = 0; i < (validos / 2); i++)
    {
        aux = arreglo[j];
        arreglo[j] = arreglo[i];
        arreglo[i] = aux;
        j--;
    }
}

// c. Hacer una funci�n para mostrar el contenido del arreglo.
void mostrarArregloChar(char arreglo[], int dimension)
{
    printf("%sARREGLO:%s ", CYAN, NORMAL);
    for (int i = 0; i < dimension; i++)
    {
        printf("%s%c%s", APERTURA, arreglo[i], CERRADO);
    }
    printf("\n");
}

// d. Hacer la funci�n main con el men� correspondiente.
void ejercicioDos()
{
    printf("PUNTO A:\n\n");
    int dimension = 10;
    int validos = 0;
    char listaCaracteres[dimension];
    ingresarElementosChar(listaCaracteres, dimension, &validos);
    mostrarArregloChar(listaCaracteres, validos);
    puts("=========================================================================\n");

    printf("PUNTO B:\n\n");
    invertirArreglo(listaCaracteres, validos);
    mostrarArregloChar(listaCaracteres, validos);
    puts("=========================================================================\n");

    printf("PUNTO C:\n\n");
    printf("Muestra de Arreglo:\n");
    mostrarArregloChar(listaCaracteres, validos);
    puts("=========================================================================\n");
}

/** ------------------                EJERCICIO 3               -------------------------- **/

// 3. Hacer una funci�n que reciba como par�metro un arreglo de n�meros enteros de un d�gito y retorne el valor decimal
// de dicho n�mero. Por ejemplo, un arreglo que tiene cargados los valores 3, 2, 8 y 9, la fn retorna el valor 3289.

/** ------------------                EJERCICIO 4               -------------------------- **/

// 4. Hacer una funci�n que retorne la posici�n del valor m�ximo de un arreglo de n�meros enteros.
int valorMaximoArreglo(int arreglo[], int dimension)
{
    int mayorElemento = 0;
    int posicionMayor = 1;

    for (int i = 0; i < dimension; i++)
    {
        if (mayorElemento < arreglo[i])
        {
            mayorElemento = arreglo[i];
            posicionMayor = i;
        }
    }
    return posicionMayor + 1;
}

void ejercicioCuatro()
{
    printf("Ejercicio 4:\n\n");
    int arregloNumeroEnteros[10] = {1, 2, 7, 10, 36, 8, 55, 33, 9, 11};
    mostrarArregloEntero(arregloNumeroEnteros, 10);
    int mayorNumero = valorMaximoArreglo(arregloNumeroEnteros, 10);
    printf("\nLa posicion del Mayor Elemento: | %d |\n", mayorNumero);
    puts("=========================================================================\n");
}

/** ------------------                EJERCICIO 5               -------------------------- **/

// 5. Sea una matriz de n�meros enteros, de dimensiones: 12 filas y 31 columnas. Contienen las precipitaciones
// correspondientes a un a�o entero. Las filas corresponden a los meses y las columnas a los d�as. Se pide:
// a. Hacer una funci�n para cargar la matriz de forma autom�tica.
void iniciarMatrizValoresRandoms(int matriz[][31], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            matriz[i][j] = rand() % 100;
        }
    }
}

void mostrarMatriz(int matriz[][31], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        printf("\nMes %s%d%s:\n", APERTURA, i, CERRADO);
        puts("---------------");
        for (int j = 0; j < 31; j++)
        {
            printf("%s%d%s", APERTURA, matriz[i][j], CERRADO);
        }
        printf("\n");
    }
}

// b. Hacer una funci�n que retorne el d�a de m�xima precipitaci�n para un mes determinado.

int determinarMaximoRangoDelMes(int matriz[][31], int mes)
{
    int valor = valorMaximoArreglo(matriz[mes], 31);
    return valor;
}

// c. Hacer una funci�n que cargue en un arreglo de 12 posiciones el resultado de aplicar la fn anterior a cada
// mes de a�o.

void cargarArregloConMaximos(int arreglo[], int dimension, int matriz[][31])
{
    for (int i = 0; i < dimension; i++)
    {
        arreglo[i] = determinarMaximoRangoDelMes(matriz, i);
    }
}

// d. Hacer la funci�n main con el men� correspondiente.

void ejercicioCinco()
{

    printf("%sEjercicio 5:%s\n\n", VERDE, NORMAL);
    printf("Punto A:\n");
    int anioEntero[12][31];
    iniciarMatrizValoresRandoms(anioEntero, 12);
    mostrarMatriz(anioEntero, 12);
    puts("===========================================================================");
    printf("Punto B:\n\n");
    int valorMaximoMatriz = determinarMaximoRangoDelMes(anioEntero, 0);
    printf("Maximo Rango fue el Dia: %s%d%s\n", APERTURA, valorMaximoMatriz, CERRADO);
    puts("===========================================================================");
    printf("Punto C:\n\n");
    int listaMaximos[12];
    cargarArregloConMaximos(listaMaximos, 12, anioEntero);
    mostrarArregloEntero(listaMaximos, 12);
    puts("===========================================================================");
}

/** ------------------                EJERCICIO 6               -------------------------- **/

// 6. Dada una cadena de caracteres, hacer una funci�n que determine si dicha cadena es pal�ndromo (se lee de igual forma
// de adelante para atr�s como viceversa) o no. La funci�n recibe como par�metro la cadena y retorna 1 o 0 seg�n sea la
// respuesta.

int polindromo(char arreglo[])
{
    int tamanio = strlen(arreglo);
    int flag = 1;
    int j = tamanio - 1;

    for (int i = 0; i < tamanio / 2; i++)
    {
        if (arreglo[i] != arreglo[j])
        {
            flag = 0;
        }
        j--;
    }
    return flag;
}

void verificacionPolindromo(char palabra[])
{
    int verificacion = polindromo(palabra);
    if (verificacion)
    {
        printf("%s %s %s ES POLINDROMO.\n", APERTURA, palabra, CERRADO);
    }
    else
    {
        printf("%s %s %s NO es POLINDROMO.\n", APERTURA, palabra, CERRADO);
    }
}

void verificacionPalabraPolindromo()
{
    char palabra[30];
    printf("Ingrese PALABRA:\n");
    fflush(stdin);
    scanf("%s", &palabra);
    verificacionPolindromo(palabra);
}

/** ------------------                EJERCICIO 7               -------------------------- **/

// 7. Hacer una funci�n que intercambie el contenido de dos variables. (pasaje de par�metros por referencia)

void intercambio(int *variable1, int *variable2)
{
    int datoAux;
    datoAux = *variable2;
    *variable2 = *variable1;
    *variable1 = datoAux;
}

/** ------------------                EJERCICIO 8               -------------------------- **/

// 8. Dados dos arreglos de n�meros enteros ordenados de menor a mayor, hacer una funci�n que los reciba como
// par�metros y retorne un tercer arreglo que contenga los datos de los arreglos anteriores, tambi�n ordenados. Se los
// debe intercalar.

void copiaArreglo(int arreglo[], int copiaArreglo[], int dimencion, int posicionCopia)
{
    for (int i = posicionCopia; i < dimencion; i++)
    {
        copiaArreglo[i] = arreglo[i - posicionCopia];
    }
}

void pasajeArregloMayor(int arreglo1[], int arreglo2[], int arregloCopia[], int dimencion1, int dimencion2)

{
    copiaArreglo(arreglo1, arregloCopia, dimencion2, 0);
    copiaArreglo(arreglo2, arregloCopia, dimencion2, dimencion1);
}

void ejercicioOcho()
{
    printf("%sEjercicio 8:%s\n\n", VERDE, NORMAL);
    puts("===========================================================================");
    int listaNumeroUno[5] = {1, 2, 3, 4, 5};
    int listaNumeroDos[5] = {6, 7, 8, 9, 0};
    int listaCompletaNumeros[10];

    printf("Lista Numero 1:\n");
    mostrarArregloElementos(listaNumeroUno, 5);
    printf("Lista Numero 2:\n");
    mostrarArregloElementos(listaNumeroDos, 5);

    printf("Lista Numero 3 copia de los dos Anteriores:\n");
    pasajeArregloMayor(listaNumeroUno, listaNumeroDos, listaCompletaNumeros, 5, 10);
    mostrarArregloEntero(listaCompletaNumeros, 10);
    puts("===========================================================================");
}

/** ------------------                EJERCICIO 9               -------------------------- **/

// 9. Dados dos arreglos paralelos, uno con apellidos y otro con edades. Se debe hacer un programa para encontrar el
// apellido de la persona de mayor edad. Se debe modularizar.

/** ------------------                EJERCICIO 10               -------------------------- **/

// 10. Hacer una funci�n que reciba como par�metros de entrada un arreglo de enteros y su dimensi�n, y tres par�metros
// de salida, tres n�meros enteros que representen: valor m�ximo, valor m�nimo y promedio. Se debe usar pasaje de
// par�metros por referencia
