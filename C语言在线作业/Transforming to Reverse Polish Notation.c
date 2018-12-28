#include "stdio.h"
#include "string.h"
#include "ctype.h"

#define SIZE 100

void push(char c);  /*��ջ����*/
char pop(void);	    /*��ջ����*/

char stack[SIZE];   /*�����ջ*/
char out[SIZE];	    /*����沨�����е�����*/
int top = -1, j = 0;/*top���±���ʽ��ջָ��*/

int main(void)
{
	char in[] = "15+21*(41-12)-1128/12";/*�������׺���ʽ*/
	int i = 0;
	char c;

	memset(out, ' ', SIZE);/*ȫ����ʼ��Ϊ�ո�*/
	while (in[i] != '\0')
	{
		switch (in[i])
		{
		case '0': case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9':
			while (isdigit(in[i]))
				out[j++] = in[i++]; /*�����ַ�ֱ�ӽ����沨������*/
			j++;
			i--;
			break;
		case '+': case '-':	/*�Ӽ����㴦��*/
			while (top >= 0 && stack[top] != '(') {
				out[j++] = pop();        /*��ջ*/
				j++;
			}
			push(in[i]);	/*��ջ*/
			break;
		case '*': case '/':	/*�˳����㴦��*/
			while (top >= 0 && (stack[top] == '*' || stack[top] == '/')) {
				out[j++] = pop();
				j++;
			}
			push(in[i]);
			break;
		case '(':    /*��Բ���Ŵ���*/
			push(in[i]);    /*��Բ����'('ֱ����ջ*/
			break;
		case ')':    /*��Բ���Ŵ���*/
			while (top >= 0 && (c = pop()) != '(') {
				out[j++] = c;        /*��ջ*/
				j++;
			}
			break;
		case ' ':
			break;
		default:
			printf("illegal input!\n");    /*�����Ƿ��ַ�������*/
			return -1;
		}
		i++; //�ƶ�����һ���ַ�
	}
	while ((c = pop()) != '\0') {
		out[j++] = c;        /*��ջ*/
		j++;
	}
	out[j] = '\0';    /*�γ��沨���ַ���*/
	printf("%s\n", out);    /*����沨���ַ���*/

	return 0;
}

void push(char c) /*�����c��ջ����*/
{
	top++;
	stack[top] = c;
}

char pop(void)
{
	char c = stack[top];;

	top--;

	return c;
}


