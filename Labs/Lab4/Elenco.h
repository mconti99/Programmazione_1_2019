#ifndef _ELENCO_H
#define _ELENCO_H
#include "persona.h"
using std::ostream;
using std::cout;
namespace MS{
	struct Record;
	struct Record{
		Persona Info; //metto persona
		Record * next;
	};
	class Elenco{
		private: 
			Record * testa;
			bool pop(Persona &);
		public:
			Elenco(){testa=0;}
			~Elenco();
			//inserimento
			bool Push(const Persona &)throw(const char *);
			//ricerca
			bool ricerca(const Persona &, int &);
			//eliminazione
			bool eliminate(Persona &, const int pos);
			int get_n()const;
			ostream & print(ostream &) const;
	};
}
#endif
