#include "pacco.h"
namespace MS{
	Pacco::Pacco(const Pacco &P){
		codice=P.codice;
		peso=P.peso;
		indirizzo=new char[strlen(P.indirizzo)+1];
	}
	const Pacco & Pacco::operator=(const Pacco &P){
		if(this!=&P){
			delete [] indirizzo;
			codice=P.codice;
			peso=P.peso;
			indirizzo=new char[strlen(P.indirizzo)+1];
		}
		return *this;
	}
	ostream & Pacco::print(ostream & out)const{
		out << codice << " " << peso << " " << indirizzo <<" " << endl;
		return out;
	}
	istream & Pacco::input(istream & in){
		in >> peso;
		in >> codice;
		char buffer[100];
		in.getline(buffer,100);
		delete [] indirizzo;
		indirizzo=new char[strlen(buffer)+1];
		strcpy(indirizzo,buffer);
		return in;
	}
	ostream & operator<<(ostream & out, const Pacco &P){
		return P.print(out);
	}
	istream & operator>>(istream & in, Pacco &P){
		return P.input(in);
	}
}
