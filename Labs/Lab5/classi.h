#ifndef _CLASSI_H
#define _CLASSI_H
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
namespace MS{
	class Bolletta{
		protected:
			char * codicecliente;
			float importo;
			float costoalsecondo;
			int numtelefonate;
		public:
			Bolletta(): codicecliente(new char[1]), importo(0.0), costoalsecondo(0.0), numtelefonate(0){strcpy(codicecliente,"");}
			Bolletta(const char * COD, const float I, const float COS, const int N): codicecliente(new char[strlen(COD)+1]), importo(I), costoalsecondo(COS), numtelefonate(N){strcpy(codicecliente,COD);}
			virtual ~Bolletta(){delete [] codicecliente;}
			Bolletta(const Bolletta &);
			const Bolletta & operator=(const Bolletta &);
			virtual void AggiornaBolletta(const int); 
			const char * get_cod()const{return codicecliente;}
			float get_i()const{return importo;}
			float get_cos()const{return costoalsecondo;}
			int get_n()const{return numtelefonate;}
			virtual void GeneraBolletta(ostream &)const;
	};
	class Fisso : public Bolletta{
		char * indirizzo;
		float canone;
		public:
			Fisso(): Bolletta(), indirizzo(new char[1]), canone(0.0){strcpy(indirizzo, "");}
			Fisso(const char * COD, const float I, const float COS, const int N, const char * add, const float can): Bolletta(COD, I, COS, N), indirizzo(new char[strlen(add)+1]), canone(can){strcpy(indirizzo,add);}
			virtual ~Fisso(){delete [] indirizzo;}
			Fisso(const Fisso &);
			const Fisso & operator=(const Fisso &);
			virtual void AggiornaBolletta(const int durata);
			virtual void GeneraBolletta(ostream &)const;
	};
	class Mobile : public Bolletta{
		float costoallarisposta;
		public:
			Mobile(): Bolletta(), costoallarisposta(0.0){}
			Mobile(const char * COD, const float I, const float COS, const int N,const float costo): Bolletta(COD,I,COS,N), costoallarisposta(costo){}
			virtual void AggiornaBolletta(const int durata);
			virtual void GeneraBolletta(ostream &)const;
	};
}
#endif
