class person {
  constructor(name, age, profession) {
    this.name1 = name;
    this.age = age;
    this.profession = profession;
  }

  saludar() {
    alert("Hola, mi nombre es " + this.name + ", tengo " + this.age + " años y soy " + this.profession);
  }
}

class hero {
  constructor(name,power) {
    this.name = name;
    this.power = power;
  }
  myself() {
    alert("Soy " + this.name + " y mi poder es " + this.power);
  }
}

class villian extends hero {
  constructor(name, power, malevolentPlan) {
    super(name, power);
    this.malevolentPlan = malevolentPlan;
  }

  threaten() {
    alert("Voy a " + this.malevolentPlan);
  }
}


class book {
  constructor(title, autor, publicYear) {
    this.title = title;
    this.autor = autor;
    this.publicYear = publicYear;
  }

  toString() {
    return "Datos del Libro:\n- Titulo: " + this.title + "\n -Autor: " + this.autor + "\n- Año de publicacion: " + this.publicYear;
  }
}

class digitalBook extends book {
  constructor(title, autor, publicYear, format) {
    super(title, autor, publicYear);
    this.format = format;
  }
  
  viewFormat() {
    alert(this.toString());
  }
  toString() {
    return super.toString() + "\n- Formato: " + this.format;
  }
}



/*---------------------------------------------------------------------- */

/* EJERCICIO 1 */
function showProperties() {
  let name = document.getElementById("name").value;
  let age = document.getElementById("age").value;
  let profession = document.getElementById("profession").value;
  
  let persona = {
    name: name
    , age: age
    , profession: profession
  };
  name.value = "";
  age.value = "";
  profession.value = "";
  alert("Name: " + persona.name + "\nAge: " + persona.age + "\nProfession: " + persona.profession);
}

/* EJERCICIO 2 */
function starAndShow() {
  let book1 = new book(
    prompt("Ingrese el titulo del libro:"),
    prompt("Ingrese el Autor:"),
    prompt("Ingrese el año de publicacion:"));
  alert(book1.toString());
}

/* EJERCICIO 3 */
function starAndShow2() {
  let persona = new person(
    prompt("Ingrese su Nombre:"),
    prompt("Ingrese su Edad:"),
    prompt("Ingrese su Profecion:")
  );
  alert(persona.saludar());
}

/* EJERCICIO 4 */
function starAndShow3() {
  let hero1 = new hero(
    prompt("Ingrese el nombre del Heroe:"),
    prompt("Ingrese el poder del Heroe:")
  );
  let villian1 = new villian(
    prompt("Ingrese el nombre del Villano:"),
    prompt("Ingrese el poder del Villano:"),
    prompt("Ingrese el plan malevolo del Villano:")
  );
  alert(hero1.myself());
  alert(villian1.threaten());
}

/* EJERCICIO 5 */
function starAndShow4() {
  let book = new digitalBook(
    prompt("Ingrese el titulo del libro:"),
    prompt("Ingrese el Autor:"),
    prompt("Ingrese el año de publicacion:"),
    prompt("Ingrese el formato del libro:")
  );
  book.viewFormat();
}
/* EJERCICIO 6 */
let listNames = [];
function pushToList() {
  let name = document.getElementById("names").value;
  if (name != "") {
    listNames.push(name);
  }
  document.getElementById("names").value = "";
}

function convertToUpperCase() {
  let result = document.getElementById("result");
  if (listNames.length != 0) {
    listNames = listNames.map(name => name.toUpperCase());
    result.innerHTML = listNames;
  } else {
    result.innerHTML = "No hay nombres en la lista";
  }
}

/* EJERCICIO 7 */
let listNumbers = [564, 23, 45, 67, 89, 9,76,85,2];
function searchNumber() {
  let searchUserNumber = prompt("Ingrese el numero a buscar:");
  result.innerHTML = (listNumbers.find(number => number == searchUserNumber)) ?
    alert("¡FELICIDADES!\nEl numero se encuentra en la Lista")
  :
    alert("El numero no se encuentra en la Lista");
  searchNumber.value = "";
}

/* EJERCICIO 8 */
function displayListOfPairs() {
  listOfPairs = listNumbers.filter(number => number % 2 == 0);
  alert(listOfPairs);
}