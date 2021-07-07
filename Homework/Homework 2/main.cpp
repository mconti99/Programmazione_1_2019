#include "elenco.h"

int main() 
{ /*
	//acquisiscco dati di due voci
	Voce v1;
	Voce v2;
	cout<<"Voce v1";
	read(v1);
	cout<<endl<<"Voce v2";
	read(v2);
	
	//stampa a schermo le due voci
	cout<<endl<<"Voce v1";
	write(v1);
	cout<<endl<<"Voce v2";
	write(v2);
	
	
	//stabilisce se v1 > v2
	if (bool mygreater = greater_than(v1,v2))
	cout<<endl<<"v1 > v2";
	
	
	//stabilisce se due voci sono uguali
	if(	bool myequal = equal(v1,v2))
	cout<<endl<<"le due Voci sono uguali"<<endl;
	

	//copia la voce v1 in v2
	copy(v1,v2);
	cout<<endl<<"Voce v1 dopo la copia";
	write(v1);
	cout<<endl<<"Voce v2 dopo la copia";
	write(v2);
 
	//dealloca una Voce e ne inizializza la chiave
	destroy(v2); 
*/

 	//acquisizione dati elenco
	int nelem;
	elenco myElenco;
	read(myElenco, nelem);
	
	//stampa a schermo dell'elenco
	write(myElenco, nelem);
	
	//cerco elemento e ne restituisco la posizione
	Voce v3;
	create(v3);
	read(v3);
	int posv3;
	if(bool found = in(myElenco, nelem, v3, posv3))
	cout<<"la voce e' presente nell'elenco alla posizione "<<posv3<<endl;
	else
	cout<<"la voce non e' presente nell'elenco";
	
	//ordino elenco
	sort(myElenco, nelem);
	cout<<endl<<"Elenco ordinato in ordine crescente ";
	write(myElenco, nelem);

	//vedo se l'elenco è pieno
	if(bool full = isFull(myElenco, nelem))
	cout<<endl<<"l'elenco è pieno";
	
	//vedo se l'elenco è vuoto
	if(bool empty = isEmpty(myElenco, nelem))
	cout<<endl<<"l'elenco è vuoto"; 
	
	//inserimento di un ulteriore elemento
	cout<<"inserisci la voce da aggiungere all'elenco:"<<endl;
	Voce v4;
	read(v4);
	insert(myElenco, nelem, v4);
	cout<<endl<<"Elenco aggiornato ";
	write(myElenco, nelem);
	sort(myElenco, nelem);
	
	
	//inserisco elemento nel vettore ordinato
	Voce v5;
	read(v5);
	insert_ord(myElenco, nelem, v5);
	cout<<endl<<"Elenco aggiornato ";
	write(myElenco, nelem);
	
	return 0;
}

