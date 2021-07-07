#include "data.h"
namespace MS{
	ostream & Data::print(ostream & out)const{
		out << giorno << "/" << mese << "/" << anno;
		return out;
	}
	ostream & operator << (ostream & out, const Data & D){
		return D.print(out);
	}
}
