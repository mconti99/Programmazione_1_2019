#ifndef _CLASSI_H
#define _CLASSI_H
#include <iostream>
#include <cstring>
using namespace std;
namespace MS{
	class Cliente{
		char codice[100];
		string indirizzo;
		public:
			Cliente(): indirizzo(""){strcpy(codice,"");}
			Cliente(const char * c, const string & i): indirizzo(i){strcpy(codice,c);}
			const char * get_c()const{return codice;} 
			bool con_iva()const;
			void set_c(const char * s){strcpy(codice,s);}
	};
	class Prodotto{
		char id[100];
		char * genere;
		float costo;
		public:
			Prodotto(): genere(new char[1]), costo(0.0){strcpy(genere,""); strcpy(id,"");}
			Prodotto(const char * i, const char * g, const float c): genere(new char[strlen(g)+1]), costo(c){strcpy(genere,g); strcpy(id,i);}
			virtual ~Prodotto(){delete [] genere;}
			Prodotto(const Prodotto &);
			const Prodotto & operator=(const Prodotto &);
			const char * get_i()const{return id;}
			const char * get_g()const{return genere;}
			float get_costo()const{return costo;}
			virtual float calcola_iva(const char *)const=0;
	};
	class Bene : public Prodotto{
		bool prima_n;
		char * descrizione;
		public:
			Bene(): Prodotto(), prima_n(false), descrizione(new char[1]){strcpy(descrizione,"");}
			Bene(const char * i, const char * g, const float c, const bool p, const char * d): Prodotto(i,g,c), prima_n(p), descrizione(new char[strlen(d)+1]){strcpy(descrizione,d);}
			virtual ~Bene(){delete [] descrizione;}
			Bene(const Bene &);
			const Bene & operator=(const Bene &);
			virtual float calcola_iva(const char *)const;
	};
	class Servizio : public Prodotto{
		char * tipo;
		public:
			Servizio(): Prodotto(), tipo(new char[1]){strcpy(tipo,"");}
			Servizio(const char * i, const char * g, const float c, const char * t): Prodotto(i,g,c), tipo(new char[strlen(t)+1]){strcpy(tipo,t);}
			virtual ~Servizio(){delete [] tipo;}
			Servizio(const Servizio &);
			const Servizio & operator=(const Servizio &);
			virtual float calcola_iva(const char *)const;
	};
	struct Record{
		Prodotto * p;
		int qta;
		float costotot; //di tutte le qta
	};
	class Ordine{
		static const int MAX=2;
		Cliente * c;
		Record v[MAX];
		int nelem;
		public:
			Ordine(): c(0), nelem(0){}
			//inserimento nella prima posizione libera-con eccezione nel caso di vettore pieno
			bool insert(Record &) throw(const char *);
			//calcolare il totale dell'ordineù
			float calcolaordine()const;
			void AssociaCliente( Cliente *  Cl) {c = Cl;}
			int get_nelem()const{return nelem;}
			void stampa(ostream &)const;
	};
}
#endif
