package Ejer2;

public class Libros {
    private String nom;

    public Libros(String nom){
        setNom(nom);
    }

    public String getNom() {
        return nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    @Override
    public String toString() {
        return "Libros{" +
                "nom='" + nom + '\'' +
                '}';
    }
}
