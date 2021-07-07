#ifndef _CLASSI_H
#define _CLASSI_H
#include <iostream>
#include <cstring>
#include <string>
#include "data.h"
using namespace std;
namespace MS{
	class Entry{
		friend ostream & operator << (ostream &, const Entry &);
		friend istream & operator >> (istream &, Entry &);
		private:
		static const int dim=40;
		char * cognome;
		char * nome;
		char id[dim];

		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Entry(): cognome(new char[1]), nome(new char[1]){strcpy(cognome,""); strcpy(nome, ""); strcpy(id, "");}
			Entry(const char * C, const char * N, const char * I): cognome(new char[strlen(C)+1]), nome(new char[strlen(N)+1]){strcpy(cognome,C); strcpy(nome, N); strcpy(id, I);}
			virtual ~Entry() {delete [] cognome; delete [] nome;}
			Entry(const Entry &);
			const Entry & operator=(const Entry &);
			const char * get_c()const{return cognome;}
			const char * get_n()const{return nome;}
			const char * get_i()const{return id;}
			void set_c(const char * s){delete [] cognome; cognome=new char[strlen(s)+1]; strcpy(cognome,s);}
			void set_n(const char * s){delete [] nome; nome=new char[strlen(s)+1]; strcpy(nome,s);}
			void set_i(const char * s){strcpy(id,s);}
	};
	class Riga : public Entry{
		friend ostream & operator << (ostream &, const Riga &);
		friend istream & operator >> (istream &, Riga &);
		private:
		bool presenza;
		int voto;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);			
		public:
			Riga(): Entry(), presenza(false), voto(0){}
			Riga(const char * C, const char * N, const char * I): Entry(C,N,I), presenza(false), voto(0){}
			int get_v()const{return voto;}
			bool get_p()const{return presenza;}
			bool set_v(const int) throw(const char *);
			void set_p(const bool p){presenza=p;}
		
	};
	class Registro{
		static const int max=30;
		string materia;
		string docente;
		string classe;
		int numeroCorr;
		Data data;
		Riga v[max];
		public:
			Registro(): materia(""), docente(""), classe(""), numeroCorr(0) {}
			Registro(const Data & dat, const string mat, const string doc, const string cla, const int num): data(dat), materia(mat), docente(doc), classe(cla), numeroCorr(num){}
			bool test()const{return (numeroCorr==max);} 
			void inserimento_ord(const Riga &) throw(const char *);
			bool in(const Riga &)const;
			void interrogazione(const char *);
			string get_materia()const{return materia;}
			string get_docente()const{return docente;}
			string get_classe()const{return classe;}
			int get_numero()const{return numeroCorr;}
			Data get_data()const{return data;} /* */
			void set_materia(const string s){materia=s;}
			void set_docente(const string s){docente=s;}
			void set_classe(const string s){classe=s;}
			int media_g()const;
			void print(ostream &)const;
			void stampavideo()const;
	};
}

#endif
