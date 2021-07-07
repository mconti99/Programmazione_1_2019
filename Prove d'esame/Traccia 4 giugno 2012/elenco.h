#ifndef _ELENCO_H
#define _ELENCO_H
#include "eccezione.h"
#include "manoscritto.h"
#include <fstream>
namespace MS{
	typedef Manoscritto T;
	class Elenco{
		static const int max=10;
		T v[max];
		int nelem;
		public:
			Elenco(): nelem(0){}
			void insert_ord(const T &) throw(Duplicato &);
			bool is_in(const T &, int &)const;
			void remove(const T &);
			void stampa()const;
			void input(istream &);
	};
}
#endif
