function sayHello(name, response) {
    alert("Soy funcion");
    response();
}


const button = document.getElementById('button-input');

button.addEventListener('click', function (e) {
    e.preventDefault();
    const name = document.getElementById('input-name').value;
    
    sayHello(name,() => {
        alert("Soy callback "+ name);
    });
});


