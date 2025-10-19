#include <iostream>
#include <string>
using namespace std;

class Utilisateur {
private:
    string nom;
    string role;
    static int nbUtilisateursConnectes;

public:

    Utilisateur(const string& n, const string& r) : nom(n), role(r) {
        nbUtilisateursConnectes++;
        cout << "[Connexion] " << nom << " (" << role << ") est connecté." << endl;
        afficherNbConnectes();
    }


    ~Utilisateur() {
        nbUtilisateursConnectes--;
        cout << "[Déconnexion] " << nom << " (" << role << ") est déconnecté." << endl;
        afficherNbConnectes();
    }


    static int getNbUtilisateursConnectes() {
        return nbUtilisateursConnectes;
    }


    static void afficherNbConnectes() {
        cout << "Nombre d’utilisateurs connectés : " << nbUtilisateursConnectes << endl;
    }


    void afficher() const {
        cout << "Utilisateur : " << nom << " | Rôle : " << role << endl;
    }
};


int Utilisateur::nbUtilisateursConnectes = 0;


int main() {
    cout << "=== Début du programme ===" << endl;

    {
        Utilisateur u1("Amine", "admin");
        Utilisateur u2("Sara", "visiteur");

        cout << "\n--- État actuel ---" << endl;
        Utilisateur::afficherNbConnectes();

        {
            Utilisateur u3("Hiba", "éditeur");
            cout << "\n--- Après nouvelle connexion ---" << endl;
            Utilisateur::afficherNbConnectes();
        }

        cout << "\n--- Après déconnexion de Hiba ---" << endl;
        Utilisateur::afficherNbConnectes();
    }

    cout << "\n--- Après déconnexion de tous ---" << endl;
    Utilisateur::afficherNbConnectes();

    cout << "=== Fin du programme ===" << endl;
    return 0;
}
