#include "classi.h"
namespace MS{
	Attivita::Attivita(const Attivita &A){
		pid=A.pid;
		started=A.started;
		descrizione=new char[strlen(A.descrizione)+1];
		strcpy(descrizione,A.descrizione);
	}
	const Attivita & Attivita::operator=(const Attivita &A){
		if(this!=&A){
			delete [] descrizione;
			pid=A.pid;
			started=A.started;
			descrizione=new char[strlen(A.descrizione)+1];
			strcpy(descrizione,A.descrizione);
		}
		return *this;
	}
	Processo::Processo(const Processo &P): Attivita(P){
		stato=P.stato;
		nome=new char[strlen(P.nome)+1];
		strcpy(nome,P.nome);
	}
	const Processo & Processo::operator=(const Processo &P){
		if(this!=&P){
			Attivita::operator=(P);
			delete [] nome;
			stato=P.stato;
			nome=new char[strlen(P.nome)+1];
			strcpy(nome,P.nome);
		}
		return *this;
	}
	ostream & operator<<(ostream & out, const Attivita &A){ //funzioni friend, non membro
		return A.print(out);
	}
	istream & operator>>(istream & in, Attivita &A){
		return A.input(in);
	}
	ostream & Attivita::print(ostream &out)const{
		out << pid << " " << descrizione << " " << started << " ";
		return out;
	}
	istream & Attivita::input(istream &in){
		in>> started;
		in>> pid;
		char buffer[100];
		in.getline(buffer,100);
		set_d(buffer);
		return in;
	}
	ostream & Processo::print(ostream & out)const{
		Attivita::print(out);
		out << nome << " " << stato << endl;
		return out;
	}
	istream & Processo::input(istream &in){
		Attivita::input(in);
		in >> stato;
		char buffer[100];
		in.getline(buffer,100);
		set_n(buffer);
		return in;
	}
	ostream & operator<<(ostream & out, const Processo &P){
		return P.print(out);
	}
	istream & operator>>(istream &in, Processo &P){
		return P.input(in);
	}
	void Attivita::attiva(){
		started=true;
	}
	void Processo::attiva(){
		Attivita::attiva();
		if(stato=='P') stato='R';
	}
}
