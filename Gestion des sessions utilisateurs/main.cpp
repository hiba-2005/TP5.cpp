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
        cout << "[Connexion] " << nom << " (" << role << ") est connect�." << endl;
        afficherNbConnectes();
    }


    ~Utilisateur() {
        nbUtilisateursConnectes--;
        cout << "[D�connexion] " << nom << " (" << role << ") est d�connect�." << endl;
        afficherNbConnectes();
    }


    static int getNbUtilisateursConnectes() {
        return nbUtilisateursConnectes;
    }


    static void afficherNbConnectes() {
        cout << "Nombre d�utilisateurs connect�s : " << nbUtilisateursConnectes << endl;
    }


    void afficher() const {
        cout << "Utilisateur : " << nom << " | R�le : " << role << endl;
    }
};


int Utilisateur::nbUtilisateursConnectes = 0;


int main() {
    cout << "=== D�but du programme ===" << endl;

    {
        Utilisateur u1("Amine", "admin");
        Utilisateur u2("Sara", "visiteur");

        cout << "\n--- �tat actuel ---" << endl;
        Utilisateur::afficherNbConnectes();

        {
            Utilisateur u3("Hiba", "�diteur");
            cout << "\n--- Apr�s nouvelle connexion ---" << endl;
            Utilisateur::afficherNbConnectes();
        }

        cout << "\n--- Apr�s d�connexion de Hiba ---" << endl;
        Utilisateur::afficherNbConnectes();
    }

    cout << "\n--- Apr�s d�connexion de tous ---" << endl;
    Utilisateur::afficherNbConnectes();

    cout << "=== Fin du programme ===" << endl;
    return 0;
}
