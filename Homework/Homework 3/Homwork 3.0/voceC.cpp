#include "voceC.h"

Voce::Voce(const int K, const char* I){ 
	descrizione=new char[strlen(I)+1];
	strcpy(descrizione, I);
	chiave=K;
}
Voce::Voce(const Voce & V){
	descrizione=new char[strlen(V.descrizione)+1]; 
	strcpy(descrizione,V.descrizione);
	chiave=V.chiave;
}
const Voce & Voce::operator=(const Voce & V){
	if(this!=&V){
	delete [] descrizione; 
	descrizione=new char[strlen(V.descrizione)+1]; 
	strcpy(descrizione,V.descrizione);
	chiave=V.chiave;
}
return *this;
}
/* istream & operator>>(istream & in, Entry & E){
char buffer[100];
in>>e.key;
//ignore vanno evitati, bisogna dare la responsabilità all'utente
in.getline(buffer,100);
delete[] e.info;
e.info=new char[strlen(buffer)+1];
strcpy(e.info, buffer);
return in;
}
*/
void Voce::read(){ // da utilizzare su una variabile che non è stata distrutta
	cout<<"inserire la chiave della voce: ";
	cin>>chiave;
	char buffer[N];
	cout<<"\n inserire la descrizione della voce: ";
	cin.ignore();
	cin.getline(buffer, N-1);
	delete [] descrizione;
	descrizione=new char[strlen(buffer)+1];
	strcpy(descrizione,buffer);
}
/* bool entry::operator==(const entry & e)const{

}
*/
void Voce::write()const{
	cout<<"la chiave della voce e': "<<chiave<<endl;
	cout<<"la descrizione della voce e': "<<descrizione<<endl;
}
bool Voce::equal(const Voce & v1)const{
	bool uguali;
	if((chiave==v1.chiave) && (!strcmp(descrizione,v1.descrizione))){
		uguali=true;
	}
	else uguali=false;
	return uguali;
}
bool Voce::greater_than(const Voce & v1)const{
	bool maggiore;
	if(chiave>v1.chiave){
		maggiore=true;
	}else maggiore=false;
	return maggiore;
}

