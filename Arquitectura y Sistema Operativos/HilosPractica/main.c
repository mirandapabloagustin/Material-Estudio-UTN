#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <semaphore.h>

#define MAX 10

#define CANTIDAD_HILOS 10

// Creo el semaforo
sem_t semaforo;

void * funcionConSemaforo()
{
    sem_wait(&semaforo);
    printf("Soy el thread [%d]\n", pthread_self());
    sem_post(&semaforo);
    Sleep(300);

    pthread_exit(0);
}





void *funcion1()
{
    printf("Thread: %d\n", pthread_self());
    pthread_exit(0);
}



void *funcion(void *p)
{
    printf("Thread: %d\n", pthread_self());
    pthread_exit(0);
}



void sumaValor()
{
    int i = 0;
    printf("Hilo: %d INICIE!\n", pthread_self());
    while(i < 4)
    {
        printf("Hilo: %d Valor I de la funcion: %d\n", pthread_self(),i);
        printf("Apreta enter, Hilo: %d\n",pthread_self());
        getch();
        i++;
        Sleep(500);
    }
    printf("Hilo: %d TERMINE!\n", pthread_self());
    pthread_exit(0);
}



void sumaValor2(int i)
{
    printf("Hilo: %d INICIE!\n", pthread_self());
    while(i < 1000)
    {
        printf("Hilo: %d Valor I de la funcion: %d\n", pthread_self(),i);
        i++;
        Sleep(500);
    }
    printf("Hilo: %d TERMINE!\n", pthread_self());
    pthread_exit(0);
}




void wait()
{
    printf("Hola soy el thread con el id: %d, voy a dormir 4 segundos y luego continuo\n", pthread_self());

    Sleep(4000);

    printf("\nListo!! soy el thread con el id: %d, ya finalice luego de 4 segundos.\n", pthread_self());
}


void punto_6();
void punto_3();
void punto_1();





int main()
{


    punto_6();




//    pthread_attr_t attr;
//    pthread_t thid[MAX];
//    pthread_attr_init(&attr);
//    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
//    system("pause");
//    for(int i = 0; i < MAX; i++)
//    {
//        pthread_create(&thid[i], NULL, funcion1, NULL);
//    }
//    printf("Start sleep\n");
//    Sleep(10000);
//    printf("End sleep\n");





//    pthread_t hilo1;
//    pthread_t hilo2;
//
//    pthread_attr_t estructuraHilo;
//
//    pthread_attr_init(&estructuraHilo);
//
////    system("pause");
//
//    pthread_create(&hilo1, NULL, sumaValor, NULL);
//
//    pthread_create(&hilo2,&estructuraHilo, sumaValor2, 950);
//
//
//    pthread_join(hilo1, NULL);
//    pthread_join(hilo2, NULL);
//
//    printf("Terminado");
//
//    printf("Thread finalizado.\n");





//    // CREA DOS VARIABLES TIPO PTHREAD LLAMADAS "TH1" Y "TH2"
//    pthread_t th1, th2;
//
//    system("pause");
//    // CREA UN HILO:
//    //     ASIGANA VARIABLE   FUNCION
//    //              |            |
//    //              V            V
//    pthread_create(&th1, NULL, funcion, NULL);
//    //                    ^                ^
//    //                    |                |
//    //VALOR DE LA EST. ATRI POR DEFECTO   ATRIBUTO DE HILO POR DEFECTO
//
//    //LO MISMO QUE ARRBA PERO CON LA VARIABLE "TH2"
//    pthread_create(&th2, NULL, funcion, NULL);
//
//    //TE MUESTRA EL ID DEL HILO QUE SE ESTA EJECUTANDO
//    printf("El thread principal continua ejecutando: %d\n", pthread_self());
//
//    //TE MUESTRA UN SEGUIMIENTO DEL HILO LLAMADO "th1" HASTA SU FINALIZACION
//    pthread_join(th1,NULL);
//
//    //TE MUESTRA UN SEGUIMIENTO DEL HILO LLAMADO "th2" HASTA SU FINALIZACION
//    pthread_join(th2,NULL);










//    pthread_t thread,thread2,thread3,thread4;
//
//    int err, err2, err3, err4;
//
//    err =  pthread_create(&thread, NULL, wait, NULL);
//    err2 = pthread_create(&thread2, NULL, wait, NULL);
//    err3 = pthread_create(&thread3, NULL, wait, NULL);
//    err4 = pthread_create(&thread4, NULL, wait, NULL);


    /* PARAMETROS DE LA FUNCION pthread_create (thread, attr, start_routine, arg)

        1er param: (&thread) ubicacion (variable) donde el ID del nuevo hilo creado va a ser almacenado, o NULL si el ID no es necesario.
                    identificador para el nuevo thread devuelto por la funcion.

        2do param: (NULL) Son los atributos que le vamos a dar al thread como ser estado, politicas de planificacion, direccion de pila, etc.
                    Si pasamos NULL se le van a pasar los atributos por defecto.

        3er param: (wait) Esta es la funcion start(), o sea en donde se va a ejacutar el hilo en el codigo que escribimos.

        4to param: (NULL) Es el argumento a pasarle a la funcion, es un puntero genérico para pasar (mejor dicho emular) una lista de
                   argumentos, normalmente empaquetada en una struct (en caso de ser mas de 1 argumento). Estos son pasados a la funcion
                   start(). Si la funcion no recibe argumentos pasamos NULL.
    */
    /*
        RETORNO DE pthread_create:

        -En caso de exito, la funcion retorna 0.

        Cuando ocurre un error los siguientes valores son retornados dependiendo del error:

            -EAGAIN: El sistema no tiene recursos necesarios para crear un nuevo thread, o bien hay un limite impuesto para el numero
                     total de threads para un proceso. (PTHREAD_THREADS_MAX es excedido)

            -EFAULT: thread o attr es/son puntero(s) invalido(s)

            -EINVAL: attr no es un objeto de atributos inicializados para un thread.

    */

//    if (err || err2 || err3 || err4)
//    {
//        printf("Ocurrio un error en algun thread: retornos de los threads 1:|%d|,2:|%d|,3:|%d|,4:|%d|", err,err2,err3,err4);
//        return 1;
//    }
//
//    printf("Retorno de pthread_create: %d: \n",err); //ID del primer thread creado
//
//    printf("Esperamos...\n");
//
//    pthread_join(thread, NULL); //comentar estas lineas y ver que sucede
//    pthread_join(thread2, NULL);
//    pthread_join(thread3, NULL);
//    pthread_join(thread4, NULL);
//
//    printf("Thread finalizado.\n");

    return 0;
}

void punto_1()
{
    sem_t sema1, sema2, sema3;

    void  * miFuncion1(void * x)
    {
        int i = 0;

        while (i < 3)
        {
            sem_wait(&sema1);
            printf("Hilo %d\n", x);
            sem_post(&sema2);
            Sleep(1);
            i++;
        }
    }

    void * miFuncion2(void * x)
    {

        int i = 0;

        while (i < 3)
        {
            sem_wait(&sema2);
            printf("Hilo %d\n", x);
            sem_post(&sema3);
            Sleep(1);
            i++;
        }
    }

    void * miFuncion3(void * x)
    {

        int i = 0;

        while (i < 3)
        {
            sem_wait(&sema3);
            printf("Hilo %d\n", x);
            sem_post(&sema1);
            Sleep(1);
            i++;
        }
    }

    int uno = 1, dos = 2, tres = 3;

    pthread_t hilo1;
    pthread_t hilo2;
    pthread_t hilo3;

    sem_init(&sema1, 0, 1);
    sem_init(&sema2, 0, 0);
    sem_init(&sema3, 0, 0);

    pthread_create(&hilo1, NULL, miFuncion1, uno);
    pthread_create(&hilo2, NULL, miFuncion2, dos);
    pthread_create(&hilo3, NULL, miFuncion3, tres);

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    pthread_join(hilo3, NULL);

}




void punto_3()
{
    sem_t sema1, sema2, sema3;

    void  * miFuncion1(void * x)
    {
        int i = 0;

        while (i < 3)
        {
            sem_wait(&sema1);
            printf("A", x);
            sem_post(&sema2);
            Sleep(1);
            i++;
        }
    }

    void * miFuncion2(void * x)
    {

        int i = 0;

        while (i < 3)
        {
            sem_wait(&sema2);
            printf("B", x);
            sem_post(&sema3);
            Sleep(1);
            i++;
        }
    }

    void * miFuncion3(void * x)
    {

        int i = 0;

        while (i < 3)
        {
            sem_wait(&sema3);
            printf("C\n", x);
            sem_post(&sema1);
            Sleep(1);
            i++;
        }
    }

    int uno = 1, dos = 2, tres = 3;

    pthread_t hilo1;
    pthread_t hilo2;
    pthread_t hilo3;

    pthread_attr_t attr; // declaramos estruc

    pthread_attr_init(&attr); // iniciaamo la estructura de los hilos

    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE); // indicamos que los hilos van a ser dependientes entre si (JOIN)

    sem_init(&sema1, 0, 1);
    sem_init(&sema2, 0, 0);
    sem_init(&sema3, 0, 0);

    pthread_create(&hilo1, NULL, miFuncion1, uno);
    pthread_create(&hilo2, NULL, miFuncion2, dos);
    pthread_create(&hilo3, NULL, miFuncion3, tres);

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    pthread_join(hilo3, NULL);

}


void punto_6()
{
    sem_t a, c, b;

    void  * miFuncion1(void * x)
    {
        int i = 0;

        while (i < 3)
        {
            sem_wait(&a);
            printf("A");
            sem_post(&c);
            Sleep(1);
            i++;
        }
    }

    void * miFuncion2(void * x)
    {

        int i = 0;

        while (i < 3)
        {
            sem_wait(&b);
            printf("B");
            sem_post(&a);
            sem_post(&b);
            Sleep(1);
            i++;
        }
    }

    void * miFuncion3(void * x)
    {

        int i = 0;

        while (i < 3)
        {
            sem_wait(&b);
            sem_wait(&c);
            printf("C\n");
            sem_post(&b);
            Sleep(1);
            i++;
        }
    }

    pthread_t hilo1;
    pthread_t hilo2;
    pthread_t hilo3;

    pthread_attr_t attr; // declaramos estruc

    pthread_attr_init(&attr); // iniciaamo la estructura de los hilos

    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE); // indicamos que los hilos van a ser dependientes entre si (JOIN)

    sem_init(&a, 0, 0);
    sem_init(&b, 0, 1);
    sem_init(&c, 0, 0);

    pthread_create(&hilo1, NULL, miFuncion1, NULL);
    pthread_create(&hilo2, NULL, miFuncion2, NULL);
    pthread_create(&hilo3, NULL, miFuncion3, NULL);

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    pthread_join(hilo3, NULL);

}



















