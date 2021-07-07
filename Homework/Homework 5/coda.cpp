#include "Coda.h"
namespace MS{
	bool Coda::push(const T &e){
		if(full()) return false;
		Record * q=new Record;
		q->elem=e;
		q->next=l;
		l=q;
		return true;
	}
	bool Coda::append(const T & e){

		if(full()) return false;
		Record * temp=l;
		if(empty()) { push(e); return true;}
		else{
			while(temp->next) temp=temp->next;
			Record * q=new Record;
			q->elem=e;
			q->next=0;
			temp->next=q;
		}
			return true;
} 
	bool Coda::pop(T & e){
		if(empty()) return false;
		Record * temp=l;
		e=l->elem;
		l=l->next;
		delete temp;
		return true;
	}
	Coda::~Coda(){
		Record * temp;
		while(l){
			temp=l;
			l=l->next;
			delete [] temp;
		}
	}
}//namespace
