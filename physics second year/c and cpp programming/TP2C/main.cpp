#include <iostream>

using namespace std;

int main()
{
    int N(0);
    do{
        cout<<"Saisir N tel que N>0. N=";
        cin>>N;
    }while(N<=0);

    int T[N];
    int i;
    double a;
    double S;
    for(i=0;i<N;i++){
        cout<<"entrer T["<<i <<"]"<<endl;
        cin>>a;
        T[i]=a;
        S=S+T[i];

    }
    cout<<"Somme=";
    cout<<S<<endl;


// chercher le max
    double Max;
    int position_max;
    for(i=0;i<N;i++){
        if(T[i]>Max){
            Max=T[i];
            position_max = i;
        }
    }
    cout<<"Max=" <<Max<< " a la position " << position_max << endl;

    double Min;
    int position_min;
    Min=Max;
    for(i=0;i<N;i++){
        if(T[i]<Min){
            Min=T[i];
            position_min=i;
        }
    }
    cout<<"Min=";
    cout<<Min<<" a la position " << position_min << endl;

    int n;
    int c;
    int b;
    int T2[n];

    do{
        cout<<"Saisir a tel que b>0. b=";
        cin>>b;
    }while(b<0);

    do{
        cout<<"Saisir c tel que c>b et c>0. c=";
        cin>>c;
    }while(c<b and c>0);

    for(n=b;n<=c;n++){
            T2[n-b]=T[n];
            cout<<"T2["<<n<<"] : "<<T2[n]<<endl;

    }
    double T3[N-1];
    for(int i=0;i<N-1;i++){
            T3[i]=T[i+1];
            cout<<"  T3["<<i<<"]="<<T3[i];
    }

    return 0;
}
