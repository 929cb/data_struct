#include <assert.h>
#include <stdio.h>

int my_strlen(const char* str)
{
	assert(str);

	int count = 0;
	
	while(*str++) count++;

	return count;
}

char* my_strcpy(char* dest, const char* src)
{
	assert(dest && src);

	char* str = dest;

	while(*str++ = *src++);

	return dest;
}

char* my_strncat(char* dest, const char* src, int count)
{
	assert(dest && src);

	char *temp = dest;

	while(*temp++);

	temp--;

	while((*temp++ = *src++) && --count);

	if(count <= 0) *temp = '\0';

	return dest;
}

int my_strncmp(const char* dest, const char* src, int count)
{
	assert(dest && src);

	if(!count) return 0;

	while(*dest == *src)
	{
		if(--count == 0 || *dest == '\0' && *src == '\0') return 0;
		
		dest++;
		src++;
	}

	return (*dest - *src);
}

char* my_strstr(const char* dest, const char* src)
{
	assert(dest && src);

	if(*src == '\0') return ((char*)dest);

	const char* d = dest;
	const char* s = src;
	const char* res = dest;

	while(*dest && *src)
	{
		if(*dest == *src)
		{
			dest++;
			src++;
		}
		else
		{
			src = s;
			dest = ++d;
		}
	}

	if(*src == '\0')
	{
		int temp = src - s; 
		int offset = dest - res - temp;
		return (char*)(res + offset);
	}
	else return NULL;
}

char* my_strtok(char* dest, const char* src)
{
	assert(src);

	char* res = NULL;
	static char* reserve = NULL;
	static int count = 0;
	static int dest_len = 0;
	int src_len = 0;
#if 0
	if(dest)
	{
		dest_len = my_strlen(dest);
		src_len = my_strlen(src);
		res = dest;

		for(; *dest; dest++)
		{
			for(int i = 0; i < src_len; i++)
			{
				if(i == 0) count++;

				if(*dest == *(src + i))
				{
					*dest = '\0';
					reserve = dest;
					return res;
				}
			}
		}
	}
	else
	{
		res = reserve + 1;
		dest = res;
		src_len = my_strlen(src);

		for(; *dest; dest++)
		{
			for(int i = 0; i < src_len; i++)
			{
				if(i == 0) count++;

				if(*dest == *(src + i))
				{
					*dest = '\0';
					reserve = dest;
					return res;
				}
			}
		}
	}
#endif

	if(dest)
	{
		dest_len = my_strlen(dest);
		src_len = my_strlen(src);
		res = dest;
	}
	else
	{
		res = reserve + 1;
		dest = res;
		src_len = my_strlen(src);
	}

	for(; *dest; dest++)
	{
		for(int i = 0; i < src_len; i++)
		{
			if(i == 0) count++;

			if(*dest == *(src + i))
			{
				*dest = '\0';
				reserve = dest;
				return res;
			}
		}
	}
	

	if(count > dest_len) return NULL;

	return res;
}


void* my_memcpy(void* dest, const void* src, int n)
{
	assert(dest && src);

	void* res = dest;

	if(src < dest)	//	额外实现了memmove解决地址相叠的问题
	{
		// (dest) += (n - 1);
		// (src) += (n - 1);

		while(n--) *((char*)dest + n) = *((char*)src + n);
	}
	else
		while(n--) *((char*)dest++) = *(char*)src++;

	return res;
}

int my_memcmp(const void* dest, const void* src, int n)
{
	assert(dest && src);

	while(*(char*)dest == *(char*)src)
	{
		if(--n == 0) return 0;

		(char*)dest++;
		(char*)src++;
	}

	return (*(char*)dest - *(char*)src);
}

void* my_memset(void* dest, int c, int n)
{
	assert(dest);

	void* res = dest;

	while(n--)
	{
		*(char*)dest++ = (char)c;
	}

	return res;
}


int main()
{
#if 0
	char* p1 = "abcdefabcdef";
	char* p2 = "";

	char* p = my_strstr(p1, p2);
	
	printf("%s", p);

#else

	char* ch = "123@qq.com";
	char* split = ".@q";
	char buf[my_strlen(ch) + 1];
	
	my_strcpy(buf, ch);

	char* str = NULL;
	for(str = my_strtok(buf, split); str; str = my_strtok(NULL, split))
		if(*str) printf("%s\n", str);
		
#endif

	int arr1[] = {65531, 65532, 65533, 65534, 65535};
	int arr2[5] = {0};

	my_memcpy(arr1 + 2, arr1, 12);
	//my_memcpy(arr2, arr1, sizeof(arr1));
	for(int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
		printf("%d\n", arr1[i]);


	int n1[] = {1, 2, 3};
	int n2[] = {1, 2, 5};

	int res = my_memcmp(n1, n2, 9);
	printf("%d\n", res);


	char c[10] = "";

	my_memset(c, '1', sizeof(c));
	printf("%s\n", c);


	return 0;
}
