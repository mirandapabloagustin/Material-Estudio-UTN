package com.agus.clases;

public class Cuenta {
    private double saldo;
    private String titular;

    public Cuenta(double saldo, String titular){
        this.saldo = saldo;
        this.titular = titular;
    }
    public Cuenta(){
    }

    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public String getTitular() {
        return titular;
    }

    public void setTitular(String titular) {
        this.titular = titular;
    }

    public void depositar (double deposito){
        this.saldo += deposito;
    }
    public void retiro (double retirar){
        this.saldo -= retirar;
    }

    public double consulta(){return this.saldo;}

    public void encargado(double monto){
        double intereces = monto * 0.17;
        System.out.println("Monto de invencion: "+monto+"\nMonto Total con intereses a Retirar: " + (monto+intereces));
    }

    
    @Override
    public String toString() {
        return "Cuenta [" +
                "Titular:" + titular +
                " ; Saldo:'" + saldo + '\'' +
                ']';
    }
}


