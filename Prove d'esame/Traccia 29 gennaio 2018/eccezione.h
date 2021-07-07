#ifndef _ECC_H
#define _ECC_H
#include <cstring>
#include <iostream>
using namespace std;
namespace MS{
	class bad_id{
		string message;
		public:
			bad_id(const string & msg): message(msg){}
			string what()const{return message;}
	};
}
#endif
