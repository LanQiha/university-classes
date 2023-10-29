#include <iostream>
#include <cmath>

using namespace std;

#include "complexe.h"
#include "complexe.cpp"

int main()
{

    complexe A;
    A.affiche();
    complexe B(2.);
    B.affiche();
    complexe C(1.,1.);
    C.affiche();
    cout<<"le module de A est : "<<A.getModule()<<endl;
    cout<<"le module de B est : "<<B.getModule()<<endl;
    cout<<"le module de c est : "<<C.getModule()<<endl;
    cout << "l'argument de A est : " << A .getArg()<<endl;
    cout << "l'argument de B est : " << B .getArg()<<endl;
    cout << "l'argument de C est : " << C .getArg()<<endl;

    cout << (A!=B)<<endl;

    cin>>A;
    cout<<A;

    cout<< A+B;
    cout<< (A+=B);
    return 0;

}
