#include "magazzino.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

  Magazzino M;
  int n;

  Crea_Magazzino(M,n);
  Visualizza_Magazzino(M,n);
   char C[N];

   int pos=-1;
   cout << "\n Ricerca Prodotto.";
   cout << "\n Inserire il Codice: ";
   cin.ignore();
   cin.getline(C,N);

   if(Cerca_Prodotto(M,n,C,pos)) cout << "\n Prodotto presente. Posizione: " << pos;
   else  cout << "\n Prodotto NON presente." ;
   system("PAUSE");	

   // Elimina il Prodotto in posizione pos se esiste.";
   if(Elimina_Prodotto(M,n,pos)) cout << "\n prodotto eliminato dal magazzino!";
   else cout << "\n impossibile eliminare: prodotto non presente in magazzino.";
   Visualizza_Magazzino(M,n);
   Stampa_StatoMagazzino(M,n); cout << "\n Stato salvato su file.";
   system("PAUSE");	
   return 0; 
}
