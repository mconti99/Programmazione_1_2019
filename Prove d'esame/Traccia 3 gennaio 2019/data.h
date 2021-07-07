#ifndef _DATA_H
#define _DATA_H
#include <iostream>
using namespace std;
namespace MS{
	class Data{
		friend ostream & operator << (ostream &, const Data &);
		private:
			int giorno;
			int mese;
			int anno;
		protected:
			virtual ostream & print(ostream &)const;
		public:
			Data(): giorno(0), mese(0), anno(0){}
			Data(const int g, const int m, const int a): giorno(g), mese(m), anno(a){}
	};
}
#endif
