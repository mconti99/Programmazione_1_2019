#include "classi.h"
namespace MS{
Veicolo::Veicolo(const Veicolo & V){
	tipo= new char[strlen(V.tipo)+1];
	strcpy(tipo, V.tipo);
	marca= new char[strlen(V.marca)+1];
	strcpy(marca, V.marca);
}
const Veicolo & Veicolo::operator=(const Veicolo &V){
	if(this!=&V){
		delete [] tipo;
		delete [] marca;
		tipo= new char[strlen(V.tipo)+1];
		strcpy(tipo, V.tipo);
		marca= new char[strlen(V.marca)+1];
		strcpy(marca, V.marca);
	}
	return *this;
}
ostream& Veicolo::print(ostream & out)const{
	out << tipo << " " << marca;
	return out;
}
istream& Veicolo::input(istream & in){
	char buffer[100];
	char buff[100];
	in.getline(buffer,100);
	in.getline(buff,100);
	set_t(buffer);
	set_ma(buff);
	return in;
}
ostream & operator << (ostream & out, const Veicolo & V){
	return V.print(out);
}
istream & operator >> (istream & in, Veicolo &V){
	return V.input(in);
}
bool Veicolo::operator==(const Veicolo &V)const{
return ((!strcmp(tipo, V.tipo))&& (!strcmp(marca,V.marca)));
}
bool Veicolo::operator!=(const Veicolo &V)const{
return !(*this==V);
}
Auto::Auto() : Veicolo(), classe(2){
	modello=new char[1];
	strcpy(modello, "");
}
Auto::Auto(const char* T, const char* M, const char* Mod, const int C):
	Veicolo(T,M), classe(C){
		modello=new char[strlen(Mod)+1];
		strcpy(modello,Mod);
	}
Auto::Auto(const Auto& A) : Veicolo(A), classe(A.classe){
	modello=new char[strlen(A.modello)+1];
	strcpy(modello, A.modello);
}
void Auto::set_mo(const char * Mod){
	delete [] modello;
	modello=new char[strlen(Mod)+1];
	strcpy(modello,Mod);
}
bool Auto::operator==(const Auto & A)const{
	return (Veicolo::operator==(A) && !strcmp(modello,A.modello) && (classe == A.classe));
}
bool Auto::operator!=(const Auto & A)const{
	return !(*this==A);
}
bool Auto::operator>(const Auto & A)const{
	return (classe>A.classe);
}
bool Auto::operator<(const Auto & A)const{
	return (classe<A.classe);
}
const Auto& Auto::operator=(const Auto & A){
	if(this!=&A){
		Veicolo::operator=(A); //viene fatto un up-casting
		delete [] modello;
		modello=new char[strlen(A.modello)+1];
		strcpy(modello, A.modello);
		classe=A.classe;
	}
	return *this;
}
float Auto::CalcolaPedaggio()const{
	for(int i=0;i<7;i++) 
	if(Table[i].L==classe) return Table[i].V; //se non c'è la classe nella tabella, chiamo l'eccezione
	throw Eccezione(classe,"classe inesistente");
}	
ostream & Auto::print(ostream & out)const{
	Veicolo::print(out);
	out << ' ' << modello << ' ' << classe << endl;
	return out;
}

istream & Auto::input(istream & in){
	char buffer[100];
	Veicolo::input(in);
	in >> buffer; //in.getline(buffer,100);
	set_mo(buffer);
	// in >> Classe; //non esiste l'operatore di flusso sul tipo Classes
	return in;
}
ostream & operator<<(ostream & out, const Auto & A){
	// out << (Veicolo &)A; //il valore che dobbiamo modificare è un riferimento
	//out << A; 
	return A.print(out);
}
istream & operator>>(istream & in, Auto & A){
	return A.input(in);
}
}//namespace
