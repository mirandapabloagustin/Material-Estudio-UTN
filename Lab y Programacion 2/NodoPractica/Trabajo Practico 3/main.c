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

/**     -------------------       PROTORIPADO ------------------  **/
// 1. Calcular el factorial de un n�mero en forma recursiva.
int factorial(int numero);
void ejerUno();

// 2. Calcular la potencia de un n�mero en forma recursiva.
int potencia(int numero, int exponente);

// 3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
void ejerTres();
void mostrarArregloRecurcivo(int arreglo[], int validos, int posicionInicial);

// 4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en
// forma invertida(recursivo).
void mostrarArregloInversoRecurcivo(int arreglo[], int validos);
void ejerCuatro();

// 5. Determinar en forma recursiva si un arreglo es capicúa.
int capicua(int arreglo[], int incremento, int decremento);
void validacionCapicua(int valor);
void ejerCinco();

// 6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de
// la suma.
int sumatorioRecursivo(int arreglo[], int validos, int posicionInicial);
void ejerSeis();

// 7. Buscar el menor elemento de un arreglo en forma recursiva.

int encontrarMenorRecursividad(int arreglo[], int validos, int posicionInicial)
{
    int menor;
    if (posicionInicial < validos && menor > arreglo[posicionInicial])
    {
        menor = encontrarMenorRecursividad(arreglo, validos, posicionInicial + 1);
    }
    else
    {
        menor = arreglo[posicionInicial];
    }
    return menor;
}

void ejerSiete()
{
    int arreglo[10] = {12, 36, 23, 45, 18, 234, 76, 57, 8, 112};
    int valor = encontrarMenorRecursividad(arreglo, 10, 0);
    printf("%s%d%s", APERTURA, valor, CERRADO);
}











int main()
{
    system("cls");
    printf("%sTrabajo Practico 3%s\n\n", VERDE, NORMAL);
    ejerSiete();

    return 0;
}

















// Ejer 1:
int factorial(int numero)
{
    int respuesta;
    if (numero == 0)
    {
        respuesta = 1;
    }
    else
    {
        respuesta = numero * factorial(numero - 1);
    }
    return respuesta;
}

void ejerUno()
{

    printf("%sEjercicio 1:%s\n", CYAN, NORMAL);
    puts("==============================================================");
    int numero;
    printf("Ingresar un valor:\n");
    fflush(stdin);
    scanf("%d", &numero);
    int factor = factorial(5);
    printf("Factorial del valor %d: %s%d%s\n", numero, APERTURA, factor, CERRADO);
    puts("==============================================================");
}

// Ejer 2:
int potencia(int numero, int exponente)
{
    int respuesta;
    if (exponente == 0)
    {
        respuesta = 1;
    }
    else
    {
        respuesta = numero * potencia(numero, exponente - 1);
    }
    return respuesta;
}

void ejerDos()
{
    printf("%sEjercicio 2:%s\n", CYAN, NORMAL);
    puts("==============================================================");
    int numero;
    int exponente;
    printf("Ingresar un valor:\n");
    fflush(stdin);
    scanf("%d", &numero);
    printf("Ingresar un Exponente:\n");
    fflush(stdin);
    scanf("%d", &exponente);
    int numeroPotencia = potencia(numero, exponente);
    printf("La Potencia de %d con exp. %d: %s%d%s\n", numero, exponente, APERTURA, numeroPotencia, CERRADO);
    puts("==============================================================");
}

// Ejer 3:
void mostrarArregloRecurcivo(int arreglo[], int validos, int posicionInicial)
{
    if (posicionInicial != validos)
    {
        printf("%s%d%s", APERTURA, arreglo[posicionInicial], CERRADO);
        mostrarArregloRecurcivo(arreglo, validos, posicionInicial + 1);
    }
}

void ejerTres()
{
    int arregloNumero[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    mostrarArregloRecurcivo(arregloNumero, 10, 0);
}

// Ejer 4:

void mostrarArregloInversoRecurcivo(int arreglo[], int validos)
{
    if (validos > 0)
    {
        printf("%s %d %s", APERTURA, arreglo[validos - 1], CERRADO);
        mostrarArregloInversoRecurcivo(arreglo, validos - 1);
    }
}

void ejerCuatro()
{
    int arregloNumero[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    mostrarArregloInversoRecurcivo(arregloNumero, 10);
}

// Ejer 5:

void validacionCapicua(int valor)
{
    if (valor == 1)
    {
        printf("\nEs Capicua.\n");
    }
    else
    {
        printf("\nNo es Capicua.\n");
    }
}

int capicua(int arreglo[], int incremento, int decremento)
{
    int respuesta = 1;
    if (incremento < decremento)
    {
        if (arreglo[incremento] == arreglo[decremento])
        {
            respuesta = capicua(arreglo, incremento + 1, decremento - 1);
        }
        else
        {
            respuesta = 0;
        }
    }

    return respuesta;
}

void ejerCinco()
{
    printf("%sEjercicio 5.%s\n\n", VERDE, NORMAL);
    puts("==============================================================");

    int arregloCapicua[] = {1, 3, 4, 3, 1};
    int valor = capicua(arregloCapicua, 0, 4);
    mostrarArregloRecurcivo(arregloCapicua, 5, 0);
    validacionCapicua(valor);
    puts("==============================================================");
}

// Ejer 6:

int sumatorioRecursivo(int arreglo[], int validos, int posicionInicial)
{
    int valor = arreglo[posicionInicial];
    if (posicionInicial == validos)
    {
        valor = 0;
    }
    else
    {
        valor += sumatorioRecursivo(arreglo, validos, posicionInicial + 1);
    }
    return valor;
}

void ejerSeis()
{
    printf("%sEjercicio 6:%s\n", CYAN, NORMAL);
    puts("==============================================================");
    int arregloNumero[5] = {12, 21, 30, 52, 1};
    printf("Arreglo numeros: ");
    mostrarArregloRecurcivo(arregloNumero, 5, 0);
    int valor = sumatorioRecursivo(arregloNumero, 5, 0);
    printf("\nLa Suma total: %s%d%s\n", APERTURA, valor, CERRADO);
    puts("==============================================================");
}

// Ejer 7:
