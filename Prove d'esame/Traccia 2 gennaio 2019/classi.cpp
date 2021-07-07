#include "classi.h"
namespace MS{
	bool Cliente::con_iva()const{
		if(codice[0]=='P') return true;
		else return false;
	}
	Prodotto::Prodotto(const Prodotto &P){
		costo=P.costo;
		strcpy(id,P.id);
		genere=new char[strlen(P.genere)+1];
		strcpy(genere,P.genere);
	}
	const Prodotto & Prodotto::operator=(const Prodotto &P){
		if(this!=&P){
		delete [] genere;
		costo=P.costo;
		strcpy(id,P.id);
		genere=new char[strlen(P.genere)+1];
		strcpy(genere,P.genere);
	}
	return *this;
	}
	Bene::Bene(const Bene &B): Prodotto(B){
		descrizione=new char[strlen(B.descrizione)+1];
		strcpy(descrizione,B.descrizione);
		prima_n=B.prima_n;
	}
	const Bene & Bene::operator=(const Bene &B){
		if(this!=&B){
			Prodotto::operator=(B);
			delete [] descrizione;
			descrizione=new char[strlen(B.descrizione)+1];
			strcpy(descrizione,B.descrizione);
			prima_n=B.prima_n;
		}
		return *this;
	}
	Servizio::Servizio(const Servizio &S): Prodotto(S){
		tipo=new char[strlen(S.tipo)+1];
		strcpy(tipo,S.tipo);
	}
	const Servizio & Servizio::operator=(const Servizio &S){
		if(this!=&S){
			delete [] tipo;
			tipo=new char[strlen(S.tipo)+1];
			strcpy(tipo,S.tipo);
		}
		return *this;
	}
	float Bene::calcola_iva(const char *s)const{
		Cliente c;
		c.set_c(s);
		if(c.con_iva()==true) return 0.0;
		else{
			if(prima_n==true) return 0.04*get_costo();
			else{
				return 0.22*get_costo();
			}
		}
	}
	float Servizio::calcola_iva(const char * s)const{
		Cliente c;
		c.set_c(s);
		if(c.con_iva()==true) return 0.0;
		else{
			return 0.1*get_costo();
		}
	}
	bool Ordine::insert(Record &e) throw(const char *){
		if(nelem==MAX) throw "Eccezione: impossibile aggiungere un ulteriore prodotto all''ordine";
		else{
			Cliente client;
			e.costotot=(e.p->get_costo()+e.p->calcola_iva(client.get_c()))*e.qta;
			v[nelem]=e;
			nelem++;
			return true;
		}
	}
	float Ordine::calcolaordine()const{
		float tot;
		for(int i=0;i<nelem;i++){
			tot=tot+v[i].costotot;
		}
		return tot;
	}
	void Ordine::stampa(ostream & out)const{
		for(int i=0;i<nelem;i++){
		out << "Prodotto: " << v[i].p->get_g() << " Quantita': " << v[i].qta << endl;
		out << "Costo: "<< v[i].p->get_costo() << endl;
		out <<  "**************************************"<<endl;
	}
	}
}
