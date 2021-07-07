/*14:12:30
Si realizzi in linguaggio C++ mediante il costrutto class del linguaggio una Coda di brani musicali. 
A tale scopo si realizzi:
1)	la classe Brano che ha le seguenti variabili membro:

"	Titolo: stringa (usare la libreria string del C++)
"	ID: numero intero
"	Durata: numero reale, rappresentante la durata del brano espresso in minuti

Si implementino per la classe Brano le funzioni di accesso per ciascuna variabile membro (get) 
e l'overloading degli operatori di flusso << e >>.

2)	La classe Coda implementa una coda circolare rappresentata mediante vettore allocato 
dinamicamente (variante: mediante una lista concatenata a puntatori) e fornisce le consuete 
funzionalità per la gestione FIFO degli elementi. 

Si realizzi quindi un modulo utente che effettua il test delle due classi ed inoltre implementa le seguenti operazioni:
-	Svuota una coda stampando i dati degli elementi estratti su file di tipo testo;
-	Inserisce brani in una coda leggendo dal file di tipo testo prima generato. A tale scopo 
si definisca la funzione bool inserisci_da_file(const char * filename, Coda & C) throw (bad_mode &) 
che -fornito in ingresso il nome del file- inserisce gli elementi nell'oggetto C. La funzione lancia 
una eccezione di tipo bad_mode (fornita dallo studente) se l'operazione di apertura del file non va a 
buon fine, ed inoltre restituisce un valore booleano per segnalare all'utente l'impossibilità di introdurre 
in coda tutti gli elementi presenti nel file quando la coda dovesse risultare piena. 
 
Si strutturi il codice dell'intera applicazione (programma principale e classe) secondo 
le appropriate tecniche di programmazione modulare (illustrate al corso e nei testi adottati).
*/
