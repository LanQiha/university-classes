#include <iostream>

using namespace std;

#include "Liste.h"

int main()
{
    cout << "Creation d'une liste chainee l." << endl;
    Liste l;
  
    cout << "ajouteEnTete : ";
    l.ajouterEnTete(1);
    l.afficherGaucheDroite();

    cout << "ajouteEnTete : ";
    l.ajouterEnTete(2);
    l.afficherGaucheDroite();

    cout << "supprimeTete : ";
    l.supprimerTete();
    l.afficherGaucheDroite();

    cout << "ajouteEnTete : ";
    l.ajouterEnTete(2);
    l.afficherGaucheDroite();
    
    cout << "ajouteEnQueue : ";
    l.ajouterEnQueue(10);
    l.afficherGaucheDroite();
    
    cout << "afficherDroiteGauche : ";
    l.afficherDroiteGauche();
    
    cout << "nbElements : " << l.nbElements() << endl;
    
    unsigned int nb = 1;
    
    cout << "iemeElement a l'indice " << nb << " : " << l.iemeElement(nb) << endl;
    
    cout << "modifierIemeElement a l'indice " << nb << " : ";
    l.modifierIemeElement(1, 3);
    l.afficherGaucheDroite();
    
    cout << "ajouteEnTete : ";
    l.ajouterEnTete(4);
    l.afficherGaucheDroite();
    
    ElementL e = 10;
    
    cout << "rechercherElement " << e << " : " << l.rechercherElement(e) << endl;
    
    cout << "ajouterEnTete : ";
    l.ajouterEnQueue(5);
    l.afficherGaucheDroite();
    
    cout << "estVide (0 pour faux, 1 pour vrai) : " << l.estVide() << endl;
    
    nb = 3;
    
    cout << "insererElement a l'indice " << nb << " : ";
    l.insererElement(6, 3);
    l.afficherGaucheDroite();
    
    Liste li;
    li = l;
    cout << "liste li (copie de l) : ";
    li.afficherGaucheDroite();
    
    cout << "trier : ";
    l.trier();
    l.afficherGaucheDroite();
    
    l.vider();
    cout << "l.vider() : ";
    l.afficherGaucheDroite();
   
    cout << "l.estVide() ? : " << l.estVide();
    
    cout << " " << endl;
    cout << "Les fonctions ont ete correctement appelee." << endl;

    return 0;
}
