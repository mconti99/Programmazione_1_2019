#include "Magazzino.h"

int main(int argc, char *argv[])
{
/*Prodotto c1;
Prodotto c2("A1","Tavolo",4);
Prodotto c3=c2; 
c2.Visualizza_DatiProdotto();
cout <<"Inserisci dati prodotto"<<endl;
c1.Inserisci_DatiProdotto();
c1.Visualizza_DatiProdotto();
c1.set_Q(19);
c1.set_Des("Poltrona");
c1.Visualizza_DatiProdotto();
*/

Magazzino m1;
Magazzino m2(2);
m1.Inserisci_Dati_Magazzino();
m2.Inserisci_Dati_Magazzino();
int p=0;
int x=0;
m1.Cerca_Prodotto("mamma",p);
if(p!=-1) cout<<"la posizione di mamma e' "<<p<<endl;
else cout <<"la stringa mamma non e' presente"<<endl;
m2.Cerca_Prodotto("aaaaa",x);
if(x!=-1) cout<<"la posizione di aaaa e' "<<x<<endl;
else cout <<"la stringa aaaa non e' presente :("<<endl;
m1.Elimina_Prodotto(p);
m1.Visualizza_Magazzino();
m2.Visualizza_Magazzino();
system("PAUSE");
m2.Stampa_StatoMagazzino();

system("PAUSE");
return 0;
}

