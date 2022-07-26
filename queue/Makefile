queue:main.o InitQueue.o DestroyQueue.o GetHead.o QueueLength.o ClearQueue.o EnQueue.o DeQueue.o
	gcc -o queue main.o InitQueue.o DestroyQueue.o GetHead.o QueueLength.o ClearQueue.o EnQueue.o DeQueue.o
 
main.o:
	gcc -c main.c -o main.o

InitQueue.o:
	gcc -c InitQueue.c -o InitQueue.o

DestroyQueue.o:
	gcc -c DestroyQueue.c -o DestroyQueue.o

EnQueue.o:
	gcc -c EnQueue.c -o EnQueue.o

DeQueue.o:
	gcc -c DeQueue.c -o DeQueue.o

GetHead.o:
	gcc -c GetHead.c -o GetHead.o

QueueLength.o:
	gcc -c QueueLength.c -o QueueLength.o

ClearQueue.o:
	gcc -c ClearQueue.c -o ClearQueue.o

.PHONY:rm
rm:
	sudo rm queue *.o
