import { Usuario } from "./Models";

export interface ITarea {
  id: number | null;
  priorida: number | null;
  descripcion: string | null;
  hecho: boolean | null;
}

export interface IUsuario {
  id: number | null;
  nombreUsuario: string | null;
  email: string | null;
  contrasenia: string | null;
}

export interface RespuestaLogeo {
  user: Usuario,
  token: string
}