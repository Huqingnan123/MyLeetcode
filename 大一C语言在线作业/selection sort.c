#include <stdio.h>
void SelectionSort(int a[], int length);        //参数传址
int main(void)
{
	int a[1024], length;
	printf("Please tell me how many numbers (<=1024) you want to sort:");
	scanf("%d", &length);
	printf("Please input %d intergers:\n", length);      //表示对length个数进行排序，下标从0到length-1
	for (int i = 0; i <= length - 1; i++)
		scanf("%d", &a[i]);    
	SelectionSort(a, length);     //括号内单独一个a,将length的值传递给之后的形参，a是“数组名”，相当于一个指针，指向a[10]这个数组
	for (int i = 0; i <= length - 1; i++)
		printf("%d ", a[i]);
	return 0;
}
void SelectionSort(int a[], int length)
{
	for (int i = 0; i < length - 1; i++)          //从前到后循环，每一次都把之后所剩最小的数交换到现在的位置，一次循环不是作一次交换，就是不交换！！！
	{
		int min=i, j, temp;     //先让目前未排序序列的第一个数a[i]作为min值
		for (j = i + 1; j <= length-1 ; j++)   
		{
			if(a[j]<a[min])
				min = j;           //依次检索，标记出序列中最小的数为a[min],让之后的数再与a[min]比较大小，比完一轮后，最终找到a[i]之后的"最小数"与a[i]换位置   
		}
		temp = a[i];
		a[i] = a[min];         //min代表最小的那个数
		a[min] = temp;
	}
}        //若不是返回值void型，还应加个return某某值！！！

