#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

// Exercice 1 
class NbComplexe
{
public:
float re, im;

NbComplexe(float _re = 0.0, float _im = 0.0) : re(_re), im(_im) {}

void operator = (const NbComplexe & complexe){
re = complexe.re;
im = complexe.im;
}

bool operator < (const NbComplexe & complexe) const {
return (this->moduleComplexe() > complexe.moduleComplexe());
}

NbComplexe operator * (const NbComplexe & other) const {
NbComplexe complexe(0,0);
complexe.re = re * other.re - im * other.im;
complexe.im = im * other.re + re * other.im;
return complexe;
}

friend ostream & operator << (ostream & flux, const NbComplexe & complexe){
flux << complexe.re << ((complexe.im >= 0)? " + " : " ") << complexe.im;
return flux;
}

friend istream & operator >> (istream & flux, NbComplexe & complexe){
flux >> complexe.re >> complexe.im;
return flux;
}

float moduleComplexe() const {
return sqrt(pow(re, 2) + pow(im, 2));
}

~NbComplexe(){}
};

// Trie par selection
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

// Trie par insertion
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

// Exercice 2
void lireTabNbComplexeDepuisFichier(NbComplexe * tab, int & taille, string _fichier){
ifstream fichier(_fichier);
string premiereLigne;
getline(fichier, premiereLigne);
taille = stoi(premiereLigne);
for (int i = 0; i < taille; i++){
if (fichier >> tab[i].re >> tab[i].im){
fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// cout << "re : " << tab[i].re << endl;
// cout << "im : " << tab[i].im << endl;
}
}
// cout << "taille : " << taille << endl;
}

// Exercice 3
void ecrireTabNbComplexeDansFichier(NbComplexe * tab, int taille, string _fichier){
ofstream fichier(_fichier);
fichier << to_string(taille) + "\n";
for(int i = 0; i < taille; ++i){
fichier << to_string(tab[i].re) + " " + to_string(tab[i].im) + " i\n";
}
}

int main(){

// Exercice 2
string fichierRandom = "random.txt";
string fichierSorted = "sorted.txt";
string fichierReverse = "reverse.txt";

int taille = 20000;

NbComplexe * tabRandom = new NbComplexe [taille];
NbComplexe * tabSorted = new NbComplexe [taille];
NbComplexe * tabReverse = new NbComplexe [taille];

lireTabNbComplexeDepuisFichier(tabRandom, taille, fichierRandom);
lireTabNbComplexeDepuisFichier(tabSorted, taille, fichierSorted);
lireTabNbComplexeDepuisFichier(tabReverse, taille, fichierReverse);

for(int i = 0; i < taille; ++i){
cout << tabRandom[i] << endl;
}

// Exercice 3
string fichierEcrire = "tab.txt";
ecrireTabNbComplexeDansFichier(tabSorted, taille, fichierEcrire);

// Exercice 4
// Trie par insertion : 
/* clock_t tempsExecution = clock();
trierParInsertion(tabRandom, taille); // environ 6.8 secondes.
tempsExecution = clock() - tempsExecution;
cout << "Execution du trie par insertion de tabRandom en " << ((float)tempsExecution)/CLOCKS_PER_SEC << " secondes." << endl;

clock_t tempsExecution2 = clock();
trierParInsertion(tabSorted, taille); // environ 0.0014 secondes.
tempsExecution2 = clock() - tempsExecution2;
cout << "Execution du trie par insertion de tabSorted en " << ((float)tempsExecution2)/CLOCKS_PER_SEC << " secondes." << endl;

clock_t tempsExecution3 = clock();
trierParInsertion(tabReverse, taille); // environ 13.5 secondes.
tempsExecution3 = clock() - tempsExecution3;
cout << "Execution du trie par insertion de tabReverse en " << ((float)tempsExecution3)/CLOCKS_PER_SEC << " secondes." << endl;

// Trie par selection : 
clock_t tempsExecution4 = clock();
trierParSelection(tabRandom, taille); // environ 13.5 secondes.
tempsExecution4 = clock() - tempsExecution4;
cout << "Execution du trie par selection de tabRandom en " << ((float)tempsExecution4)/CLOCKS_PER_SEC << " secondes." << endl;

clock_t tempsExecution5 = clock();
trierParSelection(tabSorted, taille); // environ 13.5 secondes.
tempsExecution5 = clock() - tempsExecution5;
cout << "Execution du trie par selection de tabSorted en " << ((float)tempsExecution5)/CLOCKS_PER_SEC << " secondes." << endl;

clock_t tempsExecution6 = clock();
trierParSelection(tabReverse, taille); // environ 13.5 secondes.
tempsExecution6 = clock() - tempsExecution6;
cout << "Execution du trie par selection de tabReverse en " << ((float)tempsExecution6)/CLOCKS_PER_SEC << " secondes." << endl; */

NbComplexe comp;
cin >> comp;

// Liberation de la mémoire allouée
delete [] tabRandom;
delete [] tabSorted;
delete [] tabReverse;
return 0;
}
