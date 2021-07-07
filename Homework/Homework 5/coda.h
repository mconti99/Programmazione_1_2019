#ifndef _CODA_H
#define _CODA_H
#include "classi.h"
namespace MS{



class Coda{
	typedef Veicolo * T;
	struct Record;
	struct Record{
		T elem;
		Record * next;
	};
	Record * l;
	bool push(const T &);
	public:
		Coda(){l=0;}
		bool append(const T &e);
		bool pop(T& e);
		bool empty()const{return l==0;}
		bool full()const{return false;}
		//top
		~Coda();
		
};
}
#endif
