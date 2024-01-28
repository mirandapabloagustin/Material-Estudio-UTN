
import PackageAmx_50_100.*;
import PackageArl_44.*;
import PackageSdKfz173.*;
import PackageSu122.*;
import PackegaTigerE.Empleado;
import PackegaTigerE.Gerente;
import PackegaTigerE.Secretaria;

import java.util.*;
import java.util.List;


public class Main {
    public static void main(String[] args) {
        System.out.println("== EJERCICIO 1 ==");
        ejer1();
        System.out.println("== EJERCICIO 2 ==");
        ejer2();
        System.out.println("== EJERCICIO 3 ==");
        ejer3();
        System.out.println("== EJERCICIO 4 ==");
        ejer4();
        System.out.println("== EJERCICIO 5 ==");
        ejer5();
    }
    public static void ejer1(){
        Sistema gestion = new Sistema();

        Coche auto1 = new Coche(5,false,"FIAT","Felix",5500.30);
        Coche auto2 = new Coche(5,false,"RENAULT","Break",4500.20);
        Moto moto1 = new Moto("150cc",true,"Honda","CG titan",3500.45);
        Moto moto2 = new Moto("250cc",false,"Yamaha","FAZER",4800.70);

        gestion.getListaCoches().add(auto1);
        gestion.getListaCoches().add(auto2);
        gestion.getListaCoches().add(moto1);
        gestion.getListaCoches().add(moto2);
        gestion.mostrarListado();

        System.out.println("SE ELIMINA UN VEHICULO DE LA LISTA");
        gestion.getListaCoches().remove((gestion.getListaCoches().get(2)));
        gestion.mostrarListado();

        System.out.println("DISPONIBILIDAD VEHICULO:");
        System.out.println(gestion.getListaCoches().get(1).toString());

        System.out.println(gestion.verificarAlquiler(gestion.getListaCoches().get(2))
                ? "DISPONIBLE" : "ALQUILADO");

        Scanner scanner = new Scanner(System.in);
        System.out.print("INGRESE TIEMPO EN DIAS DE ALQUILER:");
        int dias = scanner.nextInt();
        System.out.println("VALOR DEL ALQUILER: "+ auto1.calcularPrecioAlquiler(dias));

    }

    public static void ejer2(){
        System.out.println("= CALCULAR AREA DE OBJETO =");
        Rectangulo rectangulo1 = new Rectangulo(14.5,5.33);
        rectangulo1.calcularArea();
        Circulo circulo1 = new Circulo(5.5);
        circulo1.calcularArea();
    }

    public static void ejer3(){
        List<Persona> listado = new ArrayList<>();
        Persona persona1 = new Persona("Juan",31,7563456);
        Persona persona2 = new Persona("Jorge",34,4563452);
        Persona persona3 = new Persona("German",21,2342345);
        listado.add(persona1);
        listado.add(persona2);
        listado.add(persona3);
        Collections.sort(listado);
        listado.forEach(System.out::println);
    }

    public static void ejer4(){
        List<Animal> listaAnimales = new ArrayList<Animal>();
        Perro animal1 = new Perro("Chihuahua","Demoledor",5,2);
        Perro animal2 = new Perro("Bulldog Fances","Pepino",3,4);
        Perro animal3 = new Perro("Border Collie","Lazy",7,15);
        Gato animal4 = new Gato("Lulu",4,3,"Ceda");
        Gato animal5 = new Gato("Peque",5,5,"Pelusa");
        Gato animal6 = new Gato("Dante",4,3,"Vello");
        listaAnimales.add(animal1);
        listaAnimales.add(animal2);
        listaAnimales.add(animal3);
        listaAnimales.add(animal4);
        listaAnimales.add(animal5);
        listaAnimales.add(animal6);
        listaAnimales.forEach(System.out::println);
        System.out.println("SE ORDENARON SEGUN SU PESO");
        Collections.sort(listaAnimales);
        listaAnimales.forEach(System.out::println);
    }

    public static void ejer5(){
        ArrayList<Empleado> listaEmpleados = new ArrayList<Empleado>();
        Empleado trabajador1 = new Gerente("Jorge",34,22387452,196787.00,"Gerencia");
        Empleado trabajador2 = new Gerente("Juan",31,28476345,145467.00,"Gerencia");
        Empleado trabajador3 = new Gerente("Cesar",45,2387452,221944.00,"Gerencia");
        Empleado trabajador4 = new Secretaria("German",21,2387452,75263.00,18);
        Empleado trabajador5 = new Secretaria("Flor",23,2387452,87346.00,14);
        Empleado trabajador6 = new Secretaria("Belen",24,2387452,77346.00,7);
        listaEmpleados.add(trabajador1);
        listaEmpleados.add(trabajador2);
        listaEmpleados.add(trabajador3);
        listaEmpleados.add(trabajador4);
        listaEmpleados.add(trabajador5);
        listaEmpleados.add(trabajador6);
        listaEmpleados.forEach(System.out::println);

        System.out.println("Bonificacion del Empleado ("+trabajador3.getNombre()+") : "+trabajador3.calcularBonificacion()+"\n"+
                "Salario Total + Bonficacion: "+(trabajador3.getSalario()+trabajador3.calcularBonificacion()));

        System.out.println("Bonificacion del Empleado ("+trabajador5.getNombre()+") : "+trabajador5.calcularBonificacion()+"\n"+
                "Salario Total + Bonficacion + Hs Extra: "+(trabajador5.getSalario()+trabajador5.calcularBonificacion()));
    }
}