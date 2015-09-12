fqBaseSum : fqBaseSum.c kseq.h
	gcc -lz fqBaseSum.c -o fqBaseSum
clean : 
	rm fqBaseSum
