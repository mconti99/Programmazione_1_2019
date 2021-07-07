#include "candidato.h"
namespace MS{
	Candidato::Candidato(const Candidato &C){
		nome=new char[strlen(C.nome)+1];
		cognome=new char[strlen(C.cognome)+1];
		anno=C.anno;
		strcpy(codice,C.codice);
		strcpy(nome,C.nome);
		strcpy(cognome,C.cognome);
	}
	const Candidato & Candidato::operator=(const Candidato &C){
		if(this!=&C){
			delete [] nome;
			delete [] cognome;
			nome=new char[strlen(C.nome)+1];
			cognome=new char[strlen(C.cognome)+1];
			anno=C.anno;
			strcpy(codice,C.codice);
			strcpy(nome,C.nome);
			strcpy(cognome,C.cognome);
		}
		return *this;
	}
	ostream & Candidato::print(ostream & out)const{
		out << codice << " " << nome << " " << cognome << " " << anno;
		return out;
	}
	istream & Candidato::input(istream & in){
		in.getline(codice,N);
		char buffer[N];
		char buff[N];
		in.getline(buffer,N);
		in.getline(buff,N);
		set_n(buffer);
		set_c(buff);
		in >> anno;
		return in;
	}
	ostream & operator<<(ostream & out, const Candidato &C){
		return C.print(out);
	}
	istream & operator>>(istream & in, Candidato &C){
		return C.input(in);
	}
}
