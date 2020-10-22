#include <stdio.h>
int num;
int my_strlen(void);
int main(void)
{
	int N, i;
	scanf("%d", &N);
	while (getchar() != '\n')              //为了清空输入时的回车
		continue;
	for (i = 1,num=0; i <= N; i++,num=0)      //使每次输入字符计算宽度时num=0
	{
		num=my_strlen();                    //将返回的值赋给num输出（即为宽度）
		printf("%d\n", num);                //不能直接用my_strlen()放在printf中，那样要两次输入字符串才会打印，相当于两次调用
	}
	return 0;
}
int my_strlen(void)
{
	if (getchar()!= '\n')
	{
		num++;                //重复使用函数，计算非换行符之前的宽度（num计数）
		my_strlen();
	}
	return num;               //因为是递归，只是返回到上一级的my_strlen函数，实际上要不断返回num直到返回到主函数中！
}