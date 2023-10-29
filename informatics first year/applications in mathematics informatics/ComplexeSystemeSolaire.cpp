#include<Grapic.h>

using namespace grapic;

#include <iostream>
#include <math.h>

using namespace std;

const int DIMW = 500;

struct complexe{
    float x;
    float y;
};

typedef complexe Vecteur;
typedef complexe Point;

complexe makeComplexe (float x, float y){
complexe c;
c.x = x;
c.y = y;
return c;
}

complexe makeComplexeExp (float r, float ThetaRad){
return makeComplexe(r*cos(ThetaRad), r*sin(ThetaRad));
}

float toRadian (float degre){
return ((degre * M_PI) / 180);
}

complexe operator + (complexe a, complexe b){
return makeComplexe(a.x + b.x, a.y + b.y);
}

complexe operator - (complexe a, complexe b){
return makeComplexe(a.x - b.x, a.y - b.y);
}

complexe operator * (complexe a, float b){
return makeComplexe(b * a.x, b * a.y);
}

complexe operator * (float b, complexe a){
return makeComplexe(b * a.x, b * a.y);
}

complexe operator * (complexe a, complexe b){
return makeComplexe((a.x * b.x) - (a.y * b.y), (a.x * b.y) + (a.y * b.x));
}

complexe scale (complexe a, float cx, float cy, float lambda){
complexe b, c;
c = makeComplexe(cx, cy);
b = (a-c) * lambda + c;
return b;
}

complexe Rotate (complexe a, float cx, float cy, float angleRad){
complexe c, b, rot;
c = makeComplexe(cx, cy);
rot = makeComplexeExp(1, angleRad);
b = (a-c) * rot + c;
return b;
}

struct SolarSystem
{
complexe sun, earth, moon, mercury, venus, mars;
};

void initSolarSystem(SolarSystem &s)
{
    s.sun = makeComplexe (DIMW/2, DIMW/2);
    s.earth = s.sun + makeComplexe (110, 110);
    s.moon = s.earth + makeComplexe (30, 30);
    s.mercury = s.sun + makeComplexe (50, 50);
    s.venus = s.sun + makeComplexe (75, 75);
    s.mars = s.sun + makeComplexe (160, 160);
}

void draw (SolarSystem s){
color(200,200,0);
circleFill(s.sun.x, s.sun.y, 30);
color(100, 100, 100);
circleFill(s.mercury.x, s.mercury.y, 7);
color(0, 0, 200);
circleFill(s.earth.x, s.earth.y, 15);
color(150, 150, 150);
circleFill (s.moon.x, s.moon.y, 5);
color(200, 150, 0);
circleFill (s.venus.x, s.venus.y, 10);
color(250, 0, 0);
circleFill (s.mars.x, s.mars.y, 13);
}

void update (SolarSystem &s){
s.mercury = Rotate (s.mercury, s.sun.x, s.sun.y, toRadian(0.2));
s.venus = Rotate (s.venus, s.sun.x, s.sun.y, toRadian(0.06));
s.mars = Rotate (s.mars, s.sun.x, s.sun.y, toRadian(0.02));
Vecteur tr;
tr = s.moon - s.earth;
s.earth = Rotate(s.earth, s.sun.x, s.sun.y,toRadian(0.04));
s.moon = s.earth + tr;
s.moon = Rotate(s.moon, s.earth.x, s.earth.y, toRadian(0.1));
}

int main(int , char**)
{
    bool stop=false;
	winInit("SolarSystem",DIMW,DIMW);
	backgroundColor(300,300,300);

    SolarSystem s;
	initSolarSystem(s);
	while(!stop){
	    winClear();
        draw(s);
        update(s);
        delay(1);
        stop = winDisplay();
	}
	winQuit();
	return 0;
}
