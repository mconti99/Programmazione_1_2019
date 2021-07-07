#ifndef _LAVORATORE_H_
#define _LAVORATORE_H_

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

namespace Mynamespace{

class Lavoratore {
	
	friend ostream & operator<<(ostream &, const Lavoratore&);
    friend istream & operator>>(istream &, Lavoratore&);
	
	protected:
		char matricola[10];
		char *azienda;
		int annoAssunzione;
	
	private:
		static const float pagaBase = 10000.0;
		bool validaMatr(const char *) const;
		
	protected:
		float getPagaBase() const {return pagaBase;}
		virtual ostream & stampa(ostream &out) const;
	
	public:
		Lavoratore();
		Lavoratore(const char *matricola, const char *azienda, const int annoAssunzione);
		Lavoratore(const Lavoratore&);
		virtual ~Lavoratore() {delete [] azienda;}
		//get e set
		const char* getMatricola() const {return matricola;}
		void setMatricola(const char *);
		const char* getAzienda() const {return azienda;}
		void setAzienda(const char *);
		int getAnnoAssunzione() const {return annoAssunzione;}
		void setAnnoAssunzione(const int);
		
		virtual float calcolaStipendio() const = 0;
		
		const Lavoratore& operator=(const Lavoratore&);
};
}
#endif
