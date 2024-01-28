import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { Usuario } from 'src/app/core/Models';
import { ApiService } from 'src/app/core/services/api.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})

export class LoginComponent implements  OnInit{

  public usuarioLogueado: Usuario = {
    id: null,
    nombreUsuario: null,
    email: null,
    contrasenia: null
  };

  constructor(
    private apiService: ApiService, 
    private router: Router
    ) { }

  email : string ="";
  password : string ="";

  ngOnInit(): void {

  }

  public inicioSesion() {
    
    //utilizamos la funcion del servicio para obtener el usuario por email y contraseña 
    //nos suscribimos al observable que nos devuelve la funcion
    this.apiService.obtenerUsuarioPorEmailYContrasenia(this.usuarioLogueado.email!, this.usuarioLogueado.contrasenia!).subscribe({
      
      next: (result) =>{
        if(result){
          //si el usuario existe, nos redirige al home
          this.router.navigate(["/home"])
        }
      },
      //si no existe, nos muestra un mensaje de error
      error: (error) => console.log(error)
    })
  
  }

}

