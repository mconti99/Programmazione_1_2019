#include "contocorrente.h"
namespace MS{
	conto::conto(): numeroConto(0), titolare(""), m(0){
		movimenti=new float[10];
	}
	conto::conto(const string M, const int N, const int MAX): numeroConto(N), titolare(M), m(0), maxMov(MAX){
		movimenti=new float[MAX];
	}
	conto::conto(const conto& C): numeroConto(C.numeroConto), titolare(C.titolare), m(C.m), maxMov(C.maxMov){
		movimenti=new float[maxMov];
		for(int i=0;i<m;i++){
			movimenti[i]=C.movimenti[i];
		}
	}
	const conto & conto::operator=(const conto &C){
		if(this!=&C){
			delete [] movimenti;
			numeroConto=C.numeroConto; 
			titolare=C.titolare;
			m=C.m; 
			maxMov=C.maxMov;
			movimenti=new float[maxMov];
			for(int i=0;i<maxMov;i++){
				movimenti[i]=C.movimenti[i];
			}
		}
		return *this;
	}
	bool conto::prelievo(const float p){
		if(p>0) throw "prelievo non effettuabile";
    	else if(m=0) return false; 
    	else if(calcolo_saldo() <-p) return false;
    		else{ movimenti[m]=p;
    		m++;
    		return true;
			}
	}
	bool conto::versamento(const float v){
    	if(v<0) throw "versamento non effettuabile"; 
    	else{
    		movimenti[m]=v;
    		m++;
    		return true;
	}
}
	float conto::calcolo_saldo()const{
		float somma=0;
		for(int i=0;i<m;i++){
			somma = somma + movimenti[i];
		}
		return somma;
	}
	ostream & conto::stampa_saldo(ostream & out)const{
		out << "Il saldo e' "<< calcolo_saldo() <<" e il numero di conto e' "<<numeroConto;
		return out;
	}
	ostream & conto::stampa_movimenti(ostream & out)const{
	out << "Il numero di conto e' "<< numeroConto <<" e i movimenti effettuati sono:"<<endl;
	for(int i=0;i<m;i++){
		out<<movimenti[i]<<endl;
	}
	return out;
	}
}



