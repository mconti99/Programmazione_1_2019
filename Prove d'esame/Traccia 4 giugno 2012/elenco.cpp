#include "elenco.h"
namespace MS{
	void Elenco::insert_ord(const T &e ) throw(Duplicato &){
		int i,p=0;
		bool trovato=false;
		if(is_in(e,p)==true) throw Duplicato("errore eccezione");
		else if(nelem==0 || v[nelem-1].get_c() < e.get_c()) {v[nelem]=e; nelem++;}
		else{
			while(i<nelem && !trovato){
				if(v[i].get_c()>e.get_c()){
					for(int j=nelem;j>i;j--) v[j]=v[j-1];
					nelem++;
					v[i]=e;
					trovato=true;
				}
				else i++;
			}
		}
	}
	bool Elenco::is_in(const T & e, int &pos)const{
		int i=0;
		bool trovato=false;
		while(i<nelem && !trovato){
			if(v[i].get_c()==e.get_c()){
				trovato=true;
				pos=i;
			}
			else i++;
		}
		return trovato;
	}
	void Elenco::remove(const T &e ) {
		int p=0;
		if(is_in(e,p)==true){
			for(int i=p;i<nelem-1;i++){
				v[i]=v[i+1];
			}
		}
		nelem--;
	}
	void Elenco::stampa()const{
		ofstream f;
		f.open("prova.txt");
		if(f){
			for(int i=0;i<nelem;i++){
				v[i].visualizza_dati(f);
			}
		}
		else cout <<"errore in apertura file"<<endl;
	}
	void Elenco::input(istream & in){
		for(int i=0;i<nelem;i++){
			v[i].memorizza_dati(in);
		}
	}
}
