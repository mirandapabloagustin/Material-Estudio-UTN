package org.example.Package1;
import java.io.Serializable;

public class Materias implements Serializable {
    private static final long serialVersionUID = 2456524564245623454L;
    private String nombre;
    private double nota;

    public Materias(String nombre, double nota) {
        this.nombre = nombre;
        this.nota = nota;
    }

    public Materias() {
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        if (nombre.length() > 0) {
            this.nombre = nombre;
        } else {
            System.out.println("El nombre no puede estar vacio");
        }
    }

    public double getNota() {
        return nota;
    }

    public void setNota(double nota) {
        if (nota >= 0 && nota <= 10) {
            this.nota = nota;
        } else {
            System.out.println("La nota debe estar entre 0 y 10");
        }
    }

    @Override
    public String toString() {
        return  "[ Nombre: " + nombre + " | Nota: " + nota + " ]";
    }
}
