#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define n 6
void UpShell_Sort(int *p);
void LowShell_Sort(int *p);
/*设命令行为：program str1 str2 str3 str4 str5
其中program为文件名，也就是一个由program.c经编译、链接后生成的可执行文件program.exe，其后各跟5个参数。
对main()函数来说，它的参数argc记录了命令行中命令与参数的个数，共6个*/
int main(int argc, char *argv[])
{
	int i, x[n];
	for (i = 0; i < n; i++)
		scanf("%d", x + i);
	if (argc > 1)
	{
		if (strcmp(argv[1], "-d") == 0)     //若输入了-d,则argv[1]指向-d
			LowShell_Sort(x);
	}
	else
		UpShell_Sort(x);
	for (i = 0; i < n; i++)
		printf("%d ", *(x + i));
	printf("\n");
	return 0;
}
void UpShell_Sort(int *p)/*采用希尔升序排序,采用gap=n/2进行分组进行插入排序，最后进行简单的插入排序*/
{
	int gap, i, j, t;
	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)  //x[gap]是第一组中的第二个元素，开始在组内排序，它排完后，对它之后x[gap+1]在第二组内进行同样操作
		{
			t = *(p + i);
			for (j = i - gap; j >= 0 && *(p + j) > t; j -= gap)
				*(p + j + gap) = *(p + j);
			*(p + j + gap) = t;
		}
}
void LowShell_Sort(int *p)/*采用希尔降序排序*/
{
	int gap, i, j, t;
	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
		{
			t = *(p + i);
			for (j = i - gap; j >= 0 && *(p + j) < t; j -= gap)
				*(p + j + gap) = *(p + j);
			*(p + j + gap) = t;
		}
}
