package Ejer2;

import java.util.ArrayList;

public class Baul <X extends Libros>{
    private X dato;
    private int tope;
    private ArrayList<X> elementos = new ArrayList<>(tope);

    public Baul(int tope){
        setTope(tope);
    }

    public int getTope() {
        return tope;
    }

    public void setTope(int tope) {
        this.tope = tope;
    }

    public void agregar (X dato){
        elementos.add(dato);
    }
    public void eliminar(int pos){
        elementos.remove(elementos.get(pos));
    }

    @Override
    public String toString() {
        return "Baul:\n" + elementos+"\n";
    }
}
