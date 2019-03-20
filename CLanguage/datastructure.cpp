// #include <iostream>
// #include <malloc.h>  
// using namespace std;  
  
// #define ElemType int  
// typedef struct Node  
// {  
//    ElemType data;  
//    struct Node *next;  
  
// }Node,*Node_List;  
// //1.头插法初始化无头结点链表(改变节点数据或者指针必须给函数传入该变量的地址)  
// void Init_Node_List_No_HeadInsert(Node **head);//Init_Node_List(Node *&L)或者Init_Node_List(Node_List &L)  
// //2.尾插法初始化无头结点链表(改变节点数据或者指针必须给函数传入该变量的地址)  
// void Init_Node_List_No_BackInsert(Node **head);//Init_Node_List(Node *&L)或者Init_Node_List(Node_List &L)  
// //3.1显示有有结点链表数据  
// void Show_Node_List_HaHead(Node *L);//无需改变指针L所以值传递  
// //3.2显示有无结点链表数据  
// void Show_Node_List_NoHead(Node_List L);//无需改变指针L所以值传递  
// //4.尾插法初始化有头结点链表  
// void Init_Node_List_Have_BackInsert(Node **head); //对于有头节点的头节点所指向的位置不变可以用  
// //5.头插法初始化有头结点链表  
// void Init_Node_List_Have_HeadInsert(Node **head);



// int main()  
// {  
//     Node_List myNode;  
//     int select=1;  
//     while(select)  
//     {  
//         cout<<"***********************************************\n";  
//         cout<<"*      [1] Init_Node_List_No_HeadInsert       *\n";  
//         cout<<"*      [2] Init_Node_List_No_BackInsert       *\n";  
//         cout<<"*      [3] Init_Node_List_Have_HeadInsert     *\n";  
//         cout<<"*      [4] Init_Node_List_Have_BackInsert     *\n";  
//         cout<<"*      [5] Show_Node_List_HaHead              *\n";  
//         cout<<"*      [6] Show_Node_List_NoHead              *\n";  
//         cout<<"*      [0] Quit                               *\n";  
//         cout<<"***********************************************\n";  
//     cout<<"Please select a number which represent you want to operate:>";   
//     cin>>select;  
//     switch(select)  
//     {  
//     case 1:  
//     Init_Node_List_No_HeadInsert(&myNode);//如果用的是Init_Node_List(Node **L)必须Init_Node_List(&myNode);  
//     break;  
//     case 2:  
//         Init_Node_List_No_BackInsert(&myNode);  
//     break;  
//     case 3:  
//         Init_Node_List_Have_HeadInsert(&myNode);  
//         break;  
//     case 4:  
//         Init_Node_List_Have_BackInsert(&myNode);  
//         break;  
//     case 5:  
//         Show_Node_List_HaHead(myNode);  
//         break;  
//     case 6:  
//         Show_Node_List_NoHead(myNode);  
//         break;  
//     default :  
//         cout<<"Thanks for  using!\n";  
//         break;  
//     }  
//     }  
// return 0;  
// }  





// //1.头插法初始化无头结点链表  
// void Init_Node_List_No_HeadInsert(Node **head)//Init_Node_List(Node *&L)或者Init_Node_List(Node_List &L)  
// {  
//     Node *p,*t;         //t工作指针,p临时指针*/  
//     int i=1,a;  
//     cout<<"please input datas (end of -1):";  
//     while(cin>>a,a!=-1)// while(scanf("%d",&a))  
//     {    if(a)  
//     {  
//         t=(Node *)malloc(sizeof(Node));//建立第一个节点  
//                if(!t)  
//                    {  
//                     cout<<"申请内存失败\n";  
//                     exit(0);  
//                      }  
//                 t->data=a;  
          
//         if(i==1)  
//         {  
//             t->next=NULL;//第一个节点指针置空，其实就是最后一个节点  
//         }  
//         else  
//         {  
              
//             t->next=p;  
//         }  
//         p=t;  
//     }  
//     i++;//记录节点数  
//     }  
//     if(i==1)//如果没有输入节点数据并且输入-1结束  
//     {  
//         exit(0);  
//     }  
//     *head=t;//头指针指向最前面的节点  
      
// }     
// //2.尾插法初始化无头结点链表  
// void Init_Node_List_No_BackInsert(Node **head)//Init_Node_List(Node *&L)或者Init_Node_List(Node_List &L)  
// {  
//     Node *p,*t;  //t工作指针,p临时指针  
//     int i=1,a;  
//     cout<<"please input datas (end of -1):";  
//     while(cin>>a,a!=-1)// while(scanf("%d",&a))  
//     {    if(a)  
//     {  
//         t=(Node *)malloc(sizeof(Node));//建立第一个节点  
          
//                if(!t)  
//                    {  
//                     cout<<"申请内存失败\n";  
//                     exit(0);  
//                      }  
//                t->data=a;  
//         if(i==1)  
//         {  
//             *head=t;//将头节点指向第一个节点  
//         }  
//         else  
//         {  
//             p->next=t;  
//         }  
//         p=t;//p指向建立的节点t  
//     }  
//     i++;//记录节点数  
//     }  
//     if(i==1)//如果没有输入节点数据并且输入-1结束  
//     {  
//         exit(0);  
//     }  
//     p->next=NULL;//将最后一个节点的指针域置空  
      
// }  
// //3.1 显示有头结点链表数据  
// void Show_Node_List_HaHead(Node_List L)//无需改变指针L所以值传递  
// {  
//     cout<<"链表节点：";  
//     while(L->next!=NULL)  
//     {  
          
//         cout<<L->next->data;  
//         if(L->next->next!=NULL)  
//         {  
//             cout<<"->";  
//         }  
//         L=L->next;  
          
//     }  
//     cout<<"\n";  
// }  
// //3.2显示无头结点链表数据  
// void Show_Node_List_NoHead(Node_List L)//无需改变指针L所以值传递  
// {  
//     cout<<"链表节点：";  
//     while(L!=NULL)  
//     {  
          
//         cout<<L->data;  
//         if(L->next!=NULL)  
//         {  
//             cout<<"->";  
//         }  
//         L=L->next;  
          
//     }  
//     cout<<"\n";  
// }  
// //4.尾插法初始化有头结点链表  
// void Init_Node_List_Have_BackInsert(Node **head)  
// {    Node *s;  
//     Node *r=*head=(Node*)malloc(sizeof(Node));  
//             if(!r)  
//                    {  
//                     cout<<"申请内存失败\n";  
//                     exit(0);  
//                      }  
//         (*head)->data=NULL;  
//         (*head)->next=NULL;  
//     int a,i=1;  
//     cout<<"please input datas (end of -1):";  
//      while(cin>>a,a!=-1){  
//           if(a){  
//                s=(Node *)malloc(sizeof(Node));  
                
//                if(!s)  
//                    {  
//                     cout<<"申请内存失败\n";  
//                     exit(0);  
//                      }  
//                s->data=a;  
//                r->next=s;  
//                r=s;      
//           }  
//           i++;  
//          }   
//      if(i==1)//如果没有输入节点数据并且输入-1结束  
//     {  
//         exit(0);  
//     }  
//      r->next=NULL;  
// }  
// //5.头插法初始化有头结点链表  
// void Init_Node_List_Have_HeadInsert(Node **head)  
// {  
//     Node *s;  
//     Node *r=*head=(Node*)malloc(sizeof(Node));  
//     (*head)->data=NULL;  
//     (*head)->next=NULL;  
// int a,i=1;  
//     cout<<"please input datas (end of -1):";  
//      while(cin>>a,a!=-1){  
//           if(a){  
//                s=(Node *)malloc(sizeof(Node));  
//                s->data=a;   
//               s->next=r->next;  
//                r->next=s;  
//                if(i==1)  
//                {  
//                s->next=NULL;  
//                }   
                
//           }  
//       i++;  
//          }   
//      if(i==1)//如果没有输入节点数据并且输入-1结束  
//     {  
//         exit(0);  
//     }  
       
// }  


