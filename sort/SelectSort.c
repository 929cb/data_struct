//	选择排序
void SelectSort(SqList *L)
{
	int i, j, min;

	for(i = 0; i < L->length - 1; i++)
	{
		min = i;

		for(j = i + 1; j < L->length; j++)
		{
			if(L->r[min].key > L->r[j].key) min = j;
		}

		if(min != i) 
		{
			int t = L->r[min].key;
			L->r[min].key = L->r[i].key;
			L->r[i].key = t;
		}
	}
}


//	堆排序
void HeapAdjust(elem R[], int s, int m)	//	s为根结点下标，m为数组最大下标
{
	rc = R[s];

	for(j = 2 * s; j <= m; j *= 2)	//	j为s的左孩子下标
	{
		if(j < m && R[j] > R[j + 1]) ++j;	//	小根堆

		if(rc <= R[j]) break;

		R[s] = R[j];
		s = j;
	}

	R[s] = rc;
}

void HeapSort(elem R[])	//	对R[1~n]进行堆排序
{
	int i;
	
	for(i = n / 2; i >= 1; i--)	//	n/2为最后一个非叶子节点
	{
		HeapAdjust(R, i, n);	//	建立初始堆
	}

	for(i = n; i > 1; i--)	//	进行n-1趟排序
	{
		Swap(R[1], R[i]);	//	根与最后一个元素交换
		HeapAdjust(R, 1, i - 1);	//	对R[1 ~ i-1]重新建堆
	}
}
