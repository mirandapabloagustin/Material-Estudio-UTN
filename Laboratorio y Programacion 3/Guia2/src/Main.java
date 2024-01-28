import com.agus.clases.Estudiante.*;
import com.agus.clases.Producto.*;
import com.agus.clases.agenda.*;
import com.agus.clases.*;
import java.util.*;
import java.time.*;

public class Main {
    public static void main(String[] args) {

/*        System.out.println("Ejercicio 1\n=====================================================");
        Cuenta cliente1 = new Cuenta(180000.00,"Jorge Karp");
        cliente1.encargado(cliente1.getSaldo());

        System.out.println("\nEjercicio 2\n=====================================================");
        Vuelo viaje1 = new Vuelo("Pinamar","Catamarca", LocalDateTime.now(),LocalDateTime.now().plusHours(1).plusMinutes(45));
        viaje1.duracion_vuelo();*/

   /*     System.out.println("\nEjercicio 3\n=====================================================");
        ArrayList<Agenda> listaContacto = new ArrayList<Agenda>();
        menuAgenda(listaContacto);*/

/*        System.out.println("\nEjercicio 4\n=====================================================");
        menuEstudiantes();*/

        System.out.println("\nEjercicio 5\n=====================================================");
        menuProductos();

    }



    public static void menuAgenda(ArrayList<Agenda> lista){
        Scanner scanner = new Scanner(System.in);
        int posContacto;
        int opc;
        do{
            System.out.println("AGENDA PERSONAL");
            System.out.println("1] Ingresar Contacto.");
            System.out.println("2] Modificar Contacto.");
            System.out.println("3] Mostrar Contactos.");
            System.out.println("4] Eliminar Contacto.");
            System.out.println("0] SALIR.");
            System.out.print("Elegir Opcion: ");
            opc = scanner.nextInt();

            switch (opc) {
                case 1:
                    Gestion.agregarContacto(Gestion.crearContacto(),lista);
                    break;
                case 2:
                    posContacto = Gestion.altaContacto(Gestion.inputString(),lista);
                    if (posContacto >-1) {
                        Gestion.modificarContacto(lista.get(posContacto));

                    }else{
                        System.out.println("Usuario no Existe.");
                    }
                    break;
                case 3:
                    System.out.println(lista.toString());
                    break;
                case 4:
                    posContacto = Gestion.altaContacto(Gestion.inputString(),lista);
                    if (posContacto >-1) {
                        Gestion.borrarContacto(posContacto,lista);
                    }else{
                        System.out.println("Usuario no Existe.");
                    }
                    break;
            }

        }while(opc != 0);


    }


    public static void menuEstudiantes() {
        ArrayList<Estudiante> listaEstudiantes = new ArrayList<Estudiante>();

        Scanner scanner = new Scanner(System.in);
        int opc;
        do{
            System.out.println("ESTUDIANTES:");
            System.out.println("1] Ingresar Alumnos.");
            System.out.println("2] Ingresar Materia a Alumno.");
            System.out.println("3] Modificar Alumnos.");
            System.out.println("4] Mostrar Alumnos.");
            System.out.println("5] Eliminar Alumnos.");
            System.out.println("0] SALIR.");
            System.out.print("Elegir Opcion: ");
            opc = scanner.nextInt();

            switch (opc) {
                case 1:
                    listaEstudiantes.add(GestionEstuduanteMaterias.crearAlumno());
                    break;
                case 2:
                    GestionEstuduanteMaterias.agregarMateriaAlumno(listaEstudiantes);
                    break;
                case 3:
                    GestionEstuduanteMaterias.modificarAlumno(listaEstudiantes);
                    break;
                case 4:
                    System.out.println(listaEstudiantes.toString());
                    break;
                case 5:
                    GestionEstuduanteMaterias.borrarAlumno(listaEstudiantes);
                    break;
            }

        }while(opc != 0);



    }

    public static void menuProductos(){
        Scanner scanner = new Scanner(System.in);
        GestionProductos gestionProductos = new GestionProductos();
        int opc;
        do {
            System.out.println("PRODUCTOS");
            System.out.println("1] CARGAR Producto");
            System.out.println("2] RETIRAR Producto");
            System.out.println("3] ESTADO Producto");
            System.out.println("4] VER Productos");
            System.out.println("0] SALIR.");
            System.out.print("Elegir Opcion: ");
            opc = scanner.nextInt();
            switch (opc){
                case 1 :
                    gestionProductos.agregarProductos();
                    break;
                case 2:
                    gestionProductos.descontarStock();
                    break;
                case 3:
                    gestionProductos.estadoProd();
                    break;
                case 4:
                    gestionProductos.mostrarListaProd();
                    break;
            }
        }while(opc != 0);
    }
}



