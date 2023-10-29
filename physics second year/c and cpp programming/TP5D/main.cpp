#include <iostream>
#include <vector>
#include<ctime>
#include<cstdlib>

using namespace std;

double nbAleatoire();
vector<double> trouveNegatif(vector<double>V);

int main()
{
    int A;
    cout<<"nb de cases = ";
    cin>>A;
    vector<double> Va(A);
    for(int i=0;i<A;i++){
        Va[i]= nbAleatoire();
        cout<<"V["<<i<<"] = "<<Va[i]<<endl;
    }
    return 0;
}

double nbAleatoire()
{
double alea;
alea = (-1.)+(rand()*(2.)/RAND_MAX);
return alea;
}

