/*16:23
Si vuole realizzare un semplice programma per la gestione di posti in un parcheggio a più piani. 
Il parcheggio è costituito da un nome (oggetto di tipo string), un indirizzo (oggetto di tipo string), 
e un determinato numero di piani, che per semplicità considereremo fissato e pari a due. Ogni piano ha 
però un numero variabile di posti, che viene specificato all'atto della definizione del parcheggio.

Un piano è un oggetto istanza della propria classe, ed è costituito a sua volta da un numero di posti 
e da un vettore di record (allocato dinamicamente) rappresentante i posti disponibili. Ciascun record 
contiene un campo intero che rappresenta l'identificativo del posto e per semplicità corrisponderà alla 
posizione del record nel vettore, e da un campo booleano per specificare se il posto è libero o occupato. 
Inizialmente il vettore è inizializzato specificando tutti gli identificativi e il valore false per specificare
 che i posti sono liberi.
Per un piano deve essere possibile chiedere quanti sono i posti disponibili, assegnare un posto e  liberare 
un posto. La funzione membro che assegna il posto nel caso vi siano posti disponibili ritorna l'identificativo 
del posto assegnato, e assegna il primo posto libero sul piano. La funzione membro che libera il posto il cui 
identificativo è specificato come parametro di ingresso lancia una eccezione di tipo bad_id (classe fornita dallo s
tudente) nel caso l'identificativo sia non ammissibile (il posto su quel piano è inesistente). Non è possibile liberare 
un posto se il piano è vuoto.
Si implementino inoltre le funzionalità necessarie per la corretta gestione della estensione dinamica.

Il parcheggio deve fornire una funzione membro che restituisce il numero totale di posti liberi, una funzione
 membro che consente l'ingresso di un veicolo (cioè l'assegnazione di un piano e di un posto) se esistono posti 
 liberi riempiendo prima il primo piano e poi il secondo, e l'estrazione di un veicolo, specificando il piano e 
 l'identificativo del posto. Se la posizione specificata è inesistente, viene segnalato l'errore e l'impossibilità 
 di effettuare l'operazione.

L'utente deve poter stampare su file testo lo stato del parcheggio, nome, indirizzo, e per ciascun piano 
l'identificativo del posto e se è libero o occupato.

Stabilisce lo studente quali funzionalità realizzare nel dettaglio per implementare l'applicazione sopra 
descritta e ne fornisca il test mediante un opportuno programma utente di prova.
*/
