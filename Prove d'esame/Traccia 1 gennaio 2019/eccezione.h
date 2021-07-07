#ifndef _ECC_H
#define _ECC_H
#include <iostream>
#include <cstring>
using namespace std;
namespace MS{
	class Eccezione{
		char cod[100];
		string message;
		public:
			Eccezione(const string & msg, const char * c): message(msg){strcpy(cod,c);}
			string what()const{return message;}
			const char * get_cod()const{return cod;}
	};
}
#endif
