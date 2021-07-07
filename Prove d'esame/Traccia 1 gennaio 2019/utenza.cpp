#include "utenza.h"
namespace MS{
	Utenza::Utenza(const Utenza &U){
		strcpy(numerotel,U.numerotel);
		strcpy(codice,U.codice);
		intestatario=new char[strlen(U.intestatario)+1];
	}
	const Utenza & Utenza::operator=(const Utenza &U){
		if(this!=&U){
			delete [] intestatario;
			strcpy(numerotel,U.numerotel);
			strcpy(codice,U.codice);
			intestatario=new char[strlen(U.intestatario)+1];
		}
		return *this;
	}
	ostream & Utenza::print(ostream &out)const{
		out << codice << " " << intestatario << " " << numerotel;
		return out;
	}
	ostream & operator<<(ostream & out, const Utenza &U){
		return U.print(out);
	}
}
