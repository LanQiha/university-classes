#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class date
{
private:
    int* jour;
    int* mois;
    int* annee;
public:
    date();
    date(int j,int m,int a);
    date(const date& d);
    ~date();
    void definirDate(int j,int m,int a);
    void afficheDate();
    bool operator == (const date& d);
    date& operator = (const date& d);
    friend istream& operator>>(istream &flux,date& d);
    friend ostream& operator<<(ostream &flux,date& d);
    date operator + (int j);
    bool anneeBissextile();
};


#endif // DATE_H_INCLUDED
