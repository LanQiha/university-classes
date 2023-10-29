#include<iostream>
#include<string>
#include<vector>
#include<fstream>


using namespace std;

struct nobel {string nom; string discipline; int annee; int age; string pays;};


vector<nobel>lecture(){
ifstream f;
f.open("tp7nobel.txt");
int n;
f>>n;
vector<nobel> A(n);
for(int i=0; i<n; i++){
    f>>A[i].nom>>A[i].discipline>>A[i].annee>>A[i].age>>A[i].pays;
}
f.close();
return A;
}


void anneelaureats(vector<nobel> NO){

int A;
cout<<"Annee choisis : ";
cin>>A;
for(int i=0;i<19;i++){
    if(A==NO[i].annee){
        cout<<NO[i].nom<<endl;
   }
}
}


void payslaureats(vector<nobel> NO){
string Pays;
cout<<"Pays choisis : ";
cin>>Pays;
int compteur;
compteur = 0;
for(int i=0;i<19;i++){
    if(Pays==NO[i].pays){
        compteur = compteur + 1;
    }
}
cout<<compteur<<" laureat pour ce pays"<<endl;
}


double agemoyen(vector<nobel>NO,string dis){
    int age;
    age = 0;
    int compt;
    compt = 0;
    double amoy (0.);
    for(int i=0;i<19;i++){
        if(dis==NO[i].discipline) {
            compt = compt + 1;
            age = age + NO[i].age;}

    }
    amoy = (((1.0)*age)/compt);
    return amoy;
}


vector<nobel>selectDiscipline(vector<nobel> NO,string dis){
vector<nobel> nobeldis;
for(int i=0; i<19;i++){
    if(dis==NO[i].discipline){
        nobeldis.push_back(NO[i]);
    }
}
return nobeldis;
}

int menu()
{
    int choix(5);
    cout<<"Que voulez-vous faire?"<<endl;
    cout<<"1) Trouver les laureats pour une annee donnee."<<endl;
    cout<<"2) Compter le nombre de laureats d'un pays."<<endl;
    cout<<"3) Calculer l'age moyen des laureats."<<endl;
    cout<<"4) affiche les laureat d'une discipline."<<endl;
    cout<<"5) Quitter le programme."<<endl;
    cout<<"Choix : "; cin>>choix;
    return choix;

}


int main()
{
    vector<nobel>B;
    B = lecture();
int choix;
do{

    choix = menu();


    if(choix==1){
            anneelaureats(B);
    }

    if(choix==2){
            payslaureats(B);
    }

    if(choix==3){
         string dis;
    cout<<"discipline choisis : ";
    cin>>dis;
        cout<<"age moyen = "<<agemoyen(B,dis)<<endl;
    }

    if(choix==4){
             string dis;
    cout<<"discipline choisis : ";
    cin>>dis;
        vector<nobel>C;
    C=selectDiscipline(B,dis);
        for(int i=0;i<C.size();i++){
        cout<<C[i].nom<<" "<<C[i].annee<<" "<<C[i].age<<" "<<C[i].pays<<endl;
    }
    }

    if(choix==5){
        cout<<"fin du programme";
    }
}while(choix!=5);
    return 0;
}
