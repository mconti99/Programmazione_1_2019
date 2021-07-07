#include "indeterminato.h"
namespace MS{
	ostream & Indeterminato::print(ostream &out)const{
		Determinato::print(out);
		out << " " << exp << endl;
		return out;
	}
	istream & Indeterminato::input(istream &in){
		Determinato::input(in);
		in >> exp;
		return in;
	}
	ostream & operator<<(ostream & out, const Indeterminato &I){
		return I.print(out);
	}
	istream & operator>>(istream & in, Indeterminato &I){
		return I.input(in);
	}
	bool Indeterminato::check(const int annocorrente)const throw(const char *){
		if(get_cod()[0]=='B' && get_cod()[1]=='H'){
			if(!strcmp(get_titolo(),"Laurea") && get_voto()>=106 && annocorrente-get_a()<=30) return true;
			else if(!strcmp(get_titolo(),"Laurea") && get_voto()>=106 && exp==true && annocorrente-get_a()>30) return true;
			else if(!strcmp(get_titolo(),"Laurea") && annocorrente-get_a()<=30 && exp==true && get_voto()<106) return true;
			else return false;
		}
		else throw "errore CODICE ERRATO";
	}
}
