#include <stdio.h>
void insertSort(int a[], int length);        //������ַ
int main(void)
{
	int a[1024],length;
	printf("Please tell me how many numbers (<=1024) you want to sort:");
	scanf("%d", &length);
	printf("Please input %d intergers:\n", length);      //��ʾ��length�������������±��0��length-1
	for (int i = 0; i <= length-1; i++)
		scanf("%d", &a[i]);    //ע�⣡���������ڵ���һ�� a������
	insertSort(a, length);     //��a��length��ֵ���ݸ�֮����βΣ�      a�ǡ������������൱��һ��ָ�룬ָ��a[10]������飡����
	for (int i = 0; i <= length-1; i++)
		printf("%d ", a[i]);
	return 0;
}
void insertSort(int a[], int length)
{
	for (int i = 1; i <= length-1; i++)
	{
		int temp, j;
		temp = a[i];         //��һ���������ĵڶ�����ʼ������������
		for (j = i - 1; j >= 0 && a[j] > temp; j--)    //��֮ǰ������һ�飬��������С����ȵ�����ֹͣ��������Ϊǰ���Ѿ��ź��˵ģ�
		{
			a[j + 1] = a[j];    //�������ϴ���ʱ�����ϴ��������һλ
		}
		a[j + 1] = temp;       // j�����һ��1��������ѭ����˵����ʱ��j=-1����a[j]<=temp,�����ڿ���ֹͣ�������������бȽϵ�tempֵ��������a[j]���ڵĺ�һλ
	}
}        //�����Ƿ���ֵvoid�ͣ���Ӧ�Ӹ�returnĳĳֵ������

