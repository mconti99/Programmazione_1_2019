#ifndef _CANDIDATO_H
#define _CANDIDATO_H
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
namespace MS{
	class Candidato{
		friend ostream & operator<<(ostream &, const Candidato &);
		friend istream & operator>>(istream &, Candidato &);
		private:
		static const int N=100;
		char codice[N];
		char * nome;
		char * cognome;
		int anno;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Candidato(): nome(new char[1]), cognome(new char[1]), anno(0){strcpy(codice,"");strcpy(nome,""); strcpy(cognome, "");}
			Candidato(const char * c, const char * n, const char * cogn, const int a): nome(new char[strlen(n)+1]), cognome(new char[strlen(cogn)+1]), anno(a){strcpy(nome,n); strcpy(cognome,cogn); strcpy(codice,c);}
			virtual ~Candidato(){delete [] nome; delete [] cognome;}
			Candidato(const Candidato &);
			const Candidato & operator=(const Candidato &);
			const char * get_cod()const{return codice;}
			const char * get_n()const{return nome;}
			const char * get_c()const{return cognome;}
			int get_a()const{return anno;}
			void set_cod(const char * s){strcpy(codice,s);}
			void set_n(const char * s){delete [] nome; nome=new char[strlen(s)+1]; strcpy(nome,s);}
			void set_c(const char * s){delete [] cognome; cognome=new char[strlen(s)+1]; strcpy(cognome, s);}
			void set_a(const int a){anno=a;}
			virtual bool check(const int)const=0;
			
	};
}
#endif
