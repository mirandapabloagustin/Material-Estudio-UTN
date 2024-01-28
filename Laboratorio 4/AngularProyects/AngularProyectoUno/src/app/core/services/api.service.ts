import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable, catchError, map, of } from 'rxjs';
import { Usuario } from '../Models';

@Injectable({
  providedIn: 'root'
})
export class ApiService {

  //creamos una variable privada de tipo HttpClient
  private url = 'http://localhost:3000';

  //indicamos al constructor que vamos a usar la variable http
  constructor(
    private http: HttpClient,
  ) { }

  //creamos un metodo para obtener todos los usuarios
  public obtenerUsuarios() : Observable<Usuario[]> {
    return this.http.get<Usuario[]>(`${this.url}/usuarios`);
  }

  //creamos un metodo para obtener un usuario por id
  public obtenerUnUsuario(id: number) : Observable<Usuario> {
    return this.http.get<Usuario>(`${this.url}/usuarios/${id}`);
  }

  //creamos un metodo para borrar un usuario por id
  public borrarUnUsuario(id: number) : Observable<boolean> {
    return this.http.delete<Usuario>(`${this.url}/usuarios/${id}`).pipe(
      map(resp => {return true;}),
      // el catchError es para capturar el error y usar el of para devolver un false porque el catchError devuelve un observable y nosotros queremos un booleano por eso mandamos un obsevable que contiene un false
      catchError(error => of(false))
    );
  }

  //creamos un metodo para obtener un usuario por email y contraseña
  public obtenerUsuarioPorEmailYContrasenia(email: string, contrasenia: string) : Observable<Usuario> {
    return this.http.get<Usuario>(`${this.url}/usuarios?email=${email}&contrasenia=${contrasenia}`);
  }

}
