#include "voce.h"
typedef Voce elenco[N];

void read(elenco & , int & );
void write(const elenco & , const int );
bool in(const elenco & , const int , const Voce & , int &);
void sort(elenco & , const int );
bool isFull(const elenco & , const int );
bool isEmpty(const elenco & , const int );
void insert(elenco & , int & , const Voce & );
void insert_ord(elenco & , int & , const Voce & );
void remove(elenco & , int & , const Voce & );
bool is_sorted(const elenco & , const int );

