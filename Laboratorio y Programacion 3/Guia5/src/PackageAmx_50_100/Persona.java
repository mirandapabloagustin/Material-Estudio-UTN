package PackageAmx_50_100;

public class Persona implements Comparable<Persona>{
    protected String nombre;
    protected int edad;
    protected  int dni;

    public Persona() {
    }

    public Persona(String nombre, int edad, int dni) {
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
        return  "Nombre..: " + nombre + "\n" +
                "Edad....: " + edad + "\n"+
                "Dni.....: " + dni+ "\n";
    }

    @Override
    public int compareTo(Persona pibeCualquiera) {
        return Integer.compare(this.edad,pibeCualquiera.edad);
    }
}
