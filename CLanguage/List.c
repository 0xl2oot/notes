// 此链表为单链表，存储数据为多项式，
// 能进行项的增删查改操作，并能求多项式的和差积

#include <stdio.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct
{
	double coef; 			// 系数
	int exp;				// 指数
	struct tagNode * next;	// 指向下一个项
} ListNode;

// ----------函数原型----------
void ShowMenu();
void InitList(ListNode * L);
void DestroyList(ListNode * L);


int main()
{
	int choice;
	struct tagNode *pa,*pb;
	ShowMenu();
	scanf("%d",&choice);
	while(choice)
	{
		switch(choice)
		{
			case 1:
				InitList(pa);
				InitList(pb);
				break;
			case 2:
			case 3:
			case 4:

			default : break;
		}
		ShowMenu();
		scanf("%d",&choice);
	}
	return 1;
}


// ----------函数实现----------
void ShowMenu()
{
	printf("\n-------------\n");
	printf("1.初始化\n");
	printf(" \n");
	printf("请输入要进行的操作[1-]:"); 
}
void InitList(ListNode * L)
{
	;
}