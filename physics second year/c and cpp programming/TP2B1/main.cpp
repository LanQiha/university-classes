#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float h(0.);
    float a(0.);
    float b(0.);
    int n(0);

    do{
        cout<<"Saisir n tel que n soit impair et n>0. n=";
        cin>>n;
    }while(n%2==0 and n<0);

    do{
        cout<<"Saisir a et b tel que a<b"<<endl;
        cout<<"a=";
        cin>>a;
        cout<<"b=";
        cin>>b;
    }while(a>=b);

    int i(0);

    h=(b-a)/(n+1);
    cout<<"h=";
    cout<<h<<endl;

    double X(0.);
    X=sin(a)+sin(b);
    cout<<"X=";
    cout<<X<<endl;

    double Y(0.);
    for(i=1;i<=n;i=i+2){
        Y=Y+(sin(a+i*h));
        }
    cout<<"Y=";
    cout<<Y<<endl;

    double Z(0.);
    for(i=2;i<n;i=i+2){
         Z=Z+(sin(a+i*h));
    }
    cout<<"Z=";
    cout<<Z<<endl;

    double W(0.);
    W=h/3.0;
    cout<<"W=";
    cout<<W<<endl;

    double I(0.);
    I=W*(X+4*Y+2*Z);
    cout<<"I=";
    cout<<I;

return 0;
}
