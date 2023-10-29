#include <iostream>
#include <cmath>

using namespace std;

#include "complexe.h"

//fonction

complexe :: complexe(){
    im = 0;
    re = 0;
}

complexe :: complexe(double r){
    im = 0;
    re = r;
}

complexe :: complexe(double r, double i){
    im = i;
    re = r;
}

double complexe :: getRe(){
     return re;
}

double complexe :: getIm(){
    return im;
}

double complexe :: getModule(){
    double Mod(0.);
    Mod = sqrt((pow(re,2)+pow(im,2)));
    return Mod;
}

double complexe :: getArg(){
    if (re!=0){
        return atan(im/re)*180/M_PI;
    }

    else if(im>0){
        return 90.0;
    }

    else if(im<0){
         return 270.0;
    }

    else return (0.);
    }

void complexe :: affiche(){
    cout<<re<<"+i"<<im<<endl;
}

bool complexe :: operator == (complexe com){
if((com.re == re)and(com.im == im)){
    return true;}
else return false;
}

bool complexe :: operator != (complexe com){
if((com.re == re)and(com.im == im)){
    return false;}
else return true;
}

istream& operator>>(istream &flux,complexe& comp1){
    cout<<"re = ";
    flux>>comp1.re;
    cout<<"im = ";
    flux>>comp1.im;
    return flux;
    }

ostream& operator<<(ostream &flux,complexe comp1){
    flux<<comp1.re<<"+i"<<comp1.im<<endl;
    return flux;
    }

complexe complexe :: operator + (complexe com1){
    complexe z;
    z.re = com1.re + re;
    z.im = com1.im + im;
    return z;
}

complexe& complexe :: operator += (complexe com2){
    re += com2.re;
    im += com2.im;
}
