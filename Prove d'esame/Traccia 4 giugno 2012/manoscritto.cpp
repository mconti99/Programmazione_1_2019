#include "manoscritto.h"
namespace MS{
	Manoscritto::Manoscritto(const Manoscritto &M){
		codice=M.codice;
		numpag=M.numpag;
		autore=new char[strlen(M.autore)+1];
		strcpy(autore,M.autore);
		formato=new char[strlen(M.formato)+1];
		strcpy(formato,M.formato);
	}
	const Manoscritto & Manoscritto::operator=(const Manoscritto &M){
		if(this!=&M){
			delete [] autore;
			delete [] formato;
			codice=M.codice;
			numpag=M.numpag;
			autore=new char[strlen(M.autore)+1];
			strcpy(autore,M.autore);
			formato=new char[strlen(M.formato)+1];
			strcpy(formato,M.formato);
		}
		return *this;
	}
	void Manoscritto::visualizza_dati(ostream & out)const{
		out << autore << " " << formato << " " << codice << " " << numpag;
	}
	void Manoscritto::memorizza_dati(istream & in){
		char buffer[100];
		char buff[100];
		in.getline(buffer,100);
		in.getline(buff,100);
		delete [] autore;
		delete [] formato;
		autore=new char[strlen(buffer)+1];
		formato=new char[strlen(buff)+1];
		strcpy(autore,buffer);
		strcpy(formato,buff);
		in >> numpag;
		in >> formato;
	}
}
