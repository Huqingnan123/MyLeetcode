#include <stdio.h>
#include <limits.h>
int Caculator(unsigned long long n, int k);
int main(void)
{
	unsigned long long n;
	int k,number;
	printf("%d\n", sizeof(unsigned long long)*CHAR_BIT);              //������λ
	while ((scanf("%llu %d", &n, &k) == 2) && n >= 1 && n <= 4294967293)     //  llu��unsigned long long����
	{
		number=Caculator(n, k);
		printf("%d\n", number);
	}
	return 0;
}
int Caculator(unsigned long long n, int k)
{
	unsigned long long i = n;
	int number;        //i���ݴ�nֵ��number��ʾ��kλ��
	int count = 0;       //count����n��λ��
	do
	{
		count++;        //��һ��ѭ��count�ͼ�1����������n�Ƕ��٣�������һλ��������n��λ��!
		i /= 10;
	} while (i > 0);    //һ��nλ�����Խ���ѭ��n�Σ������n-1λ���Ͽ�ʼһ�������ĵ�1�Σ�
	if (k > count)
		return -1;
	if (k <= count)
	{
		for (i = 1; i <= k - 1; i++)       //һֱȡ����ȥ��kλ�ұߵ���������k-1��
		{
			n /= 10;                  
		}
		number = n % 10;                   //ȡ����kλ
		return number;
	}
}