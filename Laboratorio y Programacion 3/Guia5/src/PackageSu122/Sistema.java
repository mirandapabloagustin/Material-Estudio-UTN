package PackageSu122;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Sistema {
    private List<Vehiculo> listaCoches = new ArrayList<>();

    public List<Vehiculo> getListaCoches() {
        return listaCoches;
    }

    public Coche crearVehiculoCoche(){
        Scanner scanDouble = new Scanner(System.in);
        Scanner scanInt = new Scanner(System.in);
        Scanner scan = new Scanner(System.in);
        System.out.print("MARCA........: ");
        String marca = scan.nextLine();
        System.out.print("MODELO.......: ");
        String modelo = scan.nextLine();
        System.out.print("PRECIO.......: ");
        Double precio = scanDouble.nextDouble();
        System.out.print("Cant.PUERTAS.: ");
        int puertas = scanInt.nextInt();
        Coche auto = new Coche(puertas,false, marca, modelo, precio);
        return auto;
    }

    public Moto crearVehiculoMoto(){
        Scanner scan2 = new Scanner(System.in);
        Scanner scan = new Scanner(System.in);

        System.out.print("MARCA........: ");
        String marca = scan.nextLine();
        System.out.print("MODELO.......: ");
        String modelo = scan.nextLine();
        System.out.print("PRECIO.......: ");
        Double precio = scan2.nextDouble();
        System.out.print("Cilindrada...: ");
        String cilindrada = scan.nextLine();

        Moto ciclomotor = new Moto(cilindrada,false, marca, modelo, precio);
        return ciclomotor;
    }

    public boolean verificarAlquiler(Vehiculo automotor) {
        boolean result = false;
        for (Vehiculo i : listaCoches) {
            if (i.alquilado == automotor.alquilado) {
                result = true;
                break;
            }
        }
        return result;
    }


    public void mostrarListado(){
        System.out.println( !listaCoches.isEmpty() ? listaCoches.toString() : "No hay Vehiculos cargados");
    }
}
