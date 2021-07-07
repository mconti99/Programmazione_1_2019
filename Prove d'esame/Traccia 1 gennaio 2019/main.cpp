#include <iostream>
#include "mobile.h"
#include "fisso.h"
using namespace MS;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Fisso f1("UF101", "Vico Giambattista", "0812225534", "appartamento", Indirizzo("Via Mergellina", "5", "Napoli", "80121"));
	cout << f1 << endl;
	Fisso f2("UF102", "Morante Elsa", "062121212", "Appartamento", Indirizzo(" Via Margutta"," 10 ","Roma"," 00122"));
	cout << f2 << endl;
	Mobile m1("UM101","Foscolo Ugo", "+393385577322", L2);
	cout << m1 << endl;
	Mobile m2("UM102","Alighieri Dante", "+39338120032", L1);
	cout << m2 << endl;
	try{
	if(m1.check_n()) cout << "UM101: formato numero mobile valido"<<endl;
	if(m2.check_n()) cout << "UM102: formato numero mobile valido"<<endl;
	}catch (Eccezione & e){
		cout << e.get_cod() << ": " << e.what() << endl;
	}
	Utenza * v[3];
	v[0]=&f1;
	v[1]=&m1;
	v[2]=&f2;
	for(int i=0;i<3;i++){
		if(v[i]->apply()==true) cout << "offerta applicabile"<<endl;
		else cout << "offerta NON applicabile" << endl;
	}
	return 0;
}
