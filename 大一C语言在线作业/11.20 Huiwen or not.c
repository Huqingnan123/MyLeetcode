#include <stdio.h>
#include <string.h>
int HW(char s[],int i,int j);
int main(void)
{
	int N,i,length;
	char s[1000];
	scanf("%d", &N);
	while (getchar() != '\n')
		continue;
	for (i = 1; i <= N; i++)
	{
		fgets(s, 1000, stdin);
		length = strlen(s);     //��Ϊ������ַ������л��з����������˳���,�������һ���±���length-2
		if (HW(s, 0, length - 2) == 1)
			printf("Yes!\n");
		else
			printf("No!\n");
	}
	return 0;
}
int HW(char s[], int i, int j)
{
	if (i >= j)
		return 1;       //���һֱ���ϵ��ף��ͷ���1
	if (s[i] != s[j])
		return 0;       //�в����Ͼͷ���0
	if (s[i] == s[j])
		HW(s, i + 1, j - 1);  //����ƥ��
}