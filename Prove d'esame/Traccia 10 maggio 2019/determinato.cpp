#include "determinato.h"
namespace MS{
	Determinato::Determinato(const Determinato &D): Candidato(D){
		titolo=new char[strlen(D.titolo)+1];
		strcpy(titolo,D.titolo);
		voto=D.voto;
	}
	const Determinato & Determinato::operator=(const Determinato &D){
		if(this!=&D){
			Candidato::operator=(D);
			delete [] titolo;
			titolo=new char[strlen(D.titolo)+1];
			strcpy(titolo,D.titolo);
			voto=D.voto;
		}
		return *this;
	}
	ostream & Determinato::print(ostream & out)const{
		Candidato::print(out);
		out << " " << titolo << " " << voto<<endl;
		return out;
	}
	istream & Determinato::input(istream & in){
		Candidato::input(in);
		char buffer[100];
		in.getline(buffer,100);
		set_titolo(buffer);
		in >> voto;
		return in;
	}
	ostream & operator<<(ostream & out, const Determinato &D){
		return D.print(out);
	}
	istream & operator>>(istream & in, Determinato &D){
		return D.input(in);
	}
	bool Determinato::check(const int annocorrente)const throw(const char*){
		if(get_cod()[0]=='A' && get_cod()[1]=='H'){
			if(!strcmp(titolo,"Laurea") || (!strcmp(titolo,"Diploma") && voto>=90 && annocorrente-get_a()<=25)) return true;
			else return false;
		}
		else throw "errore CODICE ERRATO";
	}
}
