//	直接插入排序（边插入边排序，最先将第一个元素当作有序表，后面元素依次插入排序）
//	将下标0位置当作哨兵

void InsertSort(SqList *L)
{
	int i, j;

	for(i = 2; i <= L->length; i++)
	{
		if(L->r[i].key < L->r[i - 1].key)	//	若 < 才需要插入
		{
			L->r[0] = L->r[i];	//	复制为哨兵

			for(j = i - 1; L->r[0].key < L->r[j].key; j--)
			{
				L->r[j + 1] = L->r[j];
			}

			L->r[j + 1] = L->r[0];
		}
	}
}



//	折半插入排序（前一部分相当于有序表，可使用二分法）
void BiInsertSort(SqList *L)
{
	int i, j;
	int low, high, mid;

	for(i = 2; i <= L->length; i++)
	{
		L->r[0] = L->r[i];

		low = 1;
		high = i - 1;

		while(low <= high)	//	二分法查找插入位置
		{
			mid = (low + high) / 2;

			if(L->r[0].key < L->r[mid].key) high = mid - 1;
			else low = mid + 1;
		}//	循环结束，high+1为插入位置

		for(j = i - 1; j >= high + 1; j--) L->r[j + 1] = L->r[j];

		L->r[high + 1] = L->r[0];
	}
}


//	希尔排序
void ShellInsert(SqList *L, int dk)
{
	int i, j;

	//	dk为步长
	for(i = dk + 1; i <= L->length; i++)
	{
		if(L->r[i].key < L->r[i - dk].key)
		{
			L->r[0] = L->r[i];

			for(j = i - dk; j > 0 && L->r[0].key < L->r[j].key; j -= dk)
			{
				L->r[j + dk] = L->r[j];
			}

			L->r[j + dk] = L->r[0];
		}
	}
}

void ShellSort(SqList *L, int dlta[], int t)	//	最后一个增量值必须为1，且除了1之外没有公因子
{
	//	按增量序列dlta[0~t-1]对顺序表L作希尔排序
	for(int k = 0; k < t; k++)
	{
		ShellInsert(L, dlta[k]);	//	一趟增量为dlta[k]的插入排序
	}
}
