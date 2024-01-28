package com.agus.PackegeType64;

import java.util.ArrayList;
import java.util.List;

public class Estudiante extends Persona{
    private String carrera;
    private List<Materia> listaMaterias  = new ArrayList<Materia>();

    public Estudiante(String nombre, int edad, int dni, String carrera,Materia materia) {
        super(nombre, edad, dni);
        this.carrera = carrera;
        listaMaterias.add(materia);
    }

    public String getCarrera() {
        return carrera;
    }

    public void setCarrera(String carrera) {
        this.carrera = carrera;
    }

    private void estudiar(){
        System.out.println("= ESTOY ESTUDIANDO =");
    }

    @Override
    public String toString() {
        return super.toString() + "\n   - Estudiante [Carrera: " + carrera + ']';
    }
}
