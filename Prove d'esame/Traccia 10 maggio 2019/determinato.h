#ifndef _DETERMINATO_H
#define _DETERMINATO_H
#include "candidato.h"
namespace MS{
	class Determinato : public Candidato{ //codice inizia per AH
		friend ostream & operator<<(ostream &, const Determinato &);
		friend istream & operator>>(istream &, Determinato &);
		char * titolo;
		int voto;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Determinato(): Candidato(), titolo(new char[1]), voto(0){strcpy(titolo, "");}
			Determinato(const char * c, const char * n, const char * cogn, const int a, const char * t, const int voto): Candidato(c,n,cogn,a), titolo(new char[strlen(t)+1]), voto(voto){strcpy(titolo, t);}
			virtual ~Determinato(){delete [] titolo;}
			Determinato(const Determinato &);
			const Determinato & operator=(const Determinato &);
			const char * get_titolo()const{return titolo;}
			int get_voto()const{return voto;}
			void set_titolo(const char *s){delete [] titolo; titolo=new char[strlen(s)+1]; strcpy(titolo,s);}
			void set_voto(const int s){voto=s;}
			virtual bool check(const int)const throw(const char *);
	};
}
#endif
