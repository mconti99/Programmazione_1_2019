#ifndef _ECCEZIONE_H
#define _ECCEZIONE_H
namespace MS{
	class Eccezione{
		string message;
		public:
			explicit Eccezione(const string msg): message(msg){}
			string what()const{return message;}
	};
}
#endif
