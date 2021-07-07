#ifndef _DIRIGENTE_H_
#define _DIRIGENTE_H_
#include <ctime>
#include "lavoratore.h"
using std::time_t;

namespace Mynamespace{
class Dirigente: public Lavoratore {
	
	public:
		Dirigente(): Lavoratore() {}
		Dirigente(const char *matricola, const char *azienda, const int annoAssunzione): 
			Lavoratore(matricola, azienda, annoAssunzione){}
		//Dirigente(const Dirigente&); //inutile, invocato di default quello di classe base
		//const Dirigente& operator=(const Dirigente&); //inutile, invocato di default quello di classe base
		
		virtual float calcolaStipendio() const;
		
	private:
		ostream & stampa(ostream &out) const;
};

} //fine namespace
#endif
