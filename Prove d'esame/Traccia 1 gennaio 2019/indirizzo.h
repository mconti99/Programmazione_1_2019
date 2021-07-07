#ifndef _INDIRIZZO_H
#define _INDIRIZZO_H
#include <iostream>
#include <cstring>
using namespace std;
namespace MS{
	class Indirizzo{
		friend ostream & operator<<(ostream &, const Indirizzo &);
		private:
		string via;
		string numerociv;
		string citta;
		string cap;
		protected:
			ostream & stampa(ostream &)const;
		public:
			Indirizzo(): via(""), numerociv(""), citta(""), cap(""){}
			Indirizzo(const string & v, const string & n, const string & c, const string & ca): via(v), numerociv(n), citta(c), cap(ca){}
			string get_v()const{return via;}
			string get_n()const{return numerociv;}
			string get_c()const{return citta;}
			string get_cap()const{return cap;}
	};
}
#endif
