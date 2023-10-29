#include <iostream>

using namespace std;

int main()
{
int tailleTableau = 0;
cout << "Taper la taille du tableau souhaite : ";
cin >> tailleTableau;
float * tab = NULL;
tab = new float [tailleTableau];
for(int i = 0; i < tailleTableau; ++i)
{
cout << "Valeur a stocker dans la case numero " << i << " : ";
cin >> tab[i];
}
for(int i = 0; i < tailleTableau; ++i)
{
cout << "tab["<< i<< "] = " << tab[i] << endl;
}
delete [] tab;
return 0;
}
