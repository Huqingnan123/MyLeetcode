#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu_info {
	char ID[12];
	char name[20];
	float English;
	float math;
	float physics;
	float C_program;
	double average;
	double allscore;
	struct stu_info *next;
};
typedef struct stu_info Stu_info;
Stu_info *Input(void);
void Output(Stu_info *p);
void Modify(Stu_info *head);
void Cal_avg(Stu_info *p);
void Output_r(Stu_info *p);
void SelectSort(Stu_info *p);
int main(void)
{
	char temp[12];
	Stu_info *head = NULL;
	head = Input();
	Output(head);
	Modify(head);
	Cal_avg(head);
	Output_r(head);
	SelectSort(head);
	return 0;
}
Stu_info *Input(void)
{
	int N, i;
	Stu_info *head = NULL, *prev, *current, student;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		current = (Stu_info *)malloc(sizeof(Stu_info));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		scanf("%s %s %f %f %f %f", current->ID, current->name, &current->English, &current->math, &current->physics, &current->C_program);
		prev = current;
	}
	return head;
}
void Output(Stu_info *p)
{
	char s1[] = "ID", s2[] = "Name", s3[] = "English", s4[] = "Math", s5[] = "Physics", s6[] = "C";
	printf("%-15s%-20s%-10s%-10s%-10s%-10s\n", s1, s2, s3, s4, s5, s6);
	while (p)
	{
		printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n", p->ID, p->name, p->English, p->math, p->physics, p->C_program);
		p = p->next;
	}
	putchar('\n');
}
void Modify(Stu_info *p)
{
	Stu_info *p1 = p;
	int N, i;
	float grades;
	char tempID[12], subject[12];
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		p = p1;
		scanf("%s %s %f", tempID, subject, &grades);
		while (p)
		{
			if (strcmp(tempID, p->ID) == 0)
			{
				switch (subject[0])
				{
				case'E':
					p->English = grades;
					break;
				case'M':
					p->math = grades;
					break;
				case'P':
					p->physics = grades;
					break;
				case'C':
					p->C_program = grades;
					break;
				}
				break;
			}
			else
				p = p->next;
		}
	}
	printf("Alter:\n");
	char s1[] = "ID", s2[] = "Name", s3[] = "English", s4[] = "Math", s5[] = "Physics", s6[] = "C";
	printf("%-15s%-20s%-10s%-10s%-10s%-10s\n", s1, s2, s3, s4, s5, s6);
	p = p1;
	while (p)
	{
		printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n", p->ID, p->name, p->English, p->math, p->physics, p->C_program);
		p = p->next;
	}
	putchar('\n');
}
void Cal_avg(Stu_info *p)
{
	while (p)
	{
		double add = 0;
		add = p->English + p->math + p->physics + p->C_program;
		p->average = add / 4;
		p = p->next;
	}
}
void Output_r(Stu_info *p)
{
	printf("SumAndAvg:\n");
	char s1[] = "ID", s2[] = "Name", s3[] = "SUM", s4[] = "AVG";
	printf("%-15s%-20s%-10s%-10s\n", s1, s2, s3, s4);
	while (p)
	{
		double add = 0;
		add = p->English + p->math + p->physics + p->C_program;
		p->allscore = add;
		printf("%-15s%-20s%-10.2lf%-10.2lf\n", p->ID, p->name, p->allscore, p->average);
		p = p->next;
	}
	putchar('\n');
}
void SelectSort(Stu_info *p)  /*选择法排序*/
{
	Stu_info *p1 = p, *p2;   /*头指针副本*/
	int length = 0, i, j;
	while (p1)
	{
		length++;
		p1 = p1->next;        /*计算节点个数*/
	}
	for (i = 0, p1 = p; i <= length - 2; i++, p1 = p1->next)
	{
		Stu_info *min = p1, temp;		/*最开始作为最小节点标记*/
		for (j = i + 1, p2 = p1->next; j <= length - 1; j++, p2 = p2->next)
		{
			if (p2->average < min->average)
				min = p2;
		}
		temp = *p1;      /*需要保存排序节点的全部信息*/
		strcpy(p1->ID, min->ID);
		strcpy(p1->name, min->name);
		p1->English = min->English;
		p1->math = min->math;
		p1->physics = min->physics;
		p1->C_program = min->C_program;
		p1->average = min->average;
		p1->allscore = min->allscore;

		strcpy(min->ID, temp.ID);
		strcpy(min->name, temp.name);
		min->English = temp.English;
		min->math = temp.math;
		min->physics = temp.physics;
		min->C_program = temp.C_program;
		min->average = temp.average;
		min->allscore = temp.allscore;
	}
	printf("Sort:\n");
	char s1[] = "ID", s2[] = "Name", s3[] = "AVG";
	printf("%-15s%-20s%-10s\n", s1, s2, s3);
	while (p)
	{
		printf("%-15s%-20s%-10.2lf\n", p->ID, p->name, p->average);
		p = p->next;
	}
	putchar('\n');
}