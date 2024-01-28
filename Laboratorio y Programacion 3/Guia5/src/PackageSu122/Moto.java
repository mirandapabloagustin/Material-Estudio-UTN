package PackageSu122;

public class Moto extends Vehiculo implements Alquilable{
    protected String cilindrada;

    public Moto(String cilindrada, boolean alquilado, String marca, String modelo, Double precio) {
        super(alquilado,marca,modelo,precio);
        this.cilindrada = cilindrada;
    }

    public String getCilindrada() {
        return cilindrada;
    }

    public void setCilindrada(String cilindrada) {
        this.cilindrada = cilindrada;
    }

    @Override
    public String toString() {
        return super.toString() +
                "     = TIPO Moto = \n" +
                "     - Cilindrada.:" + cilindrada + "\n";
    }

    @Override
    public double calcularPrecioAlquiler(int dias) {
        double precio = this.precio * dias;
        return precio;
    }
}
