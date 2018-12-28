#include <stdio.h>   //虽然vs不支持VLA
#include <string.h>
struct Web {
	char shortname[21];
	char longname[41];
	char URL[41];
};
void insertselection(struct Web Ip[], int length);
int main(void)
{
	int n,i;
	scanf("%d", &n);
	getchar();
	struct Web IP[n];
	for (i = 0; i <= n - 1; i++)
		scanf("%s %s %s", IP[i].shortname, IP[i].longname, IP[i].URL);
	for (i = 0; i <= n - 1; i++)
		printf("%-20s%-40s%s\n", IP[i].shortname, IP[i].longname, IP[i].URL);
	putchar('\n');
	insertselection(IP,n);
	for (i = 0; i <= n - 1; i++)
		printf("%-20s%-40s%s\n", IP[i].shortname, IP[i].longname, IP[i].URL);
	return 0;
}
void insertselection(struct Web IP[], int length)
{
	int i;
	for ( i = 1; i <= length - 1; i++)           //从第二个开始检索
	{
		int j;
		struct Web temp;
		temp = IP[i];				//保存进行“插排”的元素的值
		for (j = i - 1; j >= 0 && strcmp(IP[j].shortname,temp.shortname)>0 ; j--)    
		{
			IP[j + 1] = IP[j];       //较大值向后移位,覆盖掉a[i]的值
		}
		IP[j + 1] = temp;       
	}
}        