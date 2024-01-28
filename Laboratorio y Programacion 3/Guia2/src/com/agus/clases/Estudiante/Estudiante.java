package com.agus.clases.Estudiante;

import java.util.ArrayList;

public class Estudiante {
    private String nombre;
    private int edad;
    private float promedio;
    private ArrayList<Materias> materiasAprobadas = new ArrayList<Materias>();

    public Estudiante() {
    }

    public Estudiante(String nombre, int edad, float promedio, ArrayList<Materias> materiasAprobadas) {
        this.nombre = nombre;
        this.edad = edad;
        this.promedio = promedio;
        this.materiasAprobadas = materiasAprobadas;
    }
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public float getPromedio() {
        return promedio;
    }

    public void setPromedio(float promedio) {
        this.promedio = promedio;
    }

    public ArrayList<Materias> getMateriasAprobadas() {
        return materiasAprobadas;
    }

    public void setMateriasAprobadas(ArrayList<Materias> materiasAprobadas) {
        this.materiasAprobadas = materiasAprobadas;
    }

    public void agregarMateriaAprobada(Materias materia) {
        materiasAprobadas.add(materia);
        promedio = actualizarPromedio();
    }

    private float actualizarPromedio() {
        float total =0;
        for (Materias i: materiasAprobadas){
            total += i.getNota();
        }
        return total/ materiasAprobadas.size();
    }


    @Override
    public String toString() {
        return "\nEstudiante[" +
                "Nombre: " + nombre +
                "|Edad: " + edad +
                "|Promedio: " + promedio +
                "|Materias Aprovadas: " + materiasAprobadas;
    }
}
