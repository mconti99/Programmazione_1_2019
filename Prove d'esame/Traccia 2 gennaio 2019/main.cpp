#include <iostream>
#include "classi.h"
using namespace MS;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Bene P1("id1","cibo", 2.00,false,"pasta");
	Record e;
	e.p=&P1;
	e.qta=2;
	
	Bene P2("id2", "TV", 500.0, false, "smart");
	Record e1;
	e1.p=&P2;
	e1.qta=1;
	
	Servizio S1("id3", "parcheggio", 250.0, "in citta'");
	Record e2;
	e2.p=&S1;
	e2.qta=1;
	
	Cliente c2("A111", "indirizzomio");
	Ordine O;
	O.AssociaCliente(&c2);
	O.insert(e);
	cout<<"Prodotto P1 aggiunto all'ordine"<<endl;
	O.insert(e1);
	cout<<"Prodotto P2 aggiunto all'ordine'"<<endl;
	try{
	O.insert(e2);
	cout<<"Servizio S1 aggiunto all'ordine"<<endl;
}catch(const char * e){
	cout << e << endl;
}
	
	cout<<"Dettaglio Ordine"<<endl;
	cout<<"Codice Cliente: " << c2.get_c() << endl;
	O.stampa(cout);
	cout << "Totale ordine: " << O.calcolaordine()<< endl;	
	return 0;
}
