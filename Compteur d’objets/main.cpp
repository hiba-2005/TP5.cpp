#include <iostream>
using namespace std;

class Boite {
private:
    double longueur;
    double largeur;
    double hauteur;
    static int nbBoites;

public:

    Boite(double l, double L, double h) : longueur(l), largeur(L), hauteur(h) {
        nbBoites++;
        cout << "[Constructeur] Bo�te cr��e (" << longueur << " x " << largeur << " x " << hauteur << ")" << endl;
    }


    ~Boite() {
        nbBoites--;
        cout << "[Destructeur] Bo�te d�truite." << endl;
    }


    void afficher() const {
        cout << "Dimensions : " << longueur << " x " << largeur << " x " << hauteur << endl;
    }

    static void getNombreBoites() {
        cout << "Nombre total de bo�tes : " << nbBoites << endl;
    }
};


int Boite::nbBoites = 0;


int main() {
    cout << "=== D�but du programme ===" << endl;

    Boite b1(2.0, 3.0, 4.0);
    Boite b2(5.0, 2.5, 3.5);
    Boite b3(1.0, 1.0, 1.0);

    cout << "\n--- D�tails des bo�tes ---" << endl;
    b1.afficher();
    b2.afficher();
    b3.afficher();

    cout << "\n--- Compteur actuel ---" << endl;
    Boite::getNombreBoites();

    cout << "=== Fin du programme ===" << endl;
    return 0;
}
