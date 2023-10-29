#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

double randReel();
double randReel2(double min, double max);

int main(){


    cout<<"RAND_MAX="<<RAND_MAX<<endl;
    srand(time(0));
    int alea(0);

    for(int i=0;i<10;i++){
        alea=rand();
        cout<<"rand() numero "<<i+1<<" = "<<alea<<endl;
        }


    double a;
    for(int i=0;i<3;i++){
            a = randReel();
            cout << "nombre " << i+1<<"=" << a <<endl;
    }


    int A;
    int B;
    do{
        double c;
        cout<<"Min = ";
        cin>>A;
        cout<<"Max = ";
        cin>>B;
        c=randReel2(A,B);
        cout<<"randReel = "<<c<<endl;

    }while(B<=A);

    return 0;

}

double randReel(){
    double alea2(rand());
    return alea2*1./RAND_MAX;
}

double randReel2(double Min, double Max){
    double alea3(0.);
    alea3=rand();
    alea3=Min+alea3*((Max-Min)/RAND_MAX);
    return alea3;
}






