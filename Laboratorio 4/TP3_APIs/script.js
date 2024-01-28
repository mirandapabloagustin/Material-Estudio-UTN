
let actualPage = "https://rickandmortyapi.com/api/character/?page=1";
let nextPage = "";
let prevPage = "";


//Async es una palabra reservada que se utiliza para definir una función asincrona
// los () => {} es una función flecha que se utiliza para definir una función
// se guarda en una constante para poder utilizarla en cualquier parte del código
const cargarDatos = async () => {
  try {
    //await es una palabra reservada que se utiliza para esperar a que una promesa se resuelva
    const rta = await fetch(actualPage);
    
    // status es una propiedad de la respuesta que nos indica el estado de la misma
      // rta.json() retorna una promesa
      // data es el objeto que retorna la promesa y que contiene los datos o el error
    const datos = await rta.json();
      
    nextPage = datos.info.next;

    prevPage = datos.info.prev;

      // forEach es un método de los arreglos que nos permite iterar sobre cada uno de los elementos
      datos.results.forEach((personaje) => { 
        const etiqueta = document.createRange().createContextualFragment(
          `<div class="card">
          <h2>${personaje.name}</h2>
          <img src="${personaje.image}" alt="${personaje.name}">
          </div>`);
          document.querySelector(".container").append(etiqueta);
      });

  } catch (error) {
    console.log(error.message);
  }
};

cargarDatos();

document.getElementById("btnSiguiente").addEventListener("click", () => {
  if (nextPage != null) {
    document.querySelector(".container").innerHTML = "";
    actualPage = nextPage;
    cargarDatos();
  }
});

document.getElementById("btnAnterior").addEventListener("click", () => {
  if (prevPage != null) {
    document.querySelector(".container").innerHTML = "";
    actualPage = prevPage;
    cargarDatos();
  }
});

