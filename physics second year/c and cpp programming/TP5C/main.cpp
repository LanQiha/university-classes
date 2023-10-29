#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "tableau.h"
#include "tableau.cpp"

using namespace std;



int main()
{
    int B;
    cout<<"nb de cases = ";
    cin>>B;
    double* b = 0;
    b = new double [B];
    for(int i = 0;i<=B;i++){
            b[i]=nbAleatoire();
            cout<<"b["<<i<<"] = "<<b[i]<<endl;

    }
int nNeg(0);
    double* Tneg(trouveNegatif(b,B,nNeg));

    cout << "nombre de n'egatif :" <<nNeg << endl;


    return 0;
}



