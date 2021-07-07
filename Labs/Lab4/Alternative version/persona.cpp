#include "persona.h"
namespace MS{
	ostream & Persona::print(ostream & out)const{
		out << nome << " " << cognome << " " << anno << endl;
		return out;
	}
	ostream & operator<<(ostream & out, const Persona &P){
		return P.print(out);
	}
	bool Persona::operator==(const Persona & P)const{
		return ((nome==P.nome) && (cognome==P.cognome) && (anno==P.anno));
	}
}
