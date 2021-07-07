#include "libreria.h"

void leggiComplex(Complesso &a){
	cout<<"inserire il numero complesso, cioè il coefficiente reale e quello immaginario"<<endl;
	cin>>a.re;
	cin>>a.imm;
}
void stampaComplex(const Complesso a){
	cout<<"il numero complesso inserito e':"<<endl;
	cout<<a.re<<"+"<<a.imm<<"i"<<endl;
}
Complesso /* & */ sommaComplex(const Complesso a, const Complesso b){
	Complesso ris;
	ris.re=a.re+b.re;
	ris.imm=a.imm+b.imm;
	return ris; //ritorno per valore
}
//passare per riferimento EVITA la copia, quindi velocizza il processo
// non ha senso passare per riferimento sommaComplex, in quanto è una variabile locale alla funzione
// l'unica soluzione sarebbe allocare l'indirizzo della variabile nell'area heap
Complesso prodottoComplex(const Complesso a, const Complesso b){
	Complesso ris;
	ris.re=(a.re*b.re)-(a.imm*b.imm);
	ris.imm=(a.re*b.imm)+(b.re*a.imm);
	return ris;
}
double moduloComplex(const Complesso a){
	double m,s;
	s=(a.re*a.re)+(a.imm*a.imm);
	m=sqrt(s);
	return m;
}
void LeggiElementi(Vettore Vet, int & nelem){
	do {
	cout<<"\n Inserisci il numero di elementi (n<100) dell' elenco : ";
	cin>>nelem;
	} while(nelem>=100);
	for(int i=0;i<nelem;i++){
		leggiComplex(Vet[i]);
	}
}
//sul record non sono definiti gli operatori di flusso, cin e cout
void StampaVettore(const Vettore Vet, const int nelem){
	Complesso b;
	for(int i=0;i<nelem;i++){
		b=Vet[i];
		stampaComplex(b);
	}
}
void ModuloBubbleSort(Vettore Vet, const int nelem){
	Complesso temp; bool swap;
	int i=0,j;
	do{
		swap=false;
		for(j=0;j<nelem-1;j++){
			if(moduloComplex(Vet[j])>moduloComplex(Vet[j+1])){
				temp=Vet[j];
				Vet[j]=Vet[j+1];
				Vet[j+1]=temp;
				swap=true;
			}
		}
		i++;
	}while(i<nelem && swap);
}


void ModuloBubbleSor(Vettore V, const int n) {
int i,j;

for(i=1;i<n;i++){
for(j=0;j<n-1;j++){
if(moduloComplex(V[j])>moduloComplex(V[j+1])){

swap(V[j],V[j+1]);
}
}
}
}
