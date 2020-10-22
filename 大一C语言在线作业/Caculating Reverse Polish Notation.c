#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

#define SIZE 1000

void push(int n);        /*ѹջ����*/
int pop(void);           /*��ջ����*/

int stack[SIZE];         /*��������Ϊֵջʹ��*/
int top = -1;            /*�±���Ϊջ��"ָ��"*/

int main(void)
{
	char ch;
	int n;
	int loprd, roprd;

	while ((ch = getchar()) == ' ')
		;
	while (ch != '\n')
	{
		if (isdigit(ch)) {
			n = 0;
			do {
				n = n * 10 + ch - '0';
				ch = getchar();
			} while (isdigit(ch));
			push(n);
		}
		else {
			roprd = pop();
			loprd = pop();
			switch (ch) {
			case '+':
				loprd += roprd;
				break;
			case '-':
				loprd -= roprd;
				break;
			case '*':
				loprd *= roprd;
				break;
			case '/':
				if (roprd == 0) {
					printf("divide by zero!"); /*�������Ϊ��*/
					return -1;                 /*�����쳣*/
				}
				loprd /= roprd;
				break;
			default:
				printf("illegal operator��\n");
				return -2;
			}
			push(loprd);
			ch = getchar();
		}
		while (ch == ' ')
			ch = getchar();
	}
	if (top > 0) {
		printf("illegal input, lack of operators!\n");
		return -4;
	}
	printf("result is %d\n", pop());

	return 0;
}

void push(int n)
{
	top++;    /*ջָ��ָ���ѹ��Ԫ*/
	stack[top] = n;/*������ջ*/
}

int pop(void)
{
	int x;

	if (top < 0) {
		printf("illegal input!\n");
		exit(-3);
	}
	x = stack[top];/*ջ��Ԫ��ֵ����x*/
	top--;/*ջָ���1��ָ����һ��Ԫ*/

	return x;/*����ջ��Ԫ��ֵ*/
}
