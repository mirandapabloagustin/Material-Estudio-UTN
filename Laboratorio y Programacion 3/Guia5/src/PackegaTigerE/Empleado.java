package PackegaTigerE;

import PackageAmx_50_100.Persona;

public abstract class Empleado extends Persona {
    protected Double salario;

    public Empleado(String nombre, int edad, int dni, Double salario) {
        super(nombre, edad, dni);
        this.salario = salario;
    }

    public Double getSalario() {
        return salario;
    }

    public void setSalario(Double salario) {
        this.salario = salario;
    }

    public double calcularBonificacion(){
        return 0;
    }

    @Override
    public String toString() {
        return  super.toString()+
                "Salario.: " + salario+"\n";
    }
}
