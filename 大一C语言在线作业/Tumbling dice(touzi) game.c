#include <stdio.h>
int sum(int x);                 //计算一个数各位数的和
int Caculator(int a,int b);     //计算两个启动数生成的点数
int main(void)
{
	int a, b, N, i,point_sum_old,point_sum_new;       //分别记为第一次原始点数和之后的更新的点数
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &a, &b);
		point_sum_old =Caculator(a, b);
		if (point_sum_old == 7 || point_sum_old == 11)
		{
			printf("success!\n");         
			continue;      //如果第一次就success，一定要continue将i加一，进行下一次循环，输入下一组a，b        (否则又会进入下面的else中重复输出，因为else只会和上一个if配对）！！！！
		}
		if(point_sum_old == 2 || point_sum_old == 3 || point_sum_old == 12)
			printf("fail!\n");  //如果第一次就fail，会自动进行下一组输入
		else                       
		{                        
			do
			{
				point_sum_new = Caculator(++a, ++b);
				if (point_sum_new == point_sum_old)
				{
					printf("success!\n");
					break;                           //跳出循环，不再循环计算点数
				}
			} while (point_sum_new != 7);
			if(point_sum_new == 7)
				printf("fail!\n");
		}
	}
	return 0;
}
int Caculator(int a, int b)
{
	int sum_a, sum_b, point_a, point_b, point_sum,k;
	sum_a = sum(a);
	sum_b = sum(b);
	point_a = 1 + sum_a % 6;
	point_b = 1 + sum_b % 6;
	k = point_a + point_b;
	return k;
}
int sum(int x)
{
	int sums = 0;
	do
	{
		sums += (x % 10);
		x /= 10;
	} while (x != 0);
	return sums;
}