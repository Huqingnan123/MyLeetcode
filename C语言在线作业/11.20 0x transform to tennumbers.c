#include <stdio.h>
#define BASE 16
int main(void)
{
	int N,i,j,num=0;
	char c,s[1000];
	scanf("%d", &N);
	while ((c = getchar()) != '\n')
		continue;
	for (i = 1; i <= N; i++)
	{
		fgets(s, 1000, stdin);
		for (j =2;s[j] != '\n'; j++)
		{
			if(s[j]<58)
				num = num * BASE + s[j] - '0';
			if(s[j]>64&&s[j]<97)
				num = num * BASE + s[j] - 55;
			if(s[j]>96)
				num = num * BASE + s[j] - 87;
		}
		printf("%d\n", num);
		num = 0;
	}
	return 0;
}