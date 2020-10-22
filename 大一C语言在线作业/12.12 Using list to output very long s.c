#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct str{
	char c;
	struct str *next;
};
typedef struct str Str;
int main(void)
{
	Str *head = NULL;
	Str *prev, *current;
	int count=0,i;
	char input_c,*string;
	while ((input_c=getchar()) != '#')
	{
		current = (Str *)malloc(sizeof(Str));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;         //先做好指针链接操作
		current->c = input_c;
		prev = current;
		count++;                     //统计#之前的字符个数
	}
	if (head != NULL)
		string = (char *)malloc((count + 2) * sizeof(char));     //需要加入换行符和空字符
	current = head;                  //准备从头开始将字符存入数组
	for (i = 0; i <= count - 1,current!=NULL; i++)
	{
		putchar(current->c);
		*(string + i) = current->c;
		current = current->next;
	}
	printf("\n\n");
	string[count] = '\n';
	string[count+1] = '\0';
	while (head!= NULL)                  //清空动态内存的玄学方法！！！
	{
		current = head->next;
		free(head);
		head = current;
	}
	printf("%s\n", string);
	free(string);
	return 0;
}
