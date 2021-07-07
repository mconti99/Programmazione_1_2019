#include "classi.h"
namespace MS{
	Bolletta::Bolletta(const Bolletta & B){
		codicecliente=new char[strlen(B.codicecliente)+1];
		strcpy(codicecliente,B.codicecliente);
		importo=B.importo;
		costoalsecondo=B.costoalsecondo;
		numtelefonate=B.numtelefonate;
	}
	const Bolletta & Bolletta::operator=(const Bolletta &B){
		if(this!=&B){
			delete [] codicecliente;
			codicecliente=new char[strlen(B.codicecliente)+1];
			strcpy(codicecliente,B.codicecliente);
			importo=B.importo;
			costoalsecondo=B.costoalsecondo;
			numtelefonate=B.numtelefonate;
		}
		return *this;
	}
	void Bolletta::AggiornaBolletta(const int durata){
		importo=importo+(costoalsecondo*durata);
		numtelefonate++;
	}
	void Bolletta::GeneraBolletta(ostream & out)const{
		out << codicecliente << " " << numtelefonate << " " << importo ;
	}
	Fisso::Fisso(const Fisso &F): Bolletta(F){
		indirizzo=new char[strlen(F.indirizzo)+1];
		strcpy(indirizzo,F.indirizzo);
		canone=F.canone;
	}
	const Fisso & Fisso::operator=(const Fisso &F){
		if(this!=&F){
			Bolletta::operator=(F);
			delete [] indirizzo;
			indirizzo=new char[strlen(F.indirizzo)+1];
			strcpy(indirizzo,F.indirizzo);
			canone=F.canone;
		}
		return *this;
	}
	void Fisso::AggiornaBolletta(const int durata){
		Bolletta::AggiornaBolletta(durata);
	}
	void Fisso::GeneraBolletta(ostream & out)const{
		Bolletta::GeneraBolletta(out);
		out << " " << canone << " " << indirizzo;
	}
	void Mobile::GeneraBolletta(ostream & out)const{
		Bolletta::GeneraBolletta(out);
		out << " " << costoallarisposta ;
	}
	void Mobile::AggiornaBolletta(const int durata){
		Bolletta::AggiornaBolletta(durata);
		importo=importo+costoallarisposta;
	}
}
