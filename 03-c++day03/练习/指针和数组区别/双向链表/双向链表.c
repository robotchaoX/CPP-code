#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *pre;
	struct node *next;
}Node;

typedef struct link
{
	Node head;
	int size;
}Link;



void *init()
{
	Link *mylink = (Link *)malloc(sizeof(Link));
	if (NULL == mylink)
	{
		return NULL;
	}
	mylink->size = 0;
	mylink->head.data = -1;
	mylink->head.next = NULL;
	mylink->head.pre = NULL;

	return mylink;
}




void insert(void *head, int data, int pos)
{
	if (NULL == head)
	{
		return;
	}

	Link *mylink = (Link *)head;

	if (pos < 0 || pos > mylink->size)
	{
		pos = mylink->size;
	}

	Node * newnode =(Node *)malloc(sizeof(Node));

	if (NULL == newnode)
	{
		return;
	}

	newnode->data = data;
	newnode->pre = NULL;
	newnode->next = NULL;
	
	//先判断链表是否为空
	if (mylink->size == 0)
	{
		newnode->next = mylink->head.next;
		newnode->pre = &(mylink->head);
		mylink->head.next = newnode;

		mylink->size++;
		return;
	}

	Node *pCur = &(mylink->head);
	Node *pre = NULL;
	for (int i = 0; i < pos; ++i)
	{
		pCur = pCur->next;
	}
	//判断是否是最后一个
	if (pos == mylink->size)
	{
		newnode->next = pCur->next;
		newnode->pre = pCur;
		pCur->next = newnode;
		mylink->size++;
		return;
	}

	pre = pCur->next;
	pCur->next = newnode;
	newnode->pre = pCur;
	newnode->next = pre;
	pre->pre = newnode;
	mylink->size++;

}

void print(void *p)//正序打印
{
	Node *d = (Node *)p;

	while (d != NULL)
	{
		printf("%d ", d->data);
		d = d->next;
	}
	printf("\n");
}

//倒序打印
void revprint(void *p)
{
	Link *d = (Link *)p;
	Node * d1 = d->head.next;

	while (d1->next != NULL)
	{
		d1 = d1->next;
	}
	printf("-------------------\n");
	while (d1 != &(d->head))
	{
		printf("%d ", d1->data);
		d1 = d1->pre;
	}
	printf("\n");
}



void delete(void *head, int pos)//删除节点
{
	if (NULL == head)
	{
		return;
	}
	Link *mylink = (Link *)head;

	if (pos <= 0 || pos>mylink->size)
	{
		return;
	}
	Node *pCur = &(mylink->head);
	Node *pre = NULL;
	//Node * pone = NULL;
	for (int i = 0; i < pos; ++i)
	{
		pCur = pCur->next;
	}

	pre = pCur->next;
	//pone = pre->next;
	if (pos == mylink->size)
	{
		pCur->next = pre->next;
		free(pre);
		mylink->size--;
		return;
	}
	pre->next->pre = pCur;
	pCur->next = pre->next;
	free(pre);
	
	mylink->size--;
}


void destroy(void *head)//销毁链表
{
	if (NULL == head)
	{
		return;
	}
	Link *mylink = (Link *)head;
	//Node *pre = mylink->head.next;
	Node *pre = &(mylink->head);
	Node *pCur = pre->next;

	while ( pre->next != NULL)
	{
		free(pre);
		pre = pCur;
		pCur = pCur->next;
	}
	
	//free(mylink->head.pre);
	//free(mylink);
	//mylink = NULL;

}




void test()
{

	Link *p1 = NULL;
	p1 = init();
	insert(p1, 10, 0);

	insert(p1, 20, 0);

	insert(p1, 30, 0);

	insert(p1, 40, 3);

	insert(p1, 666, 2);

	print((p1->head.next));
	revprint(p1);
	delete(p1, 3);
	printf("-------------\n");
	print((p1->head.next));
	revprint(p1);
	//destroy(p1);
}






int main()
{

	test();

	system("pause");

}