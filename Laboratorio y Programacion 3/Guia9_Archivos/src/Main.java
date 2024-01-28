import javax.swing.*;
import java.io.*;
import java.util.Scanner;
        public class Main {
            public static void main(String[] args) {
        /*
        EJERCICIO 1:
        Crea un fichero de texto con el nombre y contenido que tú desees. Por ejemplo, Ejercicio1.txt
        Realiza un programa en Java que lea el fichero <<Ejercicio1.txt>> carácter a carácter y muestre
        su contenido por pantalla  sin espacios.
        Por ejemplo, si el fichero contiene el siguiente texto “Hola que haces”, deberá mostrar “Holaquehaces”.
         */
                System.out.println("== EJERCICIO 1 ==");
                ejer1();
                System.out.println("\n===================================");
        /*
        EJERCICIO 2:
        Realiza un programa en Java donde introduzcas la ruta de un fichero por teclado y un texto que queramos
        a escribir en el fichero con JOptionPane.showInputDialog
        Posteriormente, muestra el contenido del fichero.
         */
                System.out.println("== EJERCICIO 2 ==");
                ejerc2();
                System.out.println("\n===================================");
        /*
        EJERCICIO 3:
        Realiza un programa en Java donde introduzcas la ruta de un fichero a través del paso de parámetros
        y te indique si el fichero existe o de lo contrario no existe.
        Si faltan argumentos en el main() se debe mostrar un mensaje indicándolo.
        Posteriormente mostrar el número de caracteres del fichero.
         */
                System.out.println("== EJERCICIO 3 ==");
                ejer3();
                System.out.println("\n===================================");
            }
            public static void ejer1(){
                File archivo = new File("src\\Ejercicio1\\texto_Ejercicio.txt");
                try {
                    FileReader lector = new FileReader(archivo);

                    while (lector.ready()){
                        char caracter = (char) lector.read();
                        if (caracter != ' '){
                            System.out.print(caracter);
                        }
                    }
                }catch (FileNotFoundException e){
                    System.out.println("El archivo no existe");
                } catch (IOException e) {
                    System.out.println("Hubo un problema : \n" + e.getMessage());
                }
            }

            /// region "Ejercicio 2"
            public static File crearRuta() throws NullPointerException{
                Scanner sc = new Scanner(System.in);
                String ruta = JOptionPane.showInputDialog("Introduce la ruta del archivo: ");
                String introRuta = "src\\Ejercicio2\\";
                StringBuilder sb = new StringBuilder(introRuta);
                sb.append(ruta);
                File archivo = new File(sb.toString());
                return archivo;
            }

            public static void escribir(File archivo) throws FileNotFoundException, IOException {
                FileWriter escritor = new FileWriter(archivo);
                String texto = JOptionPane.showInputDialog("Introduce el texto a escribir: ");
                escritor.write(texto);
                escritor.close();
            }

            public static void leer(File archivo) throws FileNotFoundException, IOException {
                FileReader lector = new FileReader(archivo);
                while (lector.ready()){
                    char caracter = (char) lector.read();
                    System.out.print(caracter);
                }
                lector.close();
            }
            public static  void ejerc2(){
                try {
                    File archivo = crearRuta();
                    escribir(archivo);
                    leer(archivo);
                }catch (NullPointerException e){
                    System.out.println("No se ha introducido ninguna ruta");
                }catch (FileNotFoundException e){
                    System.out.println("El archivo no existe");
                } catch (IOException e) {
                    System.out.println("Hubo un problema : \n" + e.getMessage());
                }
            }

            /// endregion

            public static void ejer3(){
                Scanner scan = new Scanner(System.in);
                String ruta = JOptionPane.showInputDialog("Introduce la ruta del archivo: \n " +
                        "Ejemplo: \nsrc\\\\Ejercicio3\\\\texto_Ejercicio.txt");
                File archivo = new File(ruta);
                int contador = 0;
                try {
                    if(archivo.exists()){
                        FileReader lector = new FileReader(archivo);
                        while (lector.ready()){
                            char caracter = (char) lector.read();
                            contador++;
                        }
                        lector.close();
                    }else{
                        throw new FileNotFoundException();
                    }
                }catch (FileNotFoundException e){
                    System.out.print("El archivo no existe");
                }catch (IOException e){
                    System.out.print("Hubo un problema : \n" + e.getMessage());
                }finally {
                    System.out.print("El archivo tiene " + contador + " caracteres");
                }
            }


        }