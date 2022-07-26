list_order:main.o InitList.o DestroyList.o ListInsert.o ListDelete.o GetElem.o GetLength.o ClearList.o ListEmpty.o LocateElem.o
	gcc -o list_order main.o InitList.o DestroyList.o ListInsert.o ListDelete.o GetElem.o GetLength.o ClearList.o ListEmpty.o LocateElem.o
 
main.o:
	gcc -c main.c -o main.o

InitList.o:
	gcc -c InitList.c -o InitList.o

DestroyList.o:
	gcc -c DestroyList.c -o DestroyList.o

ListInsert.o:
	gcc -c ListInsert.c -o ListInsert.o

ListDelete.o:
	gcc -c ListDelete.c -o ListDelete.o

GetElem.o:
	gcc -c GetElem.c -o GetElem.o

GetLength.o:
	gcc -c GetLength.c -o GetLength.o

ClearList.o:
	gcc -c ClearList.c -o ClearList.o

ListEmpty.o:
	gcc -c ListEmpty.c -o ListEmpty.o

LocateElem.o:
	gcc -c LocateElem.c -o LocateElem.o

.PHONY:rm
rm:
	sudo rm list_order *.o
