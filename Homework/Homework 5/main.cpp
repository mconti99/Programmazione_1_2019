#include <iostream>
#include <fstream>
#include "classi.h"
#include "coda.h"
using namespace MS;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Auto A1("dio", "bello", "bo", 1);
	Auto A2("auto", "fiat", "panda", 6);
	Auto A3("auto", "toyota", "yaris", 5);
	
	Coda C;
	cout<<A1;
	cout << A2;
	cout << A3;
	A1=A2;
	Auto v[3]; //vettore di auto fatto da 3 elementi
	v[0]=A1;
	v[1]=A2;
	v[2]=A3;
	try{
	for(int i=0;i<3;i++){
		cout << "pedaggio:" << v[i].CalcolaPedaggio() << endl;
}
}catch(Eccezione & e){
	cout << e.what() << " e la classe che da' problemi e' " << e.get_l() << endl;
}
	C.append(&A1); //inserisco nella coda
	C.append(&A2);
	C.append(&A3);

	
	Veicolo * elem;
	C.pop(elem);
	cout<<*elem<<endl;
	C.pop(elem);
	cout<<*elem<<endl;
	C.pop(elem);
	cout << * elem<<endl;

	system("PAUSE");
	return 0;
}
