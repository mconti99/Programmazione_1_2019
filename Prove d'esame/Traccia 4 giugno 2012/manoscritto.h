#ifndef _MANO_H
#define _MANO_H
#include <iostream>
#include <cstring>
using namespace std;
namespace MS{
	class Manoscritto{
		int codice;
		char * autore;
		int numpag;
		char * formato;
		public:
			Manoscritto(): codice(0), autore(new char[1]), numpag(0), formato(new char[1]){strcpy(autore,""); strcpy(formato,"");}
			Manoscritto(const int c, const char * a, const int n, const char * f): codice(c), autore(new char[strlen(a)+1]), numpag(n), formato(new char[strlen(f)+1]){strcpy(autore,a); strcpy(formato,f);}
			virtual ~Manoscritto(){delete [] autore; delete [] formato;}
			Manoscritto(const Manoscritto &);
			const Manoscritto & operator=(const Manoscritto &);
			virtual void visualizza_dati(ostream &)const;
			virtual void memorizza_dati(istream &);
			int get_c()const{return codice;}
	};
}
#endif 
