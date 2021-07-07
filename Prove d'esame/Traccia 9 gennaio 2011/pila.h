#ifndef _PILA_H
#define _PILA_H
#include "pacco.h"
#include "filexcept.h"
#include <fstream>
namespace MS{
	typedef Pacco T;
	struct Record;
	struct Record{
		T info;
		Record * next;
	};
	class Pila{
		Record * testa;
		public:
			Pila(){testa=0;}
			bool push(const T & );
			bool pop(T &);
			bool top(T &)const;
			bool empty()const {return (testa==0);}
			bool full()const {return false;}
			void leggidafile() throw(FileExcep &);
	};
}
#endif
