#include <stdio.h>
int sum(int x);                 //����һ������λ���ĺ�
int Caculator(int a,int b);     //�����������������ɵĵ���
int main(void)
{
	int a, b, N, i,point_sum_old,point_sum_new;       //�ֱ��Ϊ��һ��ԭʼ������֮��ĸ��µĵ���
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &a, &b);
		point_sum_old =Caculator(a, b);
		if (point_sum_old == 7 || point_sum_old == 11)
		{
			printf("success!\n");         
			continue;      //�����һ�ξ�success��һ��Ҫcontinue��i��һ��������һ��ѭ����������һ��a��b        (�����ֻ���������else���ظ��������Ϊelseֻ�����һ��if��ԣ���������
		}
		if(point_sum_old == 2 || point_sum_old == 3 || point_sum_old == 12)
			printf("fail!\n");  //�����һ�ξ�fail�����Զ�������һ������
		else                       
		{                        
			do
			{
				point_sum_new = Caculator(++a, ++b);
				if (point_sum_new == point_sum_old)
				{
					printf("success!\n");
					break;                           //����ѭ��������ѭ���������
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