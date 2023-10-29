#include<Grapic.h>

#include<iostream>

using namespace grapic;

using namespace std;

const int MAX = 100;

const int DIMW = 500;

/**<

CELLULE NON VIDE

0, 1 voisine -> meurt
2, 3 voisines -> survit
>= 4 voisines -> meurt

CELLULE VIDE

3 voisines -> naissance

*/

struct Cellule
{
    int etat; /**< 0: mort, 1: vivant */
};

struct JeuDeLaVie
{
    Cellule grille[MAX][MAX];
    int nbVivante;
    int nbl;
    int nbc;
};

void init(JeuDeLaVie& jeu)
{
    jeu.nbVivante = 0;

    jeu.nbl = 10;
    jeu.nbc = 10;

    for(int i=0; i<jeu.nbl; i++)
    {
        for(int j=0; j<jeu.nbc; j++)
        {
            jeu.grille[jeu.nbl][jeu.nbc].etat = 0;
        }
    }
}

void etat_initial(JeuDeLaVie& jeu, int nbVivante)
{
    jeu.nbVivante = nbVivante;

    int dx, dy;

    for(int i=0; i<jeu.nbVivante; i++)
    {
        do
        {
            dx = rand()%10;
            dy = rand()%10;
        } while(jeu.grille[dx][dy].etat == 1);

        jeu.grille[dx][dy].etat = 1;
    }
}

void etat_suivant(JeuDeLaVie& jeu)
{
    int nb;

    JeuDeLaVie jeuSuivant;
    jeuSuivant = jeu;

    for(int i=0; i<jeu.nbl; i++)
    {
        for(int j=0; j<jeu.nbc; j++)
        {
            nb = 0;

            for(int a=i-1; a<=i+1; a++)
            {
                for(int b=j-1; b<=j+1; b++)
                {
                    nb = nb + jeu.grille[a][b].etat;

                    if(jeu.grille[i][j].etat == 0 and nb==3)
                    {
                        jeuSuivant.grille[i][j].etat = 1;
                        jeuSuivant.nbVivante++;
                    }

                    if(jeu.grille[i][j].etat == 1)
                    {
                        if(nb<=1 or nb>=4)
                        {
                            jeuSuivant.grille[i][j].etat = 0;
                            jeuSuivant.nbVivante--;
                        }
                    }
                }
            }
        }
    }
    jeu = jeuSuivant;
}

void drawCellule(JeuDeLaVie& jeu)
{
    for(int i=0; i<jeu.nbl; i++)
    {
         for(int j=0; j<jeu.nbc; j++)
         {
             if(jeu.grille[i][j].etat == 1)
             {
                 circleFill(DIMW/4 + i * 25, DIMW/4 + j * 25, 5);
             }
             else
             {
                 circle(DIMW/4 + i * 25, DIMW/4 + j * 25, 5);
             }
         }
    }
}

int main(int , char**)
{
    bool stop = false;

	winInit("JeuDeLaVie",500,500);
	backgroundColor(120,70,200);

	JeuDeLaVie jeu;

	init(jeu);
	etat_initial(jeu, 10);

	while(!stop)
    {
        winClear();

        drawCellule(jeu);
        etat_suivant(jeu);
        delay(1000);

        cout<<jeu.nbVivante<<endl; /**< ATTENTION : jeu.nbVivante < 0 */

        stop = winDisplay();
    }

	pressSpace();
	winQuit();
	return 0;
}
