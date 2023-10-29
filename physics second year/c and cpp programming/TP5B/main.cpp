#include <iostream>

using namespace std;

int modifie(int *iPtr){
*iPtr = 5;
return *iPtr;
}

double* trouveMin(double T[4]){
    double Min(T[0]);
    double* tPtr;
    for(int i=0;i<5;i++){
            if(T[i]<Min){
                Min=T[i];
                tPtr = &T[i];
    }
}
return tPtr;
}

int main()
{
    int j(2);
    int *jPtr;
    jPtr = &j;
    modifie(jPtr);
    cout<<"j = "<<j<<endl;

    double T2[4];
    for(int i=0;i<5;i++){
        cout<<"T["<<i<<"] = ";
        cin>>T2[i];
    }
    double* minPtr;
    minPtr= trouveMin(T2);
    cout<<"minPtr = "<<*minPtr;
    return 0;
}


