#ifndef COMPLEXE_H_INCLUDED
#define COMPLEXE_H_INCLUDED

class complexe
{

private :
    double re;
    double im;
public :
    complexe();
    complexe(double r);
    complexe(double r, double i);
    double getRe();
    double getIm();
    double getModule();
    double getArg();
    void affiche();
    bool operator == (complexe com1);
    bool operator != (complexe com1);
    friend istream& operator>>(istream &flux,complexe& comp1);
    friend ostream& operator<<(ostream &flux,complexe comp1);
    complexe operator + (complexe com1);
    complexe& operator += (complexe com2);
};

#endif // COMPLEXE_H_INCLUDED
