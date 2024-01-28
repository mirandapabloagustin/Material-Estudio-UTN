package com.agus.clases.Estudiante;
import java.util.ArrayList;
import java.util.Scanner;

public class GestionEstuduanteMaterias {

    public static Estudiante crearAlumno(){

        Estudiante alumno = new Estudiante();

        Scanner scanner = new Scanner(System.in);

        System.out.print("Ingrese Nombre....: ");
        alumno.setNombre(scanner.nextLine());

        System.out.print("Ingrese Edad......: ");
        alumno.setEdad(scanner.nextInt());

        return alumno;
    }

    public static Materias crearMateria(){
        Scanner scanner = new Scanner(System.in);
        Scanner scannerFloat = new Scanner(System.in);

        Materias materia = new Materias();

        System.out.print("Nombre Materia....: ");
        materia.setNombre(scanner.nextLine());

        System.out.print("Nota Materia......: ");
        materia.setNota(scannerFloat.nextFloat());

        System.out.print("Carga Hs..........: ");
        materia.setCargaHoraria(scanner.nextLine());

        System.out.print("Profesor Materia..: ");
        materia.setProfesor(scanner.nextLine());

        return materia;
    }
    public static String inputNombre(){
        Scanner scan = new Scanner(System.in);
        System.out.print("Ingrese nombre Buscado: ");
        String input = scan.nextLine();
        return input;
    }
    public static int altaAlumno(ArrayList<Estudiante>listaEstudiante){
        String buscado = inputNombre();
        int pos = -1;
        for(int i = 0; i < listaEstudiante.size();i++){
            if (listaEstudiante.get(i).getNombre().equalsIgnoreCase(buscado)){
                pos = i;
            }
        }
        return pos;
    }

    public static void modificarAlumno(ArrayList<Estudiante>listaEstudiante){
        Scanner scanner = new Scanner(System.in);
        int alta = altaAlumno(listaEstudiante);
        if (alta >= 0){
            System.out.print("Ingrese Nuevo Nombre....: ");
            listaEstudiante.get(alta).setNombre(scanner.nextLine());
            System.out.print("Ingrese Nueva Edad......: ");
            listaEstudiante.get(alta).setNombre(scanner.nextLine());
        }else {
            System.out.println("USUARIO NO EXIsTE.");
        }
    }

    public static void ingresarMateria(Estudiante alumno){
        alumno.agregarMateriaAprobada(crearMateria());
    }

    public static void agregarMateriaAlumno(ArrayList<Estudiante>listaEstudiante){
        int alta = altaAlumno(listaEstudiante);
        if(alta >= 0){
            ingresarMateria(listaEstudiante.get(alta));
        }else{
            System.out.println("USUARIO NO EXISTE.");
        }
    }

    public static void borrarAlumno(ArrayList<Estudiante>listaEstudiante){
        int alta = altaAlumno(listaEstudiante);
        if(alta >0){
            listaEstudiante.remove(alta);
        }else{
            System.out.println("USUARIO NO EXISTE.");
        }
    }

}
