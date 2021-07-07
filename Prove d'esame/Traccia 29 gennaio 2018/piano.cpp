#include "piano.h"
namespace MS{
	int Piano::assegna(){
		if(get_disponibili()!=0){
		bool trovato=false;
		int i=0;
		while(i<posti && !trovato){
			if(v[i].occupato==false) {
			v[i].occupato=true;
			trovato=true;
		}
		else i++;
		}
		return i;
	}
	else{
		cout << "piano pieno, non e' possibile assegnare nuovi posti"<<endl;
		return 0;
	}
	}
	bool Piano::libera(const int t)throw(bad_id &){
		if(t<0 || t>posti) throw bad_id("il posto non esiste");
		else{
			if(get_disponibili()==posti) return false;
			else{
				v[t].occupato==false;
			}
		}
	}
	int Piano::get_disponibili()const{
		int g=0;
		for(int i=0;i<posti;i++){
			if(v[i].occupato==false) g++;
		}
		return g;
	}
	Piano::Piano(const Piano &P){
		posti=P.posti;
		v=new Record[posti];
		for(int i=0;i<posti;i++){
			v[i]=P.v[i];
		}
	}
	const Piano & Piano::operator=(const Piano &P){
		if(this!=&P){
			delete [] v;
			posti=P.posti;
			v=new Record[posti];
			for(int i=0;i<posti;i++){
				v[i]=P.v[i];
			}
		}
		return *this;
	}
	void Piano::stampa(ostream & out)const{
		for(int i=0;i<posti;i++){
			out << v[i].id << " " << v[i].occupato << endl;
		}
	}
}
