package Estucturas;

import javax.xml.stream.events.EndElement;
import java.util.ArrayDeque;

public class Cola<E> {
    private E elemento;
    private ArrayDeque<E> lista = new ArrayDeque<>();
    private int topeMax;

    public Cola(int topeMax) {
        setTopeMax(topeMax);
    }

    public int getTopeMax() {
        return topeMax;
    }

    public void setTopeMax(int topeMax) {
        this.topeMax = topeMax;
    }

    public void apilar(E dato){
        if(lista.size() <= topeMax){
            lista.addLast(dato);
        }else{
            System.out.println("= COLA LLENA =");
        }
    }
    public E desapilar(){
        E valor = lista.getFirst();
        lista.removeFirst();
        return valor;
    }
    public boolean colaVacia(){
        return lista.isEmpty();
    }

    public E tope () {
        return lista.getFirst();
    }

}
