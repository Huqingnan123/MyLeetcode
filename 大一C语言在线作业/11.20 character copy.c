#include <stdio.h>
void mycpy(char s[],char t[],int n);
int main(void)
{
	char t[1000], s[1000], c;
	int i, j , n, N;
	scanf("%d", &N);
	getchar();
	for (i = 1; i <= N; i++)
	{
		
		j = 0;
		while ((c = getchar()) != '\n')
			t[j++] = c;
		t[j] = '\0';
		scanf("%d", &n);
		getchar();
		mycpy(s, t, n);
		printf("%s\n",s);
	}
	return 0;
}
void mycpy(char s[], char t[], int n)
{
	int i;
	for (i = 0; i <= n-1; i++)
	{
		s[i] = t[i];
	}
	s[n] = '\0';
}