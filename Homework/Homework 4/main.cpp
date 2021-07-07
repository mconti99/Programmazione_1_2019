using namespace std;
#include "conto_apacchetto.h"
using namespace MS;
int main(int argc, char** argv) {
		ordinario c("Valeria Vittorini", 2020, 100, 0.02, 3);
	base o("Paolo Rossi", 2010, 100, 0.03, 2,15,true,2);
	
	if(c.prelievo(-100)) cout << "prelievo effettuato" << endl;
	else cout << "impossibile prelevare!" << endl;
	
	if(c.versamento(100)) cout << "versamento effettuato" << endl;
	else cout << "impossibile versare!" << endl;
	
	if(c.prelievo(-25)) cout << "prelievo effettuato" << endl;
	else cout << "impossibile prelevare!" << endl;
	
	if(c.versamento(40)) cout << "versamento effettuato" << endl;
	else cout << "impossibile versare!" << endl;
	
	if(c.prelievo(-100)) cout << "prelievo effettuato" << endl;
	else cout << "impossibile prelevare!" << endl;
	
	try {

	if(c.versamento(-100)) cout << "versamento effettuato" << endl;
	else cout << "impossibile versare!" << endl;
  
  }
  catch(const char * e) {
  	 cout << e << endl;
  }

  c.stampa_saldo(cout);
  cout << "\n";
  c.stampa_movimenti(cout);
  cout << "\n";
  
  ofstream myfile;
  myfile.open("prova.txt");
  if(myfile) {
  	c.stampa_saldo(myfile);
  myfile << "\n";
  c.stampa_movimenti(myfile);
  cout << "\n";
  myfile.close();
  }
  else cout << "file non creato!" << endl;
     
	
  if(o.prelievo(-100)) cout << "prelievo effettuato" << endl;
	else cout << "impossibile prelevare!" << endl;
	
	if(o.versamento(70)) cout << "versamento effettuato" << endl;
	else cout << "impossibile versare!" << endl;
	
	if(o.prelievo(-25)) cout << "prelievo effettuato" << endl;
	else cout << "impossibile prelevare!" << endl;
	
	if(o.versamento(30)) cout << "versamento effettuato" << endl;
	else cout << "impossibile versare!" << endl;
	
	if(o.prelievo(-100)) cout << "prelievo effettuato" << endl;
	else cout << "impossibile prelevare!" << endl;
	
	try {

	if(o.versamento(-100)) cout << "versamento effettuato" << endl;
	else cout << "impossibile versare!" << endl;
  
  }
  catch(const char * e) {
  	 cout << e << endl;
  }

  if(o.versamento(30)) cout << "versamento effettuato" << endl;
	else cout << "impossibile versare!" << endl;
	
	if(o.prelievo(-10)) cout << "prelievo effettuato" << endl;
	else cout << "impossibile prelevare!" << endl;
	
  o.stampa_saldo(cout);
  cout << "\n";
  o.stampa_movimenti(cout);
  cout << "\n";
  //esempio di binding dinamico per la funzione calcolo_spese
  conto * v[2];
  v[0]=&c;
  v[1]=&o;
  
  cout << "spese dei conti: " << endl;
  cout << v[0]->calcolo_spese();
  cout << "\n";
  cout << v[1]->calcolo_spese();
	
	
	return 0;
}
/*
Si sviluppi un programma che simuli un certo numero di operazioni almeno su due conti correnti di tipo 
differente per effettuare il test delle classi realizzate 
(inclusa la stampa su file di tipo testo) e fornisca un esempio di 
binding dinamico per la funzione di calcolo della spesa
*/
