#include <stdio.h>
int eightQueen(int row, int line, int(*chess)[8]);
int notDanger(int row, int line, int(*chess)[8]);
int count = 0;
int main(void)
{
	int chess[8][8] = { 0 };
	eightQueen(0, 8, chess);
	return 0;
}
int eightQueen(int row, int line, int(*chess)[8])   //row行，line列！！！
{
	int Temp_chess[8][8], i, j;   //每次进入此函数都临时棋盘复制
	for (i = 0; i <= 7; i++)
		for (j = 0; j <= 7; j++)
			Temp_chess[i][j] = chess[i][j];
	if (row == 8)                //递归结束条件，输出符合的情况
	{
		printf("This is the %dth right situation:\n", count + 1);
		for (i = 0; i <= 7; i++)
		{
			for (j = 0; j <= 7; j++)
				printf("%d ", *(*(chess + i) + j));
			printf("\n");
		}
		printf("\n\n");
		count++;
	}
	else
	{
		for (i = 0; i <= line - 1; i++)        //从当前行的位置从左到右开始检索是否有合适的位置
		{
			if (notDanger(row, i, chess))
			{
				for (j = 0; j <= 7; j++)
					*(*(Temp_chess + row) + j) = 0;
				*(*(Temp_chess + row) + i) = 1;			 //若这行的此位置合适，则标记为1
				eightQueen(row + 1, line, Temp_chess);		//继续去排下一行的皇后
			}
		}
	}
}
int notDanger(int row, int line, int(*chess)[8])
{
	int i, j, flag_rightup = 0, flag_leftup = 0, flag_row = 0;//0表示符合要求
	for (i = 0; i <= 7; i++)
	{
		if (*(*(chess + i) + line) == 1)     //判断这一列是否已经有皇后
		{
			flag_row = 1;
			break;
		}
	}
	for (i = 0; i <= 7; i++)
	{
		j = row + line - i;                //在同一条右上斜线上，i+j相等
		if (j <= 7 && j >= 0 && (*(*(chess + i) + j) == 1))
		{
			flag_rightup = 1;
			break;
		}
	}
	for (i = 0; i <= 7; i++)
	{
		if (row >= line)
		{
			j = line - row + i;                //在同一条左上斜线且在左下部分时，i-j=row-line
			if (j <= 7 && j >= 0 && ((*(*(chess + i) + j) == 1)))
			{
				flag_leftup = 1;
				break;
			}
		}
		else
		{
			j = line - row + i;                //在同一条左上斜线且在右上部分时，j-i=line-row
			if (j <= 7 && j >= 0 && ((*(*(chess + i) + j) == 1)))
			{
				flag_leftup = 1;
				break;
			}
		}
	}
	if (flag_row || flag_rightup || flag_leftup)
		return 0;
	else
		return 1;       //返回1则说明这个位置是安全的
}