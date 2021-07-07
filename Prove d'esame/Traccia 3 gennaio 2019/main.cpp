#include <iostream>
#include "classi.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace MS;
int main(int argc, char** argv) {
	Riga e2("capuozzo", "carlo", "a");
	Riga e3("paesano", "davide", "b");
	Riga e4("guarino", "roberta", "c");
	Riga e5("vitale", "luciano", "d");
	Riga e1("conti", "matteo", "e");
	Registro r1(Data(24,1,2020), "matematica", "vittorini", "quinta E", 0);
	if(r1.test()==0) cout << "puoi continuare"<<endl;
	try{
	r1.inserimento_ord(e2);
	r1.inserimento_ord(e3);
	r1.inserimento_ord(e4);
	r1.inserimento_ord(e5);
	r1.inserimento_ord(e1);
}catch(const char * e){
	cout << e << endl;
}
	r1.interrogazione("a");
	r1.interrogazione("b");
	r1.interrogazione("c");
	r1.interrogazione("d");
	cout << "la media e'" << r1.media_g() << endl;
	r1.stampavideo();
	return 0;
}
