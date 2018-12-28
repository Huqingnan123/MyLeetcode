#include <stdio.h>
#define Swap(a,b) ((a)=(a)+(b),(b)=(a)-(b),(a)=(a)-(b))
int main(void)
{
	int a, b,k=0;
	while (scanf("%d %d", &a, &b) == 2)
	{
		k++;
		printf("Case %d:\nBefore Swap:a=%d b=%d\n", k ,a, b);
		Swap(a, b);
		printf("After Swap:a=%d b=%d\n\n", a, b);
	}
	return 0;
}