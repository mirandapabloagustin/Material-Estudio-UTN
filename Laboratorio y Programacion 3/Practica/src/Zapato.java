import java.io.Serializable;

public class Zapato implements Serializable {
    private double talle;
    private transient String marca;
    private transient static final long serialVersionUID = 34897723462L;

    public Zapato(double talle, String marca) {
        this.talle = talle;
        this.marca = marca;
    }

}

