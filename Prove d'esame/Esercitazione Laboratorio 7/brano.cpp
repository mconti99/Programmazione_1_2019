#include "brano.h"
namespace MS{
	ostream & Brano::print(ostream & out)const{
		out << titolo << " " << id << " " << durata;
		return out;
	}
	istream & Brano::input(istream & in){
		in >> titolo;
		in >> id;
		in >> durata;
		return in;
	}
	ostream & operator<<(ostream & out, const Brano &B){
		return B.print(out);
	}
	istream & operator>>(istream & in, Brano &B){
		return B.input(in);
	}
}
