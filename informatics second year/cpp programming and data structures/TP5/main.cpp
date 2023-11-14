#include "TableauDynamique.h"
#include <iostream>
#include <ctime>

int main()
{
	TableauDynamique * tab = new TableauDynamique;
	std::cout << "Capacite : " << tab->capacite << ", Taille utilisee: " << tab->taille_utilisee << std::endl;
	TableauDynamique * t = new TableauDynamique;
	ElementTD e = 3;
	ElementTD el = 5;
	t->ajouterElement(e);
	std::cout << "Capacite : " << t->capacite << ", Taille utilisee: " << t->taille_utilisee << std::endl << ", element a la case 0 : " << t->valeurIemeElement(0) << std::endl;
	
	t->ajouterElement(e);
	t->afficher(); 

	t->modifierValeurIemeElement(el, 1);
	t->afficher(); 
	
	t->supprimerElement(0);
	t->afficher(); 
	
	t->vider();
	t->afficher(); 

	int n = 500000;
	int tabStat [n];
	
	int k = 100000;
	int l = 20000000;
	
	 clock_t tempsExecution = clock();
	for(int i = 0; i < n; ++i)
		tabStat[i] = 0;
	tempsExecution = clock() - tempsExecution;
	std::cout << "Temps d'execution : " << ((float)tempsExecution)/CLOCKS_PER_SEC << " secondes." << std::endl;
	
	clock_t tempsExecution2 = clock();
	for(int i = 0; i < n; ++i)
		tab->ajouterElement(e);
	tempsExecution2 = clock() - tempsExecution2;
	std::cout << "Temps d'execution2 : " << ((float)tempsExecution2)/CLOCKS_PER_SEC << " secondes." << std::endl;
	
	std::cout << "Comparaison : " << (1.0 * tempsExecution2)/tempsExecution << std::endl;
	
	int  * tabStatique;
	tabStatique = new int [l];
	clock_t tempsExecution3 = clock();
	for(int i = k; i < l; i=i+k)
		tabStatique[i] = 0;
	tempsExecution3 = clock() - tempsExecution3;
	std::cout << "Temps d'execution3 : " << ((float)tempsExecution3)/CLOCKS_PER_SEC << " secondes." << std::endl;
	
	tab->vider();
	clock_t tempsExecution4 = clock();
	for(int i = k; i < l; i=i+k)
		tab->ajouterElement(e);
	tempsExecution4 = clock() - tempsExecution4;
	std::cout << "Temps d'execution4 : " << ((float)tempsExecution4)/CLOCKS_PER_SEC << " secondes." << std::endl;
	
	std::cout << "Comparaison2 : " << (1.0 * tempsExecution4)/tempsExecution3 << std::endl;
	
	// Libération de la mémoire dynamique
	if (tabStatique != nullptr) {
		delete [] tabStatique;
		tabStatique = nullptr;
    	}
    	ElementTD ele = 9;
    	ElementTD elem = 10;
    	
    	t->ajouterElement(el);
    	t->ajouterElement(ele);
    	t->ajouterElement(e);
    	
    	t->afficher(); 
	
	t->trier();
	t->afficher(); 
	
	std::cout << "Indice de l'element e : " << t->rechercherElement(ele) << std::endl;
	
	t->insererElement(elem,0);
	t->afficher(); 
	
	t->supprimerElement(2);
	t->afficher(); 
	
	return 0;
}
