// ------------------------------------------顺序存储结构的插入和删除---------------------------------------

// #include <stdio.h>
// #include <string.h>

// #define OK 1
// #define ERROR 0
// #define TRUE 1
// #define FALSE 0
// typedef int Status;

// #define MAXSIZE 200
// typedef int ElemType;
// typedef struct 
// {
//  ElemType data[MAXSIZE];
//  int length;
// } SqList;


// // 获取元素操作
// Status GetElem(SqList L,int i,ElemType *e)
// {
//  if(L.length==0 || i<1 || i>L.length)
//      return ERROR;
//  *e=L.data[i-1];
//  return OK;
// }

// // 插入操作
// Status ListInsert(SqList *L,int i,ElemType e)
// {
//  int k;
//  if(L->length==MAXSIZE)
//      return ERROR;
//  if(i<1 || i>L->length+1)
//      return ERROR;
//  if(i<=L->length)
//  {
//      for(k=L->length-1;k>=i-1;k--)
//          L->data[k+1]=L->data[k];
//  }
//  L->data[i-1]=e;
//  L->length++;
//  return OK;
// }

// // 删除操作
// Status ListDelete(SqList *L,int i,ElemType *e)
// {
//  int k;
//  if(L->length==0)
//      return ERROR;
//  if(i<1 || i>L->length+1)
//      return ERROR;
//  *e=L->data[i-1];
//  if(i<L->length)
//  {
//      for(k=i;k<L->length;k++)
//          L->data[k-1]=L->data[k];
//  }
//  L->length--;
//  return OK;
// }

// int main()
// {
	// ElemType e=5;
	// memset(L.data,0,sizeof(L.data));
	// L.length=0;
	// ListInsert(&L,1,e);
	// e=6;
	// ListInsert(&L,2,e);
	// ListDelete(&L,1,&e);
	// GetElem(L,1,&e);
	// printf("%d\n",e);
//  return 1;
// }


// -----------------------------------线性表的链式存储结构----------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;


typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node;
typedef struct Node *LinkList;

// typedef struct Node
// {
//  ElemType data;
//  struct Node *next;
// } Node,*LinkList;

Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while(p && j<i)
	{
		p = p->next;
		++j;
	}
	if(!p || j>i)
		return ERROR;
	*e = p->data;
	return OK;
}


Status ListInsert(LinkList *L,int i,ElemType e)
{
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	while(p && j<i)
	{
		p = p->next;
		++j;
	}
	if(!p || j>i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}


Status ListDelete(LinkList *L,int i,ElemType *e)
{
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while(p->next && j<i)
	{
		p = p->next;
		++j;
	}
	if(!(p->next) || j>i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}


void CreateListHead(LinkList *L,int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		p->next = (*L)->next;
		(*L)->next = p;
	}

}


Status ClearList(LinkList *L)
{
	LinkList p,q;
	p = (*L)->next;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next=NULL;
	return OK;
}


int main()
{
	LinkList L;
	CreateListHead(&L,10);


	int a,i = 1;
	LinkList head,rear;
	LinkList p;
	head = (LinkList)malloc(sizeof(Node));
	rear = (LinkList)malloc(sizeof(Node));
	head->next = rear;
	rear->next = NULL;
	p = head;
	while(scanf("%d",&a) && a)
	{
		ListInsert(&p,i++,a);
		p = p->next;
	}
	i--;
	p = head->next;
	while(i--)
	{
		printf("%d\n",p->data);
		p = p->next;
	}

	return 1;
}
























