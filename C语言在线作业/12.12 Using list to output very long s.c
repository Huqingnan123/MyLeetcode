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
		current->next = NULL;         //������ָ�����Ӳ���
		current->c = input_c;
		prev = current;
		count++;                     //ͳ��#֮ǰ���ַ�����
	}
	if (head != NULL)
		string = (char *)malloc((count + 2) * sizeof(char));     //��Ҫ���뻻�з��Ϳ��ַ�
	current = head;                  //׼����ͷ��ʼ���ַ���������
	for (i = 0; i <= count - 1,current!=NULL; i++)
	{
		putchar(current->c);
		*(string + i) = current->c;
		current = current->next;
	}
	printf("\n\n");
	string[count] = '\n';
	string[count+1] = '\0';
	while (head!= NULL)                  //��ն�̬�ڴ����ѧ����������
	{
		current = head->next;
		free(head);
		head = current;
	}
	printf("%s\n", string);
	free(string);
	return 0;
}
