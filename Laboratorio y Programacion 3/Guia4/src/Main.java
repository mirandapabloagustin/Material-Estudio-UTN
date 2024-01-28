import com.agus.PackegeType64.*;
import com.agus.PackageMk3.*;
import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        // jercicio1();
        // ejercicio2();


    }
    public static void ejercicio1(){
        Materia laboratorio = new Materia();
        laboratorio.setNombre("Laboratorio");

        Estudiante alumno = new Estudiante("Ian",27,2376623,"Tec-Programacion",laboratorio);
        Profesor docente = new Profesor("Jorge",35,37624837,laboratorio);

        System.out.println(alumno.toString());
        System.out.println(docente.toString());
    }



    public static void ejercicio2(){
        ImageIcon icon = new ImageIcon("C:\\Users\\Agus-Notebook\\Desktop\\Facultad\\" +
                "3er Cuantrimestre\\Laboratorio3\\Guia4\\src\\com\\agus\\PackageMk3\\calavera.png");
        String [] botones = {"Jugar","Salir"};
        int opc = JOptionPane.showOptionDialog(null, "Bienvenido al lugar donde " +
                "nadie sobrevive\n tu destino dependera de lo que hagas...", "LOST LANDS",
                JOptionPane.DEFAULT_OPTION, JOptionPane.QUESTION_MESSAGE, icon, botones, botones[0]);
        switch (opc+1){
            case 1:
                selecPj();
                break;
        }
    }
    public static void selecPj(){
        ImageIcon icon = new ImageIcon("C:\\Users\\Agus-Notebook\\Desktop\\Facultad\\" +
                "3er Cuantrimestre\\Laboratorio3\\Guia4\\src\\com\\agus\\PackageMk3\\calavera.png");
        String [] botones = {"Mago","Guerrero","Arquero"};
        int opc = JOptionPane.showOptionDialog(null, "Selecione un Personaje:", "LOST LANDS",
                JOptionPane.DEFAULT_OPTION, JOptionPane.QUESTION_MESSAGE, icon, botones, botones[0]);
        switch (opc+1){
            case 1:

                break;
            case 2:
                break;
            case 3:

                break;
        }
    }




}