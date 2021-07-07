#include <iostream>
#include <stdlib.h>
#include <string.h>
const int N=100;


using namespace std;
struct Voce{
	int chiave;
	char * descrizione;
};


void create(Voce &, const int=0, const char* =""); //utilizzo dei valori di defalut, nel caso l'utente volesse inizializzare
// in questa stringa c'è solo il terminatore
void read(Voce &);
void write(const Voce &);
void copy(Voce &, const Voce &);
bool equal(const Voce &, const Voce &);
bool greater_than(const Voce &, const Voce &);
void destroy(Voce &);
