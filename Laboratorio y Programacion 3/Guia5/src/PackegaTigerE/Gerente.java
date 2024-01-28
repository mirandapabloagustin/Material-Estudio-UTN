package PackegaTigerE;

public class Gerente extends Empleado{
    private String departamento;

    public Gerente(String nombre, int edad, int dni, Double salario, String departamento) {
        super(nombre, edad, dni, salario);
        this.departamento = departamento;
    }

    public String getDepartamento() {
        return departamento;
    }

    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }

    @Override
    public String toString() {
        return  "---------------------------"+"\n"+
                super.toString()+
                "Depto...: " + departamento;
    }

    @Override
    public double calcularBonificacion() {
        double rest = (this.salario * 0.30);
        return rest;
    }
}
