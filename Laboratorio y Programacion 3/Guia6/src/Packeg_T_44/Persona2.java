package Packeg_T_44;

public class Persona2 {
    protected String nombre;
    protected int edad;
    protected int dni;

    public Persona2(){
    }

    public Persona2(String nombre, int edad, int dni) {
        this.nombre = nombre;
        this.edad = edad;
        this.dni = dni;
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

    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    @Override
    public String toString() {
        return  "  - Nombre..: " + nombre+ "\n"+
                "  - Edad....: " + edad+ "\n"+
                "  - Dni.....: " + dni;
    }
}
