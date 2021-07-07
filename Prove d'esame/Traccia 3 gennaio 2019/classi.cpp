#include "classi.h"
namespace MS{
	Entry::Entry(const Entry &E){
		cognome=new char[strlen(E.cognome)+1];
		nome=new char[strlen(E.nome)+1];
		strcpy(cognome,E.cognome); 
		strcpy(nome, E.nome); 
		strcpy(id, E.id);
	}
	const Entry & Entry::operator=(const Entry &E){
		if(this!=&E){
			delete [] nome;
			delete [] cognome;
			cognome=new char[strlen(E.cognome)+1];
			nome=new char[strlen(E.nome)+1];
			strcpy(cognome,E.cognome); 
			strcpy(nome, E.nome); 
			strcpy(id, E.id);
		}
		return *this;
	}
	ostream & Entry::print(ostream & out)const{
		out << nome << " " << cognome << " " << id ;
		return out;
	}
	istream & Entry::input(istream & in){
		char buffer[dim];
		char buff[dim];
		in.getline(buffer,dim);
		in.getline(buff,dim);
		set_n(buff);
		set_c(buff);
		in.getline(id, dim);
		return in;
	}
	ostream & operator << (ostream & out, const Riga & E){
		return E.print(out);
	}
	istream & operator >> (istream & in, Riga & E){
		return E.input(in);
	}
	ostream & Riga::print(ostream & out)const{
		Entry::print(out);
		out << " " << presenza << " " << voto <<endl;
		return out;
	}
	istream & Riga::input(istream & in){
		Entry::input(in);
		in >> presenza;
		in >> voto;
		return in;
	}
	bool Riga::set_v(const int v) throw(const char *){
		if(presenza==false) throw "errore eccezione";
		else{
			if(v<0 || v>10) return false;
			else {
				voto=v; 
				return true;
			}
		}
	}
	void Registro::inserimento_ord(const Riga & e) throw(const char *){
		bool trovato=false;
		int i=0;
		if(in(e)==true) throw "errore eccezione ordinamento";
		else if(numeroCorr==0 || strcmp(v[numeroCorr-1].get_c(),e.get_c())<0) {v[numeroCorr]=e; numeroCorr++;}
		else{
		while(i<numeroCorr && !trovato){
			if(strcmp(v[i].get_c(),e.get_c())>0){
				for(int j=numeroCorr;j>i;j--){
					v[j]=v[j-1];
				}
				numeroCorr++;
				v[i]=e;
				trovato=true;
			}
		else i++;
		}
		}
	}
	bool Registro::in(const Riga & x)const{
		bool trovato=false;
		int i=0;
		while(i<numeroCorr && !trovato){
			if(v[i].get_i()==x.get_i()){
				trovato=true;
			}
			else i++;
		}
		return trovato;
	}
	void Registro::interrogazione(const char * s){
		int p=0;
		
		for(int i=0;i<numeroCorr;i++){
			if(!strcmp(v[i].get_i(),s)){
				v[i].set_p(1);
			cout<<"che voto vuoi dare?"<<endl;
			cin>>p;
			if(v[i].set_v(p)==true) cout<< "voto inserito"<<endl;
		}
		}
	}
	int Registro::media_g()const{
		int somma=0;
		for(int i=0;i<numeroCorr;i++){
			somma= somma+v[i].get_v();
		}
		return (somma)/numeroCorr;
	}
	void Registro::print(ostream & out)const{
		out << "Registro di data" << data << ", di materia " << materia << endl;
		out << "di docente " << docente << ", di classe " << classe << " e di " <<endl;
		out << numeroCorr << " alunni";
		for(int i=0;i<numeroCorr;i++){
			out << v[i].get_c() << " " << v[i].get_n() << " " << v[i].get_v() << " " << v[i].get_p() <<" " << v[i].get_i() <<endl;
		}
	}
	void Registro::stampavideo()const{
		cout << "Registro di data " << data << ", di materia " << materia << endl;
		cout << ", di docente " << docente << ", di classe " << classe << " e di " <<endl;
		cout << numeroCorr << "alunni" << endl;
		for(int i=0;i<numeroCorr;i++){
			cout << "-----------------"<<endl;
			cout << v[i].get_c() << " " << v[i].get_n() << " " << v[i].get_p();
			if(v[i].get_v()==0) cout << " e voto *" << endl;
			else cout << " " << v[i].get_v() << endl;
		}
	}
}
