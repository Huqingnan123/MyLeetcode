#include <stdio.h>
int main(void)
{
	char number[10] = { '0','1','2','3','4','5','6','7','8','9'}, character[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int count1[10] = { 0,0,0,0,0,0,0,0,0,0 }, count2[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, i, j, k = 0;
	char c;
	while ((c = getchar()) != EOF)
	{
		for(i=0;i<=9;i++)
		{
			if (c == number[i])
				count1[i]++;
		}
		for (i = 0; i <= 25; i++)
		{
			if (c == character[i]||c==character[i]-32)
				count2[i]++;
		}
		if ((c < 48)|| (c > 57&& c < 65)||(c>90&&c<97) || c>122)
			k++;
	}
	for (i = 0; i <= 9; i++)
	{
		if (i != 9)
			printf("%d:%d ", number[i]-48, count1[i]);
		else
			printf("%d:%d\n", number[i]-48, count1[i]);
	}
	for (i = 0; i <= 25; i++)
	{
		if (i != 25)
			printf("%c:%d ", character[i], count2[i]);
		else
			printf("%c:%d\n",character[i], count2[i]);
	}
	printf("other:%d\n",k);
}