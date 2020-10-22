#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mycpy(char s[], char t[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		s[i] = t[i];
	s[i] = '\0';
}

int main()
{
	int i, N, n;
	char s[10000], t[10000];
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++)
	{
		fgets(t, 10000, stdin);
		scanf("%d", &n); 
		getchar();
		mycpy(s, t, n);
		printf("%s\n", s);
	}
	return 0;
}
