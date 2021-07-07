#ifndef _EXCEPT_H
#define _EXCEPT_H
namespace MS{
	class FileExcep{
		string message;
		public:
			FileExcep(const string s="errore eccezione file"): message(s){}
			string what()const{return message;}
	};
}
#endif
