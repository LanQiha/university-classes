#include<Grapic.h>

#include<iostream>

using namespace grapic;

using namespace std;

const float Tfroid = -40;
const float Tchaud = 30;

struct complexe{
    float x,y;
};

typedef complexe Point;

struct Color {
unsigned char r, v, b;
};

/*------------------------------/



/------------------------------*/

complexe makeComplexe (float x, float y){
complexe c;
c.x = x;
c.y = y;
return c;
}

complexe operator + (complexe a, complexe b){
return makeComplexe (a.x + b.x, a.y + b.y);
}

complexe operator - (complexe a, complexe b){
return makeComplexe (a.x - b.x, a.y - b.y);;
}

complexe operator * (float lambda, complexe a){
return makeComplexe(lambda*a.x, lambda*a.y);;
}

complexe operator * (complexe a, float lambda){
return makeComplexe(lambda*a.x, lambda*a.y);
}

/*------------------------------/



/------------------------------*/

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

/*------------------------------/



/------------------------------*/

complexe interpolation (complexe a, complexe b, float t)
{
    return (1-t)*a + t*b;;
}

/*------------------------------/



/------------------------------*/

/*Color colorTemperature (float temperature)
{
Color froid = {0, 0, 255};
Color chaud = {255, 0, 0};
float t = (temperature - Tfroid) / (Tchaud - Tfroid);
return ((1-t) * froid + chaud * t);
}
void DrawLine (complexe nb1, complexe nb2){
line(nb1.x, nb1.y, nb2.x, nb2.y);
}*/

void draw_line(Point A, Point B, Color CA, Color CB)
{
    float t;
    Point prec = A, cur;
    Color Ccur;
    int i;
    for(i=0;i<=100;++i)
    {
        t = float(i)/100;
        cur = (1-t)*A + t*B;            // interpolation point
        Ccur = (1-t)*CA + t*CB;         // interpolation couleur
        color( Ccur.r, 0, Ccur.b);
        line(prec.x,prec.y,cur.x,cur.y);
        prec = cur;
    }
}

int main(int , char**)
{
	winInit("InterpolationBase",500,500);
	backgroundColor(100,50,200);

	complexe nb1 {150, 150};
	complexe nb2 {350, 350};

	float pas = 0.1;

    winClear();

    Color r;
    r.r = 255;
    r.b = 0;
    r.v = 0;

    Color b;
    b.r = 0;
    b.v = 0;
    b.b = 255;

    draw_line(nb1, nb2, r, b);

    //for(int i = 0; i<10; i++)
    //{
    //c = colorTemperature(((Tchaud - Tfroid)/10) * i - Tfroid);
    //color(c.r, 0, c.b);
    //DrawLine (interpolation(nb1, nb2, i*pas), interpolation(nb1, nb2, (i+1)*pas));
    //}

	pressSpace();
	winQuit();
	return 0;
}
