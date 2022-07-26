//	冒泡排序
void BubbleSort(SqList *L)
{
	int i, j, flag;

	for(i = 1; i < L->length; i++)
	{
		flag = 1;
		for(j = 0; j < L->length - i; j++)
		{
			if(L->r[j].key > L->r[j + 1].key)
			{
				flag = 0;
				
				L->r[j].key += L->r[j + 1].key;
				L->r[j + 1].key = L->r[j].key - L->r[j + 1].key;
				L->r[j].key -= L->r[j + 1].key;
			}
		}

		if(flag) break;
	}
}





//	快速排序
int Partition(SqList *L, int low, int high)
{
	L->r[0] = L->r[low];
	int pivotKey = L->r[low].key;	//	将第一个元素当作哨兵，并作为中间值;	大的往右放、小的往左放

	while(low < high)
	{
		while(low < high && L->r[high].key >= pivotKey) --high;
		L->r[low] = L->r[high];

		while(low < high && L->r[low].key >= pivotKey) ++low;
		L->r[high] = L->r[low];
	}

	L->r[low] = L->r[0];

	return low;
}

void FastSort(SqList *L, int low, int high)
{
	if(low < high)
	{
		int pivot = Partition(L, low, high);	//	找中间轴

		FastSort(L, low, pivot - 1);
		FastSort(L, pivot + 1, high);
	}
}
