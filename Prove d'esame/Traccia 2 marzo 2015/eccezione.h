#ifndef _ECC_H
#define _ECC_H
namespace MS{
	class Eccezione{
		string message;
		public:
			Eccezione(const string msg): message(msg){}
			string what()const{return message;}
	};
}
#endif
