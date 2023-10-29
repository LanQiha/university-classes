#ifndef TABLEAU_CPP_INCLUDED
#define TABLEAU_CPP_INCLUDED
using namespace std;

double nbAleatoire()
{
double alea;
alea = (-1.)+(rand()*(2.)/RAND_MAX);
return alea;
}

double* trouveNegatif(double* T,int nT,int& nNeg){
for(int i=0;i<nT;i++){
    if(T[i]<0)
        nNeg=nNeg+1;
}
double* t;
t = new double [nNeg];
int n(0);
for(int i=0;i<nT;i++){
        if(T[i]<0) {
            t[n]=T[i];
            cout << t[n] << " ";
            n+=1;
        }
}

return t;
}

#endif // TABLEAU_CPP_INCLUDED
