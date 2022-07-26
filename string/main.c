#include "main.h"

int main()
{
	SString S = {"abcbacbda", 9};
	SString T = {"cbd", 3};
  
	printf("%d\n", index_BF(S, T));

	return 0;
}
