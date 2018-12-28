#include <stdio.h>
struct dates {
	int year;
	int month;
	int day;
};
int Cal_day(struct dates date, int day[]);
int main(void)
{
	int days1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int days2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int N, i, j, add;
	scanf("%d", &N);
	getchar();
	struct dates date[N];       //×¢ÒâVLA£¡£¡£¡
	for (i = 0; i <= N - 1; i++)
		scanf("%d %d %d", &date[i].year, &date[i].month, &date[i].day);
	for (i = 0; i <= N - 1; i++)
	{
		if ((date[i].year % 4 == 0 && date[i].year % 100 != 0) || (date[i].year % 400 == 0))
			Cal_day(date[i], days2);
		else
			Cal_day(date[i], days1);
	}
}
int Cal_day(struct dates date, int days[])
{
	int add, j;
	for (j = 0, add = 0; j <= date.month - 2; j++)
	{
		add += days[j];
	}
	add += date.day;
	printf("%d\n", add);
}