#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

const float minimum = -10.0;
const float maximum = 10.0;

struct Vecteur3D{
float x, y, z;
};

int main(){
srand(time(0));

Vecteur3D vect;
Vecteur3D * vectPtr = new Vecteur3D;

cout << "Taille occupée par vectPtr : " << sizeof(vectPtr) << endl;
cout << "Taille occupée par vect : " << sizeof(vect) << endl;

Vecteur3D * vectTabTas = new Vecteur3D[3];
Vecteur3D vectTabPile[3];

cout << "Taille occupée par vectTabTas : " << sizeof(vectTabTas) << endl;
cout << "Taille occupée par vectTabPile : " << sizeof(vectTabPile) << endl;

for(int i = 0; i < 3; i++){
vectTabTas[i].x = vectTabPile[i].x = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(maximum - minimum)));
vectTabTas[i].y = vectTabPile[i].y = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(maximum - minimum)));
vectTabTas[i].z = vectTabPile[i].z = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(maximum - minimum)));
}

cout << "Après les valeurs alea : " << endl;
cout << "Taille occupée par vectTabTas : " << sizeof(vectTabTas) << endl;
cout << "Taille occupée par vectTabPile : " << sizeof(vectTabPile) << endl;

cout << "Adresse du premier elément de vectTabTas : " << (long int) vectTabTas << endl;
cout << "Adresse du premier elément de vectTabPile : " << (long int) vectTabPile << endl;

cout << "Adresse x du deuxième elément de vectTabTas : " << (long int) &vectTabTas[1].x << endl;
cout << "Adresse y du deuxième elément de vectTabTas : " << (long int) &vectTabTas[1].y << endl;
cout << "Adresse z du deuxième elément de vectTabTas : " << (long int) &vectTabTas[1].z << endl;

cout << "Adresse x du deuxième elément de vectTabPile : " << (long int) &vectTabPile[1].x << endl;
cout << "Adresse y du deuxième elément de vectTabPile : " << (long int) &vectTabPile[1].y << endl;
cout << "Adresse z du deuxième elément de vectTabPile : " << (long int) &vectTabPile[1].z << endl;

cout << "vectTabTas+2 : " << (long int) vectTabTas+2 << endl;
// *(vectTabTas+2) deréférence la case numéro 2 du tableau vectTabTas cependant ce que contient la case est un Vecteur3D donc on ne peut pas l'afficher comme cela.

vectTabPile[1].x = vectTabTas[1].y - vectTabTas[2].z;
cout << "Adresse x du deuxième elément de vectTabPile : " << (long int) &vectTabPile[1].x << endl;
cout << "Adresse x du deuxième elément de vectTabPile : " << &vectTabPile[1].x << endl;

delete vectPtr;
delete [] vectTabTas;

return 0;
}
