#ifndef _MAGAZZINO_H
#define _MAGAZZINO_H
#include "vettore.h"
class Magazzino{
	//friend ostream & operator<<(ostream &, const Magazzino &);
	//friend istream & operator>>(istream &, Magazzino &);
	private:
	Vettore V;
	int n; //numero di elementi presenti in magazzino
	public:
	// DA RIVEDERE: explicit Magazzino(const int nelem=10) : n(0) {}

	void Inserisci_Dati_Magazzino();
	bool Cerca_Prodotto(const char*, int &)const;
	bool Elimina_Prodotto(const int);
	void Visualizza_Magazzino()const;
	void Stampa_StatoMagazzino()const;
};
#endif

