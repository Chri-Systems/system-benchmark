# System Benchmark
System Benchmark è un benchmark CLI scritto in C++ per computer e server che utilizza diversi tipi di test e calcoli
per valutare la velocità dei componenti (o, se usato come stress-test, per tenerli sotto carico)


## Test disponibili
Attualmente sono disponibili solo benchmark per CPU (single-thread e multi-thread)

In futuro verranno aggiunti altri benchmark (GPU, RAM, HDD/SSD) e stress-test


### CPU (single-thread e multi-thread)
- Integer: esegue operazioni con numeri interi
- Floating Point: esegue operazioni con numeri decimali
- Bitwise: esegue operazioni sui singoli bit dei dati
- Basic: esegue tutti i test CPU disponibili


## Utilizzo
Avviare l'eseguibile e selezionare il test da eseguire

Il risultato mostra il checksum (risultato delle operazioni del benchmark, serve solo a noi sviluppatori come debug), il tempo di esecuzione e il punteggio ottenuto 


## Stato del progetto
Il progetto è in fase alpha

Le funzionalità possono cambiare e potrebbero essere presenti bug

Il sistema di punteggio potrebbe cambiare nelle prossime versioni, essendo il progetto ancora nelle prime fasi di sviluppo


## Note
I risultati possono variare in base al sistema operativo, ai processi in background e al carico del sistema