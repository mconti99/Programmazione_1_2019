#ifndef _CODA_H
#define _CODA_H
#include "brano.h"
namespace MS{
	typedef Brano T;
	class Coda{
		T * coda;
		int n;
		int t;
		int c;
		int maxelem;
		public:
			Coda(const int dim=10);
			Coda(const Coda &);
			const Coda & operator=(const Coda &);
			bool append(const T &);
			bool pop(T &);
			bool Empty()const;
			bool Full()const;
			~Coda(){delete [] coda;}
	};
}
#endif
