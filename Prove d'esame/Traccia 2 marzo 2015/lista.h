#ifndef _LISTA_H
#define _LISTA_H
#include "classi.h"
#include "eccezione.h"
#include <fstream>
namespace MS{
	typedef Processo * T;
	struct Record;
	struct Record{
		T info;
		Record * next;
	};
	class Lista{
		private:
			Record * testa;
			bool push(const T &);
		public:
			Lista(){testa=0;}
			bool empty()const{return (testa==0);}
			bool append(const T &)throw (Eccezione &);
			bool remove(T &);
			~Lista();
			bool in(const T &)const;
			int getp()const;
			void schedule(const int p);
			void show(ostream& ) const;
			void store(const char * ) const;
	};
}
#endif
