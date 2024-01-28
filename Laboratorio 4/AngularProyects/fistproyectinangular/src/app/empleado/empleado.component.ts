import { Component } from '@angular/core';

@Component({
  selector: 'app-empleado',
  templateUrl: './empleado.component.html',
  styleUrls: ['./empleado.component.css']
  // se puede usar style para poner estilos en linea osea que no 
  // depende de un archivo pero se recomienda usar el styleUrls si 
  // son muchos estilos que se van a usar en el componente.
  //styles: ["p{background-color:blue;}"]

})
export class EmpleadoComponent {

  nombre: string = 'Juan';
  
  apellido: string = 'Perez';
  
  private edad: number = 25;
  
  //empresa: string = "";
  
  get _edad(): number{
    return this.edad;
  } 

  establecerEmpresa(value: string){

  };

  cuadroTextoHab: boolean = false;

  usuarioConectado: boolean = false;

  textoEstadoCuenta : string = "Usuario no Registrado"

  setUsuarioRegistrado(){
    
  }


}
