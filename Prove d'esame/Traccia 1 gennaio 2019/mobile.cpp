#include "mobile.h"
namespace MS{
	ostream & Mobile::print(ostream & out)const{
		Utenza::print(out);
		out << " " << profilo << endl;
		return out;
	}
	ostream & operator<<(ostream & out, const Mobile &M){
		return M.print(out);
	}
	bool Mobile::apply()const{
		if(profilo==L2) return true;
		else return false;
	}
	bool Mobile::check_n()const throw(Eccezione &){
		bool continua=false;
		if(strlen(get_num())<=14){
			if(get_num()[0]=='+'){
				for(int i=1;i<13;i++){
					if(get_num()[i]<='9' && get_num()[i]>='0'){
						continua=true;
					}
					else throw Eccezione("dopo il prefisso operatore non ci sono tutti numeri", get_codice());
				}
				if(continua && get_num()[1]=='3' && get_num()[2]=='9'){
					return true;
				}else throw Eccezione("il numero non ha come prime due cifre 39", get_codice());
			}
			else throw Eccezione("manca il prefisso operatore", get_codice());
		}
		else throw Eccezione("stringa troppo lunga", get_codice());
	}
}
