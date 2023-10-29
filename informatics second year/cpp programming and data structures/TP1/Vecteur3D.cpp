#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

const int taille = 10;
const int taille1 = 5;
const int taille2 = 6;
const int taille3 = taille1+taille2;

const float minimum = -10.0;
const float maximum = 10.0;

//Marge d'erreur
const float epsilon = 0.01;

struct Vecteur3D{
float x, y, z;
};

float Vecteur3DGetNorme(Vecteur3D vect){
return sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2));
}

void Vecteur3DNormaliser(Vecteur3D &vect){
vect.x = vect.x / Vecteur3DGetNorme(vect);
vect.y = vect.y / Vecteur3DGetNorme(vect);
vect.z = vect.z / Vecteur3DGetNorme(vect);
}

bool Vecteur3DEstNormalise(Vecteur3D vect){
if((fabs(Vecteur3DGetNorme(vect)) - 1) < epsilon) 
return true;
return false;
}

Vecteur3D Vecteur3DAdd(Vecteur3D vect1, Vecteur3D vect2){
cout << "Adresse de vect1 : " << (long int) &vect1 << endl;
cout << "Adresse de vect2 : " << (long int) &vect2 << endl;
Vecteur3D vectAdd;
int adresse1;
double adresse2;
cout << "Adresse de vectAdd : " << (long int) &vectAdd << endl;
cout << "Adresse de adresse1 : " << (long int) &adresse1 << endl;
cout << "Adresse de adresse2 : " << (long int) &adresse2 << endl;
vectAdd.x = vect1.x + vect2.x;
vectAdd.y = vect1.y + vect2.y;
vectAdd.z = vect1.z + vect2.z;
return vectAdd;
}

void Vecteur3DAfficher(Vecteur3D vect){
cout << "(" << fixed << setprecision(1) << vect.x << "," << fixed << setprecision(1) << vect.y << "," << fixed << setprecision(1) << vect.z << ")" << endl;
}

void Vecteur3DRemplirTabVecteurs(Vecteur3D * tab, int taille){
srand(time(0));

cout << "Adresse de tab : " << (long int) &tab << endl;
for(int i = 0; i < taille; i++){
tab[i].x = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(maximum - minimum)));
tab[i].y = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(maximum - minimum)));
tab[i].z = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(maximum - minimum)));
}
}

//Fonction alternative créee pour le TP2
//void TailleOccupeeParTab(int tab){
//cout << "Taille occupée par tab : " << sizeof(tab) << endl;
//}

void Vecteur3DAfficherTabVecteur(const Vecteur3D * tab, int taille){
for(int i = 0; i < taille; i++){
Vecteur3DAfficher(tab[i]);
}
}

int Vecteur3DMaxTabVecteurs(const Vecteur3D * tab, int taille){
float max = Vecteur3DGetNorme(tab[0]);
int indice = 0;

for(int i = 1; i <= taille; i++){
if(max <= Vecteur3DGetNorme(tab[i])){
max = Vecteur3DGetNorme(tab[i]);
indice = i;
}
}

return indice;
}

void Vecteur3DConcatenationTabVecteurs(Vecteur3D * tab1, Vecteur3D * tab2, Vecteur3D * tab3, int taille1, int taille2){
for(int i = 0; i < taille1; i++){
tab3[i].x = tab1[i].x;
tab3[i].y = tab1[i].y;
tab3[i].z = tab1[i].z;
}

for(int i = taille1; i < taille1+taille2; i++){
tab3[i].x = tab2[i - taille1].x;
tab3[i].y = tab2[i - taille1].y;
tab3[i].z = tab2[i - taille1].z;
}
}

//Méthode avec le while utilisée en cours
void Vecteur3DInverseTabVecteurs(Vecteur3D * tab, int taille, int a, int b)
{
Vecteur3D aux = {0, 0, 0};

if (a < b){
aux.x = tab[a].x;
aux.y = tab[a].y; 
aux.z = tab[a].z; 
tab[a].x = tab[b].x;
tab[a].y = tab[b].y;
tab[a].z = tab[b].z;
tab[b].x = aux.x;
tab[b].y = aux.y;
tab[b].z = aux.z;
Vecteur3DInverseTabVecteurs(tab, taille, a+1, b-1);
}
}

int main(){
Vecteur3D vecteur1 = {5, 2, 1};
Vecteur3D vecteur2 = {0, 3, 2};

//(long int) afficher l'adresse mémoire d'une variable en tant que nombre entier
cout << "Adresse de vecteur1.x : " << (long int) &vecteur1.x <<endl;

cout << "vecteur1 non normalise: ";
Vecteur3DAfficher(vecteur1);
cout << endl;

cout << "vecteur2 non normalise: ";
Vecteur3DAfficher(vecteur2);
cout << endl;

cout << "somme: ";
Vecteur3DAfficher(Vecteur3DAdd(vecteur1, vecteur2));
cout << endl;

Vecteur3DNormaliser(vecteur1);
Vecteur3DNormaliser(vecteur2);

cout << "vecteur1 normalise: ";
Vecteur3DAfficher(vecteur1);
cout << endl;

cout << "vecteur2 normalise: ";
Vecteur3DAfficher(vecteur2);
cout << endl;

cout << "somme: ";
Vecteur3D somme = Vecteur3DAdd(vecteur1, vecteur2);
Vecteur3DAfficher(somme);

if(Vecteur3DEstNormalise(somme)) cout << " est normalise" << endl;
else cout << " n'est pas normalise" << endl;

Vecteur3D * tab = new Vecteur3D[taille];
cout << "Taille occupée par tab : " << sizeof(tab) << endl;

Vecteur3DRemplirTabVecteurs(tab, taille);
Vecteur3DAfficherTabVecteur(tab, taille);
cout << "indice du tableau ayant le vecteur qui a la norme la plus grande : " << Vecteur3DMaxTabVecteurs(tab, taille) << endl;

Vecteur3D * tab1 = new Vecteur3D[taille1];
Vecteur3D * tab2 = new Vecteur3D[taille2];
Vecteur3D * tab3 = new Vecteur3D[taille3];

Vecteur3DRemplirTabVecteurs(tab1, taille1);
Vecteur3DRemplirTabVecteurs(tab2, taille2);

cout << "tab1 : " << endl;
Vecteur3DAfficherTabVecteur(tab1, taille1);

cout << "tab2 : " << endl;
Vecteur3DAfficherTabVecteur(tab2, taille2);

Vecteur3DConcatenationTabVecteurs(tab1, tab2, tab3, taille1, taille2);
cout << "Concaténation tab1 et tab2 : " << endl;
Vecteur3DAfficherTabVecteur(tab3, taille3);

cout << "Inverse tab3 : " << endl;
Vecteur3DInverseTabVecteurs(tab3, 5, 0, taille3-1);
Vecteur3DAfficherTabVecteur(tab3, taille3);

//TP2
//Dans quel ordre sont empilés les éléments d’un tableau ? La case 0 a-t-elle l’adresse la plus haute ou la plus basse ?

int t[3] = {2, 3, 5};
for(int i = 0; i <= 2; ++i){
cout << "Adresse de l'indice " << i << " : " << (long int) &t[i] << endl;
}

//L'élément ayant l'indice le plus haut est en premier emplilé sur la pile. Il a l'adresse la plus haute du tableau. La case 0 du tableau a l'adresse la plus basse.

//Dans quel ordre sont empilés les paramètres d’une fonction ou d’une procédure ?

Vecteur3DAdd(vecteur1, vecteur2);

//Les valeurs des adresses des paramètres d'une fonction ne sont pas successives sur la pile. Les dernières valeur sont empilées en premier.

//Dans quel ordre sont empilées les données membres d’un objet ?

cout << "Adresse de la donnée membre x de la structure Vecteur3D : " << (long int) &vecteur1.x << endl;
cout << "Adresse de la donnée membre y de la structure Vecteur3D : " << (long int) &vecteur1.y << endl;
cout << "Adresse de la donnée membre z de la structure Vecteur3D : " << (long int) &vecteur1.z << endl;

//Les adresses sont stockées successivement dans la pile. La dernière donnée membre déclarée est empilée en premier car elle a l'adresse la plus haute.

//Les variables locales d’un même sous-programme sont-elles, comme en TD, dans l’ordre dans lequel elles étaient déclarées dans le code ?

//Les variables locales d'un même sous-programme sont dans l'ordre dans lequel elles sont déclarées dans le code. Les adresses les plus haute appartiennent aux premières variables déclarées.

// e. Lorsque l’un des paramètres d’un sous-programme est un tableau, combien d’octets ce paramètre occupe-t-il dans la frame du sous-programme ? Le tableau est-il recopié dans cette frame ?

//TailleOccupeeParTab(t);

//Lorsque l'un des paramètre d’un sous-programme est un tableau, ce paramètre occupe 8 octets dans la frame du sous-programme car seulement son adresse mémoire est recopié. Pas de copie.

//Quel écart observez-vous entre l’adresse la plus haute et l’adresse la plus basse, parmi les adresses affichées ? Cet écart correspond-il à l’écart théorique (celui de votre trace « papier ») ? Demandez à votre encadrant d’où vient cette différence.

cout << "hello" << endl;

for(int i = 0; i < taille; ++i){
tab[i] = {0, 0, 0};
}
delete [] tab;
for(int i = 0; i < taille1; ++i){
tab1[i] = {0, 0, 0};
}
delete [] tab1;
for(int i = 0; i < taille2; ++i){
tab2[i] = {0, 0, 0};
}
delete [] tab2;
for(int i = 0; i < taille3; ++i){
tab2[i] = {0, 0, 0};
}
delete [] tab3;
return 0;
}
