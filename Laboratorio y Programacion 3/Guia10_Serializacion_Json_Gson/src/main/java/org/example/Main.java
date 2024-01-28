package org.example;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.google.gson.Gson;
import org.example.Package1.*;
import org.example.Package2.*;
import org.example.Package3.*;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        /*
        Realiza un programa en JAVA en el que le pidas al usuario las notas de las 6 asignaturas del Ciclo de DAM y las guarde
        en un fichero. Posteriormente leerá el fichero y te calculará la nota media del curso.
        Nota 1: Cada una de las asignaturas serán un objeto que se encuentran en un array de 6 posiciones, y cuyos atributos serán el nombre y la nota.
        Nota 2: Con el constructor podrás asignar directamente el nombre de la asignatura al crear el objeto. En cambio, el atributo nota, será el usuario quien lo introduzca mediante un método que controle que la nota tenga un valor entre 0 y 10.

        Ejemplo de ejecución:
        105
        Por favor, introduzca la nota de Programación: 6,5
        Introduzca la nota de Lenguajes de Marcas: 7,5
        Introduzca la nota de Bases de Datos: 7,5
        Introduzca la nota de Entornos de Desarrollo: 8
        Introduzca la nota de Sistemas Informáticos: 6,5
        Por último, introduzca la nota de FOL: 6
        ***** Notas almacenadas en el array *****
        ……… Volcando el array al fichero ………
        ***** Volcado finalizado con éxito *****
        ………Leyendo el fichero y calculando media………
        Su nota media del curso es de: 7
         */
        System.out.println("== Ejercicio 1 ==");
        //ejer1();
        System.out.println("------------------------------------------");

        /*
        Realiza un programa en JAVA en el que le pidas al usuario los datos de un estudiantes, los guarde en un fichero
        Json y los muestre.
         */

        System.out.println("== Ejercicio 2 ==");
        //ejer2();
        System.out.println("------------------------------------------");

        /*
        Consigna: Escribe un programa en Java que realice la serialización y deserialización de un objeto a formato JSON utilizando la biblioteca Gson. El programa debe realizar lo siguiente:

        Crea una clase llamada "Person" con los siguientes atributos: "name" (nombre) de tipo String y "age" (edad) de tipo int.
        Solicita al usuario que ingrese el nombre y la edad de una persona.
        Crea una instancia de la clase "Person" con los datos ingresados por el usuario.
        Utiliza Gson para serializar la instancia de la clase "Person" en formato JSON.
        Imprime en pantalla el JSON serializado.
        Utiliza Gson para deserializar el JSON y obtener una instancia de la clase "Person".
        Imprime en pantalla los datos (nombre y edad) de la persona deserializada.
         */
        System.out.println("== Ejercicio 3 ==");
        ejer3();
        System.out.println("------------------------------------------");




    }

    ///region Ejercicio 1
    public static Materias ingresarMateria() throws MateriasExceptions,Exception{
        Scanner sc = new Scanner(System.in);
        System.out.print("Nombre Materia: ");
        String nombre = sc.nextLine();
        System.out.print("Nota Materia: ");
        double nota = sc.nextDouble();

        if(nota < 0 || nota > 10){
            throw new MateriasExceptions("La nota debe estar entre 0 y 10");
        }else if(nombre.length() == 0) {
            throw new MateriasExceptions("El nombre no puede estar vacio");
        }else{
            Materias materia = new Materias(nombre, nota);
            return materia;
        }
    }

    public static void cargarMaterias(ArrayList<Materias> listaMaterias) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Cant Materias: ");
        int cantMaterias = sc.nextInt();
        int i = 0;
        do {
            try {
                listaMaterias.add(ingresarMateria());
                i++;
            } catch (MateriasExceptions e) {
                System.out.println(e.getMessage());
            } catch (Exception e) {
                System.out.println("Error inesperado, vuelva a intentarlo");
            }
        }while (i < cantMaterias) ;
    }

    public static void verMaterias(ArrayList<Materias> listaMaterias){
        for (Materias materia : listaMaterias) {
            System.out.println(materia.toString());
        }
    }

    public static void guardarEnFichero(ArrayList<Materias> listaMaterias){
        File archivo = new File("materias.bin");
        try {
            // Instancio la clase que se va a encargar de serializar
            ObjectOutputStream bw = new ObjectOutputStream(new FileOutputStream(archivo));
            // Serializo el objeto
            bw.writeObject(listaMaterias);
            // Cierro el archivo
            bw.close();
        }catch (IOException e){
            System.out.println("Error al crear el archivo");
        }finally {
            System.out.println("Acción finalizada guardarEnFichero");
        }
    }

    public static void leerFichero(){
        File archivo = new File("materias.bin");
        ArrayList<Materias> listaMaterias = new ArrayList<>();

        try {
            // Instancio la clase que se va a encargar de deserializar
            ObjectInputStream br = new ObjectInputStream(new FileInputStream(archivo));
            // Deserializo el objeto
            listaMaterias = (ArrayList<Materias>) br.readObject();
            // Cierro el archivo
            br.close();
            System.out.println(listaMaterias.toString());
        } catch (ClassNotFoundException e) {
            System.out.println("Error al Deserializar: " + e.getMessage());
        }catch (IOException e){
            System.out.println("Error al leer el archivo");
        } finally {
            System.out.println("Acción finalizada leerFichero");
        }
    }

    public static void ejer1(){
        ArrayList<Materias> listaMaterias = new ArrayList<>();
        cargarMaterias(listaMaterias);
        verMaterias(listaMaterias);
        guardarEnFichero(listaMaterias);
        System.out.println("--------------------------------------------------");
        leerFichero();
    }
    ///endregion

    ///region Ejercicio 2

    public static Estudiante crearEstudiante() throws EstudianteExceptions, RuntimeException{
        Scanner sc = new Scanner(System.in);
        System.out.print("Nombre: ");
        String nombre = sc.nextLine();
        System.out.print("DNI: ");
        int dni = Integer.valueOf(sc.nextLine());
        System.out.print("Carrera: ");
        String carrera = sc.nextLine();
        Estudiante estudiante = new Estudiante(nombre, dni, carrera);
        if(estudiante.getDni() < 0) {
            throw new EstudianteExceptions ("El DNI no puede ser negativo");
        } else if (estudiante.getNombre().length() == 0) {
            throw new EstudianteExceptions ("El nombre no puede estar vacio");
        } else if (estudiante.getCarrera().length() == 0) {
            throw new EstudianteExceptions ("La carrera no puede estar vacia");
        } else {
            return estudiante;
        }
    }


    public static void ejer2() {
        // Creo el archivo
        File archivo = new File("estudiantes.json");

        try{
            // Creo el estudiante
            Estudiante estudiante = crearEstudiante();
            // Creo el objeto que se va a encargar de serializar
            ObjectOutputStream bw = new ObjectOutputStream(new FileOutputStream(archivo));
            // Serializo el objeto
            bw.writeObject(estudiante);
            bw.close();


            // Creo el objeto que se va a encargar de deserializar
            ObjectInputStream br = new ObjectInputStream(new FileInputStream(archivo));
            // Deserializo el objeto
            Estudiante alumno = (Estudiante) br.readObject();
            br.close();
            System.out.println(alumno.toString());

        } catch (EstudianteExceptions e) {
            System.out.println(e.getMessage());
        } catch (RuntimeException e) {
            System.out.println("Error inesperado, vuelva a intentarlo");
        }catch (ClassNotFoundException e) {
            System.out.println("Error al crear/escribir el archivo");
        }catch (IOException e) {
            System.out.println("Error al crear/escribir el archivo");
        }finally {
            System.out.println("Acción finalizada");
        }

    }
    ///endregion

    ///region Ejercicio 3
    public static void ejer3(){
        // Creo el archivo
        File archivo = new File("personas.json");
        Gson gson = new Gson();
        try{
            // Creo la persona
            Persona persona = new Persona("Juan", 43343554, 25);
            // Creo el objeto que se va a encargar de serializar
            BufferedWriter bw = new BufferedWriter(new FileWriter(archivo));
            // Serializo el objeto
            gson.toJson(persona,Persona.class, bw);
            bw.close();
            // Creo el objeto que se va a encargar de deserializar
            BufferedReader br = new BufferedReader(new FileReader(archivo));
            // Deserializo el objeto
            Persona persona1 = gson.fromJson(br, Persona.class);
            br.close();
            System.out.println(persona1.toString());

        } catch (FileNotFoundException e) {
            System.out.println("Error al crear/escribir el archivo");
        } catch (IOException e) {
            System.out.println("Error inesperado: " + e.getMessage());
        }
    }

    public  static void ejer4(){
        File archivo = new File("conductores.json");
        // Creo el objeto que se va a encargar de serializar
        ObjectMapper mapper = new ObjectMapper();
        try {
            // Creo la persona
            Persona persona = new Persona("German", 45653412, 19);
            // Serializo el objeto
            mapper.writerWithDefaultPrettyPrinter().writeValue(archivo, persona);
            // Deserializo el objeto
            Persona persona1 = mapper.readValue(archivo, Persona.class);

            System.out.println(persona1);
        }catch (IOException e){
            System.out.println("Error al crear/escribir el archivo");
        }
    }


}