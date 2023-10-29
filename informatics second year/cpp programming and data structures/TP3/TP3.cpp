// Dans ce TP, nous allons écrire un programme qui va trier des tableaux de nombres complexes.

/* Exercice 1 : Définition du type nombre complexe
a. Définissez le type NbComplexe à l'aide d'une classe. Rappel : un nombre complexe est défini par sa partie réelle (que vous pourrez appeler re) et sa partie imaginaire (que vous pourrez appeler im).
b. Ajoutez deux procédures membres à cette classe : une pour saisir le nombre complexe au clavier
(initialisation des données membres) et une pour afficher le nombre complexe à l’écran sous le format : re
+im i si la partie imaginaire est positive ou nulle, et re –im i si elle est négative.
c. Créez un main qui crée un nombre complexe sur la pile, l’affiche, puis le saisi et le réaffiche. Qu’obtenez-vous ?
d. Quelle instruction permet d’afficher la taille, en octets, d’un nombre complexe ? */

/* Exercice 2 :Constructeur, destructeur et allocation dynamique
a. Ajoutez à la classe NbComplexe trois constructeurs et un destructeur. Le premier constructeur sera sans
paramètre, le deuxième aura deux paramètres pour les deux parties du nombre complexe, et le troisième
est un constructeur par copie.
b. Ajoutez une procédure membre multiplier qui multiplie le nombre complexe par un autre nombre
complexe passé en paramètre. L’instance courante contient le résultat de la multiplication, le nombre
complexe avec lequel on multiplie n’est pas modifié.
Rappel : (𝑟𝑒1 + 𝑖𝑚1 𝑖) × (𝑟𝑒2 + 𝑖𝑚2 𝑖) = (𝑟𝑒1 × 𝑟𝑒2 − 𝑖𝑚1 × 𝑖𝑚2) + (𝑖𝑚1 × 𝑟𝑒2 + 𝑟𝑒1 × 𝑖𝑚2) 𝑖
c. Complétez le main en ajoutant la création d’un nouveau nombre complexe comme étant une copie du
nombre saisi à l’exercice précédent (affichez le pour vérifier que votre constructeur fonctionne
correctement). Ensuite créez un nombre complexe différent sur le tas et affichez le. Finallement, multipliez les deux nombres et affichez le résultat. */

/* Exercice 3 : Comparaison de deux nombres complexes
Ajoutez dans la classe NbComplexe les deux fonctions membres suivantes :
une fonction module qui retourne le module du nombre complexe. Rappel : |𝑟𝑒 + 𝑖𝑚 𝑖| = √𝑟𝑒2 + 𝑖𝑚2
une fonction estPlusPetit qui indique si le nombre complexe est plus petit qu’un autre nombre
complexe passé en paramètre. La comparaison se fera sur les valeurs des modules des deux nombres.
Testez ces deux fonctions sur quelques nombres complexes. */

/* Exercice 4 : Création d'un tableau de nombres complexes aléatoires
a. Dans le main, allouez de la mémoire pour un tableau de nombres complexes dont la taille sera saisie par
l'utilisateur.
b. Remplissez le tableau avec des nombres complexes dont les parties réelles et imaginaires sont tirées
aléatoirement dans l’intervalle [-10,10] avec exactement 1 décimale de précision. L’annexe B décrit
comment faire un tirage aléatoire d’une valeur entière dans un intervalle.
c. Affichez le tableau de nombres complexes ainsi rempli et pour chaque élément du tableau affichez
également le module du nombre complexe. N'oubliez pas de libérer la mémoire allouée dynamiquement
quand vous en n’avez plus besoin */

/* Exercice 5 : Tri par sélection du tableau de nombres complexes
Définissez une procédure globale (pas une procédure membre) trierParSelection qui prend en
paramètres un tableau de nombres complexes et sa taille, et qui le trie du nombre le plus petit au plus grand (en termes de module), en utilisant l'algorithme de tri par sélection. Testez votre procédure dans le main. */

/* Exercice 6 : Tri par insertion du tableau de nombres complexes
Définissez une procédure globale (pas une procédure membre) trierParInsertion qui prend en
paramètres un tableau de nombres complexes et sa taille, et qui le trie du nombre le plus petit au plus grand (en termes de module), en utilisant l'algorithme de tri par insertion. Testez votre procédure dans le main. */

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

const float minimum = -10.0;
const float maximum = 10.0;

class NbComplexe
{
public:
NbComplexe() : re(0), im(0) {}
NbComplexe(int _re, int _im) : re(_re), im(_im) {}
NbComplexe(const NbComplexe & _complexe){
re = _complexe.re;
im = _complexe.im;
}

float moduleComplexe(){
return sqrt(pow(re, 2) + pow(im, 2));
}

bool estPlusPetit(NbComplexe & complexe){
if(complexe.moduleComplexe() > this->moduleComplexe())
return true;
else
return false;
}

NbComplexe operator* (const NbComplexe & other){
NbComplexe complexe(0,0);
complexe.re = re * other.re - im * other.im;
complexe.im = im * other.re + re * other.im;
return complexe;
}

void saisirNbComplexe(){
cout << "Saisir re : " << endl;
cin >> re;
cout << "Saisir im : " << endl;
cin >> im;
}

void afficherNbComplexe () const {
/*if(im >= 0)
cout << re << " + " << im << endl;
else
cout << re << " " << im << endl;*/
cout << re << ((im>=0)? "+" : " ")<< im << endl;
}

~NbComplexe(){}

float re, im;
};

// Exercice 5

void trierParSelection(NbComplexe * tab, int taille){
int min = 0;
NbComplexe complexe;
for(int i = 0; i < taille-1; i++){
min = i;
for(int j = i+1; j < taille; j++){
if(tab[j].moduleComplexe() < tab[min].moduleComplexe())
min = j;
}
if(min != i){
complexe = tab[i];
tab[i] = tab[min];
tab[min] = complexe;
}
}
}

// Exercice 6

void trierParInsertion(NbComplexe * tab, int taille){
NbComplexe complexe;
int j = 0;
for(int i = 1; i < taille; i++){
complexe = tab[i];
j = i;
while(j > 0 and tab[j-1].moduleComplexe() > complexe.moduleComplexe()){
tab[j] = tab[j-1];
j = j-1;
}
tab[j] = complexe;
}
}

int main(){
// Exercice 1
NbComplexe complexe;
complexe.afficherNbComplexe();
complexe.saisirNbComplexe();
complexe.afficherNbComplexe();
cout << "taille, en octets, d’un nombre complexe : " << sizeof(NbComplexe) << endl;

// Exercice 2
NbComplexe other(complexe);
other.afficherNbComplexe();
NbComplexe * ptrComplexe = new NbComplexe(2,3);
ptrComplexe->afficherNbComplexe();
NbComplexe resultat(0,0);
resultat = *ptrComplexe * other;
resultat.afficherNbComplexe();

// Exercice 3
cout << "Module de complexe : " << complexe.moduleComplexe() << endl;
cout << "Module de ptrComplexe : " << ptrComplexe->moduleComplexe() << endl;
cout << "complexe.estPlusPetit(*ptrComplexe) : " << complexe.estPlusPetit(*ptrComplexe) << endl;

// Exercice 4
int tailleTab = 0;
cout << "taille du tableau : "; cin >> tailleTab;
NbComplexe * tabComplexe = new NbComplexe [tailleTab];
srand(time(0));
for(int i = 0; i < tailleTab; ++i){
tabComplexe[i].re = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(maximum - minimum)));
tabComplexe[i].im = minimum + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(maximum - minimum)));
}
for(int i = 0; i < tailleTab; ++i){
cout << "tab[" << i << "].re = " << tabComplexe[i].re << ", " << "tab[" << i << "].im = " << tabComplexe[i].im << ", " << "module = " << tabComplexe[i].moduleComplexe() << endl;
}


// Exercice 5
cout << "Trie par selection : " << endl;
trierParSelection(tabComplexe, tailleTab);
for(int i = 0; i < tailleTab; ++i){
cout << "tab[" << i << "].re = " << tabComplexe[i].re << ", " << "tab[" << i << "].im = " << tabComplexe[i].im << ", " << "module = " << tabComplexe[i].moduleComplexe() << endl;
}

// Exercice 6
/* trierParInsertion(tabComplexe, tailleTab);
cout << "Trie par insertion : " << endl;
for(int i = 0; i < tailleTab; ++i){
cout << "tab[" << i << "].re = " << tabComplexe[i].re << ", " << "tab[" << i << "].im = " << tabComplexe[i].im << ", " << "module = " << tabComplexe[i].moduleComplexe() << endl;
} */

// libération de la mémoire allouée dynamiquement
delete ptrComplexe;
delete [] tabComplexe;

return 0;
}
