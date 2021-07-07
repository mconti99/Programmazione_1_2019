#include <iostream>
#include "classi.h"
#include "lista.h"
using namespace MS;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//operazioni di inserimento, attivazione, rimozione, show e stampa
	cout << "inserire un numero compreso tra 1 e 5 per le seguenti funzioni"<<endl;
	cout << "1-inserimento"<<endl;
	cout << "2-attivazione"<<endl;
	cout << "3-rimozione" << endl;
	cout << "4-show video"<< endl;
	cout << "5-stampa file creato da me"<<endl;
	int scelta=0;
	Lista L;
	Processo * P1 = new Processo(1,"Windows background execution", false, "runtime broker", 'W');
	Processo * P2 = new Processo(2,"Host service", false, "sysMain ", 'P');
	Processo * P3 = new Processo(3,"Windows service execuble", false, "antimalware ", 'W');
	Processo * P4 = new Processo(4,"Host service", false, "Client DNS ", 'P');
	cin>>scelta;
	if(scelta==1){
		try{
		if(L.append(P1)==true) cout << "fatto"<<endl;
		L.append(P2);
		L.append(P3);
		L.append(P4);
		cout<<"operazione 1 completata"<<endl;
	}catch(Eccezione & e){
		cout << e.what() << endl;	
	}
	}
	else if(scelta==2){
		Processo P8(8,"Windows background execution", false, "runtime broker", 'W');
		P8.attiva();
		cout << "operazione 2 completata"<<endl;
	}
	else if(scelta==3){
		L.append(P2);
		L.remove(P2);
		cout << "operazione 3 completata"<< endl;
	}
	else if(scelta==4){
		L.append(P1);
		L.append(P2);
		L.schedule(1);
		L.show(cout);
		cout << "operazione 4 completata"<<endl;
	}
	else if(scelta==5){
		L.append(P1);
		L.store("prova.txt");
		cout << "operazione 5 completata"<<endl;
	}
	else{
		cout << "si strunz"<<endl;
	}
	return 0;
}
