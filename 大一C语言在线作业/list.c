#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node *pnode);   /*�ֲ�����ԭ��*/

void InitializeList(List *plist)           /*�ӿں��������б�����Ϊ���б�*/
{
	*plist = NULL;
}

bool ListIsEmpty(const List *plist)  
{
	if (*plist == NULL)
		return true;
	else
		return false;
}

bool ListIsFull(const List *plist)
{
	Node *pt;
	bool full;
	pt = (Node *)malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);
	return full; 
}

unsigned int ListItemCount(const List *plist)     /*���ؽڵ���*/
{
	unsigned int count = 0;
	Node *pnode = *plist;
	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}
	return count;
}

bool AddItem(Item item, List *plist)            /*������Ŀ�ڵ㣬�������ӵ�plist��ָ�б��β��*/
{
	Node *pnew;
	Node *scan = *plist;					 /*scan��Ϊһ��ָ��*/
	pnew = (Node *)malloc(sizeof(Node));
	if (pnew != NULL)
		return false;                         /*�жϷ���ռ��Ƿ�ɹ���ʧ��ʱ�˳�����*/
	
	CopyToNode(item, pnew);                   /*��������ǰitem����Ϣȫ���浽pnew��ǰָ����֪��������*/
	pnew->next = NULL;
	if (scan == NULL)
		*plist = pnew;                        /*�����ǿ�������pnew����ͷ��*/
	else
	{
		while (scan->next != NULL)
			scan = scan->next;               /*�ҵ������β����pnew����ȥ*/
		scan->next = pnew;   
	}
	return true;
}

void Tarverse(const List *plist, void(*pfun)(Item item))
{
	Node *pnode = *plist;
	while (pnode != NULL)
	{
		(*pfun)(pnode->item);                 /*����ĳһ������������ÿһ����Ŀ*/
		pnode = pnode->next;
	}
}

void EmptyTheList(List *plist)
{
	Node *psave;
	while (plist != NULL)
	{
		psave = (*plist)->next;
		free(*plist);
		*plist = psave;
	}
}

static void CopyToNode(Item item, Node *pnode)
{
	pnode->item = item;						 /*���нṹ����*/
}

