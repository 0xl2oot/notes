#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;

struct Node {
	int Coefficient;	// 系数
	int Exponent;		// 指数
	PtrToNode Next;
};

typedef PtrToNode Polynomial;		// 多项式

PtrToNode CreatPoly();
void Insert(int Coefficient, int Exponent, Polynomial Poly);
Polynomial AddPoly(Polynomial Polya, Polynomial Polyb);
void AddPoly2(Polynomial Polya, Polynomial Polyb);

Polynomial CreatPoly() {
	PtrToNode head = (PtrToNode)malloc(sizeof(struct Node));
	head->Next = NULL;
	int Coefficient, Exponent;
	// 输入为系数指数，以-1结束
	while(~scanf("%d", &Coefficient) && Coefficient != -1) {
		scanf("%d", &Exponent);
		Insert(Coefficient, Exponent, head);
	}
	return head;
}

Polynomial AddPoly(Polynomial Polya, Polynomial Polyb) {
	PtrToNode head = (PtrToNode)malloc(sizeof(struct Node));
	head->Next = NULL;
	PtrToNode p;
	p = Polya->Next;
	while (p != NULL) {
		Insert(p->Coefficient, p->Exponent, head);
		p = p->Next;
	}
	p = Polyb->Next;
	while (p != NULL) {
		Insert(p->Coefficient, p->Exponent, head);
		p = p->Next;
	}
	return head;
}

void AddPoly2(Polynomial Polya, Polynomial Polyb) {
	PtrToNode p;
	p = Polyb->Next;
	while (p != NULL) {
		Insert(p->Coefficient, p->Exponent, Polya);
		p = p->Next;
	}
}

void Insert(int Coefficient, int Exponent, Polynomial Poly) {
	PtrToNode p;
	p = Poly;
	
	// 注意判断是不是空链表，即第一个插入的元素
	while (p->Next != NULL && p->Next->Exponent > Exponent) {
		p = p->Next;
	}
	
	if(p->Next != NULL && p->Next->Exponent == Exponent) {
		p->Next->Coefficient += Coefficient;
	}
	else {
		PtrToNode node = (PtrToNode)malloc(sizeof(struct Node));
		node->Coefficient = Coefficient;
		node->Exponent = Exponent;
		node->Next = p->Next;
		p->Next = node;
	}
}

void PrintPoly(Polynomial Poly) {
	PtrToNode p;
	p = Poly->Next;
	while (p != NULL) {
		printf("%dx^%d", p->Coefficient, p->Exponent);
		if(p->Next != NULL) 
			printf(" + ");
		p = p->Next;
	}
	printf("\n");
}

int main() {
	Polynomial polya = CreatPoly();
	PrintPoly(polya);
	Polynomial polyb = CreatPoly();
	PrintPoly(polyb);
	Polynomial polyc = AddPoly(polya, polyb);
	PrintPoly(polyc);
	AddPoly2(polya, polyb);
	PrintPoly(polya);
	return 0;
}

//2 3 6 3 2 4 8 7 9 1 -1
//8x^7 + 2x^4 + 8x^3 + 9x^1
//4 5 3 3 7 7 2 8 6 1 9 7 3 4 -1
//2x^8 + 16x^7 + 4x^5 + 3x^4 + 3x^3 + 6x^1
//2x^8 + 24x^7 + 4x^5 + 5x^4 + 11x^3 + 15x^1