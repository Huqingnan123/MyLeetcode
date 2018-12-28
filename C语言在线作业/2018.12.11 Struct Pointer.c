#include <stdio.h>
struct Student {
	int num;
	char name[19];
	double score;
}s[3], *p = &s[0];
int main(void)
{
	int N, i, j, point;
	scanf("%d", &N);
	getchar();
	for (i = 0; i <= N - 1; i++)
	{
		for (j = 0; j <= 2; j++)
			scanf("%d %s %lf", &s[j].num, s[j].name, &s[j].score);
		for (j = 0; j <= 2; j++)
			printf("%d\t%-20s%lf\n", s[j].num, s[j].name, s[j].score);
		for (point = 0; point <= 2; point++)
			printf("%d\t%-20s%lf\n", (p + point)->num, (p + point)->name, (p + point)->score);
	}
	return 0;
}

