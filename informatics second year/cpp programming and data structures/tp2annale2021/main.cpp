#include <iostream>

using namespace std;

#include "TableauDynamique.h"

#include <stdlib.h>
#include <time.h>

int main()
{
    TableauDynamique tab;
    for(int i = 0; i < 5; ++i)
        tab.ajouterElement(rand()%(10-0+1)+0);
    tab.afficherDonnees();
    tab.ajuster();
    tab.afficherDonnees();
    for(int i = 0; i < 7; ++i)
        tab.ajouterElement(rand()%(10-0+1)+0);
    tab.afficherDonnees();
    tab.ajuster();
    tab.afficherDonnees();
    return 0;
}
