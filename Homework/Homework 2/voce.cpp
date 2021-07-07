#include "voce.h"

void create(Voce & v, const int K, const char* I){ //non ci sono i default, perchè solo l'utente deve leggerli
	v.descrizione=new char[strlen(I)+1];
	strcpy(v.descrizione, I);
	v.chiave=K;
}
void read(Voce & v){ // da utilizzare su una variabile che non è stata distrutta
	cout<<"inserire la chiave della voce: ";
	cin>>v.chiave;
	char buffer[N];
	cout<<"\n inserire la descrizione della voce: ";
	cin.ignore();
	cin.getline(buffer, N);
	// delete [] v.descrizione;
	//se v.descrizione è diverso da 0, entra nell'if altrimenti ignora
	if(v.descrizione) delete [] v.descrizione; //distruggo quello che c'è, e allocare nella dimensione giusta quello che devo mettere
	v.descrizione=new char[strlen(buffer)+1];
	strcpy(v.descrizione,buffer);
}
void write(const Voce & v){
	cout<<"la chiave della voce e': "<<v.chiave<<endl;
	cout<<"la descrizione della voce e': "<<v.descrizione<<endl;
}
void copy(Voce & v1, const Voce & v2){
	if(&v1!=&v2) { //controlla che non si stia copiando un record su se stesso
	if(strlen(v1.descrizione)!=strlen(v2.descrizione)) {
	  delete [] v1.descrizione;
	  v1.descrizione=new char[strlen(v2.descrizione)+1];
	  }
	strcpy(v1.descrizione,v2.descrizione);
	v1.chiave=v2.chiave;
	}
 	//se si sta copiando un record su se stesso non fa nulla
}
bool equal(const Voce & v1, const Voce & v2){
	bool uguali;
	if((v1.chiave==v2.chiave) && (!strcmp(v1.descrizione,v2.descrizione))){
		uguali=true;
	}
	else uguali=false;
	return uguali;
}
bool greater_than(const Voce & v1, const Voce & v2){
	bool maggiore;
	if(v1.chiave>v2.chiave){
		maggiore=true;
	}else maggiore=false;
	return maggiore;
}
void destroy(Voce & v){
	delete [] v.descrizione;
	v.descrizione=0; // metto a 0 il puntatore per distruggere tutto quello che riguarda la voce
}
