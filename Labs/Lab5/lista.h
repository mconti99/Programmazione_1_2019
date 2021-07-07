#ifndef _LISTA_H
#define _LISTA_H
#include "classi.h"
#include "eccezione.h"
namespace MS{
	typedef Bolletta * T; //perchè metto *
	struct Record;
	struct Record{
		T info;
		Record * next;
	};
	class Lista{ //ordinata su codicecliente
			Record * testa;
			bool push(const T &);
		public:
			Lista(){testa=0;}
			void inserimento(const T &)throw(Eccezione &);
			bool empty(){return (testa=0);}
			bool full(){return false;}
			ostream & print(ostream &)const;
			bool in(const T &)const;
			~Lista();
	};
}
#endif
