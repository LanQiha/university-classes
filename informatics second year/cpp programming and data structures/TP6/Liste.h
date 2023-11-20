#ifndef _LISTE
#define _LISTE

#include "Element.h"

struct Cellule {
    ElementL info;
    Cellule * suivant;
    Cellule * precedent;
};

class Liste {
public:
    /* Donn�es membres */
    /* =============== */
    Cellule * prem;
    Cellule * last;

    /* Fonctions membres */
    /* ================= */
    Liste ();
    /* Postcondition : la liste est initialement vide */

    ~Liste ();
    /* Postcondition : la m�moire allou�e sur le tas est lib�r�e */

    Liste& operator = (const Liste & l);
    /* Postcondition : la liste correspond � une copie de l (mais les 2 listes sont totalement ind�pendantes l'une de l'autre) */

    void vider ();
    /* Postcondition : la liste ne contient plus aucune cellule */

    bool estVide () const;
    /* R�sultat : vrai si liste vide, faux sinon */

    unsigned int nbElements () const;
    /* R�sultat : nombre d'�l�ments contenus dans la liste */

    ElementL iemeElement (unsigned int indice) const;
    /* Precondition : la liste n'est pas vide, et 0 <= indice < nombre d'�l�ments
       R�sultat : valeur de l'�l�ment � l'indice en param�tre, sachant que les �l�ments sont num�rotes � partir de 0 */

    void modifierIemeElement (unsigned int indice, ElementL e);
    /* Precondition : la liste n'est pas vide, et 0 <= indice < nombre d'�l�ments
       Postcondition : e remplace l'�l�ment � l'indice en param�tre, sachant que les �l�ments sont num�rotes � partir de 0 */

    void afficherGaucheDroite () const;
    /* Postcondition : affichage de tous les �l�ments, en commen�ant par le premier (espacement entre les �l�ments) */

    void afficherDroiteGauche () const;
    /* Postcondition : affichage de tous les �l�ments, en commen�ant par le dernier (espacement entre les �l�ments) */

    void ajouterEnTete (ElementL e);
    /* Postcondition : e est ajout� en t�te de liste */

    void ajouterEnQueue (ElementL e);
    /* Postcondition : e est ajout� en fin de liste */

    void supprimerTete ();
    /* Precondition : la liste n'est pas vide
       Postcondition : la liste perd son premier �l�ment */

    int rechercherElement (ElementL e) const;
    /* R�sultat : position de la premi�re occurrence de e dans la liste (en partant de la gauche),
                  -1 si e n'est pas dans la liste. Les cellules sont num�rot�es � partir de 0, donc une valeur de retour �gale � 0
                  signifie que la premi�re occurrence de e se trouve dans la premi�re cellule de la liste. */

    void insererElement (ElementL e, unsigned int indice);
    /* Preconditions : 0 <= indice <= nombre d'�l�ments
       Postconditions : une copie ind�pendante de e est ins�r�e de sorte qu'elle occupe la position d'indice en param�tre */

    void trier ();
    /* Postcondition : la liste est tri�e dans l'ordre croissant des valeurs des �l�ments */

};

#endif
