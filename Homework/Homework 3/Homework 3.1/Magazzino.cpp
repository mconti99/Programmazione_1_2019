#include "Magazzino.h"

Magazzino::Magazzino(const int myn) : V(myn){
	n=myn;
	cout <<"inserimento dati prodotto";
	for(int i=0;i<n;i++)
	cin>>V[i];
	cout<< "fatto"<<endl;
}7
void Magazzino::Inserisci_Dati_Magazzino(){
	for(int i=0;i<n;i++){
	V[i].Inserisci_DatiProdotto();
}
}
bool Magazzino::Cerca_Prodotto(const char* code, int & pos)const{
	bool trovato=false;
	int i=0;
	pos=-1;
	while(i<n && trovato==false){
		if(!strcmp(V[i].get_Cod(),code)){
			pos=i;
			trovato=true;
		}else i++;
	}
	return trovato;
}
bool Magazzino::Elimina_Prodotto(const int p){
	    if(p>=0) {
       for(int i=p; i<n-1; i++)
         V[i]=V[i+1];
       n--;
       return true;
   }   
   else return false;
}
void Magazzino::Visualizza_Magazzino()const{
		cout<<"ora ti mostro tutti i prodotti del magazzino: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"codice del prodotto "<<i<<" :"<<V[i].get_Cod()<<endl;
		cout<<"descrizione del prodotto"<<i<<" :"<<V[i].get_Des()<<endl;
		cout<<"quantita' del prodotto"<<i<<" :"<<V[i].get_Q()<<endl;
		cout<<endl;
	}
}
void Magazzino::Stampa_StatoMagazzino()const{
	char file_name[DIM];
	ofstream f;
	do
	{
		cout<<"Inserisci il nome del file da leggere: ";
		cin>>file_name;
		f.open(file_name, ios::out);
		if(!f)
		{
			cout<<endl<<"Impossibile leggere il file, riprova."<<endl;
		}
	}while(!f);
	for(int i=0;i<n;i++){
	f<<"codice del prodotto "<<i<<" :"<<V[i].get_Cod()<<endl;
	f<<"descrizione del prodotto"<<i<<" :"<<V[i].get_Des()<<endl;
	f<<"quantita' del prodotto"<<i<<" :"<<V[i].get_Q()<<endl;
	f.close();
}
}
