package PackageSu122;

public class Coche extends Vehiculo implements Alquilable{
    private int numPuertas;

    public Coche(int numPuertas, boolean alquilado, String marca, String modelo, Double precio) {
        super(alquilado,marca,modelo,precio);
        this.numPuertas = numPuertas;
    }

    public int getNumPuertas() {
        return numPuertas;
    }

    public void setNumPuertas(int numPuertas) {
        this.numPuertas = numPuertas;
    }

    @Override
    public double calcularPrecioAlquiler(int dias) {
        double precio =  this.precio * dias;
        return precio;
    }

    @Override
    public String toString() {
        return super.toString() +
                "     = TIPO Coche = \n" +
                "     - NumPuertas.:" + numPuertas + "\n";
    }
}
