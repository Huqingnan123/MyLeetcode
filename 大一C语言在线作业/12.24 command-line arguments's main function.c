#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define n 6
void UpShell_Sort(int *p);
void LowShell_Sort(int *p);
/*��������Ϊ��program str1 str2 str3 str4 str5
����programΪ�ļ�����Ҳ����һ����program.c�����롢���Ӻ����ɵĿ�ִ���ļ�program.exe��������5��������
��main()������˵�����Ĳ���argc��¼��������������������ĸ�������6��*/
int main(int argc, char *argv[])
{
	int i, x[n];
	for (i = 0; i < n; i++)
		scanf("%d", x + i);
	if (argc > 1)
	{
		if (strcmp(argv[1], "-d") == 0)     //��������-d,��argv[1]ָ��-d
			LowShell_Sort(x);
	}
	else
		UpShell_Sort(x);
	for (i = 0; i < n; i++)
		printf("%d ", *(x + i));
	printf("\n");
	return 0;
}
void UpShell_Sort(int *p)/*����ϣ����������,����gap=n/2���з�����в������������м򵥵Ĳ�������*/
{
	int gap, i, j, t;
	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)  //x[gap]�ǵ�һ���еĵڶ���Ԫ�أ���ʼ����������������󣬶���֮��x[gap+1]�ڵڶ����ڽ���ͬ������
		{
			t = *(p + i);
			for (j = i - gap; j >= 0 && *(p + j) > t; j -= gap)
				*(p + j + gap) = *(p + j);
			*(p + j + gap) = t;
		}
}
void LowShell_Sort(int *p)/*����ϣ����������*/
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
