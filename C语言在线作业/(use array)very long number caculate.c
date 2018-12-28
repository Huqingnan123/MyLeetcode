#include <stdio.h>
#include <ctype.h>
#define N 40                    //最多可以达到四十位数
void shift(int *num, int i);    //也可以少于四十位数，自动最低位对齐的函数,并且会自动补0 
int main(void)
{
	int num1[N], num2[N], Addnum[N + 1];
	int i, carry = 0;
	for (i = 0; i <= N; i++)
		*(Addnum + i) = 0;       //将和的数组初始化为0
	for (i = N - 1; i >= 0 && isdigit(*(num1 + i) = getchar()); i--)
		*(num1 + i) -= '0';
	if (i >= 0)
		shift(num1, i);          //若此，说明最后一个数字只放到了i+1的下标位置处
	for (i = N - 1; i >= 0 && isdigit(*(num2 + i) = getchar()); i--)
		*(num2 + i) -= '0';
	if (i >= 0)
		shift(num2, i);
	for (i = 0; i <= N - 1; i++)
	{
		*(Addnum + i) = *(num1 + i) + *(num2 + i) + carry ;
		carry = *(Addnum + i) / 10;
		*(Addnum + i) %= 10;
		*(Addnum + i) += '0';
	}
	*(Addnum + N) = carry+'0';
	for (i = N; i >=0; i--)
	{
		if (*(Addnum + i) == '0')
			continue;
		else
			putchar(*(Addnum + i));
	}
	putchar('\n');
	return 0;
}
void shift(int *num, int i)
{
	int k,length = N - 1 - i;
	int lengthleft = N - length;
	for (k = 0; k < N - 1 - i; k++)
		*(num + k) = *(num + k + lengthleft);     //将后面的数字全部往前移
	for (k = N - 1 - i; k <= N - 1; k++)
		*(num + k) = 0;
}