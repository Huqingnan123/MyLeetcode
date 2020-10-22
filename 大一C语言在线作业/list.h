#pragma once
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>     /*C99����*/

#define TSIZE 45
struct film
{
	char title[TSIZE];
	int rating;
};
typedef struct film Item;
typedef struct node
{
	Item item;
	struct node*next;
}Node;

typedef Node *List;

void InitializeList(List *plist);     /*��ʼ��һ���б�����ǰplist������ָ�룩ָ��һ���б���������б���ʼ��Ϊ���б�*/

bool ListIsEmpty(const List *plist);  /*ȷ���б��Ƿ�Ϊ���б�*/

bool ListIsFull(const List *plist);   /*ȷ���б��Ƿ�����*/

unsigned int ListItemCount(const List *plist);  /*ȷ���б�����Ŀ�ĸ���*/

bool AddItem(Item item, List *plist);  /*��β�����һ����Ŀ*/

void Traverse(const List *plist, void(*pfun)(Item item));  /*��һ������������ÿһ����Ŀ(��������ʾ��Ŀ���ݵĺ�����*/

void EmptyTheList(List *plist);        /*�ͷ��Ѿ�������ڴ棨����У�*/
#endif
