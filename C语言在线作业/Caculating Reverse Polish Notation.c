#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

#define SIZE 1000

void push(int n);        /*压栈操作*/
int pop(void);           /*出栈操作*/

int stack[SIZE];         /*将数组作为值栈使用*/
int top = -1;            /*下标作为栈顶"指针"*/

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
					printf("divide by zero!"); /*输出除数为零*/
					return -1;                 /*返回异常*/
				}
				loprd /= roprd;
				break;
			default:
				printf("illegal operator！\n");
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
	top++;    /*栈指针指向待压单元*/
	stack[top] = n;/*数据入栈*/
}

int pop(void)
{
	int x;

	if (top < 0) {
		printf("illegal input!\n");
		exit(-3);
	}
	x = stack[top];/*栈顶元素值赋给x*/
	top--;/*栈指针减1，指向下一单元*/

	return x;/*返回栈顶元素值*/
}
