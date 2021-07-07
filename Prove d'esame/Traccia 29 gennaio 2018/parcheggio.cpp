#include "parcheggio.h"
namespace MS{
	int Parcheggio::postiliberi()const{
		return p1.get_disponibili()+p2.get_disponibili();
	}
	void Parcheggio::ingresso(){
		if(p1.get_disponibili()!=0) cout << "veicolo posizionato nel primo parcheggio in posizione "<< p1.assegna()<<endl;
		else if(p1.get_disponibili()==0 && p2.get_disponibili()!=0) cout << "veicolo posizionato nel secondo parcheggio posizione " << p2.assegna();
		else cout << "parcheggio pieno"<<endl;
	}
	bool Parcheggio::estrazione(const int numeropiano, const int z){
		if(numeropiano==1){ return p1.libera(z);}
		else if(numeropiano==2) {return p2.libera(z);}
		else { cout << "impossibile estrarre il veicolo" << endl; return false; }
	}
	void Parcheggio::stampa(ostream & out)const{
	out << nome << " " << indirizzo <<endl;
	p1.stampa(out);
	p2.stampa(out);
	}
}
