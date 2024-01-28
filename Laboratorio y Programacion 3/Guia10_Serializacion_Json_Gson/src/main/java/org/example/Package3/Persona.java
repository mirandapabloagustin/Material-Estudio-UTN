package org.example.Package3;

import java.io.Serializable;

public class Persona implements Serializable {
    private static final long serialVersionUID = 2456567865745343433L;

    private String nombre;
    private int dni;
    private int edad;

    public Persona() {
    }

    public Persona(String nombre, int dni, int edad) {
        setNombre(nombre);
        setDni(dni);
        setEdad(edad);
    }


    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    @Override
    public String toString() {
        return "[Nombre: " + nombre + " | DNI: " + dni + " | Edad: " + edad + "]";
    }
}
