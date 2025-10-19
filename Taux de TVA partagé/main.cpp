#include <iostream>
#include <string>
using namespace std;

class Produit {
private:
    string nom;
    float prixHT;
    static float tauxTVA;
public:

    Produit(const string& n, float p) : nom(n), prixHT(p) {
        cout << "[Création Produit] " << nom << " - Prix HT : " << prixHT << " DH" << endl;
    }


    float getPrixTTC() const {
        return prixHT * (1 + tauxTVA / 100);
    }


    void afficher() const {
        cout << nom << " | Prix HT : " << prixHT
             << " DH | Prix TTC : " << getPrixTTC() << " DH" << endl;
    }


    static void modifierTVA(float nouveauTaux) {
        tauxTVA = nouveauTaux;
        cout << "[TVA mise à jour] Nouveau taux : " << tauxTVA << "%" << endl;
    }


    static void afficherTVA() {
        cout << "Taux de TVA actuel : " << tauxTVA << "%" << endl;
    }
};


float Produit::tauxTVA = 20.0f;


int main() {
    cout << "=== Début du programme ===" << endl;

    Produit p1("Ordinateur", 8000.0);
    Produit p2("Smartphone", 4000.0);
    Produit p3("Casque audio", 500.0);

    cout << "\n--- Prix avec TVA actuelle ---" << endl;
    Produit::afficherTVA();
    p1.afficher();
    p2.afficher();
    p3.afficher();

    cout << "\n--- Changement du taux de TVA à 10% ---" << endl;
    Produit::modifierTVA(10.0);

    cout << "\n--- Prix après modification de la TVA ---" << endl;
    p1.afficher();
    p2.afficher();
    p3.afficher();

    cout << "=== Fin du programme ===" << endl;
    return 0;
}
