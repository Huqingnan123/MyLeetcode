#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node *pnode);   /*局部函数原型*/

void InitializeList(List *plist)           /*接口函数，将列表设置为空列表*/
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

unsigned int ListItemCount(const List *plist)     /*返回节点数*/
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

bool AddItem(Item item, List *plist)            /*创建项目节点，并把它加到plist所指列表的尾部*/
{
	Node *pnew;
	Node *scan = *plist;					 /*scan则为一级指针*/
	pnew = (Node *)malloc(sizeof(Node));
	if (pnew != NULL)
		return false;                         /*判断分配空间是否成功，失败时退出函数*/
	
	CopyToNode(item, pnew);                   /*用来将当前item中信息全部存到pnew当前指针所知链表区域*/
	pnew->next = NULL;
	if (scan == NULL)
		*plist = pnew;                        /*若还是空链表，把pnew放在头部*/
	else
	{
		while (scan->next != NULL)
			scan = scan->next;               /*找到链表结尾，将pnew加上去*/
		scan->next = pnew;   
	}
	return true;
}

void Tarverse(const List *plist, void(*pfun)(Item item))
{
	Node *pnode = *plist;
	while (pnode != NULL)
	{
		(*pfun)(pnode->item);                 /*将“某一”函数作用于每一个项目*/
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
	pnode->item = item;						 /*进行结构复制*/
}

