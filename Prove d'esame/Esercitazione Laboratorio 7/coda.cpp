#include "coda.h"
namespace MS{
	Coda::Coda(const int dim){
		maxelem=dim;
		n=t=c=0;
		coda= new T[maxelem];
	}
	Coda::Coda(const Coda &C){
		maxelem=C.maxelem;
		n=C.n;
		t=C.t;
		c=C.c;
		coda= new T[maxelem];
		for(int i=0;i<maxelem;i++){
			coda[i]=C.coda[i];
		}
	}
	const Coda & Coda::operator=(const Coda &C){
		if(this!=&C){
			delete [] coda;
			maxelem=C.maxelem;
			n=C.n;
			t=C.t;
			c=C.c;
			coda= new T[maxelem];
			for(int i=0;i<maxelem;i++){
			coda[i]=C.coda[i];
			}	
		}
		return *this;
	}
	bool Coda::append(const T &e){
		if(Full()) return false;
		coda[c]=e;
		c=(c+1)%maxelem;
		n++;
		return true;
	}
	bool Coda::pop(T &e){
		if(Empty()) return false;
		e=coda[t];
		t=(t+1)%maxelem;
		n--;
		return true;
	}
	bool Coda::Empty()const{
		return (n==0);
	}
	bool Coda::Full()const{
		return (n==maxelem);
	}

}
