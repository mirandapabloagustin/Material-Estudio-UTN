import java.util.ArrayList;
import java.util.HashMap;

public class Colegio {
    private String nombre;
    private ArrayList<Alumnos> listaAlumnos = new ArrayList<Alumnos>();

    public Colegio() {
    }
    public Colegio(String nombre){
        setNombre(nombre);
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public ArrayList<Alumnos> getListaAlumnos() {
        return listaAlumnos;
    }

    public void agregarAlumno(Alumnos alumno){
        try {
            if(listaAlumnos.contains(alumno)){
                throw new ExceptionAlumnos("El alumno ya existe");
            } else if (alumno.getNombre().equals("") || alumno.getNacionalidad().equals("")) {
                throw new ExceptionAlumnos("No se puede ingresar un alumno sin nombre o nacionalidad");
            } else {
                listaAlumnos.add(alumno);
            }
        } catch (ExceptionAlumnos e) {
            System.out.println(e.getMessage());
        }
    }

    private int cantNacionalidad(String nacionalida){
        int contador = 0;
        for (Alumnos elemento : listaAlumnos){
            if (elemento.getNacionalidad().equals(nacionalida)){
                contador++;
            }
        }
        return contador;
    }

    public void verNacionalidad(String nacionalidad){
        try{
            if(cantNacionalidad(nacionalidad) != 0){
                for (Alumnos elemento : listaAlumnos){
                    if (elemento.getNacionalidad().equals(nacionalidad)){
                        System.out.println(elemento);
                    }
                }
            }else {
                throw new ExceptionAlumnos("No hay alumnos de esa nacionalidad");
            }
        }catch (ExceptionAlumnos e) {
            System.out.println(e.getMessage());
        }
    }

    private Alumnos bucarAlumno(String nombre){
        for (Alumnos elemento : listaAlumnos){
            if (elemento.getNombre().equals(nombre)){
                return elemento;
            }
        }
        return null;
    }

    public void borrarAlumno(Alumnos alumno){
        try {
            listaAlumnos.remove(bucarAlumno(alumno.getNombre()));
        }catch (NullPointerException e){
            System.out.println("No se encontro el alumno");
        }
    }

    public void verTodo(){
        HashMap <String,Integer> nacionalidades = new HashMap<String,Integer>();
        for (Alumnos elemento : listaAlumnos){
            if(!nacionalidades.containsKey(elemento.getNacionalidad())){
                nacionalidades.put(elemento.getNacionalidad(), cantNacionalidad(elemento.getNacionalidad()));
            }
        }
        System.out.println(nacionalidades);
        System.out.println("------------------------------------------------------");
    }
}
