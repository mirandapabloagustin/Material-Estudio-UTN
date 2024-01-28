package PackageArl_44;

public class Gato extends Animal{
    protected String pelaje;

    public Gato(String nombre, int edad, int peso, String pelaje) {
        super(nombre, edad, peso);
        this.pelaje = pelaje;
    }

    public String getPelaje() {
        return pelaje;
    }

    public void setPelaje(String pelaje) {
        this.pelaje = pelaje;
    }
    @Override
    public String toString() {
        return "---------------------------" +"\n"+
                "= TIPO..: Gato =" +"\n"+
                super.toString()+
                "Pelaje...: " + pelaje;
    }

    @Override
    public int compareTo(Animal o) {
        return Integer.compare(this.peso,o.peso);
    }
}
