#include "libreria.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

Vettore V;
Complesso C;
int n;
cout << "\n Inserimento del vettore di numeri complessi.";
LeggiElementi(V,n);
cout << "\n Stampa del vettore inserito.";
StampaVettore(V,n);
cout << "\n";
cout << "\n Stampa sequenziale dei moduli nel vettore non ordinato.";
cout << "\n";
for (int i=0; i<n; i++)
  cout << moduloComplex(V[i])<< endl;
cout << "\n";
cout << "\n Ordino il vettore per moduli crescenti.";
ModuloBubbleSort(V,n);
cout << "\n Fatto.";
cout << "\n Stampa sequenziale dei moduli nel vettore ordinato.";
cout << "\n";
for (int i=0; i<n; i++)
  cout << moduloComplex(V[i])<< endl;
cout << "\n";   
system("PAUSE");
return 0;
}

