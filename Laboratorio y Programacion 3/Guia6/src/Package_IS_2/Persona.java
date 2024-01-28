package Package_IS_2;

public class Persona implements Comparable<Persona>{
    protected String nombre;
    protected int edades;

    public Persona(){
    }

    public Persona(String nombre, int edades) {
        this.nombre = nombre;
        this.edades = edades;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getEdades() {
        return edades;
    }

    public void setEdades(int edades) {
        this.edades = edades;
    }

    @Override
    public String toString() {
        return  "----------------------------------------" +"\n"+
                "Nombre..: " + nombre + "\n" +
                "Edades..: " + edades;
    }

    @Override
    public int compareTo(Persona o) {
        return Integer.compare(this.edades,o.edades);
    }
}
