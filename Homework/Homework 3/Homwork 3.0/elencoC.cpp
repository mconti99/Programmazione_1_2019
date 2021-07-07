#include "elencoC.h"
/* void swap_T(T&, T&);
istream & operator >> (istream & in, mylist & m){
for(int i=0;i<M.SIZE;i++){
in >> M.L[i];
M.nelem=M.size;
return in;
}

in>> M.L;
m.nelem=M.L.get_size();
return in;
}
ostream & operator << (ostream &out, const mylist &){
for(int i=0;i<M.nelem;i++)
cout < M.L[i]<<endl;
return out;


out << M.L <<endl;
return out;
}
*/
void E::read(){
	cout<<"da quante voci e' formato l'elenco?"<<endl;
	cin>>n;
	cout<<"inserisci le "<<n<<" voci:"<<endl;
	for(int i=0;i<n;i++){
		elenco[i].read();
	}
}
void E::write()const{
	cout<<"ora puoi visualizzare il tuo elenco:"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Questa e' la Voce "<<i<<":"<<endl;
		elenco[i].write();
		cout<<endl;
	}
}
bool E::in(const Voce & v, int & pos)const{
	bool trovato=false;
	int i=0;
	pos=-1;
	while(i<n && trovato==false){
		if(!strcmp(elenco[i].get_Des(),v.get_Des()) && elenco[i].get_Key()==v.get_Key()){
			pos=i;
			trovato=true;
		}else i++;
	}
	return trovato;
}
void E::sort(){
//METTERE UN FLAG SE IL VETTORE E' CASUALMENTE ORDINATO PRIMA DELLA FINE
	Voce temp; bool swap;
	int i=0,j;
	do{
		swap=false;
		for(j=0;j<n-1;j++){
			if(elenco[j].get_Key()>elenco[j+1].get_Key()){
				temp=elenco[j];
				elenco[j]=elenco[j+1];
				elenco[j+1]=temp;
				swap=true;
			}
		}
		i++;
	}while(i<n && swap);
}
bool E::isFull()const{
	bool pieno;
	if(n>= N) pieno=true;
	else pieno=false;
	return pieno;
}
bool E::isEmpty()const{
	bool vuoto;
	if(n==0) vuoto=true;
	else vuoto=false;
	return vuoto;
}
/*bool mylist::insert(const t & c){
if (n==size) return false;
L[n]=c;
n++;
return true;
}
*/
void E::insert(const Voce & v){
	bool trovato=false;
	int i=0;
	while(i<n && trovato==false){
		if(elenco[i].get_Key()==0){
			elenco[i]=v;
			trovato=true;
		}else i++;
	}
	if(!trovato) elenco[n++]=v;
}
void E::insert_ord(const Voce & v){
bool trovato;
int i=0;
    while(i<n && !trovato){
		if(elenco[i].get_Key()>v.get_Key()){
			for(int j=n-1;j>=i;j--){
				elenco[j+1]=elenco[j];
			}
			n++;
			elenco[i]=v;
			trovato=true;
		}
		i++;
	}
}

void E::remove(const Voce & v){
	int p=0;
	if(this->in(v,p)==true){
	for(int i=p;i<n;i++){
		elenco[i]=elenco[i+1];
	}
	n=n-1;
	}
	else cout<<"non e' possibile effettuare l'operazione :("<<endl;
}
bool E::is_sorted()const{
	bool ordinato=false;
	int i=0;
	while(i<n-1 && !ordinato){
		if(elenco[i].get_Key()<elenco[i+1].get_Key()){
        i++;
		}else ordinato=true;
	}
	return !ordinato;
}
