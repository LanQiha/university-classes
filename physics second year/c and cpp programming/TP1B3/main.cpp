#include <iostream>

using namespace std;

int main()
{
    int i(0);
    int Nmax(0);
    cout<<"Valeur Nmax:";
    cin>>Nmax;
    while(i<=Nmax){
        if(i%2==0){
            cout<<i<<endl;
    }
    i++;
    }

    return 0;
}
