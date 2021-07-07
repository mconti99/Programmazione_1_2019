#ifndef _PRODOTTI_H
#define _PRODOTTI_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

const int DIM=20;

class Prodotto {
private: 
    char Codice[DIM];
    char * Descrizione;
    int Qta;
public:
Prodotto(): Qta(0) {strcpy(Codice,"") ;Descrizione=new char[1]; strcpy(Descrizione,"");}
Prodotto(const char *, const char *, const int);
Prodotto(const Prodotto & ); 
const Prodotto & operator=(const Prodotto &);
void Inserisci_DatiProdotto();
void Visualizza_DatiProdotto()const;
int get_Q() const{return Qta;} 
const char * get_Cod() const {return Codice;}  
const char * get_Des() const {return Descrizione;}
void set_Cod(const char * s) {strcpy(Codice,s);}
void set_Des(const char * s) {delete [] Descrizione; Descrizione=new char[strlen(s)+1]; strcpy(Descrizione,s);} 
void set_Q(const int n){ Qta=n;}
bool operator==(const Prodotto &)const;
bool operator!=(const Prodotto &)const;

~Prodotto() {delete [] Descrizione;} 
};
#endif
