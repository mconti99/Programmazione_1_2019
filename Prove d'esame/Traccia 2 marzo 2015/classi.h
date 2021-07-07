#ifndef _CLASSI_H
#define _CLASSI_H
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
namespace MS{
	class Attivita{
		friend ostream & operator<<(ostream &, const Attivita &);
		friend istream & operator>>(istream &, Attivita &);
		private:
			int pid;
			char * descrizione;
			bool started;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Attivita(): pid(0), descrizione(new char[1]), started(false){strcpy(descrizione,"");}
			Attivita(const int P, const char * D, const bool S): pid(P), descrizione(new char[strlen(D)+1]), started(S){strcpy(descrizione,D);}
			virtual ~Attivita(){delete [] descrizione;}
			Attivita(const Attivita &);
			const Attivita & operator=(const Attivita &);
			int get_p()const{return pid;}
			bool get_s()const{return started;}
			const char * get_d()const{return descrizione;}
			void set_p(const int s){pid=s;}
			void set_s(const bool t){started=t;}
			void set_d(const char * s){delete [] descrizione; descrizione=new char[strlen(s)+1]; strcpy(descrizione,s);}
			virtual void attiva();
			
	};
	class Processo : public Attivita{
		friend ostream & operator<<(ostream &, const Processo &);
		friend istream & operator>>(istream &, Processo &);
		private:
			char * nome;
			char stato; //R (in esecuzione), P (Pronto), W (In attesa).
		protected: 
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Processo(): Attivita(), nome(new char[1]), stato('W'){strcpy(nome,"");} /* come inizializzo char*/
			Processo(const int P, const char * D, const bool S, const char * N, const char stat): Attivita(P,D,S), nome(new char[strlen(N)+1]), stato(stat){strcpy(nome,N);}
			virtual ~Processo(){delete [] nome;}
			Processo(const Processo &);
			const Processo & operator=(const Processo &);
			char get_stato()const{return stato;}
			void set_stato(const char s){stato=s;}
			const char * get_n()const{return nome;}
			void set_n(const char * s){delete [] nome; nome=new char[strlen(s)+1]; strcpy(nome,s);}
			virtual void attiva();
			
	};
}
#endif
