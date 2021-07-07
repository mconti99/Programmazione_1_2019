#ifndef _PIANO_H
#define _PIANO_H
#include <iostream>
#include <cstring>
#include "eccezione.h"
using namespace std;
namespace MS{
	struct Record;
	struct Record{
		int id; //posizione del record nel vettore
		bool occupato;
	};
	class Piano{
		int posti; //numero di posti nel piano
		Record * v; 
		public:
			Piano(const int dim=5): posti(dim), v(new Record[dim]){for(int i=0;i<dim;i++) {v[i].id=i; v[i].occupato=false;}}
			int get_disponibili()const;
			int assegna();
			int get_posti()const{return posti;}
			bool libera(const int )throw(bad_id &);
			virtual ~Piano(){delete [] v;}
			Piano(const Piano &);
			const Piano & operator=(const Piano &);
			void stampa(ostream &)const;
	};
}
#endif
