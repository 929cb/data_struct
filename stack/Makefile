stack:main.o InitStack.o DestroyStack.o GetTop.o StackLength.o ClearStack.o StackEmpty.o Push.o Pop.o
	gcc -o stack main.o InitStack.o DestroyStack.o GetTop.o StackLength.o ClearStack.o StackEmpty.o Push.o Pop.o
 
main.o:
	gcc -c main.c -o main.o

InitStack.o:
	gcc -c InitStack.c -o InitStack.o

DestroyStack.o:
	gcc -c DestroyStack.c -o DestroyStack.o

Push.o:
	gcc -c Push.c -o Push.o

Pop.o:
	gcc -c Pop.c -o Pop.o

GetTop.o:
	gcc -c GetTop.c -o GetTop.o

StackLength.o:
	gcc -c StackLength.c -o StackLength.o

ClearStack.o:
	gcc -c ClearStack.c -o ClearStack.o

StackEmpty.o:
	gcc -c StackEmpty.c -o StackEmpty.o

.PHONY:rm
rm:
	sudo rm stack *.o
