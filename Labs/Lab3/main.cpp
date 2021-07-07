#include <iostream>

#include "lavoratore.h"
#include "dirigente.h"
#include "dipendente.h"
using namespace Mynamespace;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

int main(int argc, char** argv) {
	//per eseguire i test seguenti rendere la classe Lavoratore concreta
	/*Lavoratore l("N46/009876", "UNINA", 2004);
	cout<<l<<endl;*/
	
	/*Lavoratore l1;
	cout<<l1<<endl;
	cin>>l1;
	cout<<l1<<endl;*/
	
	/*cout<<"TEST cc di copia\n";
	Lavoratore Lcopied(l);
	cout<<Lcopied<<endl;
	Lcopied.setMatricola("N46/098765");
	Lcopied.setAzienda("UNINA2");
	Lcopied.setAnnoAssunzione(1999);
	cout<<Lcopied<<endl;*/
	
	/*cout<<"TEST op di assegnazione\n";
	Lavoratore Lassigned = l;
	cout<<Lassigned<<endl;
	Lassigned.setMatricola("N64/123456");
	Lassigned.setAzienda("UNI-NA");
	Lassigned.setAnnoAssunzione(2010);
	cout<<Lassigned<<endl;*/
	
	/*cout<<"TEST metodi\n";
	l.setMatricola("A098/988")
	cout<<l<<endl;
	l.setMatricola("A09/898888")
	cout<<l<<endl;
	cout<<l.getAzienda()<<endl;
	cout<<l.getMatricola()<<endl;
	l.setAnnoAssunzione(2015);
	cout<<l.getAnnoAssunzione()<<endl;
	cout<<l<<endl;*/
	
	/*Dirigente d("N46/009876", "UNINA", 2004);
	cout<<d<<endl;*/
	
	/*Dirigente d1, d2;
	cin>>d1;
	cin>>d2;
	cout<<d1<<endl;
	cout<<d2<<endl;*/
	
	/*cout<<"TEST cc di copia\n";
	Dirigente Dcopied(d);
	cout<<Dcopied<<endl;
	Dcopied.setMatricola("N46/098765");
	Dcopied.setAzienda("UNINA2");
	Dcopied.setAnnoAssunzione(1999);
	cout<<Dcopied<<endl;*/
	
	/*cout<<"TEST op di assegnazione\n";
	Dirigente Dassigned = d;
	cout<<Dassigned<<endl;
	Dassigned.setMatricola("N64/123456");
	Dassigned.setAzienda("UNI-NA");
	Dassigned.setAnnoAssunzione(2010);
	cout<<Dassigned<<endl;*/
	
	//binding statici
	Dipendente dip("N46/009876", "UNINA", "tecnico", 2004);
	cout<<dip<<endl;
	cout << "stipendio dipendente:" << dip.calcolaStipendio() << endl;
	Dirigente dir("N46/009876", "UNINA", 2004);
	cout<<dir<<endl;
	cout << "stipendio dirigente:" << dir.calcolaStipendio() << endl;
	
	
	Lavoratore *ptr1 = new Dipendente("N46/009876", "UNINA", "tecnico", 2004); //puntatore a lavoratore "inizializzato" come dipendente 
	cout<<*ptr1;
	cout << ", stipendio dipendente:" << ptr1->calcolaStipendio() << endl;
	Lavoratore *ptr2 = new Dirigente("N46/009877", "UNINA", 2004);
	cout<<*ptr2;
	cout << ", stipendio dirigente:" << ptr2->calcolaStipendio() << endl;
	
	
	
	
	/*cout<<"TEST cc di copia\n";
	Dipendente Dcopied(dip);
	cout<<Dcopied<<endl;
	Dcopied.setMatricola("N46/098765");
	Dcopied.setAzienda("UNINA2");
	Dcopied.setAnnoAssunzione(1999);
	cout<<Dcopied<<endl;*/
	
	/*cout<<"TEST op di assegnazione\n";
	Dipendente Dassigned = dip;
	cout<<Dassigned<<endl;
	Dassigned.setMatricola("N64/123456");
	Dassigned.setAzienda("UNI-NA");
	Dassigned.setAnnoAssunzione(2010);
	cout<<Dassigned<<endl;*/
	
	return 0;
}
