import { ITarea, IUsuario } from "./Interface";

export class Tarea implements ITarea {

    id: number | null;
    priorida: number | null;
    descripcion: string | null;
    hecho: boolean | null;

    constructor(tarea?: any) {
        this.id = tarea.id != null ? tarea.id : null;
        this.priorida = tarea.priorida != null ? tarea.priorida : null;
        this.descripcion = tarea.descripcion != null ? tarea.descripcion : null;
        this.hecho = tarea.hecho != null ? tarea.hecho : null;
      }
}

export class Usuario implements IUsuario {

    id: number | null;
    nombreUsuario: string | null;
    email: string | null;
    contrasenia: string | null;

    constructor(usuario?: any) {
        this.id = usuario.id != null ? usuario.id : null;
        this.nombreUsuario = usuario.nombreUsuario != null ? usuario.nombreUsuario : null;
        this.email = usuario.email != null ? usuario.email : null;
        this.contrasenia = usuario.contrasenia != null ? usuario.contrasenia : null;
      }
}