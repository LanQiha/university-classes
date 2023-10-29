#include <iostream>

using namespace std;

int main()
{
    double A;
    cout<<"Adresse de A : "<<&A<<endl;

    double X(5.5);
    double *xPtr;
    xPtr=&X;
    cout<<"X="<<X<<endl;
    cout<<"valeur pointee sur X = "<<*xPtr<<endl;
    *xPtr=1.5;
    cout<<"X = "<<X<<endl;

    int I(3);
    int* iPtr;
    iPtr = &I;
    cout<<"iPtr = "<<*iPtr<<endl;
    I=5;
    cout<<"iPtr = "<<*iPtr<<endl;

    double T[2];
    float T2[2];
    for(int i=0;i<3;i++){
        cout<<"adresse de T["<<i<<"] = "<<&T[i]<<endl;
    }
    for(int i=0;i<3;i++){
        cout<<"adresse de T2["<<i<<"] = "<<&T2[i]<<endl;
    }

    return 0;
}
