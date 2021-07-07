#include "Prodotti.h"
Prodotto::Prodotto(const char * C, const char * D, const int Q){
	strcpy(Codice,C);
	Descrizione=new char[strlen(D)+1]; 
	strcpy(Descrizione,D);
	Qta=Q;
}
Prodotto::Prodotto(const Prodotto & C){ 
	strcpy(Codice,C.Codice);
	Descrizione=new char[strlen(C.Descrizione)+1]; 
	strcpy(Descrizione,C.Descrizione);
	Qta=C.Qta;
}
const Prodotto & Prodotto::operator=(const Prodotto &C){
	if(this!=&C){
	delete [] Descrizione; 
	strcpy(Codice,C.Codice);
	Descrizione=new char(strlen(C.Descrizione)+1);
	strcpy(Descrizione,C.Descrizione);
	Qta=C.Qta;
}
return *this;
}
void Prodotto::Inserisci_DatiProdotto() {
    char buffer[DIM];
    cout << "\n Fornire il Codice del Prodotto: ";
    cin.getline(this->Codice, DIM); 
    cout << "\n Fornire una breve descrizione del Prodotto: ";
    cin.getline(buffer, DIM);
	this->set_Des(buffer);
    cout << "\n Fornire la quantita' disponibile in magazzino: ";
    cin >> Qta; 
    cin.ignore();
}

void Prodotto::Visualizza_DatiProdotto()const {
    cout << "\n *************************************";
    cout << "\n Codice Prodotto: " << Codice;
    cout << "\n Descrizione Prodotto: " << Descrizione;
    cout << "\n Disponibilita': " << Qta; 
    cout<<endl;
}
bool Prodotto::operator==(const Prodotto & P)const{
	return (!strcmp(Codice, P.Codice) && !strcmp(Descrizione,P.Descrizione) && Qta==P.Qta);
}
bool Prodotto::operator!=(const Prodotto & P)const{
	return !(*this==P)
}
