#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double epsi;
    cout<<"epsi=";
    cin>>epsi;
    double a;
    double b;
    double M;
    double Xo;
    do{
        cout<<"Saisir un nombre a et b tel que a<b"<<endl;
        cout<<"Saisir a:"<<endl;
        cin>>a;
        cout<<"Saisir b:"<<endl;
        cin>>b;
    }while(a>=b);

    if(((a+exp(a)-2)*(b+exp(b)-2))>0){
        cout<<"Erreur";
    }

    while((b-a)>=epsi){
        M=((a+b)/2);
        if(((a+exp(a)-2)*(M+exp(M)-2))<0){
            b=M;
        }
        else a=M;


    }
    Xo=(a+b)/2;
    cout<<Xo;





    return 0;
}
