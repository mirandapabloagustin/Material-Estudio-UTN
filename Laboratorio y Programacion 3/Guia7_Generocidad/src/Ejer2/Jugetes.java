package Ejer2;

public class Jugetes {
    private String nom;

    public Jugetes(String nom){
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
        return "Jugetes{" +
                "nom='" + nom + '\'' +
                '}';
    }
}
