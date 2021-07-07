#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
class Voce{
	private:
    int chiave;
    char * descrizione;
    static const int N=100;
	public:
	Voce(): chiave(0){descrizione=new char[1]; strcpy(descrizione,"");}
	Voce(const int, const char *);
	Voce(const Voce &); //costruttore di copia
	const Voce & operator=(const Voce &);
	void read();
	void write()const;
	bool equal(const Voce &)const;
	bool greater_than(const Voce &)const;
	~Voce() {delete [] descrizione;} //distruttore
	const char * get_Des()const{return descrizione;}
	int get_Key()const{return chiave;}
	void set_Des(const char * s) {delete [] descrizione; descrizione=new char[strlen(s)+1]; strcpy(descrizione,s);} 
};
//bool operator== (const Entry &) const;
//bool operator != (const Entry &) const;
//void set_K(const int K) {Key=K;}
