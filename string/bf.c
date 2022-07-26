#include "main.h"

/*	暴力匹配：O(n*m)
 *		将主串的第pos个字符和模式串的第一个字符比较：
 *			若相等，继续逐个比较后续的字符；
 *			若不等，从主串的下一个字符起，重新与模式串的第一个字符比较。
 *		(找到返回下标，否则返回-1)
 **/
int index_BF(SString S, SString T)
{
	int i = 0, j = 0;

	while(i < S.length && j < T.length)
	{
		if(S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}

	if(j >= T.length) return (i - j);
	else return -1;
}

