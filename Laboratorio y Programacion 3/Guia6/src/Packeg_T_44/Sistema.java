package Packeg_T_44;
import java.util.*;

public class Sistema {
    private HashMap<Integer,Persona2> mapNumeros = new HashMap<>();

    public HashMap<Integer, Persona2> getMapNumeros() {
        return mapNumeros;
    }

    public void setMapNumeros(HashMap<Integer, Persona2> mapNumeros) {
        this.mapNumeros = mapNumeros;
    }

    public void agregarLista(ArrayList<Persona2> lista, HashMap<Integer,Persona2> listaHash){
        for(Persona2 i : lista){
            listaHash.put(i.getDni(),i);
        }
    }
    public void alta(Persona2 elemento) {
        mapNumeros.put(elemento.getDni(), elemento);
    }
    public void baja(int key){
        mapNumeros.remove(key);
    }

    public void modificar(Persona2 elemNuevo){
        Persona2 user = mapNumeros.get(elemNuevo.getDni());
        user.setEdad(elemNuevo.getEdad());
        user.setNombre(elemNuevo.getNombre());
        mapNumeros.put(user.getDni(),user);
    }

    public void muestraMap(HashMap<Integer,Persona2> listaHash){
        for (Map.Entry<Integer,Persona2> entidades : listaHash.entrySet()){
            System.out.println("------------------------------"+"\n"+
                               "Key...: ["+entidades.getKey()+"]\n" +
                               "= Valor =\n"+entidades.getValue());
        }
    }

    public HashMap<Integer,Persona2> ordenamientoHashMap(){
        //Creo una lista temporal la cual obtendra todos los elementos de mi HASHMAP
        ArrayList<Persona2> temp = new ArrayList<>(mapNumeros.values());
        //Ordeno los elementos con el metodo de Collections.shot
        //      - especificamos entre los parentesis la LISTA, el metodo de comparacion que va a ser por edades de cada elemento
        temp.sort(Comparator.comparingInt(Persona2::getEdad));
        // creamos otro HashMap para devolverlo ordenado
        HashMap<Integer,Persona2> aux = new HashMap<>();
        agregarLista(temp,aux);
        return aux;
    }


}
