#include <iostream>
#include "parcheggio.h"
#include "piano.h"
using namespace MS;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Parcheggio P1("Parcheggio 24h", "Via Rossini", Piano(), Piano());
	cout << "quanti sono i posti liberi? "<< P1.postiliberi() << endl;
	P1.ingresso();
	P1.ingresso();
	P1.ingresso();
	P1.ingresso();
	P1.ingresso();
	if(P1.estrazione(2,0)==true) cout << "operazione effettuata"<<endl;
	P1.stampa(cout);
	return 0;
}
