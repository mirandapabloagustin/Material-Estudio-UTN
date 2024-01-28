import java.sql.SQLOutput;
import java.time.*;
import java.util.Locale;
import java.util.Random;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        menu();
    }

    public static void menu(){
        Scanner scanner = new Scanner(System.in);
        int opc;
        do{
            System.out.println("= MENU GUIA 3 =");
            System.out.println("1] Ejecicio 1");
            System.out.println("2] Ejecicio 2");
            System.out.println("3] Ejecicio 3");
            System.out.println("4] Ejecicio 4");
            System.out.println("5] Ejecicio 5");
            System.out.println("6] Ejecicio 6");
            System.out.println("7] Ejecicio 7");
            System.out.println("0] SALIR");
            System.out.print("- Elija Opcion: ");
            opc = scanner.nextInt();
            switch (opc){
                case 1:
                    ejercicio1();
                    break;
                case 2:
                    ejercicio2();
                    break;
                case 3:
                    ejercicio3();
                    break;
                case 4:
                    ejecicio4();
                    break;
                case 5:
                    ejercicio5();
                    break;
                case 6:
                    ejercicio6();
                    break;
                case 7:
                    ejercicio7();
                    break;

            }
        }while(opc != 0);
    }

    public static String inputString(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingresar TEXTO: ");
        String text = scanner.nextLine();
        return text;
    }
    public static void ejercicio1(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("=== EJERCICIO 1 ===");
        System.out.println("Ingrese Fecha Nacimiento ");
        System.out.print("  - Año: ");
        int anio = scanner.nextInt();
        System.out.print("  - Mes: ");
        int mes = scanner.nextInt();
        System.out.print("  - Dia: ");
        int dia = scanner.nextInt();
        LocalDate fecha = LocalDate.of(anio,mes,dia);
        Period periodo = Period.between(fecha,LocalDate.now());
        System.out.println("Su Edad actual es: " + periodo.getYears());
    }
    public static void ejercicio2(){
        System.out.println("=== EJERCICIO 2 ===");
        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingrese una frase:");
        String frase = scanner.nextLine();
        String modificado = frase.replaceAll(" ","");
        boolean flag = false;
        for(int i = 0 ; i < modificado.length();i++){
            if(modificado.charAt(i) != modificado.charAt(modificado.length()-1-i)){
                flag = true;
            }
        }
        System.out.println(flag ? "No es POLINDROMO" : "Es POLINDROMO");
    }
    public static void ejercicio3(){
        System.out.println("=== EJERCICIO 3 ===");
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese una FRASE: ");
        String frase = scanner.nextLine();
        System.out.print("Ingrese SUB-FRASE Buscada: ");
        // con "contains" verifico si una String pasada por parametro existe en el texto.
        System.out.println(frase.contains(scanner.nextLine()) ? "SUB-FRASE encontrada" : "SUB-FRASE no encontrada");
    }
    public static void ejecicio4(){
        System.out.println("=== EJERCICIO 4 ===");
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese una FRASE: ");
        String frase = scanner.nextLine();
        //pasa la frase a un arreglo
        String[] arregloChar = frase.split(" ");
        //crea un StringBuilder par poder manipular los String vacio
        StringBuilder resultado = new StringBuilder();
        //recorremos el arreglo
        for (String palabra : arregloChar) {
            //si cada elemento contiene un caracter
            if (!palabra.isEmpty()) {
                //el primer caracter lo combierte en mayuscula y lo agrega a Resultado
                resultado.append(Character.toUpperCase(palabra.charAt(0)));
                //despues de la posicion pasada por "substring" lo combierte en minuscula
                resultado.append(palabra.substring(1).toLowerCase());
            }
        }
        System.out.println(resultado.toString());
    }
    public static void ejercicio5(){
        System.out.println("== EJERCICIO 5 ==");
        System.out.println("= ENCONTRAR numero ALEATORIO =");
        Random generador = new Random();
        int random = 1+generador.nextInt(100);
        System.out.println(random);
        System.out.println(game(random) ? "= GANASTE =" : "= PERDISTE =");
    }
    public static int inputNumber(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese un NUMERO: ");
        int num = scanner.nextInt();
        return num;
    }
    public static boolean game(int numero){
        boolean gameOver = false;
        int intentos = 5;
        do{
            int elegido = inputNumber();
            if(!gameOver) {
                if (elegido > numero) {
                    System.out.println("ES ALTO");
                } else {
                    System.out.println("ES BAJO");
                }
            }
            if (numero == elegido) {
                gameOver = true;
                break;
            }
            --intentos;
        }while (intentos != 0);
        return gameOver;
    }
    public static void ejercicio6(){
        System.out.print("== EJERCICIO 6 ==");
        System.out.print("= Elimina VOCAL de tu TEXTO =");
        StringBuilder modificador = new StringBuilder();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingresar TEXTO: ");
        String text = scanner.nextLine();
        System.out.print("Ingresar VOCAL a ELIMINAR: ");
        String vocal = scanner.nextLine();
        String [] arreglo = text.split(vocal);
        for (String i : arreglo){
            modificador.append(i);
        }
        System.out.print("FRASE sin VOCAL: ");
        System.out.println(modificador);

    }
    public static LocalDate ingFecha(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingresar FECHA:");
        System.out.print("  - Año: ");
        int anio = scanner.nextInt();
        System.out.print("  - Mes: ");
        int mes = scanner.nextInt();
        System.out.print("  - Dia: ");
        int dia = scanner.nextInt();
        return LocalDate.of(anio,mes,dia);
    }
    public static void ejercicio7(){
        System.out.println("== EJERCICIO 7 ==");
        System.out.println("= Averiguar dias de DIFERENCIA =");
        System.out.println("- Fecha 1:");
        LocalDate fecha1 = ingFecha();
        System.out.println("- Fecha 2:");
        LocalDate fecha2 = ingFecha();
        System.out.println("Dias de DIFERENCIA: " + (Period.between(fecha1,fecha2).getDays()+
                Period.between(fecha1,fecha2).getMonths()*30+Period.between(fecha1,fecha2).getYears()*365));
    }
    












}