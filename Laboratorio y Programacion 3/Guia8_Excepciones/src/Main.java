import java.security.spec.RSAOtherPrimeInfo;
import java.util.Scanner;

public class Main {
    public static void main (String[] args) {

        /*
        Ejercicio 1:

        Rta: El segundo esta de sobra porque seria redundante.

        try{
            Persona p = baseDeDatos.buscar(datos);
            System.out.println(“Los datos pertenecen a: ” + p);
        } catch(Exception e) {
            // Maneja cualquiera de las excepciones comprobadas
        } catch(RuntimeException e) {
            // Maneja cualquiera de las excepciones no comprobadas
        }

        ------------------------------------------------------------------------------------------

        Ejercicio 2:

        Rta: a

        public static class EjemploExcepciones{
            public static int devuelveNumero(int num) {
                try {
                    // Comprueba si el parametro es par

                    if (num % 2 == 0) {
                            // Crea una Exception con un mensaje
                            throw new Exception("Lanzando excepcion");
                    }

                    // Si el numero no es par retorna 1 sino va directamente al CATCH

                    return 1;

                } catch (Exception ex) {
                    // Al mensaje de mi Exception le concatena un String

                    ex.getMessage().concat("Rompi mi Catch");

                    // Retorna 2

                    return 2;

                } finally {
                  - Como siempre se ejecuta este codigo, Retorna 3  -
                    return 3;
                }
            }
        }
        -----------------------------------------------------------------------------------------
         */
        
        ejer3();

        ejer4();


    }




    public static int random(){
        return (int)(Math.random()*500)+1;
    }

    public static void ejer3() {
        Scanner scan = new Scanner(System.in);
        int ingreso = 0;
        int numero = random();
        int intentos = 0;
        System.out.println("= ADIVINA MI NUMERO =");
        do {
            try{
                System.out.print("Ingresar Numero...: ");
                ingreso = Integer.parseInt(scan.nextLine());
                intentos++;
                if (ingreso == numero) {
                    System.out.println("= Correcto =");
                }else {
                    if (ingreso < numero) {
                        System.out.println("Bajo");
                    } else {
                        System.out.println("Alto");
                    }
                }
            }catch (NumberFormatException e){
                System.out.println("Ingresar numeros solamente...");
            }
        }while (ingreso != numero);
        System.out.print("Intento del Jugador: " + intentos);
    }

    public static void ejer4(){
        Colegio colegio = new Colegio("Colegio Nacional");

        colegio.agregarAlumno(new Alumnos("Juan","Argentina"));
        colegio.agregarAlumno(new Alumnos("Pedro","Chileno"));
        colegio.agregarAlumno(new Alumnos("Maria","Colombiana"));
        colegio.agregarAlumno(new Alumnos("Jose","Argentina"));

        colegio.verNacionalidad("Argentina");
        System.out.println("------------------------------------------------------");
        colegio.verNacionalidad("Chileno");
        System.out.println("------------------------------------------------------");
        colegio.verTodo();
    }

}

