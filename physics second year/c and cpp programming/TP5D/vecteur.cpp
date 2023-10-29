#ifndef VECTEUR_CPP_INCLUDED
#define VECTEUR_CPP_INCLUDED
using namespace std;

vector<double> trouveNegatif(vector<double>V)
{
    int nNeg(0);
    for(int i=0;i<V.size();i++){
        if(V<0){
            cout<<V<<endl;
            nNeg=+nNeg;
        }
    }
    cout<<"nNeg = "<<nNeg<<endl;
}

double nbAleatoire()
{
double alea;
alea = (-1.)+(rand()*(2.)/RAND_MAX);
return alea;
}
