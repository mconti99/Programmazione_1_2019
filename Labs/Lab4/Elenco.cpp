#include "Elenco.h"
namespace MS{
	bool Elenco::Push(const Persona & e)throw(const char *){
		int p=0;
		if(ricerca(e, p) == true) throw("Errore");

		Record * q= new Record;
		q->Info=e;
		q->next=testa;
		testa=q;
		return true;
	}
	Elenco::~Elenco(){
		Record * q;
		while(testa){ //quando sarà 0, sarà vuota
			q=testa;
			testa=testa->next;
			delete q;
		}
	}
	bool Elenco::ricerca(const Persona & e, int & pos){
		if(testa=0){pos=0;return false;}
		Record * q=testa;
		bool trovato=false;
		int i=1;
		while(trovato==false && q){
			if(q->Info ==e){
				trovato=true;
			}else{
				i++;
				q=q->next;
			}
		pos=i;

		}
		return trovato;
	}
	
	bool Elenco::eliminate(Persona & e,const int pos){
		if((testa=0) || pos <1) return false;
		if(pos==1) {pop(e); return true;}
		else{
		Record * q=testa;
		int i=1;
		while(i<pos-1){q=q->next;i++;} //q punta al record che precede quello da eliminare
	 	Record * temp=q->next; //temp è quello da eliminare
	 	e=temp->Info;
	 	q->next=q->next->next; //temp scompare
	 	delete temp;
	 	return true;
	 }
	}
	bool Elenco::pop(Persona & e){
		if(testa==0) return false;
		Record * q;
		q=testa;
		e=testa->Info;
		testa=testa->next;
		delete q;
		return true;
	}

	ostream & Elenco::print(ostream & out) const{
		Record * temp=testa;
		while(temp){
			out<< temp->Info << ' ';
			temp=temp->next;
		}
		return out;
	}

}
