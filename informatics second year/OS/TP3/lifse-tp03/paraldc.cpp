#include <iostream>
#include <cstdlib>

using namespace std;

/*Code source pour le TP3 de LIFSE */

int main(int argc, char *argv[]) {

	if(argc > 2) {
		cout << "Il faut exactement un argument après la commande." << endl;
		return 0;
	}

  /* Le code ci-dessous sera à commenter par la suite */
  cout << "la commande lancée est " << argv[0] << " avec " << argc << " argument(s): " << endl;

  // impression de la suite d'arguments.
  for (int i = 0 ; i < argc; i++){
    cout << argv[i] << ",";
  }
  cout << endl;

  // TODO  
  
  return 0;
}
