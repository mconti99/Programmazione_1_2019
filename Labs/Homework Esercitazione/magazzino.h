#include "prodotto.h"
#include <cstring>
#include <fstream>
typedef Prodotto Magazzino[N];
void Crea_Magazzino(Magazzino &, int&);
bool Cerca_Prodotto(const Magazzino & , const int, const char*, int &);
bool Elimina_Prodotto(Magazzino &, int &, const int);
void Visualizza_Magazzino(const Magazzino & , const int);
void Stampa_StatoMagazzino(const Magazzino &, const int);
