#include "dipendente.h"

namespace Mynamespace{
Dipendente::Dipendente(const Dipendente &D) : /* chiamo il costruttore di copia di Lavoratore */Lavoratore(D) {
	qualifica = new char[strlen(D.qualifica) + 1];
	strcpy(qualifica, D.qualifica);
}

const Dipendente &Dipendente::operator=(const Dipendente& D) {
	if(this != &D) {
		Lavoratore::operator=(D);
		if(qualifica) delete [] qualifica;
		qualifica = new char[strlen(D.qualifica) + 1];
		strcpy(qualifica, D.qualifica);
    }
    return *this;  
}

float Dipendente::calcolaStipendio() const {
	time_t data;
    tm *dataInfo;
    data=time(NULL); // ottiene l' ora odierna
    dataInfo=localtime(&data); // converte data in una struttura tm (nota il passaggio per indirizzo)
	int annoCorrente = dataInfo->tm_year+1900;
	
	float ret = getPagaBase();
	int anzianita = annoCorrente - annoAssunzione;
	for (int i=1; i<anzianita; i++) {
		ret += ret * 0.05; //incrementa del 5% ogni anno
	}
	return ret;
}

ostream & Dipendente::stampa(ostream &out) const {
	return Lavoratore::stampa(out)<< " qualifica " <<qualifica<< ", stipendio attuale: "<<calcolaStipendio();
	
}

} //fine namespace
