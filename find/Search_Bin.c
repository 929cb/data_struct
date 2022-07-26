#include "main.h"

int Search_Bin(SSTable ST, KeyType key)
{
	int mid, low = 1, high = ST.len;

	while(low <= high)
	{
		mid = (low + high) / 2;

		if(ST.R[mid].key == key) return mid;
		else if(ST.R[mid] > key) high = mid - 1;
		else low = mid + 1;
	}

	return 0;
}

int Search_Bin(SSTable ST, KeyType key, int low, int high)
{
	if(low > high) return 0;

	int mid = (low + high) / 2;
	
	if(ST.R[mid].key == key) return mid;
	else if(ST.R[mid].key > key) return Search_Bin(ST, key, low, mid - 1);
	else return Search_Bin(ST, key, mid + 1, high);
}
