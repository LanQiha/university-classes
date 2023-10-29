#include <iostream>

using namespace std;

#include "date.h"
#include "date.cpp"

/*date premiereDate(date dateA,date dateB){
    if(dateA.annee>dateB.){
        return dateA;
    }else if(date)
}*/

int main()
{
    date dateInit;
    dateInit.afficheDate();

    date date2(9,12,2021);
    date2.afficheDate();

    dateInit.definirDate(1,1,2001);

    date dateCopie(dateInit);
    dateCopie.afficheDate();

    cout <<"date 2 == copie ? " << (dateCopie == date2) << endl;
    cout << "date init = " <<endl;
    dateInit.afficheDate();
    date2=dateInit;
    cout<<"date 2 = date innit"<<endl;
    date2.afficheDate();
    cout<<date2;
    cin>>date2;
    cout<<date2;

    cout << endl <<"année bisextile ? " << date2.anneeBissextile()<< endl;
    date2.afficheDate();
    dateCopie = date2 +400;
    dateCopie.afficheDate();
    return 0;
}
