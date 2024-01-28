public class Alumnos {
    private String nombre;
    private String nacionalidad;

    public Alumnos(){
    }

    public Alumnos(String nombre,String nacionalidad){
        setNombre(nombre);
        setNacionalidad(nacionalidad);
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getNacionalidad() {
        return nacionalidad;
    }

    public void setNacionalidad(String nacionalidad) {
        this.nacionalidad = nacionalidad;
    }



    @Override
    public String toString() {
        return  "   - Nombre: " + nombre + '\n' +
                "   - Nacionalidad: " + nacionalidad;
    }
}
