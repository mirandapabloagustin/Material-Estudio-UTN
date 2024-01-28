package PackageSu122;

public abstract class Vehiculo {
    protected String marca;
    protected String modelo;
    protected double precio;
    protected boolean alquilado;

    public Vehiculo(boolean alquilado,String marca, String modelo, double precio) {
        this.alquilado = alquilado;
        this.marca = marca;
        this.modelo = modelo;
        this.precio = precio;
    }


    @Override
    public String toString() {
        return "== DETALLES VEHICULO ==\n" +
                "     - Marca......:" + marca + "\n"+
                "     - Modelo.....:" + modelo + "\n"+
                "     - Precio.....:" + precio+"\n"+
                "     - Alquilado..:" + alquilado + "\n";
    }
}
