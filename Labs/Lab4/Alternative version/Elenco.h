#ifndef _ELENCO_H
#define _ELENCO_H
#include "persona.h"
using std::ostream;
using std::cout;
namespace MS{

	class Elenco{
		private: 
			Persona v[20];
			int nelem;
		public:
			Elenco(){nelem=0;}
			//inserimento ordinato per cognome
			void inserimento_ord(const Persona &);
			//ricerca
			bool ricerca_bin(const int first, const int last, const Persona x);
			//eliminazione
			void eliminate_ord(Persona &, const int pos);
			ostream & print(ostream &) const;
	};
}
#endif
