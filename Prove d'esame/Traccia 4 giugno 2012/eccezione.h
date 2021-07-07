#ifndef _ECC_H
#define _ECC_H
#include <cstring>
#include <iostream>
using namespace std;
namespace MS{
	class Duplicato{
		string message;
		public:
			Duplicato(const string & msg): message(msg){}
			string what()const{return message;}
	};
}
#endif
