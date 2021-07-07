#ifndef _VEICOLO_H
#define _VEICOLO_H
#include <iostream>
#include <cstring>
#include "table.h"
#include "eccezione.h"
using namespace std;
namespace MS{
class Veicolo{
	friend ostream & operator << (ostream &, const Veicolo &);
	friend istream & operator >> (istream &, Veicolo &);
	private:
		char * tipo;
		char * marca;
	protected:
		virtual ostream& print(ostream &)const;
		virtual istream& input(istream &);
	public:
		Veicolo() : tipo(new char[1]), marca(new char[1]) {strcpy(tipo,""); strcpy(marca,"");}
		Veicolo(const char * T, const char * M): tipo(new char[strlen(T)+1]), marca(new char[strlen(M)+1]) {strcpy(tipo,T); strcpy(marca,M);}
		virtual ~Veicolo(){delete [] tipo; delete [] marca;}
		Veicolo(const Veicolo &);
		const Veicolo & operator=(const Veicolo &);
		const char * get_t()const {return tipo;}
		const char * get_ma()const{return marca;}
		void set_t(const char * s){delete [] tipo; tipo=new char[strlen(s)+1]; strcpy(tipo, s);}
		void set_ma(const char * s){delete [] marca; marca=new char[strlen(s)+1]; strcpy(marca, s);}
		bool operator==(const Veicolo &)const;
		bool operator!=(const Veicolo &)const;
		virtual float CalcolaPedaggio()const=0;
};
class Auto : public Veicolo{
	friend ostream & operator<<(ostream &, const Auto &);
	friend istream & operator>>(istream &, Auto &);
	private:
		char * modello;
		int classe;
	protected:
		virtual ostream & print(ostream &)const;
		virtual istream & input(istream &);
	public:
		Auto();
		Auto(const char *, const char *, const char *, const int);
		virtual ~Auto(){delete [] modello;}
		Auto(const Auto &);
		const Auto & operator=(const Auto &);
		int get_c()const {return classe;}
		const char * get_mo()const{return modello;}
		void set_c(const Classes s){classe=s;}
		void set_mo(const char *);
		bool operator==(const Auto &)const;
		bool operator!=(const Auto &)const;
		bool operator>(const Auto &)const;
		bool operator<(const Auto &)const;
		virtual float CalcolaPedaggio()const;
};
}
#endif
