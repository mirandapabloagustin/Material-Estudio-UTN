package PackageArl_44;

public abstract class Animal implements Comparable<Animal>{
    protected String nombre;
    protected int edad;
    protected int peso;

    public Animal(String nombre, int edad, int peso) {
        this.nombre = nombre;
        this.edad = edad;
        this.peso = peso;
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

    public int getPeso() {
        return peso;
    }

    public void setPeso(int peso) {
        this.peso = peso;
    }

    @Override
    public String toString() {
        return  "Nombre...: "+ nombre + "\n" +
                "Edad.....: "+ edad +"\n"+
                "Peso.....: "+ peso+"\n";
    }
}
