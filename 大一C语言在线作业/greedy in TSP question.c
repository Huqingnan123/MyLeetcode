#include <stdio.h>
#define n 4			             //代表城市的个数
int main(void)
{
	int D[n][n], S[n], Sum=0, i=1, j, k, L, Dtemp, Found;
	S[0] = 0;        //表示从0号城市出发
	D[0][1] = 2; D[0][2] = 6; D[0][3] = 5; D[1][0] = 2; D[1][2] = 4; D[1][3] = 4;   //D[i][j]表示从第i个城市到第j个城市的距离，开始先对其做初始化
	D[2][0] = 6; D[2][1] = 4; D[2][3] = 2; D[3][0] = 5; D[3][1] = 4; D[3][2] = 2;	//S[n]数组中的号码顺序即代表了城市之间的访问顺序
	do
	{
		k = 1; Dtemp = 10000;    //Dtemp只要大于剩下“未排列访问顺序”的任意两城市间距离最大值就行,k代表城市编号，（这题从0号城市出发，每一次k都从1号城市开始检索，刷新）
		do 
		{
			L = 0; Found = 0;
			do					//遍历S[n]数组，判断编号k的城市是否已经到过，Found为1表示找到了，跳出
			{
				if (S[L] == k)
				{
					Found = 1;      //若Found=1则不参与后面的if语句比较距离，k++来对下一个城市
					break;
				}
				else
					L++;
			} while (L < i);
			if (Found == 0 && D[k][S[i - 1]] < Dtemp) //表示k号城市并没有到过，且到访问列表中的最后一个城市的距离更小，则把k号城市作为优先地
			{
				j = k;			//类似于选择法，用j来记住城市编号
				Dtemp = D[k][S[i - 1]];
			}
			k++;
		} while (k < n);
		S[i] = j;
		i = i + 1;     //接着找下一个城市（若定下起始城市，则只需要找n-1次城市）
		Sum = Sum + Dtemp;
	} while (i < n);         //进行n-1次寻找，i从1 ->（n-1）
	Sum = Sum + D[0][j];    //最后还要返回
	for (j = 0; j < n; j++)
		printf("%d, ",S[j]);
	printf("\n");
	printf("Total Length:%d\n", Sum);
}