#ifndef _UTENZA_H
#define _UTENZA_H
#include <iostream>
#include <cstring>
using namespace std;
namespace MS{
	class Utenza{
		friend ostream & operator<<(ostream &, const Utenza &);
			char codice[100];
			char * intestatario;
			char numerotel[100];
		protected:
			virtual ostream & print(ostream &)const;
		public:
			Utenza(): intestatario(new char[1]){strcpy(codice,"");strcpy(intestatario,"");strcpy(numerotel,"");}
			Utenza(const char * s1, const char * s2, const char * s3): intestatario(new char[strlen(s2)+1]){strcpy(codice, s1); strcpy(intestatario,s2); strcpy(numerotel, s3);}
			virtual ~Utenza(){delete [] intestatario;}
			Utenza(const Utenza &);
			const Utenza & operator=(const Utenza &);
			virtual bool apply()const=0;
			const char * get_num()const{return numerotel;}
			const char * get_codice()const{return codice;}
	};
}
#endif
