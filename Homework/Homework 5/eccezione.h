#include <string>
#include "table.h"

using std::string;
namespace MS{
	class Eccezione{
		string msg;
		int livello;
		public:
			Eccezione(const int C, const string m="errore") : msg(m), livello(C){}
			string what()const {return msg;}
			int get_l()const{return livello;}
	};
}
