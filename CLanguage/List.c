// ������Ϊ�������洢����Ϊ����ʽ��
// �ܽ��������ɾ��Ĳ��������������ʽ�ĺͲ��

#include <stdio.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct
{
	double coef; 			// ϵ��
	int exp;				// ָ��
	struct tagNode * next;	// ָ����һ����
} ListNode;

// ----------����ԭ��----------
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


// ----------����ʵ��----------
void ShowMenu()
{
	printf("\n-------------\n");
	printf("1.��ʼ��\n");
	printf(" \n");
	printf("������Ҫ���еĲ���[1-]:"); 
}
void InitList(ListNode * L)
{
	;
}