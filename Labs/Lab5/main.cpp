#include <iostream>
#include "classi.h"
#include "lista.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace MS;
int main(int argc, char** argv) {
	Bolletta b1("codice",0.0,0.05,0);
	b1.GeneraBolletta(cout);
	
	Fisso f1("hey", 0.0, 0.10, 0, "cavallino", 20);
	Mobile m1("ciao", 0.0, 0.05,0, 0.20);
	cout <<"---------"<<endl;
	Bolletta * v[3];
	v[0]=&b1;
	v[1]=&f1;
	v[2]=&m1;
	v[0]->GeneraBolletta(cout);
	cout << endl;
	v[1]->GeneraBolletta(cout);
	cout << endl;
	v[2]->GeneraBolletta(cout);
	return 0;
}
