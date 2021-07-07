#ifndef _DIPENDENTE_H_
#define _DIPENDENTE_H_
#include <ctime>
#include "lavoratore.h"
namespace Mynamespace{
class Dipendente: public Lavoratore {
	
	public:
		char *qualifica; //stringa allocata dinamicamente
		ostream & stampa(ostream &out) const;
	
	public:
		//costruttore senza argomenti
		Dipendente() : Lavoratore() {qualifica = new char[1];	strcpy(qualifica, "");}
		//costruttore con argomenti
		Dipendente(const char *matricola, const char *azienda, const char *qua, const int annoAssunzione) : 
			Lavoratore(matricola, azienda, annoAssunzione) {
			qualifica = new char[strlen(qua) + 1];
			strcpy(qualifica,qua);
			}
		//costruttore di copia
		Dipendente(const Dipendente&);
		virtual ~Dipendente() {delete [] qualifica;}
		
		virtual float calcolaStipendio() const;
		//operatore di assegnazione
		const Dipendente& operator=(const Dipendente&);
};

} //fine namespace
#endif
