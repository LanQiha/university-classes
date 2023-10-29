#include <iostream>

using namespace std;

int main()
{
    double Note;
    do{
        cout<<"Note entre 0 et 20:";
        cin>>Note;
    } while(Note<0||Note>20);

    if(Note<10){
        cout<<"Echec";
    }

    if((Note>=10)and(Note<12)){
        cout<<"Passable";
        }

    if((Note>=12)and(Note<14)){
        cout<<"Assez Bien";
    }

    if((Note>=14)and(Note<16)){
        cout<<"Bien";
    }

    if(Note>=16){
        cout<<"Tres bien";
    }

return 0;

}
