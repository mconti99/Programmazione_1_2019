#ifndef _PARK_H
#define _PARK_H
#include "piano.h"
namespace MS{
	class Parcheggio{
		string nome;
		string indirizzo;
		Piano p1;
		Piano p2;
		public:
			Parcheggio(): nome(""), indirizzo(""){}
			Parcheggio(const string & n, const string & i, const Piano & a, const Piano & z): p1(a), p2(z),nome(n), indirizzo(i){}
			int postiliberi()const;
			void ingresso();
			bool estrazione(const int numeropiano, const int);
			void stampa(ostream &)const;
	};
}
#endif
