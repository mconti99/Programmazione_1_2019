#include "prodotto.h"

void Inserisci_DatiProdotto(Prodotto &P){
	cout<<"inserire il codice: "<<endl;
	cin.getline(P.Codice,N);
	cout<<"inserire la descrizione: "<<endl;
	cin.getline(P.Descrizione,N);
	cout<<"inserire la quantita': "<<endl;
	cin>>P.Qta;
}

void Visualizza_DatiProdotto(const Prodotto &P){
	cout<<"codice: "<<P.Codice<<endl;
	cout<<"descrizione: "<<P.Descrizione<<endl;
	cout<<"quantita': "<<P.Qta<<endl;
}
