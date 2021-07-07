#include "vettore.h"
Vettore::Vettore(const int n){
	nmax=n;
	V=new T[nmax]; //alloco lo spazio
}
Vettore::Vettore(const Vettore &P){
	nmax=P.nmax;
	V=new T[P.nmax];
	for(int i=0;i<nmax;i++){
		V[i]=P.V[i]; //copio gli elementi dei due vettori
	}
} //costruttore di copia	
const Vettore & Vettore::operator=(const Vettore &P){
	if(this!=&P){//per evitare un self assignment
	delete [] V;
	nmax=P.nmax; //copio le variabili membro
	V=new T[P.nmax]; 
	for(int i=0;i<nmax;i++){
		V[i]=P.V[i]; // V[i]=P[i]; noi abbiamo definito le seconde, sono sull'oggetto di tipo vettore
	}
	}
	return *this;
}
bool Vettore::operator != (const Vettore &P)const{
	bool trovato=false;
	int i=0;
	if(nmax!=P.nmax) return true;
	while(i<nmax && !trovato)
	/*if(V[i]!=P.V[i]) */if(V[i].equal(P.V[i])==false)
	trovato=true;
	else i++;
	return trovato;
}
bool Vettore::operator == (const Vettore &P)const{
	return !(*this!=P);
}
T& Vettore::operator[] (const int index){ //torniamo un'area di memoria, senza const perchè altrimenti l'utente non potrebbe 
//modificare il vettore, che è privato
	return V[index];
}
const T& Vettore::operator[] (const int index)const{ //cambia la signature, sono diverse per overloading
return V[index];
}
/*ostream & operator<<(ostream & out, const Vettore &P){
	for(int i=0;i<P.nmax;i++){
		out << P[i] << ' ';
	}
	return out;
}
*/
/*istream & operator>>(istream & in, Vettore &P){ //non sa quanti elementi deve leggere
//legge esattamente nmax elementi
	for(int i=0;i<P.nmax;i++){
		in >> P[i];
	}
	return in;
}
*/
