package com.agus.clases.Producto;

import java.time.LocalDate;

public class Producto {

    private int codigo;
    private String descripcion;
    private int stock;
    private float precio;
    private LocalDate añoVencimiento;

    public Producto() {
    }

    public Producto(int codigo, String descripcion, int stock, float precio, LocalDate añoVencimiento) {
        this.codigo = codigo;
        this.descripcion = descripcion;
        this.stock = stock;
        this.precio = precio;
        this.añoVencimiento = añoVencimiento;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }

    public float getPrecio() {
        return precio;
    }

    public void setPrecio(float precio) {
        this.precio = precio;
    }

    public LocalDate getAñoVencimiento() {
        return añoVencimiento;
    }

    public void setAñoVencimiento(LocalDate añoVencimiento) {
        this.añoVencimiento = añoVencimiento;
    }

    @Override
    public String toString() {
        return "Producto: " +
                "\n   - Codigo: " + codigo +
                "\n   - Descripcion: " + descripcion +
                "\n   - Stock: " + stock +
                "\n   - Precio: " + precio +
                "\n   - Expiracion: " + añoVencimiento;
    }
}
