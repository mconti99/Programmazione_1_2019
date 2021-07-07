#include "indirizzo.h"
namespace MS{
	ostream & Indirizzo::stampa(ostream & out)const{
		out << via << " " << numerociv << " " << citta << " " << cap << endl;
		return out;
	}
	ostream & operator<<(ostream & out, const Indirizzo &I){
		return I.stampa(out);
	}
}
