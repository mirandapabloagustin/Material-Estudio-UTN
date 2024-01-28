import Package_IS_2.Persona;
import Packeg_T_44.Persona2;
import Packeg_T_44.Sistema;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        /*
        * COLECCTION JAVA:
        *
        * INTERFACES SON:                              IMPREMENTAN LAS CLASES:
        *
        *         - LIST            --------------->           - ARRAYLIST
        *                            '------------->           - LINKEDLIST
        *
        *         - QUEUE           --------------->           - PRIORITYQUEUE
        *
        *         - SET             --------------->           - HASHSET
        *
        *         - MAP             --------------->           - HASHMAP
        */

        System.out.println("= EJERCICIO 1 =");
        ejer1();

        System.out.println("= EJERCICIO 2 =");
        ejer2();

        System.out.println("= EJERCICIO 3 =");
        ejer3();

        System.out.println("= EJERCICIO 4 =");
        ejer4();

        System.out.println("= EJERCICIO 5 =");
        ejer5();

        System.out.println("= EJERCICIO 6 =");
        ejer6();
    }
    public static String inputString(){
        System.out.print("Ingrese Texto: ");
        Scanner scan = new Scanner(System.in);
        String text = scan.nextLine();
        return text;
    }
    public static void ejer1(){
        //Usuario ingresa un texto
        String textoUsuario = inputString();

        //creo una HASHMAP donde asigamos la KEY(CHAR - CARACTER) y el valor(INT - CANT.VECES ENCONTRADO)
        HashMap<Character,Integer> listaCaracteres = new HashMap<Character,Integer>();

        // 1 - Convertimos el texto ingresado por el USUARIO en una matriz de caracteres con el metodo toCharArray
        // 2 - recorremos esta matriz con un For Each
        for(char letra : textoUsuario.toCharArray()){
            // 3 - con el METODO containsKey verificamos si ya existe en la lista de KEYS
            if(listaCaracteres.containsKey(letra)){
                // 4 - guardamos en un variable el VALOR
                int valorKey = listaCaracteres.get(letra);
                // 5 - modificamos el VALOR aumentandolo
                listaCaracteres.put(letra,valorKey+1);
            }else{
                // 6 - si el caracter no existe lo agregamos y le asignamos 1 como valor
                listaCaracteres.put(letra,1);
            }
        }

        // Pasamos cada KEY y VALOR a un Map.Entry que permite verlo pasandole cada valor con el entrySet a la lista
        for(Map.Entry<Character,Integer> entrada : listaCaracteres.entrySet()){

            System.out.println("  - Char..: "+entrada.getKey()+" |Cant.Veces..: "+entrada.getValue());

        }

    }
    public static int generarAleatorio(){
        return  (int) (Math.random() *100);
    }
    public static void ejer2(){
        List<Integer> numeros = new ArrayList<Integer>();
        //cargamos la lista con numeros aleatorios
        for(int i =0; i<50 ;i++){
            numeros.add(generarAleatorio());
        }
        //ordenamos la lista de numeros
        Collections.sort(numeros);
        //mostramos la lista
        System.out.println(numeros.toString());
        //guardamos en un hashmap para no repetir resultados
        HashSet<Integer> listado = new HashSet<>();
        for(Integer i : numeros){
            listado.add(i);
        }
        //mostramos el contenido de Hashset
        for (Integer i : listado){
            System.out.print(i+" ");
        }
    }

    public static void ejer3(){
        List<Persona> listaPersonas = new ArrayList<Persona>();

        Persona persona1 = new Persona("Agustin",28);
        Persona persona2 = new Persona("Juan",32);
        Persona persona3 = new Persona("Belen",25);
        Persona persona4 = new Persona("Emiliano",23);
        listaPersonas.add(persona1);
        listaPersonas.add(persona2);
        listaPersonas.add(persona3);
        listaPersonas.add(persona4);

        //Entre los parentesis de la declaracion del TreeMap se coloca la especificacion para el Lambda
        //definiremos  como se van a ordenar los elementos usandose el compareTo
        TreeMap<Persona, Object> cargaPersonas = new TreeMap<>((p1,p2) -> p1.compareTo(p2));

        //Se carga en la TreeMap los elementos de la lista segun las edades
        for(Persona i : listaPersonas){
            cargaPersonas.put(i,null);
        }
        // Pasamos cada KEY y VALOR a un Map.Entry que permite verlo pasandole cada valor con el entrySet a la lista
        for(Map.Entry<Persona,Object> entidades : cargaPersonas.entrySet()){
            System.out.println(entidades.getKey().toString());
        }


    }
    public static void ejer4(){
        ArrayList<Integer> listaNumeros = new ArrayList<Integer>();
        for(int i =0; i < 10; i++){
            listaNumeros.add(generarAleatorio());
        }
        System.out.print(listaNumeros.toString());

        // Creamos una variable suma que va a guardar toda la sumatoria del metodo Stream
        // .maoToInt se va a encargar de convertir todos los numeros en numeros enteros
        // isamos el .sum de la clase IntStream para realizar la sumatoria de todos los numeros
        int suma =listaNumeros.stream()
                        .mapToInt(Integer::intValue)
                        .sum();
        System.out.println("\nSumatoria con Sream: "+ suma +" | Promedio: "+(suma/listaNumeros.size()));



        HashMap<Integer,Integer> frecuencia = new HashMap<Integer,Integer>();
        for (Integer i : listaNumeros) {
            if(frecuencia.containsKey(i)){
                int valor = listaNumeros.get(i);
                frecuencia.put(i,valor+1);
            }else{
                frecuencia.put(i,1);
            }
        }

        for (Map.Entry<Integer,Integer> entidades : frecuencia.entrySet()){
            System.out.println("  - [Key..: "+entidades.getKey()+" | Valor..: " +entidades.getValue()+"]");
        }



    }

    public static void ejer5(){
        List<Integer> listaNumeros = new ArrayList<Integer>();
        for(int i =0; i < 20; i++){
            listaNumeros.add(generarAleatorio());
        }
        System.out.println(listaNumeros.toString());

        // CREAMOS UN TREESET Y GUARDAMOS CADA VALOR DE LA LISTA
        // Cuando indicamos el tipo de dato, automaticamente el TREESET se encarga de guardarlos por orden ACENDENTE
        TreeSet <Integer> nums = new TreeSet<>();
        for (Integer i : listaNumeros){
            nums.add(i);
        }
        //Mostramos los elementos de TREESET
        System.out.println("= ELEMENTOS EN FORMA ACENDENTE =");
        for(Integer i : nums){
            System.out.print(i+"-");
        }

        //Creamos un ITERADOR DECENDENTE en base al arbol de elementos
        Iterator <Integer> iteradorDesendente = nums.descendingIterator();

        // "iteradorDesendente.hasNext" es lo mismo que decir que mientras el Iterador no allá llegado al final
        // siga iterando entre los elementos
        while (iteradorDesendente.hasNext()){
            //indicamos que valor va a obtener el contenido del siguente elemento de la lista
            int valor = iteradorDesendente.next();
            System.out.println(valor+"-");
        }

    }

    public static void ejer6(){
        Sistema gestion = new Sistema();
        ArrayList<Persona2> lista = new ArrayList<Persona2>();
        lista.add(new Persona2("Jorge",34,45763324));
        lista.add(new Persona2("German",24,45633456));
        lista.add(new Persona2("Belen",25,46784234));
        lista.add(new Persona2("Cesar",45,49385624));
        lista.forEach(System.out::println);

        gestion.agregarLista(lista,gestion.getMapNumeros());
        System.out.println("\n= MUESTRAS HASH MAP CON LOS ELEMENTOS DE LA LISTA =");
        gestion.muestraMap(gestion.getMapNumeros());

        System.out.println("\n= SE MODIFICO UN ELEMENTO =");
        Persona2 user = new Persona2("Joaquin",21,45633456);
        gestion.modificar(user);
        gestion.muestraMap(gestion.getMapNumeros());
        
        System.out.println("\n= SE ORDENAMIENTO DE LOS ELEMENTO =");
        HashMap<Integer,Persona2> nuevaMap = gestion.ordenamientoHashMap();
        gestion.muestraMap(nuevaMap);

    }
}