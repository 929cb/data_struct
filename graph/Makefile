graph:main.o CreateUDN.o CreateUDG.o
	gcc -o graph main.o CreateUDN.o CreateUDG.o

main.o:
	gcc -c main.c -o main.o

CreateUDN.o:
	gcc -c CreateUDN.c -o CreateUDN.o

CreateUDG.o:
	gcc -c CreateUDG.c -o CreateUDG.o

.PHONY:rm
	rm *.o