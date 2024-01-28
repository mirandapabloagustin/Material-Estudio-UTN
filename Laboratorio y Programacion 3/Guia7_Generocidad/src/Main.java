import Ejer2.Baul;
import Ejer2.Jugetes;
import Ejer2.Libros;
import Estucturas.Caja;
import Estucturas.Cola;
import Estucturas.Persona;
import Estucturas.Pila;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;

public class Main {
    public static void main(String[] args) {


        //System.out.println("= EJERCICIO 1 =");
        //ejer1();
        //System.out.println("= EJERCICIO 2 =");
        //ejer2();

        Baul baul = new Baul<>(3);

        Libros l1 = new Libros("Juego de Tronos");
        Libros l2 = new Libros("Cars");
        Persona people = new Persona(3,"Juanpi");

        Jugetes j1 = new Jugetes("El Rayo McQueen");
        Jugetes j2 = new Jugetes("Buzz");

        baul.agregar(l1);
        baul.agregar(l2);

        System.out.println(baul.toString());

    }



    public static void ejer1() {
        Pila<Integer> pilita = new Pila<>(10);
        //SE AGREGARON ELEMENTOS
        System.out.println("= EJERCICIO TIPO PILA =");
        System.out.println("Se agregaron 3 elementos");
        pilita.apilar(5);
        pilita.apilar(15);
        pilita.apilar(10);
        System.out.println("Tope..: " + pilita.tope());
        mostrar(pilita);

        System.out.println("Se agregaron 3 elementos");
        pilita.apilar(154);
        pilita.apilar(45);
        pilita.apilar(13);
        mostrar(pilita);

        System.out.println("= EJERCICIO TIPO COLA =");

        Cola<Integer> colita = new Cola<>(5);

        System.out.println("Se agregaron 3 elementos");
        colita.apilar(10);
        colita.apilar(625);
        colita.apilar(52);
        mostrarCola(colita);

        System.out.println("Se saco uno y agregaron 2 elementos");
        colita.desapilar();
        colita.apilar(6);
        colita.apilar(85);
        mostrarCola(colita);


    }

    public static void mostrar(Pila<Integer> copia) {
        Pila<Integer> aux = new Pila<>(copia.getTopeMax());
        System.out.println("[ Tope...........*UTN MDP*........Base ]");
        System.out.print("[");
        while (!copia.pilaVacia()) {
            System.out.print(copia.tope() + "-");
            aux.apilar(copia.desapilar());
        }
        System.out.println("]\n");
        while (!aux.pilaVacia()) {
            copia.apilar(aux.desapilar());
        }
    }

    public static void mostrarCola(Cola<Integer> x) {
        Cola<Integer> aux = new Cola<>(x.getTopeMax());
        System.out.println("[ Tope...........*UTN MDP*........Base ]");
        System.out.print("[");
        while (!x.colaVacia()) {
            System.out.print(x.tope() + "-");
            aux.apilar(x.desapilar());
        }
        System.out.print("]\n");
        while (!aux.colaVacia()) {
            x.apilar(aux.desapilar());
        }

    }

    public static void ejer2(){
        Persona user = new Persona(27,"Woodie");
        Caja<Integer, Persona,Boolean> cajita = new Caja<>();
        System.out.println("\nSe agregaron 3 elementos distintos");
        cajita.agregarLista1(5);
        cajita.agregarLista2(user);
        cajita.agregarLista3(true);
        cajita.mostrar();

        System.out.println("\nSe borro el elemento de la Lista 2");
        cajita.eliminarLista2(user);
        cajita.mostrar();




    }




}