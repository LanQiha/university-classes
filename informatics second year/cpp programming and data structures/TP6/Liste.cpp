#include "Liste.h"

#include <iostream>

using namespace std;

Liste::Liste() : prem(nullptr), last(nullptr) {
}

Liste::~Liste()
{
    vider();
}

Liste& Liste::operator=(const Liste& l)
{
    Cellule * c = l.prem;
    while(c != nullptr) {
        this->ajouterEnQueue(c->info);
        c = c->suivant;
    }
    return *this;
}

void Liste::vider()
{
    Cellule* current = prem;
    while (current != nullptr) {
        Cellule* next = current->suivant;
        delete current;
        current = nullptr;
        current = next;
    }
    prem = last = nullptr;
}

bool Liste::estVide() const
{
    return (prem == nullptr);
}

unsigned int Liste::nbElements() const
{
    Cellule * c = prem;
    unsigned int nb = 0;
    while(c != nullptr){
        nb++;
        c = c->suivant;
    }
    return nb;
}

ElementL Liste::iemeElement(unsigned int indice) const
{
    ElementL e = -1;
    Cellule * c = prem;
    unsigned int nb = 0;
    while(c != nullptr){
        if(nb == indice){
            return c->info;
            break;
        }
        nb++;
        c = c->suivant;
    }
    return e;
}

void Liste::modifierIemeElement(unsigned int indice, ElementL e)
{
    Cellule * c = prem;
    unsigned int nb = 0;
    while(c != nullptr){
        if(nb == indice)
            c->info = e;
        nb++;
        c = c->suivant;
    }
}

void Liste::afficherGaucheDroite() const
{
    Cellule * c = prem;
    while(c != nullptr) {
        afficherElementL(c->info);
        cout << " ";
        c = c->suivant;
    }
    cout << " " << endl;
}

void Liste::afficherDroiteGauche() const
{
	Cellule * c = last;
    	while(c != nullptr) {
        	afficherElementL(c->info);
        	cout << " ";
        	c = c->precedent;
    	}
    	cout << " " << endl;
}

void Liste::ajouterEnTete(ElementL e)
{
    Cellule * c = new Cellule;
    c->info = e;
    c->suivant = nullptr;
	c->precedent = nullptr;
    
    if(prem == nullptr) {
    	prem = c;
    	last = c;
    }
    else {
    	c->suivant = prem;
    	prem->precedent = c;
    	prem = c;
    }
}

void Liste::ajouterEnQueue(ElementL e)
{
	Cellule * c = new Cellule;
	c->info = e;
	c->suivant = nullptr;
	c->precedent = nullptr;
	
	if(last == nullptr) {
		prem = c;
		last = c;
	}
	else {
		last->suivant = c;
		c->precedent = last;
		last = c;
	}
}

void Liste::supprimerTete()
{
    Cellule* temp = prem;
    prem = prem->suivant;
    prem->precedent = nullptr;
    delete temp;
}

int Liste::rechercherElement(ElementL e) const
{
    Cellule * c = prem;
    int nb = 0;
    while(c != nullptr) {
        if(estEgalElementL(c->info, e)) {
            return nb;
            break;
        }
        nb++;
        c = c->suivant;
    }
    return -1;
}

void Liste::insererElement(ElementL e, unsigned int indice)
{
    Cellule * c = prem;
    unsigned int nb = 0;
    
    Cellule * temp = new Cellule;
    temp->info = e;
    
    while(c != nullptr) {
        if(nb == indice) {
            c->precedent->suivant = temp;
            temp->precedent = c->precedent;
            temp->suivant = c;
            c->precedent = temp;
            break;
        }
        nb++;
        c = c->suivant;
    }
}

void Liste::trier()
{
    Cellule * c = prem;
    ElementL e;
    int i = 0;
	int j = 0;
    while(c != nullptr) {
        e = iemeElement(i);
        j = i;
        while(j > 0 and iemeElement(j-1) > e) {
            modifierIemeElement(j, iemeElement(j-1));
            j = j-1;
        }
        modifierIemeElement(j, e);
        i++;
        c = c->suivant;
    }
}

