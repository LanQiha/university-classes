#include <iostream>

using namespace std;

int main()
{
    int i(0);
    int Nmax(0);
    cout<<"Valeur Nmax:";
    cin>>Nmax;
    do{
        if(i%2==0){
            cout<<i<<endl;
        }
        i++;
    }while(i<=Nmax);


    return 0;
}
