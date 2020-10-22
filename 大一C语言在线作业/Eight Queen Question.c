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
int eightQueen(int row, int line, int(*chess)[8])   //row�У�line�У�����
{
	int Temp_chess[8][8], i, j;   //ÿ�ν���˺�������ʱ���̸���
	for (i = 0; i <= 7; i++)
		for (j = 0; j <= 7; j++)
			Temp_chess[i][j] = chess[i][j];
	if (row == 8)                //�ݹ����������������ϵ����
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
		for (i = 0; i <= line - 1; i++)        //�ӵ�ǰ�е�λ�ô����ҿ�ʼ�����Ƿ��к��ʵ�λ��
		{
			if (notDanger(row, i, chess))
			{
				for (j = 0; j <= 7; j++)
					*(*(Temp_chess + row) + j) = 0;
				*(*(Temp_chess + row) + i) = 1;			 //�����еĴ�λ�ú��ʣ�����Ϊ1
				eightQueen(row + 1, line, Temp_chess);		//����ȥ����һ�еĻʺ�
			}
		}
	}
}
int notDanger(int row, int line, int(*chess)[8])
{
	int i, j, flag_rightup = 0, flag_leftup = 0, flag_row = 0;//0��ʾ����Ҫ��
	for (i = 0; i <= 7; i++)
	{
		if (*(*(chess + i) + line) == 1)     //�ж���һ���Ƿ��Ѿ��лʺ�
		{
			flag_row = 1;
			break;
		}
	}
	for (i = 0; i <= 7; i++)
	{
		j = row + line - i;                //��ͬһ������б���ϣ�i+j���
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
			j = line - row + i;                //��ͬһ������б���������²���ʱ��i-j=row-line
			if (j <= 7 && j >= 0 && ((*(*(chess + i) + j) == 1)))
			{
				flag_leftup = 1;
				break;
			}
		}
		else
		{
			j = line - row + i;                //��ͬһ������б���������ϲ���ʱ��j-i=line-row
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
		return 1;       //����1��˵�����λ���ǰ�ȫ��
}