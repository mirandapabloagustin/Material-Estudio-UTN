package com.agus.clases.Estudiante;

public class Materias {
    private float nota;
    private String nombre;
    private String cargaHoraria;
    private String profesor;

    public Materias(float nota, String nombre, String cargaHoraria, String profesor) {
        this.nota = nota;
        this.nombre = nombre;
        this.cargaHoraria = cargaHoraria;
        this.profesor = profesor;
    }
    public Materias() {
    }

    public float getNota(){
        return nota;
    }
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getCargaHoraria() {
        return cargaHoraria;
    }

    public void setNota(float nota){
        this.nota = nota;
    }

    public void setCargaHoraria(String cargaHoraria) {
        this.cargaHoraria = cargaHoraria;
    }

    public String getProfesor() {
        return profesor;
    }

    public void setProfesor(String profesor) {
        this.profesor = profesor;
    }


    @Override
    public String toString() {
        return "\n   - Nombre: " + nombre +
                " |Nota: " + nota +
                " |Carga Horaria: " + cargaHoraria +
                " |Profesor: " + profesor;
    }
}
