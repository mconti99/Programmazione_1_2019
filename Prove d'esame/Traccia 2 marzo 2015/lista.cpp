#include "lista.h"
namespace MS{
	bool Lista::append(const T & e)throw(Eccezione &){
		if(empty()) {if(push(e)) return true;}
		else if(in(e)==true) throw Eccezione("errore eccezione");
		else{
			Record * q = testa;
			Record * temp=new Record;
			temp->info=e;
			temp->next=0;
			while(q->next) q=q->next;
			q->next=temp;
			return true;
		}
		
	}
	bool Lista::push(const T &e){
		Record * q =new Record;
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
	bool Lista::in(const T &e)const{
		bool trovato=false;
		Record * q =testa;
		while(q && !trovato){
			if(e->get_p()==q->info->get_p()){
				trovato=true;
			}
			else q=q->next;
		}
		return trovato;
	}
	bool Lista::remove(T & e){
		bool trovato=false;
		if(empty()) {cout<< "la lista e' vuota"<<endl; return false;}
		if(testa->info->get_stato()=='P'){
			Record * temp=testa;
			e=testa->info;
			testa=testa->next;
			delete temp;
			trovato=true;
		}
		else{
			Record * temp=testa;
			while(temp->next){
				if(temp->next->info->get_stato()=='P'){
					e=temp->next->info;
					Record * temp2=temp->next;
					temp->next=temp->next->next;
					delete temp2;
					trovato= true;
				}
				temp=temp->next;
			}
		}
		if(trovato==false) cout << "non ci sono stati processi pronti"<<endl;
		return trovato;
	}
	int Lista::getp()const{
		int i=0;
		Record * q = testa;
		while(q){
			if(q->info->get_stato()=='P') i++;
		}
		return i;
	}
	void Lista::schedule(const int p){
		//consente di attivare il processo corrispondente (se possibile) 
		if(testa->info->get_p()==p){
			testa->info->attiva();
			Record * temp=testa;
			testa=testa->next;
			delete temp;
		}else{
		Record * q = testa;
		while(q->next){
			if(p==q->next->info->get_p()){
				q->info->attiva();
				Record * temp2=q->next;
				q->next=q->next->next;
				delete temp2;
			}
			else q=q->next;
		}
	}
	}
	void Lista::show(ostream& out) const{
		Record * q=testa;
		while(q){
			out << *q->info;
			q=q->next;
		}
	}
	void Lista::store(const char * filename) const{
	ofstream myfile(filename, ios::out);
	if(myfile)
	{
		Record*temp=testa;
		while(temp)
		{
			myfile<<*temp->info<<endl;
			temp= temp->next;
		}
	}
	myfile.close();
	}
}
