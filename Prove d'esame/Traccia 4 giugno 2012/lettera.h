#ifndef _LETTERA_H
#define _LETTERA_H
#include "manoscritto.h"
namespace MS{
	class Lettera : public Manoscritto{
		char * mittente;
		char * destinatario;
		public:
			Lettera(): Manoscritto(), mittente(new char[1]), destinatario(new char[1]){strcpy(mittente,""); strcpy(destinatario,"");}
			Lettera(const int c, const char * a, const int n, const char * f, const char * m, const char * d): Manoscritto(c,a,n,f), mittente(new char[strlen(m)+1]), destinatario(new char[strlen(d)+1]){strcpy(mittente,m); strcpy(destinatario,d);}
			virtual ~Lettera(){delete [] mittente; delete [] destinatario;}
			Lettera(const Lettera &);
			const Lettera & operator=(const Lettera &);
			virtual void visualizza_dati(ostream &)const;
			virtual void memorizza_dati(istream &);
	};
}
#endif
