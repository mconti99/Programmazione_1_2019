#include "fisso.h"
namespace MS{
	Fisso::Fisso(const Fisso &F):Utenza(F){
		destinazione=new char[strlen(F.destinazione)+1];
		strcpy(destinazione,F.destinazione);
		i=F.i;
	}
	const Fisso & Fisso::operator=(const Fisso &F){
		if(this!=&F){
			Utenza::operator=(F);
			delete [] destinazione;
			destinazione=new char[strlen(F.destinazione)+1];
			strcpy(destinazione,F.destinazione);
			i=F.i;
		}
		return *this;
	}
	ostream & Fisso::print(ostream & out)const{
		Utenza::print(out);
		out << " " << destinazione << " " << i << endl;
		return out;
	}
	ostream & operator<<(ostream & out, const Fisso &F){
		return F.print(out);
	}
	bool Fisso::apply()const{
		if(!strcmp(destinazione,"appartamento") && i.get_c()=="Napoli") return true;
		else return false;
	}
}
