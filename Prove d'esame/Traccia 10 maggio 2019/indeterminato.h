#ifndef _INDETERMINATO_H
#define _INDETERMINATO_H
#include "determinato.h"
namespace MS{
	class Indeterminato : public Determinato{ //codice inizia per BH
		friend ostream & operator<<(ostream &, const Indeterminato &);
		friend istream & operator>>(istream &, Indeterminato &);
		private:
		bool exp;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public: 
		Indeterminato(): Determinato(), exp(false){}
		Indeterminato(const char * c, const char * n, const char * cogn, const int a, const char * t, const int voto, const bool f): Determinato(c,n,cogn,a,t,voto), exp(f){}
		bool get_e()const{return exp;}
		void set_e(const bool p){exp=p;}
		virtual bool check(const int)const throw(const char *);
	};
}
#endif
