#include<Grapic.h>

using namespace grapic;

// constantes

const int DIMW = 500;
const int MAX_PART = 100;

// structures

struct Vecteur{
float x, y;
};

const Vecteur G = {0, -9.81}; // constante de gravitation sur Terre

struct Particle{
Vecteur position;
Vecteur vitesse;
Vecteur force;
float masse;
};

struct World{
int particleSym;
Particle tableauParticles[MAX_PART];
};

// ------------------------------ //



// ------------------------------ //

Vecteur makeVecteur (float x, float y){
Vecteur v;
v.x = x;
v.y = y;
return v;
}

Vecteur makeVecteurExp (float rayon, float angle){
Vecteur v;
v.x = rayon * cos(angle);
v.y = rayon * sin(angle);
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

// ------------------------------ //



// ------------------------------ //

void init (World& w){
for(int i = 0; i<w.particleSym; i++){
w.tableauParticles[i].position = {DIMW/100 + i*15, DIMW/2};
w.tableauParticles[i].vitesse ={15, 15*0.5*i};
w.tableauParticles[i].force = {0, 0};
w.tableauParticles[i].masse = 1;
}
}

void drawParticle (Particle& p){
color(200, 200, 200);
circleFill(p.position.x, p.position.y, 5);
}

float attractionTerrestreWorld (World& w, float dt, Vecteur friction, int i){

w.tableauParticles[i].vitesse = G*dt + w.tableauParticles[i].vitesse;
w.tableauParticles[i].position = w.tableauParticles[i].vitesse*dt + w.tableauParticles[i].position;

if (w.tableauParticles[i].position.y < 0){
w.tableauParticles[i].vitesse = (((-1) * (G*dt + w.tableauParticles[i].vitesse))) * friction;
w.tableauParticles[i].position = w.tableauParticles[i].vitesse*dt + w.tableauParticles[i].position;
}

if (w.tableauParticles[i].position.y > DIMW){
w.tableauParticles[i].vitesse = (((-1)* (G*dt + w.tableauParticles[i].vitesse))) * friction;
w.tableauParticles[i].position = w.tableauParticles[i].vitesse*dt + w.tableauParticles[i].position;
}

if (w.tableauParticles[i].position.x < 0){
w.tableauParticles[i].vitesse = (((-1) * (G*dt + w.tableauParticles[i].vitesse))) * friction;
w.tableauParticles[i].position = w.tableauParticles[i].vitesse*dt + w.tableauParticles[i].position;
}

if (w.tableauParticles[i].position.x > DIMW){
w.tableauParticles[i].vitesse = (((-1) * (G*dt + w.tableauParticles[i].vitesse))) * friction;
w.tableauParticles[i].position = w.tableauParticles[i].vitesse*dt + w.tableauParticles[i].position;
}
}

// ------------------------------ //



// ------------------------------ //

int main(int , char**)
{
    bool stop = false;
	winInit("SystemePointCollisions",500,500);
	backgroundColor(120,70,200);

	color(220,70,100);

	float dt = 0.001;

	Vecteur friction = {-0.7, -0.7};

	World w;
	w.particleSym = 30;
	init(w);

	while(!stop){

    winClear();

    for(int i = 0; i<w.particleSym; i++){
    drawParticle(w.tableauParticles[i]);
    attractionTerrestreWorld(w, dt, friction, i);
    }

    stop = winDisplay();

    if(isKeyPressed(SDLK_SPACE)){
    winQuit();
    }
	}
	return 0;
}
