#include <stdio.h>
void SWAP(int u[], int k,int n);
int main(void)
{
	int u[60], n,k,i;
	while (scanf("%d %d", &n, &k) == 2)
	{
		for (i = 0; i <= n - 1; i++)
		{
			scanf("%d", &u[i]);
			if (u[i] == EOF)
				return 0;
		}
		SWAP(u, k, n);
		for (i = 0; i <= n - 1; i++)
		{
			if (i != n - 1)
				printf("%d ", u[i]);
			else
				printf("%d\n", u[i]);
		}
	}
	return 0;
}
void SWAP(int u[], int k,int n)
{
	int i,temp,j;
	for (i = 0; i < k; i++)              //һ������k����λ��ÿ�ζ��ѵ�һ��Ԫ�طŵ�����棬�����Ԫ�ض���ǰ��һλ
	{
		temp = u[0];
		for (j = 1; j <= n - 1; j++)
			u[j - 1] = u[j];
		u[n - 1] = temp;
	}
}
