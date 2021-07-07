#ifndef _ORDINARIO_H
#define _ORDINARIO_H
#include "contocorrente.h"
//le spese dipendono dal numero di operazioni effettuate
//più movimenti fatti, più spesa annua
namespace MS{
class ordinario : public conto{
		protected:
	float costo; //costo relativo ad un certo numero di operazioni (0,02 euro ogni 3 operazioni)
	int numeroCosto;
	public:
		ordinario(): conto(), costo(0.2), numeroCosto(3){}
		ordinario(const string S, const int A, const int B, const float Mio, const int num): conto(S,A,B), costo(Mio), numeroCosto(num){}
		virtual float calcolo_spese()const; //calcola la spesa corrente in base al numero di movimenti effettuati
};
}
#endif
