#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

using namespace std;

int p[2];

int isClosed = 1;

// gestionnaire du signal SIGPIPE
void gest_sigpipe(int s) {
  cout << "signal " << s << " reçu par le processus " << getpid() << endl;
    
  if(isClosed < 0) {
  	cerr << "Erreur p[1] : " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
  }
  else if(isClosed == 0) {
  	cout << "p[1] already closed" << endl;
  }
  else {
  	cout << "closing p[1]" << endl;
  	close(p[1]);
  }
}

int main(void) { // programme principal : le père
  int rf;

  pipe(p); // initialisation du pipe

  rf = fork(); // création du fils

  // mise en place d'un gestionnaire pour le signal SIGPIPE.
  struct sigaction act;
  sigaction(SIGPIPE, NULL, &act); // On récupére la structure sigaction actuelle pour SIGPIPE.
  act.sa_handler = &gest_sigpipe; // On remplace dans act le gestionnaire de signal par le notre.
  sigaction(SIGPIPE, &act, NULL); // On installe le nouveau gestionnaire de signal.

  if(rf > 0){ // cas processus père

    cout << "(père) mon PID est " << getpid() << endl << flush;
    cout << "(père) le PID de mon fils est " << rf << endl << flush;
    close(p[0]); 
    int wr;
    for(int i = 1; i < 100; i++) {
      wr = write(p[1], &i, sizeof(int)); // écriture sur le pipe
      if(wr == -1) { // cas retour d'erreur du write
        cerr << "Erreur : " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
      }
    
      cout << "(père) " << i << endl << flush;
    }

    isClosed = close(p[1]);
    if(waitpid(rf, NULL, 0) == -1) { // gestion erreur sur waitpid
      cerr << "Erreur : " << strerror(errno) << endl;
      exit(EXIT_FAILURE);
    }
    cout << "(père) terminaison normale." << endl << flush;
    
  }
  else { // cas processus fils
  
    cout << "(fils) mon PID est " << getpid() << endl << flush;
    close(p[1]);

    // lecture d'un seul entier sur le pipe
    int rd, n;
    rd = read(p[0], &n, sizeof(int));
    if(rd == -1) { // gestion erreur sur le read
      cerr << "Erreur : " << strerror(errno) << endl;
      exit(EXIT_FAILURE);
    }
    cout << "(fils) j'ai lu " << n << endl << flush;

    // le fils ferme tout de suite son descripteur de fichier en lecture,
    // alors que le père écrit encore de l'autre côté !
    close(p[0]);
    cout << "(fils) terminaison normale." << endl << flush;
 
  }

  return EXIT_SUCCESS;
}
