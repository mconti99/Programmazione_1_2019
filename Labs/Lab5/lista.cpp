#include "lista.h"
namespace MS{
	void Lista::inserimento(const T & e)throw(Eccezione &){
		if(in(e)==true) throw Eccezione("errore eccezione");
		else if((testa==0) || strcmp(testa->info->get_cod(),e->get_cod())>0) push(e);
		else{
			Record * prec=testa;
			Record * succ=0;
			Record * q = new Record;
			q->info=e;
			q->next=0;
			while(prec->next && strcmp(prec->next->info->get_cod(),e->get_cod())<0) prec=prec->next;
			succ=prec->next;
			q->next=succ;
			prec->next=q;
		}
	}
	bool Lista::push(const T &e){
		Record * q=new Record;
		q->info=e;
		q->next=testa;
		testa=q;
		return true;
	}
	Lista::~Lista(){
		Record * q;
		while(testa){
			q=testa;
			testa=testa->next;
			delete q;
		}
	}
	ostream & Lista::print(ostream & out)const{
		Record * q = testa;
		while(q){
			q->info->GeneraBolletta(out);
			q=q->next; 
		}
		return out;
	}
	bool Lista::in(const T & e)const{
		bool trovato=false;
		Record * q = testa;
		while(q && !trovato){
			if(!strcmp(q->info->get_cod(),e->get_cod())){
				trovato=true;
			} else q=q->next;
		}
		return trovato;
	}
}
