#include <stdio.h>
void SelectionSort(int a[], int length);        //������ַ
int main(void)
{
	int a[1024], length;
	printf("Please tell me how many numbers (<=1024) you want to sort:");
	scanf("%d", &length);
	printf("Please input %d intergers:\n", length);      //��ʾ��length�������������±��0��length-1
	for (int i = 0; i <= length - 1; i++)
		scanf("%d", &a[i]);    
	SelectionSort(a, length);     //�����ڵ���һ��a,��length��ֵ���ݸ�֮����βΣ�a�ǡ������������൱��һ��ָ�룬ָ��a[10]�������
	for (int i = 0; i <= length - 1; i++)
		printf("%d ", a[i]);
	return 0;
}
void SelectionSort(int a[], int length)
{
	for (int i = 0; i < length - 1; i++)          //��ǰ����ѭ����ÿһ�ζ���֮����ʣ��С�������������ڵ�λ�ã�һ��ѭ��������һ�ν��������ǲ�����������
	{
		int min=i, j, temp;     //����Ŀǰδ�������еĵ�һ����a[i]��Ϊminֵ
		for (j = i + 1; j <= length-1 ; j++)   
		{
			if(a[j]<a[min])
				min = j;           //���μ�������ǳ���������С����Ϊa[min],��֮���������a[min]�Ƚϴ�С������һ�ֺ������ҵ�a[i]֮���"��С��"��a[i]��λ��   
		}
		temp = a[i];
		a[i] = a[min];         //min������С���Ǹ���
		a[min] = temp;
	}
}        //�����Ƿ���ֵvoid�ͣ���Ӧ�Ӹ�returnĳĳֵ������

