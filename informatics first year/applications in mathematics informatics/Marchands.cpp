#include<Grapic.h>

using namespace grapic;

#include<iostream>

using namespace std;

const int DIMW = 350;
const int MAX = 50;
const float PRIXMIN = 2.;
const float PRIXMAX = 6.;

struct Vecteur
{
    int x, y;
};

struct Color
{
    unsigned char r, v, b;
};

Vecteur makeVecteur (float x, float y){
Vecteur v;
v.x = x;
v.y = y;
return v;
}

Vecteur operator + (Vecteur a, Vecteur b){
return makeVecteur(a.x + b.x, a.y + b.y);
}

Vecteur operator - (Vecteur a, Vecteur b){
return makeVecteur(a.x - b.x, a.y - b.y);
}

Vecteur operator * (Vecteur a, float lambda){
return makeVecteur(lambda*a.x, lambda*a.y);
}

Vecteur operator * (float lambda, Vecteur a){
return makeVecteur(lambda*a.x, lambda*a.y);
}

Vecteur operator * (Vecteur a, Vecteur b){
return makeVecteur(a.x*b.x - a.y*b.y, a.y*b.x + a.x*b.y);
}

Vecteur operator / (Vecteur a, float lambda){
return makeVecteur(a.x/lambda, a.y/lambda);
}

Vecteur operator / (float lambda, Vecteur a){
return makeVecteur(a.x/lambda, a.y/lambda);
}

float distance(Vecteur A, Vecteur B)
{
return (sqrt((A.x - B.x)*(A.x - B.x)+(A.y - B.y)*(A.y - B.y)));
}

Color makeColor(unsigned char r, unsigned char v, unsigned char b){
Color c;
c.r = r;
c.v = v;
c.b = b;
return c;
}

Color operator + (Color col1, Color col2){
return makeColor(col1.r + col2.r, col1.v + col2.v, col1.b + col2.b);
}

Color operator - (Color col1, Color col2){
return makeColor(col1.r - col2.r, col1.v - col2.v, col1.b - col2.b);
}

Color operator * (float lambda, Color col){
return makeColor(lambda*col.r, lambda*col.v, lambda*col.b);
}

Color operator * (Color col, float lambda){
return makeColor(lambda*col.r, lambda*col.v, lambda*col.b);
}

struct Marchand
{
    Vecteur pos;
    Color c;
    float prix;
    int nbClients;
};

struct lesMarchands
{
    Marchand tab[MAX];
    int nbMarchands;
    int x;
};

struct Client
{
    Vecteur pos;
    Color c;
};

void initMarchands (lesMarchands &lm, int nbMarchands)
{
    int i;
    lm.nbMarchands = nbMarchands;
    for(i=0; i<lm.nbMarchands; i++)
    {
        lm.tab[i].pos = makeVecteur(rand()%DIMW, rand()%DIMW);
        lm.tab[i].prix = PRIXMIN + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(PRIXMAX-PRIXMIN)));
        lm.tab[i].c = makeColor(rand()%256, rand()%256, rand()%256);
        lm.tab[i].nbClients = 0;
    }
}

void drawMarchands(lesMarchands& lm)
{
    int i;
    color(255, 0, 0);
    for(i=0; i<lm.nbMarchands; i++)
    {
        circle(lm.tab[i].pos.x, lm.tab[i].pos.y, 3);
    }
}

/* int choixDuMarchand(lesMarchands& lm, int x, int y)
{
    Vecteur client = makeVecteur(x, y);

    float prixComplet;

    float minPrixComplet = distance(lm.tab[0].pos, client) + lm.tab[0].prix;

    float indminPrixComplet = 0;

    for(int i=1; i<lm.nbMarchands; i++)
    {
        prixComplet = distance(lm.tab[i].pos, client) + lm.tab[i].prix;
        if(prixComplet<minPrixComplet)
        {
            minPrixComplet = prixComplet;
            indminPrixComplet = i;
        }
    }
    return indminPrixComplet;
}

void  TraiteVente(lesMarchands& lm, bool affiche)
{
    for(int i=0; i<lm.nbMarchands; i++)
    {
        lm.tab[i].nbClients = 0;
    }

    int indMin;

    for(int x=0; x<DIMW; x++)
    {
        for(int y=0; y<DIMW; y++)
        {
            indMin = choixDuMarchand(lm, x, y);
            lm.tab[indMin].nbClients++;

            if(affiche == true)
            {
                put_pixel(x, y, lm.tab[indMin].c.r, lm.tab[indMin].c.v, lm.tab[indMin].c.b);
            }
        }
    }
} */

void TraiteVente2(lesMarchands& lm, bool affiche)
{
    int i, j, k, kmin;
    float minDistPrix, distPrix;
    Vecteur cl;

    for(int i=0; i<lm.nbMarchands; i++)
    {
        lm.tab[i].nbClients = 0;
    }

    for(i=0; i<DIMW; i++)
    {
        for(j=0; j<DIMW; j++)
        {
            cl = makeVecteur(i, j);

            minDistPrix = distance(cl, lm.tab[0].pos) + lm.tab[0].prix;

            kmin = 0;

            for(k=1; k<lm.nbMarchands; k++)
            {
                distPrix = distance(cl, lm.tab[k].pos) + lm.tab[k].prix;

                if(distPrix<minDistPrix)
                {
                    minDistPrix = distPrix;
                    kmin = k;
                }

                lm.tab[kmin].nbClients++;

                if(affiche==true)
                {
                    put_pixel(i, j, lm.tab[kmin].c.r, lm.tab[kmin].c.v, lm.tab[kmin].c.b);
                }
            }
        }
    }
}

void updateLesMarchands(lesMarchands& lm, Plot& p)
{
    Vecteur dir[MAX];
    dir[0] = makeVecteur(0, 0);
    dir[1] = makeVecteur(-4, 0);
    dir[2] = makeVecteur(4, 0);
    dir[3] = makeVecteur(0, -4);
    dir[4] = makeVecteur(0, 4);

    int i, j, k;
    int imax, imaxMoins;
    float profit, profitMax, profitMaxMoins;

    lesMarchands lmNouveaux, lmFinal;
    lmFinal = lm;

    for(i=0; i<lmNouveaux.nbMarchands; i++)
    {
        profitMax = profitMaxMoins = lm.tab[i].nbClients * lm.tab[i].prix;

        imax = 0;
        imaxMoins = 0;

        for(j=1; j<5; j++)
        {
            lmNouveaux = lm;

            lmNouveaux.tab[i].prix = 0.9 * lm.tab[i].prix;

            lmNouveaux.tab[i].pos = lm.tab[i].pos + dir[j];

            TraiteVente2(lmNouveaux, false);

            profit = lmNouveaux.tab[i].prix * lmNouveaux.tab[i].nbClients;

            if(profit>profitMaxMoins)
            {
                profitMaxMoins = profit;
                imaxMoins = j;
            }
        }

        for(k=1; k<5; k++)
        {
            lmNouveaux = lm;

            lmNouveaux.tab[i].prix = 1.1 * lm.tab[i].prix;

            lmNouveaux.tab[i].pos = lm.tab[i].pos + dir[k];

            TraiteVente2(lmNouveaux, false);

            profit = lmNouveaux.tab[i].prix * lmNouveaux.tab[i].nbClients;

            if(profit>profitMax)
            {
                profitMax = profit;
                imax = k;
            }
        }

        if(profitMax>profitMaxMoins)
        {
            lmFinal.tab[i].pos = lm.tab[i].pos + dir[imax];
            lmFinal.tab[i].prix = lm.tab[i].prix * 1.1;
        }
        else
        {
            lmFinal.tab[i].pos = lm.tab[i].pos + dir[imaxMoins];
            lmFinal.tab[i].prix = lm.tab[i].prix * 0.9;
        }
    }
    lm=lmFinal;

    for(int l=0; l<lmFinal.nbMarchands; l++)
    {
        plot_add(p, lm.x, lmFinal.tab[l].nbClients, l);
    }

    lm.x++;
}

/* void MiseAJourUnMarchands(lesMarchands& lm, lesMarchands lmAvant, int inlm)
{
    Vecteur dir[4];
    dir[0] = makeVecteur(-1, 0);
    dir[1] = makeVecteur(1, 0);
    dir[2] = makeVecteur(0, -1);
    dir[3] = makeVecteur(0, 1);

    int maxClient = lmAvant.tab[inlm].nbClients;

    int inDeplacement = -1;

    lesMarchands lmTest;

    for(int i=0; i<4; i++)
    {
        lm = lmAvant;

        lmTest = lmAvant;
        lmTest.tab[inlm].pos = lmTest.tab[inlm].pos + dir[i];
        TraiteVente(lm, false);

        if(lmTest.tab[inlm].nbClients>maxClient)
        {
            inDeplacement = i;
            maxClient = lmTest.tab[inlm].nbClients;
        }
    }

    if(inDeplacement != 1)
    {
        lmTest.tab[inlm].pos = lmTest.tab[inlm].pos + dir[inDeplacement];
    }

    lmTest = lmAvant;
    lmTest.tab[inlm].prix = 1.1 * lmTest.tab[inlm].prix;
    TraiteVente(lmTest, false);

    if(lmTest.tab[inlm].nbClients>lmAvant.tab[inlm].nbClients)
    {
        lm.tab[inlm].prix = 1.1 * lm.tab[inlm].prix;
    }

    else
    {
        lmTest = lmAvant;
        lmTest.tab[inlm].prix = 0.9 * lmTest.tab[inlm].prix;
        TraiteVente(lmTest, false);

        if(lmTest.tab[inlm].nbClients>lmAvant.tab[inlm].nbClients)
        {
            lm.tab[inlm].prix = 0.9 * lm.tab[inlm].prix;
        }
    }
}

void MiseAJourMarchands(lesMarchands& lm)
{
    lesMarchands lmAvant;
    lmAvant = lm;

    for(int i=0; i<lm.nbMarchands; i++)
    {
        MiseAJourUnMarchands(lm, lmAvant, i);
    }
} */

int main(int , char**)
{
	winInit("Marchands",DIMW,DIMW);
	backgroundColor(230,230,230);

	lesMarchands lm;

	initMarchands(lm, 5);

	Plot p;

    plot_setSize(p, -1);

	while(1)
    {

        winClear();

        TraiteVente2(lm, true);
        drawMarchands(lm);
        updateLesMarchands(lm, p);

        plot_draw(p, 0, 4*DIMW/6, DIMW, DIMW, true); /**< NOMBRE DE CLIENTS */

        winDisplay();

    }

	pressSpace();
	winQuit();
	return 0;
}
