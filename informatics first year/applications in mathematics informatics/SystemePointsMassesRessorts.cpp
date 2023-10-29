#include<Grapic.h>

#define NMAX 100 // Macro
#define EPS 1E-07
#define CARRE(X) (X)*(X)

//return sqrt(CARRE (A.x - B.x) + CARRE(A.y - B.y))

using namespace grapic;

const int DIMW = 500;

struct Vecteur
{
    float x, y;
};

typedef Vecteur Point;

const Vecteur G = {0, -9.81};

struct Particle
{
    Vecteur position;
    Vecteur vitesse;
    Vecteur force;
    int masse;
};

struct Spring
{
    float k;
    float lg;
    int i1;
    int i2;
};


struct World
{
    Particle tabPart[NMAX];
    int nbPart;
    float dt;
    Spring tabSpring[NMAX];
    int nbSpring;
};

// ------------------------------ //



// ------------------------------ //

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

float distance(Point A, Point B)
{
return (sqrt((A.x - B.x)*(A.x - B.x)+(A.y - B.y)*(A.y - B.y)));
}

Vecteur normaliseVecteur(Vecteur v)
{
float n;
n = sqrt(v.x*v.x + v.y*v.y);
if(fabs(n)>EPS) //fabs valeur absolue
{
v.x = v.x/n;
v.y = v.y/n;
}
return v;
}

// ------------------------------ //



// ------------------------------ //

int addParticle (World& w, Point pos, Vecteur v, float masse)
{
if(w.nbPart == NMAX)
{
return -1;
}
else
{
w.tabPart[w.nbPart].position = pos;
w.tabPart[w.nbPart].vitesse = v;
w.tabPart[w.nbPart].masse = masse;
w.tabPart[w.nbPart].force.x = 0;
w.tabPart[w.nbPart].force.y = 0;
w.nbPart++;
return(w.nbPart-1);
}
}

int addSpring(World& w, int i1, int i2, float k)
{
if(w.nbSpring == NMAX)
{
return -1;
}
else
{
Spring sp;
sp.i1 = i1;
sp.i2 = i2;
sp.k = k;
sp.lg = distance(w.tabPart[i1].position, w.tabPart[i2].position);
w.tabSpring[w.nbSpring] = sp;
w.nbSpring++;
return (w.nbSpring-1);
}
}

// ------------------------------ //



// ------------------------------ //

void computeSpringForce(World& w)
{
int i1, i2, i;
float d, delta;
Vecteur e, v;
for(i=0; i< w.nbSpring; i++)
{
i1 = w.tabSpring[i].i1;
i2 = w.tabSpring[i].i2;
d = distance(w.tabPart[i1].position, w.tabPart[i2].position);
delta = d-w.tabSpring[i].lg;
v = w.tabPart[i2].position - w.tabPart[i1].position;
e = normaliseVecteur(v);
w.tabPart[i1].force = (w.tabPart[i1].force + w.tabSpring[i].k * delta * e); /**< MODELISATION INSTABLE, PAS DE FORCES DE FROTTEMENTS */
w.tabPart[i2].force = (w.tabPart[i2].force - w.tabSpring[i].k * delta * e);
}
}

// ------------------------------ //



// ------------------------------ //


void carre(World& w, float x, float y)
{
int a, b, c, d;
a = addParticle(w, makeVecteur(x, y), makeVecteur(0, 0), 10);
b = addParticle(w, makeVecteur(x + 50., y), makeVecteur(0, 0), 10);
c = addParticle(w, makeVecteur(x + 50., y - 50.), makeVecteur(0, 0), 10);
d = addParticle(w, makeVecteur(x, y - 50.), makeVecteur(0, 0), 10);
addSpring(w, a, b, 500.);
addSpring(w, b, c, 500.);
addSpring(w, c, d, 500.);
addSpring(w, d, a, 500.);
addSpring(w, a, c, 500.);
addSpring(w, b, d, 500.);
}

void draw_carre(World& w)
{
for (int i = 0; i < w.nbPart; i++)
{
    circle(w.tabPart[i].position.x, w.tabPart[i].position.y, 5);
}
for (int i = 0; i < 3; i++)
{
    line(w.tabPart[i].position.x, w.tabPart[i].position.y, w.tabPart[i+1].position.x, w.tabPart[i+1].position.y);
}
line(w.tabPart[3].position.x, w.tabPart[3].position.y, w.tabPart[0].position.x, w.tabPart[0].position.y);
line(w.tabPart[0].position.x, w.tabPart[0].position.y, w.tabPart[2].position.x, w.tabPart[2].position.y);
line(w.tabPart[1].position.x, w.tabPart[1].position.y, w.tabPart[3].position.x, w.tabPart[3].position.y);
}

// ------------------------------ //



// ------------------------------ //

void ajoutForceTerrestre(World& w, int i)
{
    w.tabPart[i].force = w.tabPart[i].force + w.tabPart[i].masse * G;
}

void updateVitessePosition(World& w) /**< PAS DE FORCES DE FROTTEMENTS */
{
    for(int i = 0; i<w.nbPart; i++)
    {
        w.tabPart[i].vitesse = (w.tabPart[i].force / w.tabPart[i].masse) * w.dt + w.tabPart[i].vitesse;
        w.tabPart[i].position = w.tabPart[i].vitesse * w.dt + w.tabPart[i].position;

        if (w.tabPart[i].position.y < 0)
        {
            w.tabPart[i].vitesse = (-1) * ((w.tabPart[i].force / w.tabPart[i].masse) * w.dt + w.tabPart[i].vitesse);
            w.tabPart[i].position = w.tabPart[i].vitesse * w.dt + w.tabPart[i].position;
        }

        if (w.tabPart[i].position.x < 0)
        {
            w.tabPart[i].vitesse = (-1) * ((w.tabPart[i].force / w.tabPart[i].masse) * w.dt + w.tabPart[i].vitesse);
            w.tabPart[i].position = w.tabPart[i].vitesse * w.dt + w.tabPart[i].position;
        }

        if (w.tabPart[i].position.y > DIMW)
        {
            w.tabPart[i].vitesse = (-1) * ((w.tabPart[i].force / w.tabPart[i].masse) * w.dt + w.tabPart[i].vitesse);
            w.tabPart[i].position = w.tabPart[i].vitesse * w.dt + w.tabPart[i].position;
        }

        if (w.tabPart[i].position.x > DIMW)
        {
            w.tabPart[i].vitesse = (-1) * ((w.tabPart[i].force / w.tabPart[i].masse) * w.dt + w.tabPart[i].vitesse);
            w.tabPart[i].position = w.tabPart[i].vitesse * w.dt + w.tabPart[i].position;
        }
    }
}

void updateForce0(World& w) /**< FONCTION ESSENTIELLE POUR LE FONCTIONNEMENT DU PROGRAMME MASSES-RESSORTS */
{
    for(int i=0; i<w.nbPart; i++)
    {
        w.tabPart[i].force = makeVecteur(0, 0);
    }
}

// ------------------------------ //



// ------------------------------ //

int main(int , char**)
{
    bool stop=false;

	winInit("SystemeMassesRessorts",500,500);
	backgroundColor(120,70,200);
	color(220,220,220);

	World w;

	w.nbPart = 0;
	w.nbSpring = 0;

	w.dt = 0.01;

	carre(w, DIMW/2, DIMW/2);

	while(!stop)
    {
    winClear();

    draw_carre(w);

    for(int i=0; i<w.nbPart; i++)
    {
        ajoutForceTerrestre(w, i);
    }

    computeSpringForce(w);

    updateVitessePosition(w);
    updateForce0(w);

    delay(1);

    stop = winDisplay();
    }
    pressSpace();
	winQuit();
	return 0;
}
