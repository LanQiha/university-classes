#include <iostream>

using namespace std;

void procedureAvecPointeur (int * ptr){
cout << "Valeur du parametre : " << *ptr << endl;
cout << "Adresse du parametre : " << (long int) &ptr << endl;
}

void procedureAvecReference (int& rf){
cout << "Valeur du parametre : " << rf << endl;
cout << "Adresse du parametre : " << (long int) &rf << endl;
}

void procedureAvecInt (int val){
cout << "Valeur du parametre : " << val << endl;
cout << "Adresse du parametre : " << (long int) &val << endl;
}

int main(){
int x = 1;
int & rx = x;
int * px = &x;

cout << "x = " << x << ", rx = " << rx << ", px = " << *px << endl;
// rx est un autre nom pour x donc x et rx ont la même adresse mémoire
cout << "&x = " << (long int) &x << ", &rx = " << (long int) &rx << ", &px = " << (long int) &px << endl;

procedureAvecPointeur(px);
procedureAvecInt(x);
procedureAvecReference(x);
procedureAvecInt(rx);
procedureAvecReference(rx);

return 0;
}
