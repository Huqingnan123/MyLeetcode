#include <stdio.h>
int num;
int my_strlen(void);
int main(void)
{
	int N, i;
	scanf("%d", &N);
	while (getchar() != '\n')              //Ϊ���������ʱ�Ļس�
		continue;
	for (i = 1,num=0; i <= N; i++,num=0)      //ʹÿ�������ַ�������ʱnum=0
	{
		num=my_strlen();                    //�����ص�ֵ����num�������Ϊ��ȣ�
		printf("%d\n", num);                //����ֱ����my_strlen()����printf�У�����Ҫ���������ַ����Ż��ӡ���൱�����ε���
	}
	return 0;
}
int my_strlen(void)
{
	if (getchar()!= '\n')
	{
		num++;                //�ظ�ʹ�ú���������ǻ��з�֮ǰ�Ŀ�ȣ�num������
		my_strlen();
	}
	return num;               //��Ϊ�ǵݹ飬ֻ�Ƿ��ص���һ����my_strlen������ʵ����Ҫ���Ϸ���numֱ�����ص��������У�
}