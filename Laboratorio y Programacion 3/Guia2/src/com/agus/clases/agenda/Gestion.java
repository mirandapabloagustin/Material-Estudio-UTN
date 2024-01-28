package com.agus.clases.agenda;
import java.util.ArrayList;
import java.util.Scanner;


public class Gestion {
    public static Agenda crearContacto(){
        Scanner scanner = new Scanner(System.in);

        System.out.print("Ingrese Nombre....: ");
        String nombre = scanner.nextLine();

        System.out.print("Ingrese Telefono..: ");
        String telefono = scanner.nextLine();

        System.out.print("Ingrese Email.....: ");
        String email = scanner.nextLine();

        Agenda contacto = new Agenda(nombre,telefono,email);

        return contacto;
    }
    public static void modificarContacto(Agenda contacto){
        Scanner scanner = new Scanner(System.in);

        System.out.print("Ingrese Nuevo Nombre....: ");
        contacto.setNombre(scanner.nextLine());

        System.out.print("Ingrese Nuevo Telefono..: ");
        contacto.setTelefono(scanner.nextLine());

        System.out.print("Ingrese Nuevo Email.....: ");
        contacto.setEmail(scanner.nextLine());
    }
    public static void agregarContacto(Agenda contacto,ArrayList<Agenda>lista) {
        lista.add(contacto);
    }
    public static void borrarContacto(int posicion,ArrayList<Agenda>lista){
        lista.remove(posicion);
    }
    public static String inputString(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese Nombre: ");
        String nombre = scanner.nextLine();
        return nombre;
    }
    public static int altaContacto(String nombre,ArrayList<Agenda>lista){
        String _nombre;
        int pos = -1;
        for(int i = 0; i < lista.size();i++){
            _nombre = lista.get(i).getNombre();
            if(_nombre.equalsIgnoreCase(nombre)){
                pos = i;
            }
        }
        return pos;
    }
}



