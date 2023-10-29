#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

struct Stock {std::string nom; int quantite;};
void operator +=(Stock& S,int n);
void operator -={Stock& S,int n);
#endif // STOCK_H_INCLUDED
