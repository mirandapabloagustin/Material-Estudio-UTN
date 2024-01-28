package com.agus.PackegeType64;

public class Profesor extends Persona{
    private Materia materia;

    public Profesor(Materia materia) {
        this.materia = materia;
    }

    public Profesor(String nombre, int edad, int dni, Materia materia) {
        super(nombre, edad, dni);
        this.materia = materia;
    }

    public Materia getMateria() {
        return materia;
    }

    public void setMateria(Materia materia) {
        this.materia = materia;
    }

    @Override
    public String toString() {
        return super.toString()+"\n   - Profesor [Materia: " + materia.getNombre() +"]";
    }
}
