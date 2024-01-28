package PackegaTigerE;

public class Secretaria extends Empleado{
    private int numHoraExtra;

    public Secretaria(String nombre, int edad, int dni, Double salario, int numHoraExtra) {
        super(nombre, edad, dni, salario);
        this.numHoraExtra = numHoraExtra;
    }

    public int getNumHoraExtra() {
        return numHoraExtra;
    }

    public void setNumHoraExtra(int numHoraExtra) {
        this.numHoraExtra = numHoraExtra;
    }

    @Override
    public String toString() {
        return  "---------------------------"+"\n"+
                super.toString() +
                "Num.Horas Extras..: " + numHoraExtra;
    }

    @Override
    public double calcularBonificacion() {
        double hsExtra = this.salario * numHoraExtra;
        double rest = (hsExtra * 0.15);
        return rest;
    }
}
