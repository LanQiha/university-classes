#include "TableauDynamique.h"

TableauDynamique::TableauDynamique()
{
    ad = new ElementTD [1];
    capacite = 1;
    taille_utilisee = 0;
}

TableauDynamique::~TableauDynamique()
{
    if (ad != nullptr) {
        delete [] ad;
        ad = nullptr;
    }
    capacite = 0;
    taille_utilisee = 0;
}

TableauDynamique::TableauDynamique(const TableauDynamique& t)
{
    capacite = t.capacite;
    taille_utilisee = t.taille_utilisee;
    ad = new ElementTD[capacite];
    for(unsigned int i = 0; i < taille_utilisee; ++i)
        ad[i] = t.ad[i];
}

void TableauDynamique::vider()
{
    if (ad != nullptr) {
        delete [] ad;
        ad = nullptr;
    }
    ad = new ElementTD [1];
    capacite = 1;
    taille_utilisee = 0;
}

void TableauDynamique::ajouterElement(ElementTD e)
{
    if (taille_utilisee == capacite) {
        ElementTD * temp = ad;
        ad = new ElementTD [2*capacite];
        capacite *= 2;
        for (unsigned int i = 0; i < taille_utilisee; ++i)
            ad[i] = temp[i];
        delete [] temp;
    }
    ad[taille_utilisee] = e;
    taille_utilisee++;
}

ElementTD TableauDynamique::valeurIemeElement(unsigned int indice) const
{
    return ad[indice];
}

void TableauDynamique::modifierValeurIemeElement(ElementTD e, unsigned int indice)
{
    ad[indice] = e;
}

void TableauDynamique::afficher() const
{
    for(unsigned int i = 0; i < taille_utilisee; ++i) {
        afficheElementTD(ad[i]);
        std::cout << " ";
    }
    std::cout << "" << std::endl;
}

void TableauDynamique::supprimerElement(unsigned int indice)
{
    for(unsigned int i = indice; i < taille_utilisee - 1; ++i)
    	ad[indice] = ad[indice + 1];
    ad[taille_utilisee - 1] = ad[taille_utilisee];
    taille_utilisee--;
    if(taille_utilisee < capacite / 3) {
        capacite = capacite / 2;
    }
}

void TableauDynamique::insererElement(ElementTD e, unsigned int indice)
{
	ajouterElement(e); // indice = taille_utilisee - 1
	int nb = taille_utilisee - indice - 1;
	int nb2 = taille_utilisee - 1;
	ElementTD temp;
	while(nb != 0){
		temp = ad[nb2 - 1];
		ad[nb2 - 1] = ad[nb2];
		ad[nb2] = temp;
		nb--;
		nb2--;
	}	
}

void TableauDynamique::trier()
{
	int nb;
	int j = 0;
	for(unsigned int i = 1; i < taille_utilisee; i++){
		nb = ad[i];
		j = i;
		while(j > 0 and ad[j-1] > nb){
			ad[j] = ad[j-1];
			j = j-1;
		}
		ad[j] = nb;
	}
}

int TableauDynamique::rechercherElement(ElementTD e) const
{
	for(unsigned int i = 0; i < taille_utilisee; i++)
		if(ad[i] == e) return i;                     
	return -1;
}

