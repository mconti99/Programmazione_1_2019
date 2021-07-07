#ifndef _BRANO_H
#define _BRANO_H
#include <iostream>
#include <cstring>
using namespace std;
namespace MS{
	class Brano{
		friend ostream & operator<<(ostream &, const Brano &);
		friend istream & operator>>(istream &, Brano &);
		string titolo;
		int id;
		float durata;
		protected:
			virtual ostream & print(ostream &)const;
			virtual istream & input(istream &);
		public:
			Brano(): titolo(""), id(0), durata(0.0){}
			Brano(const string & t, const int i, const float d): titolo(t), id(i), durata(d){}
			string get_t()const{return titolo;}
			int get_i()const{return id;}
			float get_d()const{return durata;}
	};
}
#endif
