#pragma once
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>     /*C99特性*/

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

void InitializeList(List *plist);     /*初始化一个列表，操作前plist（二级指针）指向一个列表，操作后该列表被初始化为空列表*/

bool ListIsEmpty(const List *plist);  /*确定列表是否为空列表*/

bool ListIsFull(const List *plist);   /*确定列表是否已满*/

unsigned int ListItemCount(const List *plist);  /*确定列表中项目的个数*/

bool AddItem(Item item, List *plist);  /*在尾部添加一个项目*/

void Traverse(const List *plist, void(*pfun)(Item item));  /*把一个函数作用于每一个项目(可以是显示项目内容的函数）*/

void EmptyTheList(List *plist);        /*释放已经分配的内存（如果有）*/
#endif
