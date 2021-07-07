#ifndef _CONTO_H
#define _CONTO_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
namespace MS{
	class conto{
		string titolare;
		int numeroConto;
		float * movimenti;
		int maxMov; //serve a dimensionare il vettore
		//int m; //riempimento del vettore
/* Ogni elemento del vettore contiene 
un numero positivo o un numero  negativo che indica il contante 
versato o prelevato dal conto corrente. 
*/
		protected:
			int m;
		public:
			//costruttore senza argomenti
			explicit conto();
			//costruttore con argomenti
			conto(const string, const int, const int);
			//costruttore di copia
			conto(const conto&);
			//operatore di assegnazione
			const conto & operator=(const conto &);
			//get & set
			int get_numero()const{return numeroConto;}
			int get_riemp()const{return m;}
			void set_titolare(const string s){titolare=s;}
			void set_numero(const int numero){numeroConto=numero;}
			//funzioni specifiche
			bool prelievo(const float);
			bool versamento(const float);
			float calcolo_saldo()const;
			virtual float calcolo_spese()const =0;
			//funzioni di stampa
			ostream & stampa_saldo(ostream &)const;
			ostream & stampa_movimenti(ostream &)const;
			//distruttore
			virtual ~conto(){delete [] movimenti;}
	};
} //fine namespace
#endif
