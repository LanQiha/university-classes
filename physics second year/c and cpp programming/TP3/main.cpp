#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream f;
    f.open("liste.txt",ios::in);

    if (f){
       string T[22];
       string A;
       int i;
       for(i=0;i<22;i++){
        f>>A;
        T[i]=A;
        cout<<"T["<<i<<"]="<<T[i]<<endl;
       }

    }
    else {
        cout << "impossible d'accéder au fichier"<< endl;
    }
    f.close();

    string B;
    cout<<"Entrer la premiere lettre des nom que l'on veut selectionner ";
    cin>>B;

    if(B.size() ==1){
        cout<<B<<endl;
    }
    else{
        cout<<"erreur";
    }

    string Fichier;
    Fichier="liste"+B+".txt";
    cout<<Fichier<<endl;

    f.open("liste.txt",ios::in);

    string T[22];
    if (f){

       string A;
       string Nom;
       int i;
       for(i=0;i<22;i++){
        f>>A;
        T[i]=A;
        Nom=T[i];
        }

       }

    else {
        cout << "impossible d'accéder au fichier"<< endl;
    }
    f.close();


    fstream f1;
    f1.open(Fichier,ios::out);

    for(int i=0;i<22;i++){
    string Nom;
    Nom = T[i];
    if(Nom[0]==B[0]){
            cout<< Nom<<endl;
    }
    }


}
    return 0;
}
