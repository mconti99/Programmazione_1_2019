
#include "vettore.h"
class E{
	//friend ostream & operator<<(ostream &, const mylist &);
	//friend istream & operator>>(istream &, mylist &);
	private:
	static const int N=100;
	Vettore elenco;
	int n;
	public:
	//mylist(): n(0) {} //il vettore viene inizializzato come entry per ogni elemento
	//explicit mylist(const voce &); per inizializzare
	//int get_n() const {return n;}
	E(const int myn=10): elenco(myn), n(0){}
 	void read();
	void write()const;
	bool in(const Voce & , int &)const;
	void sort();
	bool isFull()const;
	bool isEmpty()const;
	void insert(const Voce & );
	void insert_ord(const Voce & );
	void remove(const Voce & );
	bool is_sorted()const;
};
