#include "elencoC.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	/*
	//acquisiscco dati di due voci
	Voce v1;
	Voce v3;
	Voce v4(2, "mamma");
	cout<<"Voce v4:";
	v4.write();
	cout<<endl<<"Voce v2";
	v3.read();
	Voce v2(v3);
	//stampa a schermo le due voci
	cout<<endl<<"Voce v1";
	v1.write();
	cout<<endl<<"Voce v2";
	v2.write();
	
	
	//stabilisce se v1 > v2
	if (bool mygreater = v1.greater_than(v2))
	cout<<endl<<"v1 > v2";
	
	
	//stabilisce se due voci sono uguali
	if(	bool myequal = v1.equal(v2))
	cout<<endl<<"le due Voci sono uguali"<<endl;
	

	//copia la voce v1 in v2
    v1=v2;
	cout<<endl<<"Voce v1 dopo la copia";
	v1.write();
	cout<<endl<<"Voce v2 dopo la copia";
	v2.write();
 */
 //acquisizione dati elenco
	E e1;
	e1.read();
	
	//stampa a schermo dell'elenco
	e1.write();
		//cerco elemento e ne restituisco la posizione
	Voce v3;
	v3.read();
	int posv3;
	if(bool found = e1.in(v3, posv3))
	cout<<"la voce e' presente nell'elenco alla posizione "<<posv3<<endl;
	else
	cout<<"la voce non e' presente nell'elenco";
	
	//ordino elenco
	e1.sort();
	cout<<endl<<"Elenco ordinato in ordine crescente ";
	e1.write();

	//vedo se l'elenco è pieno
	if(bool full = e1.isFull())
	cout<<endl<<"l'elenco e' pieno";
	
	//vedo se l'elenco è vuoto
	if(bool empty = e1.isEmpty())
	cout<<endl<<"l'elenco e' vuoto"; 
	
	//inserimento di un ulteriore elemento
	cout<<"inserisci la voce v4 da aggiungere all'elenco:"<<endl;
	Voce v4;
	v4.read();
	e1.insert(v4);
	cout<<endl<<"Elenco aggiornato (dopo insert) ";
	e1.sort();
	e1.write();


	//inserisco elemento nel vettore ordinato
	cout<<"inserisci la voce v5 da aggiungere: "<<endl;
	Voce v5;
	v5.read();
	e1.sort();
	e1.insert_ord(v5);
	cout<<endl<<"Elenco aggiornato (dopo insert ord) ";
	e1.write();

	cout<<"l'elenco e' ordinato?"<<endl;
	if(e1.is_sorted()==true) cout<<"si, l'elenco e' ordinato"<<endl;
	else cout<<"no, non e' ordinato"<<endl;
	

	
	//rimuovo una voce
	e1.remove(v5);
	cout<<"L'elenco aggiornato senza v5 e': "<<endl;
	e1.write();
	return 0;
}
