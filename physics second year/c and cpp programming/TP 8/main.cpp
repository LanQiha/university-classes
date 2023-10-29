#include <iostream>
#include <string>

using namespace std;

struct Stock {std::string nom; int quantite;};

void operator +=(Stock& S,int n){
    S.quantite = S.quantite + n;
}

void operator -=(Stock& S,int n){
    if((S.quantite - n)<0){
            cout<<"erreur";
    }
else(S.quantite = S.quantite - n);

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
S.quantite = S.quantite - 1;
}

ostream & operator<<(ostream &flux, Stock &S){
    flux<<S.nom<<"("<<S.quantite<<")";
    return flux;
}

istream & operator>>(istream &flux, Stock &S){
    cout<<"nom : ";
    flux>>S.nom;
    cout<<"quantite = ";
    flux>>S.quantite;
    return flux;
}


int main()
{
int n;
Stock S;
cin>>S;
cout<<S<<endl;
cout<<"n = ";
cin>>n;
S+=n;
cout<<S<<endl;

cout<<"n = ";
cin>>n;
S-=n;
cout << S <<endl;

Stock S2;
Stock stockDroit;
Stock stockGauche;
cout <<"entrer stock droit et gauche " << endl;
cin>>stockDroit;
cin>>stockGauche;
Stock tot(stockDroit + stockGauche);

cout <<tot;


    return 0;
}
