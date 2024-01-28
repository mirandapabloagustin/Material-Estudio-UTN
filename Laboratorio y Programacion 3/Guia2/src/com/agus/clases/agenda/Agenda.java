package com.agus.clases.agenda;

public class Agenda {
    private String nombre;
    private String telefono;
    private String email;

    public Agenda(String nombre,String telefono, String email){
        this.nombre = nombre;
        this.telefono = telefono;
        this.email = email;
    }

    public Agenda(){};

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return  "[Nombre :" + nombre +
                " |Telefono :" + telefono +
                " |Email :" + email +
                "]\n";
    }
}
