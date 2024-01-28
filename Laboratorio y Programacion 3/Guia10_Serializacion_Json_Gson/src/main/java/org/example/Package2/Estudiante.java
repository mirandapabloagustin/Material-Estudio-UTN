package org.example.Package2;

import java.io.Serializable;

public class Estudiante implements Serializable {

    private static final long serialVersionUID = 347836247344567213L;
    private String nombre;
    private int dni;
    private String carrera;

    public Estudiante() {
    }

    public Estudiante(String nombre, int dni, String carrera) {
        setNombre(nombre);
        setDni(dni);
        setCarrera(carrera);
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

    public String getCarrera() {
        return carrera;
    }

    public void setCarrera(String carrera) {
        this.carrera = carrera;
    }

    @Override
    public String toString() {
        return "[Nombre: " + nombre + " | DNI: " + dni + " | Carrera: " + carrera + "]";
    }
}

