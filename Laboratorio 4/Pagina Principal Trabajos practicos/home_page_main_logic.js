document.addEventListener("DOMContentLoaded", function () {
    const gallery = document.querySelector(".image-gallery");
    //se obtienen todas las imagenes del div
    const images = gallery.querySelectorAll("img");
    //se obtiene el boton de siguiente
  let currentImageIndex = 0;

    function showNextImage() {
      // Ocultar la imagen actual
        images[currentImageIndex].style.display = "none";
        // Incrementar el índice de la imagen actual
        currentImageIndex = (currentImageIndex + 1) % images.length;
        // Mostrar la siguiente imagen
    images[currentImageIndex].style.display = "block";
  }

  setInterval(showNextImage, 3000); // Cambiar de imagen cada 3 segundos (3000 ms)
});
