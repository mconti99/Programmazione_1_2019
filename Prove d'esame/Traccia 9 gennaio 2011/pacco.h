#ifndef _PACCO_H
#define _PACCO_H
#include <iostream>
#include <cstring>
using namespace std;
namespace MS{
	class Pacco{
		friend ostream & operator<<(ostream &, const Pacco &);
		friend istream & operator>>(istream &, Pacco &);
		private:
		int codice;
		float peso;
		char * indirizzo;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Pacco(): codice(0), peso(0.0), indirizzo(new char[1]){strcpy(indirizzo, "");}
			Pacco(const int C, const float P, const char * I): codice(C), peso(P), indirizzo(new char[strlen(I)+1]){strcpy(indirizzo,I);}
			Pacco(const Pacco &);
			const Pacco & operator=(const Pacco &);
			virtual ~Pacco(){delete [] indirizzo;}
			void set_c(const int s){codice=s;}
			void set_p(const float s){peso=s;}
			void set_i(const char * s){delete [] indirizzo; indirizzo=new char[strlen(s)+1]; strcpy(indirizzo,s);}
	};
}
#endif
