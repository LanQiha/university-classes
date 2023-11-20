#ifndef _ELEMENT_L
#define _ELEMENT_L

typedef int ElementL;

void afficherElementL(ElementL e);

bool estEgalElementL(ElementL e1, ElementL e2);
/* Preconditions : aucune
   R�sultat : renvoie vrai si e1 est �gal � e2, faux sinon */

bool estInferieurElementL(ElementL e1, ElementL e2);
/* Preconditions : aucune
   R�sultat : renvoie vrai si e1 est strictement inf�rieur � e2, faux sinon */

#endif
