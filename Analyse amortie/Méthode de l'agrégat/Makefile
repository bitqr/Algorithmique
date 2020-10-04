all : multidep incrementer

Incrémenter.o : Incrémenter.c
	gcc -c Incrémenter.c

incrementer : Incrémenter.o
	gcc Incrémenter.o -o incrementer

Multidép.o : Multidép.c
	gcc -c Multidép.c

multidep : Multidép.o
	gcc Multidép.o -o multidep

clean : 
	rm -rf *.o multidep incrementer


