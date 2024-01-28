package Estucturas;

import javax.swing.plaf.basic.BasicTreeUI;
import java.util.ArrayList;

public class Pila <E> {
    private E elemento;
    private ArrayList<E> lista = new ArrayList<>();
    private int topeMax;

    public Pila(int maximo) {
        setTopeMax(maximo);
    }

    public int getTopeMax() {
        return topeMax;
    }

    public void setTopeMax(int topeMax) {
        this.topeMax = topeMax;
    }

    public void apilar (E dato){
        if(lista.size() >= topeMax){
            System.out.println("= PILA LLENA =");
        }else{
            lista.add(dato);
        }
    }

    public E desapilar(){
        E valor = lista.get(lista.size()-1);
        lista.remove(valor);
        return valor;
    }

    public boolean pilaVacia(){
        return lista.isEmpty();
    }

    public E tope(){
        return lista.get(lista.size()-1);
    }

    public static void mostrar (Pila<Integer> copia){
        Pila<Integer> aux = new Pila<>(copia.getTopeMax());
        System.out.println("[ Tope...........*UTN MDP*........Base ]");
        System.out.print("[");
        while (!copia.pilaVacia()){
            System.out.print(copia.tope()+"-");
            aux.apilar(copia.desapilar());
        }
        System.out.println("]");
        while (!aux.pilaVacia()){
            copia.apilar(aux.desapilar());
        }
    }

}
