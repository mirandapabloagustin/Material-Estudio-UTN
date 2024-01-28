class Persona {
  constructor(nombre, edad) {
    this.nombre = nombre;
    this.edad = edad;
  }
}

function averiguarEdad() {
  let resultado = document.getElementById("resultadoEjer1");
  let edad = document.getElementById("edad");
  if (edad.value >= 18) {
    resultado.innerHTML = "Eres mayor de edad";
  } else if (edad.value < 18 && edad.value > 0) {
    resultado.innerHTML = "Eres menor de edad";
  } else {
    resultado.innerHTML = "No has introducido una edad válida";
  }
}
//---------------------------------------------------------------------------------------------
function averiguarNota() {
  let resultado = document.getElementById("resultadoEjer2");
  let numero = document.getElementById("nota");
  if (numero.value >= 0 && numero.value < 3) {
    resultado.innerHTML = "Muy deficiente";
  } else if (numero.value >= 3 && numero.value < 5) {
    resultado.innerHTML = "Insuficiente";
  } else if (numero.value >= 5 && numero.value < 7) {
    resultado.innerHTML = "Suficiente";
  } else if (numero.value == 7) {
    resultado.innerHTML = "Bien";
  } else if (numero.value >= 8 && numero.value < 10) {
    resultado.innerHTML = "Notable";
  } else if (numero.value == 10) {
    resultado.innerHTML = "Sobresaliente";
  } else {
    resultado.innerHTML = "No has introducido una nota válida";
  }
}
//---------------------------------------------------------------------------------------------
const arreglo = [];
function almacenarEdades() {
  let retorno = document.getElementById("respuestaEjer3");
  let nombre = document.getElementById("nombre");
  let edad = document.getElementById("edad2");

  if (
    arreglo.length < 3 &&
    verificarCompos(nombre, edad) &&
    !verificarRepetido(nombre, arreglo)
  ) {
    arreglo.push(new Persona(nombre.value, edad.value));
    retorno.innerHTML = "Persona añadida correctamente";
  } else {
    retorno.innerHTML =
      "No puedes añadir más personas o no has introducido los datos correctamente.";
  }

  if (arreglo.length == 3) {
    let mayor = arreglo[0];
    for (let i = 0; i < arreglo.length; i++) {
      if (arreglo[i].edad > mayor.edad) {
        mayor = arreglo[i];
      }
    }
    retorno.innerHTML =
      "La persona de mayor edad es " +
      mayor.nombre +
      " con " +
      mayor.edad +
      " años";
  }
  limpiarCampos([nombre, edad, retorno]);
}
function verificarCompos(...campo) {
  return campo.every((campo) => campo.value != "");
}
function verificarRepetido(campo, arreglo) {
  return arreglo.some((campo) => campo.nombre == campo.value);
}
function limpiarCampos(campos) {
  campos.forEach((campo) => (campo.value = ""));
}
function limpiarArreglo() {
  arreglo.length = 0;
  let retorno = document.getElementById();
  retorno.innerHTML = "Arreglo limpiado";
}
//---------------------------------------------------------------------------------------------
function mostrarMayusculas() {
  let resultado = document.getElementById("respuestaEjer4");
  let cadena = document.getElementById("cadena");
  resultado.innerHTML = cadena.value.toUpperCase();
}
//---------------------------------------------------------------------------------------------
function piramideNumeros() {
  let resultado = document.getElementById("respuestaEjer5");
  for (let i = 0; i <= 30; i++) {
    for (let j = 0; j < i; j++) {
      resultado.innerHTML += i;
    }
    resultado.innerHTML += "<br>";
  }
}
//---------------------------------------------------------------------------------------------
function multiplos() {
  let respuesta = document.getElementById("respuestaEjer6");
  let resultado = document.getElementById("multiplos");

  for (let i = 0; i <= 500; i++) {
    if (i % 4 == 0 && i % 9 == 0) {
      resultado.innerHTML += i + " - ";
    }
  }
}
//---------------------------------------------------------------------------------------------
const arreglo2 = [];
function sumatoria() {
  let suma = 0;
  let numero = document.getElementById("numero3");
  let resultado = document.getElementById("respuestaEjer7");

  if (numero.value != 0) {
    arreglo2.push(numero.value);
    resultado.innerHTML = "Ingrese otro Numero";
    numero.value = "";
    console.log(arreglo2);
  } else {
    arreglo2.forEach((numero) => (suma += parseInt(numero)));
    resultado.innerHTML = "La suma de los números introducidos es " + suma;
  }
}
//---------------------------------------------------------------------------------------------
let cadenaEjer8 = "";
function concatenar() {
  let cadena = document.getElementById("cadena2");
  let resultado = document.getElementById("respuestaEjer8");

  if (cadena.value != "fin") {
    if (cadenaEjer8 != "") {
      cadenaEjer8 += "-" + cadena.value;
      cadena.value = "";
    } else {
      cadenaEjer8 = cadena.value;
      cadena.value = "";
    }
  } else {
    resultado.innerHTML = cadenaEjer8;
  }
  console.log(cadenaEjer8);
}
//---------------------------------------------------------------------------------------------
function contarVocales() {
  arregloVocales = ["a", "e", "i", "o", "u"];
  let cadena = document.getElementById("cadena3");
  let resultado = document.getElementById("respuestaEjer9");
  let contador = 0;

  for (let i = 0; i < cadena.value.length; i++) {
    for (let j = 0; j < arregloVocales.length; j++) {
      if (cadena.value[i] == arregloVocales[j]) {
        contador++;
      }
    }
  }
  resultado.innerHTML = "La cadena tiene " + contador + " vocales";
  cadena.value = "";
}
//---------------------------------------------------------------------------------------------
function invertirCadena() {
  let cadena = document.getElementById("cadena4");
  let resultado = document.getElementById("respuestaEjer10");
  let cadenaInvertida = "";

  for (let i = cadena.value.length - 1; i >= 0; i--) {
    cadenaInvertida += cadena.value[i];
  }
  resultado.innerHTML = cadenaInvertida;
  cadena.value = "";
}
//---------------------------------------------------------------------------------------------
function calcularArea() {
  let radio = document.getElementById("radio");
  let resultado = document.getElementById("respuestaEjer11");
  resultado.innerHTML = "El área del círculo es " + Math.PI * radio.value ** 2;
}
//---------------------------------------------------------------------------------------------
function verificarNumero() {
  let numero = document.getElementById("numero4");
  let resultado = document.getElementById("respuestaEjer12");
  switch (Math.sign(numero.value)) {
    case -1:
      resultado.innerHTML = "El número es negativo";
      break;
    case 0:
      resultado.innerHTML = "El número es cero";
      break;
    case 1:
      resultado.innerHTML = "El número es positivo";
      break;
    default:
      resultado.innerHTML = "No has introducido un número válido";
  }
}
//---------------------------------------------------------------------------------------------
arreglo3 = [];
function almacenarNombres() {
  let nombre = document.getElementById("nombre2");
  let resultado = document.getElementById("respuestaEjer13");

  if (nombre.value != "") {
    arreglo3.push(nombre.value);
    resultado.innerHTML = "Nombre añadido correctamente";
    nombre.value = "";
  } else {
    resultado.innerHTML = "No has introducido un nombre válido";
  }
  console.log(arreglo3);
}

function ordenarArreglo() {
  let resultado = document.getElementById("respuestaEjer13");
  resultado.innerHTML = arreglo3.sort();
  arreglo3.splice(0, arreglo3.length);
}
//---------------------------------------------------------------------------------------------
const arreglo4 = [];
function almacenarNumeros() {
  let numero = document.getElementById("numero5");
  let resultado = document.getElementById("respuestaEjer14");

  if (numero.value != "") {
    arreglo4.push(numero.value);
    numero.value = "";
  } else {
    resultado.innerHTML = "No has introducido un número válido";
  }
}

function buscarNumero() {
  arreglo4.sort();
  let resultado = document.getElementById("respuestaEjer14");
  resultado.innerHTML =
    "El número menor es " +
    arreglo4[0] +
    "<br>" +
    "El número mayor es " +
    arreglo4[arreglo4.length - 1];
}
//---------------------------------------------------------------------------------------------
function contarPalabras() {
  let cadena = document.getElementById("frase").value;
  let resultado = document.getElementById("respuestaEjer15");

  let nuevaCadena = cadena.split(" ");

  resultado.innerHTML = "La cadena tiene " + nuevaCadena.length + " palabras";
}
