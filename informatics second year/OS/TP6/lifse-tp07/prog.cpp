#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main(void) { // Programme principal : processus père
  int rf, p[2]; //P[0] : descripteur en lecture ; p[1] : descripteur en écriture
  int r;
  char c;
  int cnt = 0;

  pipe(p); // initialisation du pipe p

  rf = fork(); // création d'un fils

  if(rf > 0) { // cas du processus père

    close(p[0]);
    for(char i = '0'; i < '9'; i++) {
      write(p[1], &i, sizeof(char));
    }
    close(p[1]); // <-- décommenter pour fermer p[1] (descripteur pour l'écriture)
    if(waitpid(rf, NULL, 0) == -1) {
      cerr << "Erreur : " << strerror(errno) << endl;
      exit(EXIT_FAILURE);
    }
    cout << "(père) terminaison normale" << endl;

  }
  else { // cas du processus fils
    
    close(p[1]); // <-- décommenter pour fermer p[1] (descripteur pour l'écriture)
    r = read(p[0], &c, sizeof(char));
    while(r == sizeof(char)) {
      cout << "(fils) " << c << endl;
      r = read(p[0], &c, sizeof(char));
      cnt++;
    }
    if(r == -1) {
      cerr << "Erreur : " << strerror(errno) << endl;
      exit(EXIT_FAILURE);
    }
    close(p[0]);
    cout << "(fils) nombre de caractères lus : " << cnt << endl;
    cout << "(fils) terminaison normale" << endl;
  }

  return EXIT_SUCCESS;
}

