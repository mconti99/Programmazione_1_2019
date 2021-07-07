#include "pila.h"
namespace MS{
	bool Pila::push(const T & e){
		if(full()) return false;
		else{
			Record * q=new Record;
			q->info=e;
			q->next=testa;
			testa=q;
			return true;
		}
	}
	bool Pila::pop(T & e){
		if(empty()) return false;
		else{
			Record * q;
			q=testa;
			e=testa->info;
			testa=testa->next;
			delete q;
			return true;
		}
	}
	bool Pila::top(T & e)const{
		if(empty()) return false;
		e=testa->info;
		return true;
	}
	void Pila::leggidafile() throw(FileExcep &){
		//inserire nella pila n elementi leggendo i dati relativi da file binario
	ifstream infile("prova.txt",ios::binary|ios::in);
	T e;
	int n=0;
	infile.seekg(sizeof(int), ios_base::beg);
	infile.read(reinterpret_cast<char *>(&n), sizeof(int));
	if(infile){
	for(int i=0;i<n;i++){
		int x;
		infile.seekg(sizeof(int), ios_base::cur);
		if(infile.read(reinterpret_cast<char *>(&x),sizeof(int))) 
		e.set_c(x);
		else break;
		float y;
		infile.seekg(sizeof(float), ios_base::cur);
		if(infile.read(reinterpret_cast<char *>(&y),sizeof(float))) 
		e.set_p(y);
		else break;
		int z;
		infile.seekg(sizeof(int), ios_base::cur);
		if(infile.read(reinterpret_cast<char *>(&x),sizeof(int))){
			char * p=new char[z];
			infile.seekg(z*sizeof(char), ios_base::cur);
			if(infile.read(reinterpret_cast<char *>(p),sizeof(z*sizeof(char))))
			e.set_i(p);
		}
		else break;
		push(e);
		}
		infile.close();
	}
	else throw FileExcep();
	}
}
