#include <iostream>
using namespace std;

// Préconditions :  p et n > 0 et p < n
// Pas de postconditions
// Resultat : calcule les p, n combinaisons

/* Calcul d’un coefficient binomial à l’aide du triangle de Pascal */
int comb(int n, int p) {
int tmp1, tmp2;
cout <<"Calcul du nb de combinaisons de "<<p<<" elts parmi "<<n<<endl;
if ((p==0) || (n==p))
return 1;
tmp1 = comb(n-1, p-1); /* premier appel récursif */
tmp2 = comb(n-1, p); /* second appel récursif */
return tmp1 + tmp2;
}

void comb(int n, int p, int &resultat)
{
int tmp1, tmp2;
cout <<"Calcul du nb de combinaisons de "<<p<<" elts parmi "<<n<<endl;
if ((p==0) || (n==p))
resultat = 1; // Postcondition
tmp1 = comb(n-1, p-1); /* premier appel récursif */
tmp2 = comb(n-1, p); /* second appel récursif */
resultat = tmp1 + tmp2; // Postcondition
}

// Postcondition : Pointeur doit etre alloué
void comb(int n, int p, int * ptr)
{
int tmp1, tmp2;
cout <<"Calcul du nb de combinaisons de "<<p<<" elts parmi "<<n<<endl;
if ((p==0) || (n==p))
*ptr = 1;
tmp1 = comb(n-1, p-1); /* premier appel récursif */
tmp2 = comb(n-1, p); /* second appel récursif */
*ptr = tmp1 + tmp2;
}


int main() {
int c;
c = comb(4, 3);

int resultat;
comb(4, 3, resultat);

int * ptr = NULL;
comb(4, 3, ptr);

cout << "c vaut " << c << endl;
cout << "resultat vaut " << resultat << endl;
cout << "resultat vaut " << *ptr << endl;

delete ptr;

return 0;
}
