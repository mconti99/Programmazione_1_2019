#ifndef _BASE_H
#define _BASE_H
#include "conto_ordinario.h"
//con franchigia: canone include un numero limitato di operazioni gratuite
//senza franchigia: è possibile effettuare un numero illimitato di operazioni gratuite, pagando solo il canone
namespace MS{
	class base : public ordinario{
		int canone;
		bool franchigia; //se il conto è con franchigia
		int gratis; //numero di operazioni gratuite in caso di conto con franchigia
		public:
			base(): ordinario(), canone(10), franchigia(false), gratis(2){}
			base(const string S, const int A, const int B, const float comm, const int no, const int c,  const bool fr, const int free):
				ordinario(S,A,B,comm,no), canone(c), franchigia(fr), gratis(free){}
			virtual float calcolo_spese()const; //calcola la spesa corrente per il conto 
			//in base al valore delle variabili membro proprie e (eventualmente) in base al numero di movimenti effettuati
			int get_c()const{return canone;}
	};
}
#endif
