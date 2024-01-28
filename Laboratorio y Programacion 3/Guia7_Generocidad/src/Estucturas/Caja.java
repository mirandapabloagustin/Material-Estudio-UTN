package Estucturas;
import java.util.ArrayList;
import java.util.List;
public class Caja <T,V,S>{
    private static final int topeMaxGral = 10;

    private List<T> lista1 = new ArrayList<>(topeMaxGral);
    private List<V> lista2 = new ArrayList<>(topeMaxGral);
    private List<S> lista3 = new ArrayList<>(topeMaxGral);


    public void agregarLista1(T dato){
        if(lista1.size() < topeMaxGral){
            lista1.add(dato);
        }else{
            System.out.println("= COMPLETA =");
        }
    }
    public void agregarLista2(V dato){
        if(lista2.size() < topeMaxGral){
            lista2.add(dato);
        }else{
            System.out.println("= COMPLETA =");
        }
    }
    public void agregarLista3(S dato){
        if(lista3.size() < topeMaxGral){
            lista3.add(dato);
        }else{
            System.out.println("= COMPLETA =");
        }
    }

    public void eliminarLista1(T dato){lista1.remove(dato);}
    public void eliminarLista2(V dato){lista2.remove(dato);}
    public void eliminarLista3(S dato){lista3.remove(dato);}

    public void mostrar() {
        if(!lista1.isEmpty()) {
            System.out.println("Lista 1:");
            for (T elemento : lista1) {
                System.out.println(elemento);
            }
        } else {
            System.out.println("= Lista VACIA =");
        }
        if (!lista2.isEmpty()) {
            System.out.println("Lista 2:");
            for (V elemento : lista2) {
                System.out.println(elemento);
            }
        }else {
            System.out.println("= Lista VACIA =");
        }


        if(!lista3.isEmpty()) {
            System.out.println("Lista 3:");
            for (S elemento : lista3) {
                System.out.println(elemento);
            }
        }else {
            System.out.println("= Lista VACIA =");
        }
    }
}


