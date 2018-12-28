#include <stdio.h>
#include <limits.h>
int Caculator(unsigned long long n, int k);
int main(void)
{
	unsigned long long n;
	int k,number;
	printf("%d\n", sizeof(unsigned long long)*CHAR_BIT);              //看多少位
	while ((scanf("%llu %d", &n, &k) == 2) && n >= 1 && n <= 4294967293)     //  llu是unsigned long long类型
	{
		number=Caculator(n, k);
		printf("%d\n", number);
	}
	return 0;
}
int Caculator(unsigned long long n, int k)
{
	unsigned long long i = n;
	int number;        //i来暂代n值，number表示第k位数
	int count = 0;       //count计算n的位数
	do
	{
		count++;        //进一次循环count就加1，做到不论n是多少，至少是一位数，计算n的位数!
		i /= 10;
	} while (i > 0);    //一个n位数可以进入循环n次（后面的n-1位加上开始一次无消耗的1次）
	if (k > count)
		return -1;
	if (k <= count)
	{
		for (i = 1; i <= k - 1; i++)       //一直取整除去第k位右边的数，进行k-1次
		{
			n /= 10;                  
		}
		number = n % 10;                   //取出第k位
		return number;
	}
}