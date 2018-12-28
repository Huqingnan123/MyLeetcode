#include "stdio.h"
#include "string.h"
#include "ctype.h"

#define SIZE 100

void push(char c);  /*入栈操作*/
char pop(void);	    /*出栈操作*/

char stack[SIZE];   /*运算符栈*/
char out[SIZE];	    /*存放逆波兰序列的数组*/
int top = -1, j = 0;/*top：下标形式的栈指针*/

int main(void)
{
	char in[] = "15+21*(41-12)-1128/12";/*输入的中缀表达式*/
	int i = 0;
	char c;

	memset(out, ' ', SIZE);/*全部初始化为空格*/
	while (in[i] != '\0')
	{
		switch (in[i])
		{
		case '0': case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9':
			while (isdigit(in[i]))
				out[j++] = in[i++]; /*数字字符直接进入逆波兰序列*/
			j++;
			i--;
			break;
		case '+': case '-':	/*加减运算处理*/
			while (top >= 0 && stack[top] != '(') {
				out[j++] = pop();        /*出栈*/
				j++;
			}
			push(in[i]);	/*入栈*/
			break;
		case '*': case '/':	/*乘除运算处理*/
			while (top >= 0 && (stack[top] == '*' || stack[top] == '/')) {
				out[j++] = pop();
				j++;
			}
			push(in[i]);
			break;
		case '(':    /*左圆括号处理*/
			push(in[i]);    /*左圆括号'('直接入栈*/
			break;
		case ')':    /*右圆括号处理*/
			while (top >= 0 && (c = pop()) != '(') {
				out[j++] = c;        /*出栈*/
				j++;
			}
			break;
		case ' ':
			break;
		default:
			printf("illegal input!\n");    /*遇到非法字符，返回*/
			return -1;
		}
		i++; //移动到下一个字符
	}
	while ((c = pop()) != '\0') {
		out[j++] = c;        /*出栈*/
		j++;
	}
	out[j] = '\0';    /*形成逆波兰字符串*/
	printf("%s\n", out);    /*输出逆波兰字符串*/

	return 0;
}

void push(char c) /*运算符c入栈操作*/
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


