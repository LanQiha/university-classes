#include <iostream>

using namespace std;

#include "TableauDynamique.h"

int main()
{
    TableauDynamique tab1;
    TableauDynamique tab2;

    tab1.ajouterElement(1);
    tab1.ajouterElement(2);
    tab1.ajouterElement(3);
    tab1.ajouterElement(5);
    tab1.ajouterElement(7);

    tab1.afficher();

    tab2.ajouterElement(3);
    tab2.ajouterElement(4);
    tab2.ajouterElement(6);
    tab2.ajouterElement(7);
    tab2.ajouterElement(9);
    tab2.ajouterElement(12);
    tab2.ajouterElement(15);

    tab2.afficher();

    TableauDynamique * tab = tab1.unionTab(tab2);

    tab->afficher();

    return 0;
}
