#include "dirigente.h"


namespace Mynamespace{
float Dirigente::calcolaStipendio() const {
	time_t data;
	tm *dataInfo;
	data=time(NULL); // ottiene l' ora odierna
	dataInfo=localtime(&data); // converte data in una struttura tm (nota il passaggio per indirizzo)
	int annoCorrente = dataInfo->tm_year+1900;
	
	float ret = getPagaBase();
	int anzianita = annoCorrente - annoAssunzione;
	for (int i=1; i<anzianita; i++) {
		ret += ret * 0.1;
	}
	return ret;
}

ostream & Dirigente::stampa(ostream &out) const {
	//uso la funzione stampadi lavoratore
	return Lavoratore::stampa(out) << ", stipendio attuale: "<< calcolaStipendio();
}

} //fine namespace
