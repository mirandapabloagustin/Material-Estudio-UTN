package PackageSdKfz173;

public class Circulo extends FiguraGeometrica{
    protected double radio;

    public Circulo(double radio) {
        this.radio = radio;
    }

    public double getRadio() {
        return radio;
    }

    public void setRadio(double radio) {
        this.radio = radio;
    }

    @Override
    public String toString() {
        return "Circulo{" +
                "radio=" + radio +
                '}';
    }

    @Override
    public void calcularArea() {
        System.out.println("AREA Circulo: "+(Math.PI*Math.pow(this.radio,2)));
    }
}
