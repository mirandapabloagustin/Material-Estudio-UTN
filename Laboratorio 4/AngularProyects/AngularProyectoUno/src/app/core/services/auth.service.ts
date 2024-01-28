import { Injectable } from '@angular/core';
import { Usuario } from '../Models';
import { ApiService } from '../services/api.service';
import { lastValueFrom, map } from 'rxjs';


@Injectable({
  providedIn: 'root'
})
export class AuthService {

  //creamos una variable que permite almacenar varios valores 
  private usuario: Usuario | null | undefined = null;

  //injectamos una variable privada tipo apiService
  constructor(private apiService: ApiService) { }

  //creamos un metodo que me devuelve el usuario pero si esta vacio devuelve undefined
  get usuarioAltual(): Usuario | undefined {
    if (!this.usuario) {
      return undefined;
    }
    return this.usuario;
  }

  //Metodo asincronico para loguearse recibiendo como parametro el email y la contraseña
  public async ingreso(email: string, contrasenia: string): Promise<boolean> {

    //bandera para indicar si esta logueado
    let loguado: boolean = false;

    try{
      // el await es para esperar la respuesta de la api y luego asignarla a la variable si los datos son correctos
      let usuarioBuscadoEnApi = await lastValueFrom(this.apiService.obtenerUsuarioPorEmailYContrasenia(email, contrasenia));

      if(usuarioBuscadoEnApi){
        //Con el LocalStorage podemos almacenar datos en el navegador
        //setItem es para guardar datos en el navegador con el nombre de "TOKEN" y el valor de "ID"
        // El signo de admiracion al lado de ID es para indicar que no es null
        localStorage.setItem('token',usuarioBuscadoEnApi.id!.toString());

        //indicamos que esta logueado
        loguado = true;
      }

    }catch(error){
      console.log(error);
    }
    return loguado;
  }

  //Metodo para desloguearse y borra el token del navegador
  public desloguearse(): void {
    //removemos el token del navegador
    localStorage.removeItem('token');
  }

  //Este metodo sirve para chequear si esta logueado retornando un booleano
  public chequeaLogueo(): boolean{
    return localStorage.getItem('token') ? true : false;
  }

}
