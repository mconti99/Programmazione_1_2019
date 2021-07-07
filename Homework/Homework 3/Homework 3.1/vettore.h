#include "Prodotti.h"
using namespace std;
typedef Prodotto T;
class Vettore {
	//friend ostream & operator<<(ostream &, const Vettore &);
	//friend istream & operator>>(istream &, Vettore &);
	private:
	T * V;
	int nmax; //dimensione massima, non riempimento, il riempimento è definito dall'utente
	public:
		explicit Vettore(const int = 10);
		Vettore(const Vettore &); 
		const Vettore & operator=(const Vettore &);
		//bool operator == (const Vettore &)const;
		//bool operator != (const Vettore &)const;
		int get_nmax()const{return nmax;}
		T& operator[] (const int);
		const T& operator[] (const int)const; 
		~Vettore(){ delete [] V;}
};
