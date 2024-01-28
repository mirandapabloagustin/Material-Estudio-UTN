package com.agus.clases;
import java.time.Duration;
import java.time.LocalDateTime;

public class Vuelo {
    private String origen;
    private String destino;
    private LocalDateTime horaSalida;
    private LocalDateTime horaLlegada;

    public Vuelo (String origen, String destino,LocalDateTime horaSalida, LocalDateTime horaLlegada){
        this.origen = origen;
        this.destino = destino;
        this.horaSalida = horaSalida;
        this.horaLlegada = horaLlegada;
    }

    public Vuelo(){}

    public String getOrigen() {
        return origen;
    }

    public void setOrigen(String origen) {
        this.origen = origen;
    }

    public String getDestino() {
        return destino;
    }

    public void setDestino(String destino) {
        this.destino = destino;
    }

    public LocalDateTime getHoraSalida() {
        return horaSalida;
    }

    public void setHoraSalida(LocalDateTime horaSalida) {
        this.horaSalida = horaSalida;
    }

    public LocalDateTime getHoraLlegada() {
        return horaLlegada;
    }

    public void setHoraLlegada(LocalDateTime horaLlegada) {
        this.horaLlegada = horaLlegada;
    }

    public void duracion_vuelo(){
        Duration tiempoVuelo = Duration.between(this.horaSalida,this.horaLlegada);
        System.out.println("Tiempo Vuelo: "+ tiempoVuelo);
    }

    @Override
    public String toString() {
        return "Vuelo Programado :[" +
                "Origen: '" + origen + '\'' +
                "; Destino: '" + destino + '\'' +
                "; Hora Salida: '" + horaSalida + '\'' +
                "; Hora Llegada: '" + horaLlegada + '\'' +
                ']';
    }

}
