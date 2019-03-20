// https://www.zybuluo.com/wpaladins/note/326766

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 201

typedef int Status;
typedef int ElemType;
Status visit(ElemType c)
{
    printf(" %d",c);
    return OK;
}
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;


Status InitList(SqList *L)
{
    L->length=0;
    return OK;
}
Status ListEmpty(SqList L)
{
    if(L.length==0)
        return TRUE;
    else
        return FALSE;
}
Status ClearList(SqList *L)
{
    L->length=0;
    return OK;
}
Status ListLength(SqList L)
{
    return L.length;
}
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
            return ERROR;
    *e=L.data[i-1];
    return OK;
}
Status LocateElem(SqList L,ElemType e)
{
    int i;
    if (L.length==0)
            return 0;
    for(i=0;i<L.length;i++)
    {
            if (L.data[i]==e)
                    break;
    }
    if(i>=L.length)
            return 0;
    return i+1;
}
Status ListInsert(SqList *L,int i,ElemType e)
{
    int k;
    if (L->length==MAXSIZE)
        return ERROR;
    if (i<1 || i>L->length+1)
        return ERROR;
    if (i<=L->length)
    {
        for(k=L->length-1;k>=i-1;k--)
            L->data[k+1]=L->data[k];
    }
    L->data[i-1]=e;
    L->length++;
    return OK;
}
Status ListDelete(SqList *L,int i,ElemType *e)
{
    int k;
    if (L->length==0)
        return ERROR;
    if (i<1 || i>L->length)
        return ERROR;
    *e=L->data[i-1];
    if (i<L->length)
    {
        for(k=i;k<L->length;k++)
            L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}
void ListTraverse(SqList L)
{
    int i;
    printf("%d", L.data[0]);
    for(i=1;i<L.length;i++)
            visit(L.data[i]);
    printf("\n");
}
void unionL(SqList *La,ElemType c)
{
    int La_len;
    La_len=ListLength(*La);
    if (!LocateElem(*La,c))
            ListInsert(La,++La_len,c);
}
int  main()
{
    SqList La, Lb;
    InitList(&La);
    InitList(&Lb);
    int m, n, i, num, Lb_len;
    while(scanf("%d", &m) != EOF)
    {
        for(i = 0;i < m; i++){
            scanf("%d", &num);
        ListInsert(&La, i+1, num);
        }
        scanf("%d", &n);
        for(i = 0;i < n; i++){
        scanf("%d", &num);
        ListInsert(&Lb, i+1, num);
        }
        Lb_len=ListLength(Lb);
        ListTraverse(La);
        ListTraverse(Lb);
        ElemType e;
        for(i = 1; i <= Lb_len; i++)
        {
            GetElem(Lb,i,&e);
            unionL(&La, e);
            ListTraverse (La);
        }
        printf("\n");
        ClearList(&La);
        ClearList(&Lb);
  }
}