#include <iostream>

using namespace std;

#include "date.h"

date :: date(){
    cout<<"un constructeur a ete appele"<<endl;
    jour = new int;
    mois = new int;
    annee = new int;
    *jour = 1;
    *mois = 9;
    *annee = 2020;
}


date :: date(int j,int m,int a){
    cout<<"un constructeur a ete appele"<<endl;
    jour = new int;
    mois = new int;
    annee = new int;
    *jour = j;
    *mois = m;
    *annee = a;
}

date :: date(const date& d){
    cout<<"un constructeur a ete appele"<<endl;
    jour = new int;
    mois = new int;
    annee = new int;
    *jour = *d.jour;
    *mois = *d.mois;
    *annee = *d.annee;

}

date :: ~date(){
    cout<<"le destructeur a ete appele"<<endl;
    delete jour;
    delete mois;
    delete annee;
}


void date :: definirDate(int j,int m,int a){
    *jour = j;
    *mois = m;
    *annee = a;
}


void date :: afficheDate(){
    cout<<*jour<<" "<<*mois<<" "<<*annee<<" "<<endl;
}

bool date :: operator ==(const date &d){
    if ((*jour == *d.jour)and(*mois == *d.mois)and(*annee == *d.annee)){
                return true;
        }
    return false;
}

date& date :: operator = (const date& d){
    *jour = *d.jour;
    *mois = *d.mois;
    *annee = *d.annee;
}

istream& operator>>(istream &flux,date& d){
    cout<<"jour = ";
    flux >> *d.jour;
    cout<<"mois = ";
    flux>>*d.mois;
    cout<<"annee = ";
    flux>>*d.annee;
    return flux;
}

ostream& operator<<(ostream &flux,date& d){
flux<<*d.jour<<"/"<<*d.mois<<"/"<<*d.annee;
return flux;
}

bool date :: anneeBissextile(){
    if(*annee%4==0){
        return true;
    }
return false;
}

date date :: operator + (int j){
    int nbjour[]={31,28,31,30,31,30,31,31,30,31,30,31};
    date d (j+*jour , *mois , * annee);
        int i;
   i = *d.mois -1;
   while (*d.jour>nbjour[i]) {
        *d.jour = *d.jour-nbjour[i];
        *d.mois = *d.mois + 1;
        i+=1;
}
    return d;
}

