#ifndef _PERSONA_H
#define _PERSONA_H
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
using std::string;
namespace MS{
	class Persona{
		friend ostream & operator<<(ostream &, const Persona &);
		private:
			string nome;
			string cognome;
			int anno;
		protected:
			ostream & print(ostream &)const;
		public:
			//costruttore
			Persona(): nome(""), cognome(""), anno(0){}
			Persona(const string n, const string c, const int a): nome(n), cognome(c), anno(a){}
			//get
			string get_n()const{return nome;}
			string get_c()const{return cognome;}
			int get_a()const{return anno;}
			//overloading << ==
			bool operator==(const Persona &)const;
			
	};
}
#endif
