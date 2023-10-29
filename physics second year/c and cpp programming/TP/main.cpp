/*TP F2*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

string lecture(vector<string>prenom,vector<string>genre)
{
    fstream f;
    f.open("sujet4.txt"),ios::in);
    vector<string>Prenom(147);
    string A;
    for(int i = 0;i<147;i++){
    f>>A;
    Prenom[i]=A;
    }
}

 double Ratio(vector<string>genre)
{
vector<string>genre;
int m;
int f;
double r;
for(int i = 0; i<genre.size();i++){
    if(genre[i]==masculin){
        m++;
    }else(f++);
}
r=(1.0*(m/r));
return r;
}

Affiche(vector<string>prenom,vector<string>genre)
{
    char A;
    cout<<"entrer une lettre en majuscule"; cin>>A;
    char B;
    cout<<"choisir un genre, m pour masculin, f pour feminin"; cin>>B;
    if(B==m){
        cout<<"masculin";
    }else cout<<"feminin";

    vector<string>prenom;
    vector<string>genre;
    for(int i = 0;i<prenom.size();i++){
        if(prenom[i]==A){
            if(prenom[i==B]){
                cout<<prenom[i];
            }
        }

    }

}*/

bool Present(vector<string>prenom)
{
string A;
cout<<"entrer un prenom"; cin>>A;
vector<string>prenom2;
vector<string>prenom3;
bool B;
for(int i = 0;i<prenom.size();i++){
    if(A==prenom[i]){
        B=1;
    }else(B=0);
}
return B;
}


int Winmain()
{
vector<string>A; /*NOM*/
vector<string>B; /*GENRE*/
fstream f;
f.open("sujet4.txt"),ios::in);
/*ratio*/
double C;
C = Ratio(B);
cout<<"ratio = "<<C;
/*present*/
if(A==1){
    cout<<"present";
}else(cout<<"absent");


    return 0;
}
