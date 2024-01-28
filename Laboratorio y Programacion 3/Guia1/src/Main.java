import javax.swing.*;
import javax.swing.plaf.synth.SynthOptionPaneUI;
import java.awt.*;
import java.util.Arrays;
import java.util.Scanner;
import java.math.*;

public class Main {
        public static void main (String[] args){
        /*
        System.out.println("Ejercicio 1:\n" + "==========================================================");
        System.out.println("Calcular el promedio de un arreglo de números enteros. Realizar\n" +
                "variantes con arreglos ya inicializados e ingreso por teclado:\n");
        System.out.println("    Ejemplo 1:\n"+"==================");
        int[] array1 = {7,5,8};
        System.out.println("Notas : " + Arrays.toString(array1));
        double promedioFinal = promedio(array1.length, suma_array(array1));
        System.out.printf("%nEl Promedio es:  %.2f\n", promedioFinal);
        System.out.println("    Ejemplo 2:\n"+"==================");
        int[] array2;
        array2 = ingresar_notas();
        System.out.println("Notas : "+Arrays.toString(array2));
        double promedioFinal2 = promedio(array2.length, suma_array(array2));
        System.out.printf("%nEl Promedio es:  %.2f\n", promedioFinal2);

        System.out.println("Ejercicio 2:\n" + "==========================================================");
        boolean flag = averiguar_par();
        System.out.println(flag ? "Es Par\n" : "Es Impar\n");

        System.out.println("Ejercicio 3:\n" + "==========================================================");
        mostrar_numeros_primos(100);
        
        System.out.println("Ejercicio 4:\n" + "==========================================================");
        cuantos_primos_quieres();

        System.out.println("Ejercicio 6:\n" + "==========================================================");
        averiguar_primo();

        System.out.println("Ejercicio 7:\n" + "==========================================================");
        int[] array = {1,2,3,4,5,6,7,8,9,10};
        System.out.println("Suma 10 enteros : " + suma_array(array));

        System.out.println("Ejercicio 8:\n" + "==========================================================");
        System.out.println("El valor total de la Suma de Positivos es: " + suma_positivos());

        System.out.println("Ejercicio 9:\n" + "==========================================================");
        averiguar_biciesto();
        System.out.println("Ejercicio 10:\n" + "==========================================================");
        System.out.print("Valor Asci del Caracater Ingresado: " + ascii_valor());

        System.out.println("Ejercicio 11:\n" + "==========================================================");
        System.out.println("Multiplicacion enter dos numeros : " + multiplicacion(5,5) );

        System.out.println("Ejercicio 12:\n" + "==========================================================");
        ejercicio12();

        System.out.println("Ejercicio 13:\n" + "==========================================================");
        ejercicio13();

        System.out.println("Ejercicio 14:\n" + "==========================================================");
        ejercicio14();

        System.out.println("Ejercicio 15:\n" + "==========================================================");
        ejercicio15();

        System.out.println("Ejercicio 16:\n" + "==========================================================");
        ejercicio16();

        System.out.println("Ejercicio 17:\n" + "==========================================================");
        ejercicio17();

        System.out.println("Ejercicio 18:\n" + "==========================================================");
        ejercicio18();
        System.out.println("Ejercicio 19:\n" + "==========================================================");
        ejercicio19();

        System.out.println("Ejercicio 20:\n" + "==========================================================");
        ejercicio20();
        System.out.println("Ejercicio 21:\n" + "==========================================================");
        ejercicio21();
        */

        System.out.println("Ejercicio 22:\n" + "==========================================================");
        calculadoraPolacaInversaApp();

    }

    public static int suma_array(int[] array){
        int total = 0;
        for(int i : array){
            total +=i;
        }
        return total;
    }

    public static double promedio(int num, int total){

        return (double) total / num;
    }

    public static int[] ingresar_notas() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese el número de notas: ");

        int numNotas = scanner.nextInt();
        int[] array = new int[numNotas];

        for (int i = 0; i < numNotas; i++) {
            System.out.print("Ingrese notas: ");
            array[i] = scanner.nextInt();
        }
        scanner.close();
        return array;
    }

    public static boolean averiguar_par(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese un numero: ");
        int num = scanner.nextInt();
        scanner.close();
        return num % 2 == 0;
    }

    public static boolean es_primo(int num) {
        // El 0, 1 y 4 no son primos
        if (num == 0 || num == 1 || num == 4) {
            return false;
        }
        for (int x = 2; x < num / 2; x++) {
            // Si es divisible por cualquiera de estos números, no
            // es primo
            if (num % x == 0)
                return false;
        }
        // Si no se pudo dividir por ninguno de los de arriba, sí es primo
        return true;
    }

    public static void mostrar_numeros_primos(int num){
        System.out.print("Numeros Primos: [");
        boolean flag;
        int contador = 0;
        int i=0;
        while(contador < num){
            flag = es_primo(i);
            if(flag){
                contador++;
                System.out.print(i + "-");
            }
            i++;
        }
        System.out.println("]");
    }

    public static void cuantos_primos_quieres(){
        System.out.println("Indique la Cantidad de numeros primos a mostrar: ");
        Scanner scanner = new Scanner(System.in);
        int cantidad = scanner.nextInt();
        mostrar_numeros_primos(cantidad);
    }

    public static void averiguar_primo(){
        Scanner scanner = new Scanner(System.in);
        int num = 0;
        boolean flag;
        int opcion = 1;
        while(opcion == 1){
            System.out.print("Ingrese un numero: ");
            num = scanner.nextInt();
            flag = es_primo(num);
            System.out.println(flag ? "Es Primo\n" : "No es Primo\n");
            System.out.print("Desea continuar (1 = Si / 0 = No) : ");
            opcion = scanner.nextInt();
        }
        scanner.close();
    }

    public static boolean es_positivos(int num){
        return num >= 0;
    }

    public static int suma(int num1 , int num2){
        return num1+num2;
    }

    public static int suma_positivos(){
        int opcion= 1;
        boolean flag;

        Scanner scanner = new Scanner(System.in);
        int num =0;
        int total = 0;
        while(opcion == 1 ){
            System.out.print("Ingrese un numero: ");
            num =scanner.nextInt();
            flag = es_positivos(num);
            if (flag){
                total = suma(total,num);
            }
            System.out.print("Desea continuar (1=SI / 0=NO) : ");
            opcion = scanner.nextInt();
        }
        return total;
    }

    public static boolean es_biciesto(int num){
        return (num > 365);
    }

    public static void averiguar_biciesto(){
        System.out.print("Ingrese cantidad de Dias que tuvo el Año: ");
        Scanner scanner =new Scanner(System.in);
        int num =scanner.nextInt();
        boolean flag = es_biciesto( num );
        System.out.println((flag) ? "Es Biciesto" : "No es Biciesto");
        scanner.close();
    }

    public static int ascii_valor(){
        System.out.print("Ingrese un caracter :");
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        char caracter = input.charAt(0);
        scanner.close();
        return caracter;
    }

    public  static int multiplicacion(int num1, int num2){
        return num1*num2;
    }

    public static int perimetro_rectangulo(int largo,int alto){
        return 2*(largo + alto);
    }
    public static int perimetro_cuadrado(int lado) {
        return lado*4;
    }

    public static double perimetro_circulo(double radio){
        return 2*(3.14 * radio);
    }
    public static int perimetro_triangulo(int lado1,int lado2,int lado3){
        return (lado1+lado2+lado3);
    }

    public static void ejercicio12(){
        System.out.print("MENU CALCULSO PARA VAGOS\n" + "========================\n");
        System.out.print("1] Areá Rectangulo\n" + "2] Areá Cuadrado\n" + "3] Areá Circulo\n"
                + "4] Areá Triangulo\n");
        System.out.print("ingrese una Opcion: ");
        Scanner scanner = new Scanner(System.in);
        int opc = scanner.nextInt();
        switch (opc){
            case 1:
                System.out.print("Ingrese largo: ");
                int largo = scanner.nextInt();
                System.out.print("Ingrese alto: ");
                int alto = scanner.nextInt();
                System.out.print("El perimetro del Rectangulo: " + perimetro_rectangulo(largo,alto));
                break;
            case 2:
                System.out.print("Ingrese largo lado: ");
                int lado = scanner.nextInt();
                System.out.println("El perimetro del Cuadrado :"+ perimetro_cuadrado(lado));
                break;
            case 3:
                System.out.print("Ingrese Radio: ");
                int radio = scanner.nextInt();
                System.out.println("El perimetro del Circulo : " + perimetro_circulo(radio));
                break;
            case 4:
                System.out.print("Ingrese Lado1: ");
                int lado1 =scanner.nextInt();
                System.out.print("Ingrese Lado2: ");
                int lado2 =scanner.nextInt();
                System.out.print("Ingrese Lado3: ");
                int lado3 =scanner.nextInt();
                System.out.println("El perimetro del Triangulo : " + perimetro_triangulo(lado1,lado2,lado3));
                break;


        }

    }

    public static void ejercicio13(){
        String nombre = JOptionPane.showInputDialog("ingrese Nombre:");
        JOptionPane.showMessageDialog(null,"Buenos Dias " + nombre);
    }

    public static void ejercicio14(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Multiplicador Enteros:\n"+"Ingrese un Numero: ");
        int num = scanner.nextInt();
        System.out.println("1] Mostrar el Doble de " + num);
        System.out.println("2] Mostrar el Triple de " + num);
        System.out.println("- Elija Opcion: ");
        int opc = scanner.nextInt();
        switch (opc){
            case 1:
                System.out.println("El Doble de " + num+ " es: "+ (num+num));
                break;
            case 2:
                System.out.println("El Triple de " + num+ " es: "+ ((2*num)+num));
                break;
        }

    }

    public static int fahrenheitCalculo(int centigrados){
        return 32+((9*centigrados)/5);
    }

    public static void ejercicio15(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("CONVERTIDOR FAHRENHEIT:");
        System.out.print("Ingrese cantidad de Centigrados a convertir: ");

        int grados = scanner.nextInt();
        System.out.println("Grados en Fahrenheit:  = " + fahrenheitCalculo(grados));
        scanner.close();

    }

    public static double areaCirculo(double radio){
        double pi = Math.PI;
        return Math.pow((radio*pi),2);
    }


    public static void ejercicio16(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese Radio de Circulo : ");
        double radio = scanner.nextInt();
        System.out.println("Longitud Circulo : " + (float) perimetro_circulo(radio));
        System.out.println("Areá Circulo : " + (float) areaCirculo(radio));
    }
    //---------------- METODOS EJERCICIO 17 -------------------------

    public static double kilometrosMetros(double num){
        return (num*1000.00);
    }
    public static void ejercicio17(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("CONVERTIDOR Km/h a m/s:");
        System.out.print("Ingrese km/h a convertir: ");
        double km = scanner.nextDouble();
        System.out.println("En m/s : " + kilometrosMetros(km));
    }

    //---------------- METODOS EJERCICIO 18 -------------------------
    public static double hipotenusa(int lado1, int lado2){
        double valor = Math.pow(lado1,2) + Math.pow(lado2,2);
        return Math.sqrt(valor);
    }
    public static void ejercicio18(){
        Scanner scan = new Scanner(System.in);
        System.out.println("CALCULO DE HIPOTENUSA");
        System.out.print("Ingrese lado 1: ");
        int lado1 = scan.nextInt();
        System.out.print("Ingrese lado 2: ");
        int lado2 = scan.nextInt();
        scan.close();
        System.out.println("Hipotenusa del Triangulo : " + hipotenusa(lado1,lado2));
    }

    //---------------- METODOS EJERCICIO 19 -------------------------
    public static double[] temperaturasMensuales(){
        double[] array = new double[2];
        Scanner scan = new Scanner(System.in);

        for(int i =0 ; i < array.length; i++){
            System.out.print("Ingrese Temperatura Mes " +(i+1) + ": ");
            array[i] = scan.nextDouble();
        }
        scan.close();
        return array;
    }

    public static double maximoTemp(double[] array){
        double maximo = array[0];
        for (double i : array){
            if(maximo < i){
                maximo = i;
            }
        }
        return maximo;
    }
    public static double minimoTemp(double[] array){
        double minimo = array[0];
        for (double i : array){
            if(minimo > i){
                minimo = i;
            }
        }
        return minimo;
    }
    public static double promedioTemp(double[] array){
        double total = 0;
        for (int i = 0 ; i < array.length;i++){
            total += array[i];
        }
        return total / array.length;
    }
    public static void ejercicio19() {
        double [] tempMensual = temperaturasMensuales();
        System.out.println("La temperatura Minima del Mes: "+ minimoTemp(tempMensual) + " - Maxima del mes "
                + maximoTemp(tempMensual));
        System.out.println("Promedio temperatura Mensual: "+ promedioTemp(tempMensual));
    }

    // ---------------- METODOS EJERCICIO 20 -------------------------
    public static int[] numAletorios(int min,int max){
        int[] array = new int[10];
        int random;
        int i = 0;
        while( i < array.length){
            random = (int) (Math.random()*10);
            if((random >= min && random <= max)) {
                array[i] = random;
                i++;
            }
        }
        return array;
    }
    public static void ejercicio20(){
        Scanner scan = new Scanner(System.in);
        System.out.println("ALEATORIOS DENTRO DE LIMITE:");
        System.out.print("Ingrese Numero Minimo:");
        int num1 = scan.nextInt();
        System.out.print("Ingrese Numero Maximo:");
        int num2 = scan.nextInt();
        int[] array = numAletorios(num1,num2);
        System.out.println(Arrays.toString(array));

    }


    //---------------- METODOS EJERCICIO 21 -------------------------
    public static void ejercicio21(){
            Scanner scan = new Scanner(System.in);
        System.out.println("HOY ME TOCA TRABAJAR? : ");
        System.out.println("1] Lunes");
        System.out.println("2] Martes");
        System.out.println("3] Miercoles");
        System.out.println("4] Jueves");
        System.out.println("5] Viernes");
        System.out.println("6] Sabado");
        System.out.println("7] Domingo");
        System.out.println("Elija una opcion :");
        int opc = scan.nextInt();
        switch (opc){
            case 1,2,3,4,5:
                System.out.println("Es el Peor dia de la Semana, Dia laboral.");
                break;
            case 6,7:
                System.out.println("Vamaaaaaaa! Tu cuerpo lo sabe, Dia no laboral");
                break;
            default:
                System.out.println("¿Seguis de gira? Volve a intentarlo");
        }
    }

    //---------------- METODOS EJERCICIO 22 -------------------------
    public  static int inputNum(){
            int num = Integer.parseInt(JOptionPane.showInputDialog("Ingrese valor:"));
            return num;
    }
    public static int resta(int num1,int num2){return num1-num2;}
    public static double divicion(double num1,double num2){return num1/num2;}
    public static double modulo(double num1,double num2){return num1%num2;}
    public static void selector(int opcion) {
        int total = 0;
        double total2 = 0;
        int num1 = inputNum();
        int num2 = inputNum();
        switch (opcion + 1) {
            case 1:
                total = suma(num1, num2);
                JOptionPane.showMessageDialog(null, num1 + " + " + num2 + " :\nRespuesta : " +
                        total, "CalculadoraPolacaInversaApp", JOptionPane.WARNING_MESSAGE);
                break;
            case 2:
                total = resta(num1, num2);
                JOptionPane.showMessageDialog(null, num1 + " - " + num2 + " :\nRespuesta : " +
                        total, "CalculadoraPolacaInversaApp", JOptionPane.WARNING_MESSAGE);
                break;
            case 3:
                total = multiplicacion(num1, num2);
                JOptionPane.showMessageDialog(null, num1 + " * " + num2 + " :\nRespuesta : " +
                        total, "CalculadoraPolacaInversaApp", JOptionPane.WARNING_MESSAGE);

                break;
            case 4:
                total2 = divicion(num1, num2);
                JOptionPane.showMessageDialog(null, num1 + " / " + num2 + " :\nRespuesta : " +
                        total2, "CalculadoraPolacaInversaApp", JOptionPane.WARNING_MESSAGE);
                break;
            case 5:
                total = (int) Math.pow(num1, num2);
                JOptionPane.showMessageDialog(null, num1 + " ^ " + num2 + " :\nRespuesta : " +
                        total, "CalculadoraPolacaInversaApp", JOptionPane.WARNING_MESSAGE);
                break;
            case 6:
                total2 = modulo(num1, num2);
                JOptionPane.showMessageDialog(null, num1 + " % " + num2 + " :\nRespuesta : " +
                        total2, "CalculadoraPolacaInversaApp", JOptionPane.WARNING_MESSAGE);
                break;
        }
    }
    public static void calculadoraPolacaInversaApp(){
        int opc = 0;
        String[] botones = {"Suma","Resta","Multiplicacion","Division","Exponente","Modulo","SALIR"};
        while(6 != opc){
            opc = JOptionPane.showOptionDialog(null, "Bienvenido a la calculadora para Vagos\nSelecione una Opcion:",
                "CalculadoraPolacaInversaApp",JOptionPane.DEFAULT_OPTION,JOptionPane.QUESTION_MESSAGE,null,botones,botones[0]);
            if(6 != opc) {selector(opc);}
        }
        JOptionPane.showMessageDialog(null,"NOS VEMOS");
    }






}






