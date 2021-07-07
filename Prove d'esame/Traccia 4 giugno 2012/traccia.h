/*
20.43
Testo della prova
Si realizzi in C++ una gerarchia Manoscritto, Lettera. la classe Manoscritto è rappresenta 
un documento in formato elettronico, e può essere specializzato in una lettera. La classe 
Manoscritto contiene le seguenti variabili membro:
-	Codice, identificativo numerico (intero)
-	Autore (stringa allocata dinamicamente)
-	numpag, numero intero, numero di pagine
-	Formato, stringa allocata dinamicamente, formato del file

La classe Lettera aggiunge le variabili membro:
-	Mittente, stringa allocata dinamicamente
-	Desrinatario, stringa allocata dinamicamente

Le classi devono prevedere gli opportuni costruttori, e devono gestire correttamente 
l'estensione dinamica fornendo le opportune funzionalità. Devono inoltre fornire le funzioni 
visualizza_dati e memorizza_dati. Si vuole un comportamento polimorfo. Si realizzi quindi una 
classe Elenco di manoscritti. La sessione di scrittura su file viene gestita dall'elenco mediante 
una sua opportuna funzione membro che definisce la variabile di tipo stream. La funzione memorizza_dati
 si limita a riceverla come parametro di ingresso. L'Elenco è realizzato ricorrendo ad un vettore allocato 
 staticamente. La funzione di inserimento inserisce un manoscritto in ordine (rispetto al codice) e lancia 
 una eccezione nel caso il codice sia già presente nell'elenco, la funzione di eliminazione elimina effettuando
  una ricerca per codice. L'eccezione è di tipo Duplicato, classe fornita dallo studente.
Si strutturi il codice secondo le appropriate tecniche di programmazione modulare illustrate durante il corso 
e nei libri di testo adottati.
*/

