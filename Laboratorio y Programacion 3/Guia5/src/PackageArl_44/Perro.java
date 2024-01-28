package PackageArl_44;

public class Perro extends Animal{
    private String raza;

    public Perro(String raza,String nombre,int edad, int peso) {
        super(nombre,edad,peso);
        this.raza = raza;
    }

    public String getRaza() {
        return raza;
    }

    public void setRaza(String raza) {
        this.raza = raza;
    }

    @Override
    public String toString() {
        return "---------------------------" +"\n"+
                "= TIPO..: Perro =" +"\n"
                +super.toString()+
                "Raza.....: " + raza;
    }

    @Override
    public int compareTo(Animal o) {
        return Integer.compare(this.peso,o.peso);
    }
}
