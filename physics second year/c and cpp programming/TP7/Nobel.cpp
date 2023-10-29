#include<iostream>
#include<string>
#include<vector>
using namespace std;


struct Nobel {string nom; string discipline; int annee; int age; string pays};


vector<nobel>lecture(){
fstream f
f.open("tp7nobel.txt"),ios::in);
f>>struct.nom>>struct.discipline>>struct.annee>>struct.age>>struct.pays;
f.close;
return 0;
}


/*void anneelaureats(vector<nobel> NO){
vector<nobel> Ann
int Ann;
cout<<"Annee choisie : "<<Ann; cin Ann;
for(i)
if(Ann==)
}*/


/*void payslaureats(vector<nobel> NO)


double agemoyen(vector<nobel> NO,string dis)


vector<nobel> selectDiscipline(vector<nobel> NO,string dis)*/


/*int menu()
{
    int choix(5)
    cout<<"Que voulez-vous faire?"<<endl;
    cout<<"1) Trouver les laureats pour une annee donnee."<<endl;
    cout<<"2) Compter le nombre de laureats d'un pays."<<endl;
    cout<<"3) Calculer l'age moyen des laureats."<<endl;
    cout<<"4) Calculer l'age moyen des laureats pour une discipline donnee."<<endl;
    cout<<"5) Quitter le programme."<<endl;
    cout<<"Choix : "; cin>>choix;
    return choix;

}*/
