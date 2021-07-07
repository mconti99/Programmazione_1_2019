#include "lettera.h"
namespace MS{
	Lettera::Lettera(const Lettera &L): Manoscritto(L){
		mittente=new char[strlen(L.mittente)+1];
		strcpy(mittente,L.mittente);
		destinatario=new char[strlen(L.destinatario)+1];
		strcpy(destinatario, L.destinatario);
	}
	const Lettera & Lettera::operator=(const Lettera &L){
		if(this!=&L){
			Manoscritto::operator=(L);
			delete [] mittente;
			delete [] destinatario;
			mittente=new char[strlen(L.mittente)+1];
			strcpy(mittente,L.mittente);
			destinatario=new char[strlen(L.destinatario)+1];
			strcpy(destinatario, L.destinatario);
		}
		return *this;
	}
	void Lettera::visualizza_dati(ostream & out)const{
		Manoscritto::visualizza_dati(out);
		out << mittente << " " << destinatario<<endl;
	}
	void Lettera::memorizza_dati(istream & in){
		Manoscritto::memorizza_dati(in);
		char buffer[100];
		char buff[100];
		in.getline(buffer,100);
		in.getline(buff,100);
		delete [] mittente;
		delete [] destinatario;
		mittente=new char[strlen(buffer)+1];
		destinatario=new char[strlen(buff)+1];
		strcpy(mittente,buffer);
		strcpy(destinatario,buff);
	}
}
