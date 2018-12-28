#include <stdio.h>
void insertSort(int a[], int length);        //参数传址
int main(void)
{
	int a[1024],length;
	printf("Please tell me how many numbers (<=1024) you want to sort:");
	scanf("%d", &length);
	printf("Please input %d intergers:\n", length);      //表示对length个数进行排序，下标从0到length-1
	for (int i = 0; i <= length-1; i++)
		scanf("%d", &a[i]);    //注意！！！括号内单独一个 a！！！
	insertSort(a, length);     //将a和length的值传递给之后的形参！      a是“数组名”，相当于一个指针，指向a[10]这个数组！！！
	for (int i = 0; i <= length-1; i++)
		printf("%d ", a[i]);
	return 0;
}
void insertSort(int a[], int length)
{
	for (int i = 1; i <= length-1; i++)
	{
		int temp, j;
		temp = a[i];         //从一列乱序数的第二个开始进行慢慢排序
		for (j = i - 1; j >= 0 && a[j] > temp; j--)    //将之前都检索一遍，若遇到较小或相等的数，停止检索（因为前面已经排好了的）
		{
			a[j + 1] = a[j];    //当碰到较大数时，将较大数向后移一位
		}
		a[j + 1] = temp;       // j多减了一个1后跳出了循环，说明此时的j=-1或者a[j]<=temp,则现在可以停止操作，将所进行比较的temp值放在现在a[j]所在的后一位
	}
}        //若不是返回值void型，还应加个return某某值！！！

