package com.agus.clases.Producto;
import java.time.LocalDate;
import java.time.Period;
import java.util.ArrayList;
import java.util.Scanner;

public class GestionProductos {
     ArrayList<Producto> listaProductos = new ArrayList<Producto>();

    public int generarCodProduc(){
        return (int) (Math.random()*1000000000);
    }

    public Producto crearProd(){
        Scanner scanner = new Scanner(System.in);
        Scanner sInt = new Scanner(System.in);
        Scanner sFloat = new Scanner(System.in);
        Producto articulo = new Producto();
        System.out.println("= CARGAR PRODUCTO =");
        articulo.setCodigo(generarCodProduc());
        System.out.print("Descripcion..: ");
        articulo.setDescripcion(scanner.nextLine());
        System.out.print("Precio.......: ");
        articulo.setPrecio(sFloat.nextFloat());
        System.out.print("Stock........: ");
        articulo.setStock(sInt.nextInt());
        System.out.print("Expiracion...: ");
        articulo.setAñoVencimiento(LocalDate.parse(scanner.nextLine()));
        System.out.println("= PRODUCTO CARGADO =");
        return articulo;
    }

    public void agregarProductos(){
        Scanner scanner = new Scanner(System.in);
        int opc;
        do{
            listaProductos.add(crearProd());
            System.out.print("Desea seguir cargando (1= si/0= no) : ");
            opc = scanner.nextInt();
        } while(opc !=0);
    }

    public void mostrarListaProd(){
        System.out.println("= LISTA PRODUCTOS =");
        for(Producto i : listaProductos){
            System.out.println(i);
            System.out.println("=====================================");
        }
    }

    public int inputProd(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("= RETIRO PRODUCTO =");
        System.out.print("Ingrese CODIGO Producto Buscado: ");
        return scanner.nextInt();
    }

    public int buscarArticulo(int codigo){
        int pos = -1;
        for(int i = 0; i < listaProductos.size();i++){
            if(listaProductos.get(i).getCodigo() == codigo){
                pos = i;
                break;
            }
        }
        return pos;
    }

    public void descontarStock(){
        Scanner scanner = new Scanner(System.in);
        int posArticulo = buscarArticulo(inputProd());
        if(posArticulo > -1){
            System.out.print("Ingrese Cantidad a Retirar: ");
            int retiro = scanner.nextInt();
            listaProductos.get(posArticulo).setStock( listaProductos.get(posArticulo).getStock() - retiro );
            System.out.println(" = RETIRO EXITOSO = ");
        }else System.out.println("= NO EXISTE =");
    }

    public boolean verificarExp(Producto articulo){
        Period vencido = Period.between(LocalDate.now(),articulo.getAñoVencimiento());
        return vencido.isNegative();
    }

    public void estadoProd(){
        int prodBuscado = buscarArticulo(inputProd());
        if(prodBuscado > -1){
            String s = "";
            System.out.println(verificarExp(listaProductos.get(prodBuscado)) ? "Producto EXPIRO" : "EXPIRA en "+
                    Period.between(LocalDate.now(),listaProductos.get(prodBuscado).getAñoVencimiento()));
        }else System.out.println("= NO EXISTE =");
    }


    public ArrayList<Producto> getListaProductos(){
        return listaProductos;
    }


}
