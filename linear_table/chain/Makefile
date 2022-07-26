list_chain:main.o InitList.o DestroyList.o ListInsert.o ListDelete.o GetElem.o GetLength.o ClearList.o ListEmpty.o LocateElem.o CreateList_H.o CreateList_R.o
	gcc -o list_chain main.o InitList.o DestroyList.o ListInsert.o ListDelete.o GetElem.o GetLength.o ClearList.o ListEmpty.o LocateElem.o CreateList_H.o CreateList_R.o
 
main.o:
	gcc -c main.c -o main.o

InitList.o:
	gcc -c InitList_L.c -o InitList.o

DestroyList.o:
	gcc -c DestroyList_L.c -o DestroyList.o

ListInsert.o:
	gcc -c ListInsert_L.c -o ListInsert.o

ListDelete.o:
	gcc -c ListDelete_L.c -o ListDelete.o

GetElem.o:
	gcc -c GetElem_L.c -o GetElem.o

GetLength.o:
	gcc -c ListLength_L.c -o GetLength.o

ClearList.o:
	gcc -c ClearList.c -o ClearList.o

ListEmpty.o:
	gcc -c IsEmpty.c -o ListEmpty.o

LocateElem.o:
	gcc -c LocateElem_L.c -o LocateElem.o

CreateList_H.o:
	gcc -c CreateList_H.c -o CreateList_H.o

CreateList_R.o:
	gcc -c CreateList_R.c -o CreateList_R.o

.PHONY:rm
rm:
	sudo rm list_chain *.o
