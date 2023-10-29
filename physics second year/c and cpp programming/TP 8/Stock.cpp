#include <iostream>
#include <string>
using namespace std;

void operator +=(Stock& S,int n){
    S.quantite = S.quantite + n;
}

void operator -={Stock& S,int n){
    if((S.quantite - n)<0){
        cout<<"erreur";
    }
else(S.quantite = S.quantite - n);
return
}

Stock operator +(Stock stockDroit,Stock stockGauche){
    Stock S;
    if(stockDroit.nom==stockGauche.nom){
        S.nom = stockGauche.nom;
    }else(S.nom=stockDroit.nom + stockGauche.nom);
    S.quantite = stockDroit.quantite + stockGauche.quantite;
    return S;
}

void operator ++(Stock &S){
S.quantite = S.quantite + 1;
}

void operator --(Stock &S){
S.quantite = S.quantite - 1
}

ostream & operator<<(ostream &flux, Stock &S){
}

istream & operator>>(istream &flux, Stock &S){
    cout<<"nom :";
    flux>>S.nom
}
