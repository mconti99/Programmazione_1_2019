#include <iostream>
#include "indeterminato.h"
#include <fstream>
using namespace MS;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Determinato d1("AH711", "Matteo", "Conti", 1999, "Laurea", 110);
	Determinato d2("AH811", "Carlo", "Conti", 1965,"Diploma", 99);
	Indeterminato i1("BH911", "Gigi", "Buffon", 1999, "Laurea", 106, false);
	Indeterminato i2("BH1011", "Francesco", "Totti", 1900, "Diploma", 100, true);
	Indeterminato i3("CH11011", "Diego", "Demme", 1999, "Laurea", 110, false);
	Candidato * v[5];
	v[0]=&d1;
	v[1]=&d2;
	v[2]=&i1;
	v[3]=&i2;
	v[4]=&i3;
	try{
	for(int i=0;i<5;i++){
		if(v[i]->check(2020)==true){
			cout<< "AMMESSO:"<< v[i]->get_cod() << " " << v[i]->get_n() << " " << v[i]->get_c() << endl;
		}
	}
}catch(const char * e){
	cout << e << endl;
}
/*	ofstream f;
	f.open("prova.txt");
	if(f){
			try{
	for(int i=0;i<5;i++){
		if(v[i]->check(2020)==true){
			f << "AMMESSO:"<< v[i]->get_cod() << " " << v[i]->get_n() << " " << v[i]->get_c() << endl;
		}
	}
	f.close();
}catch(const char * e){
	cout << e << endl;
}
	} else cout << "errore in apertura file"<<endl;
	*/
	return 0;
}
