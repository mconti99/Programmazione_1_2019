#include <iostream>
#include <cmath>
#define max 100

//uso una struct perchè così ho una ben chiara impostazione del coefficiente reale e immaginario, col vettore sarebbe più confuso
using namespace std;
typedef struct mioComplesso{
	double re;
	double imm;
} Complesso;
typedef Complesso Vettore[max];

void leggiComplex(Complesso &); 
void stampaComplex(const Complesso);
Complesso sommaComplex(const Complesso, const Complesso);
Complesso prodottoComplex(const Complesso, const Complesso);
double moduloComplex(const Complesso);
void LeggiElementi(Vettore,  int &);
void StampaVettore(const Vettore, const int);
void ModuloBubbleSort(Vettore, const int);  //vengono modificate le posizioni all'interno del vettore, quindi non è costante
