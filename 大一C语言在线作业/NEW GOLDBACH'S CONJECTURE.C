#include <stdio.h>
int Pri(int x);
int main(void)
{
	int i, k,BEGIN,END;
	while (scanf("%d %d", &BEGIN, &END)==2)    //当输入三个EOF时跳出循环
	{
		if (BEGIN % 2 != 0)
			BEGIN += 1;                      //使成为偶数
		for (i = BEGIN; i <= END; i+=2)
		{
			for (k = 2; k <= i; k++)
			{
				Pri(k);
				Pri(i - k);
				if (Pri(k) == 1 && Pri(i - k) == 1)
				{
					printf("%d=%d+%d\n", i, k, i - k);
					break;
				}
				else
					continue;
			}
		}
		printf("\n");
	}
}
int Pri(int x)
{
	int i;
	for (i = 2; i <= x; i++)
	{
		if (i >= x)
			return 1;
		if (x%i != 0)
			continue;
		else
			break;
	}
}