#include "elenco.h"

void read(elenco & x, int & n){
	cout<<"da quante voci e' formato l'elenco?"<<endl;
	cin>>n;
	cout<<"inserisci le "<<n<<" voci:"<<endl;
	for(int i=0;i<n;i++){
		create(x[i]);
		read(x[i]);
	}
}
void write(const elenco & x, const int n){
	cout<<"ora puoi visualizzare il tuo elenco:"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Questa e' la Voce "<<i<<":"<<endl;
		write(x[i]);
		cout<<endl;
	}
}
bool in(const elenco & x, const int n, const Voce & v, int & pos){
	bool trovato=false;
	int i=0;
	pos=-1;
	while(i<n && trovato==false){
		if(!strcmp(x[i].descrizione,v.descrizione) && x[i].chiave==v.chiave){
			pos=i;
			trovato=true;
		}else i++;
	}
	return trovato;
}
void sort(elenco & x, const int n){
	Voce temp; bool swap;
	create(temp);
	int i=0,j;
	do{
		swap=false;
		for(j=0;j<n-1;j++){
			if(x[j].chiave>x[j+1].chiave){
				temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
				swap=true;
			}
		}
		i++;
	}while(i<n && swap);
	destroy(temp);
}
bool isFull(const elenco & x, const int n){
	bool pieno;
	if(n>= N) pieno=true;
	else pieno=false;
	return pieno;
}
bool isEmpty(const elenco & x, const int n){
	bool vuoto;
	if(n==0) vuoto=true;
	else vuoto=false;
	return vuoto;
}
void insert(elenco & x, int & n, const Voce & v){
	bool trovato=false;
	int i=0;
	while(i<n && trovato==false){
		if(x[i].chiave==0){
			x[i]=v;
			trovato=true;
		}else i++;
	}
	if(!trovato) x[n++]=v;
	//n=n+1;
}
void insert_ord(elenco & x, int & n, const Voce & v){
	sort(x, n);
	bool trovato=false;
	int i=1;
	while(i<n && trovato==false){
		if(x[i-1].chiave<v.chiave<x[i+1].chiave){
			x[i]=v;
			trovato=true;
		}else i++;
	}
	// n=n+1;
}
void remove(elenco & x, int & n, const Voce & v){
	int p=0;
	if(in(x,n,v,p)==true){
	for(int i=p;i<n;i++){
		x[i]=x[i+1];
	}
	n=n-1;
	}
	else cout<<"non e' possibile effettuare l'operazione :("<<endl;
}
bool is_sorted(const elenco & x, const int n){
	bool ordinato=false;
	int i=0;
	while(i<n && !ordinato){
		if(x[i].chiave<x[i+1].chiave){
        i++;
		}else ordinato=true;
	}
	return !ordinato;
}
