#include "lavoratore.h"
namespace Mynamespace{
Lavoratore::Lavoratore() {
	strcpy(matricola, "A00/000000");
	azienda = new char[1];
	strcpy(azienda, "");
	annoAssunzione = 0;
}

Lavoratore::Lavoratore(const char *ma, const char *az, const int anno) {
	if(validaMatr(ma))
		strcpy(matricola, ma);
	else
		strcpy(matricola, "A00/000000");
	azienda = new char[strlen(az) + 1];
	strcpy(azienda, az);
	annoAssunzione = anno;
}

Lavoratore::Lavoratore(const Lavoratore &L) {
	strcpy(matricola, L.matricola);
	azienda = new char[strlen(L.azienda) + 1];
	strcpy(azienda, L.azienda);
	annoAssunzione = L.annoAssunzione;
}

void Lavoratore::setMatricola(const char *ma) {
	if(validaMatr(matricola))
		strcpy(matricola, ma);
	else
		strcpy(matricola, "A00/000000");
}

void Lavoratore::setAzienda(const char *az) {
	delete [] azienda;
	azienda = new char[strlen(az) + 1];
	strcpy(azienda, az);
}

void Lavoratore::setAnnoAssunzione(const int anno) {
	annoAssunzione = anno;
}

//matricola in formato CNN/NNNNNN
bool Lavoratore::validaMatr(const char *matricola) const {
	bool ret = false;
	//controlli: lughezza = 10, quarto carattere = '/'
	if(strlen(matricola) == 10 && matricola[3]=='/') {
		int i = 0;
		ret = true;
		while (i<10 && ret) {
			if (i==0 && isdigit(matricola[i]))
				ret = false;
			else if(i!=0 && (i<3 || i>3 ) && !isdigit(matricola[i]))
				ret = false;
			i++;
		}
	}
	return ret;
}

const Lavoratore &Lavoratore::operator=(const Lavoratore& L) {
	if(this != &L) {
		strcpy(matricola, L.matricola);
		delete [] azienda;
		azienda = new char[strlen(L.azienda) + 1];
		strcpy(this->azienda, L.azienda);
		this->annoAssunzione = L.annoAssunzione;
    }
    return *this;  
}

ostream & Lavoratore::stampa(ostream &out) const {
	out<<"azienda "<<azienda<<", matr. "<<matricola<<", assunto nel "<<annoAssunzione;
	return out;
}

ostream & operator<<(ostream & out, const Lavoratore& L) {
	return L.stampa(out);
}

istream & operator>>(istream & in, Lavoratore& L) {
   char buffer[11];
   in.getline(buffer,11);
   L.setMatricola(buffer);
   in.getline(L.azienda,20);
   in>>L.annoAssunzione;
   in.ignore();
   return in;
}

} //fine namespace
