#include <iostream>
const int N=100;

using namespace std;
struct Prodotto{
	char Codice[N];
	char Descrizione[N];
	int Qta;
};

void Inserisci_DatiProdotto(Prodotto &);
void Visualizza_DatiProdotto(const Prodotto &);// avendo const davanti continuerà ad essere un parametro di solo ingresso
//lo scambio per riferimento per evitare la copia(che potrebbe essere di grandi dimensioni)
