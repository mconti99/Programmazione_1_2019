#include "magazzino.h"

void Crea_Magazzino(Magazzino & M, int &n){
	cout<<"da quanti prodotti e' fatto il magazzino?"<<endl;
	cin>>n;
	cout<<"crea il magazzino: "<<endl;
	for(int i=0;i<n;i++){
		cin.ignore();
		Inserisci_DatiProdotto(M[i]);
	}
}
bool Cerca_Prodotto(const Magazzino & M,const int n, const char* code, int &pos){
	bool trovato=false;
	int i=0;
	pos=-1;
	while(i<n && trovato==false){
		if(!strcmp(M[i].Codice,code)){
			pos=i;
			trovato=true;
		}else i++;
	}
	return trovato;
}
bool Elimina_Prodotto(Magazzino & M, int &n, const int p){
    if(p>=0) {
       for(int i=p; i<n-1; i++)
         M[i]=M[i+1];
       n--;
       return true;
   }   
   else return false;
}
void Visualizza_Magazzino(const Magazzino & M, const int n){
	cout<<"ora ti mostro tutti i prodotti del magazzino: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"codice del prodotto "<<i<<" :"<<M[i].Codice<<endl;
		cout<<"descrizione del prodotto"<<i<<" :"<<M[i].Descrizione<<endl;
		cout<<"quantita' del prodotto"<<i<<" :"<<M[i].Qta<<endl;
		cout<<endl;
	}
}
void Stampa_StatoMagazzino(const Magazzino & M, const int n){
	char file_name[N];
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
	f<<"codice del prodotto "<<i<<" :"<<M[i].Codice;
	f<<"descrizione del prodotto"<<i<<" :"<<M[i].Descrizione;
	f<<"quantita' del prodotto"<<i<<" :"<<M[i].Qta;
	f.close();
}
}
