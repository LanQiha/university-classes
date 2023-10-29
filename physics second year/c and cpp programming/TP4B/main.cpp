#include <iostream>

using namespace std;

void position(double &V0X,double &V0Z, double &t, double &X,double &Z);

void saisie(double &V0X,double &V0Z,double &t);

int main()
{
    double A(0.);
    double B(0.);
    double C(0.);
    double D(0);
    double E(0);

    /*
    cout<<"V0X = ";
    cin>>A;
    cout<<"V0Z = ";
    cin>>B;
    cout<<"t = ";
    cin>>C;
    */

    saisie(A,B,C);

    position(A,B,C,D,E);
    cout<<"x= " <<D<<endl;
    cout<<"z= " <<E<<endl;

    return 0;
}

void position(double &V0X,double &V0Z, double &t, double &X,double &Z)
{
    double g(9.81);
    X=V0X*t;
    Z=(((-1.)/2.)*g*t*t)+(V0Z*t);
}

void saisie(double &V0X,double &V0Z,double &t)
{
    cout<<"V0X = ";
    cin>>V0X;
    cout<<"V0Z = ";
    cin>>V0Z;
    cout<<"t = ";
    cin>>t;
}






