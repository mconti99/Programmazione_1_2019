#include "Elenco.h"
namespace MS{
	ostream & Elenco::print(ostream & out) const{
		for(int i=0;i<nelem;i++){
			out << v[i] << " ";
		}
		out << endl;
		return out;
	}
	void Elenco::inserimento_ord(const Persona & e){
		bool trovato=false;
		int i=0;
		if(nelem==0 || v[nelem-1].get_c()<e.get_c()){v[nelem]=e; nelem++;}
		else{
			while(i<nelem && !trovato){
				if(v[i].get_c()>e.get_c()){
					for(int j=nelem;j>i;j--){
						v[j]=v[j-1];
					}
					nelem++;
					v[i]=e;
					trovato=true;
				}
				else i++;
			}
		}
	}
	bool Elenco::ricerca_bin(const int first, const int last, const Persona x){
		int med=0;
		bool found=false;
		if((last-first)>0 && !found){
			med=(last+first)/2;
			if(v[med]==x){
				found=true;
			}
		else if(v[med].get_c()<x.get_c()) return ricerca_bin(med+1,last,x);
		else return ricerca_bin(first,med-1,x);
		}
		return found;
	}
	void Elenco::eliminate_ord(Persona & e, const int pos){
		if(ricerca_bin(0,nelem,e)==true){
			for(int i=pos;i<nelem-1;i++){
				v[i]=v[i+1];
			}
			nelem=nelem-1;
		}
		else cout << "operazione impossibile"<<endl;
	}
}
