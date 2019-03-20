// #include <iostream>
// #include <string>

// using namespace std;


// #define OK 1
// #define ERROR 0
// #define TRUE 1
// #define FALSE 0
// typedef int Status;

// typedef int ElemType;

// typedef struct LNode
// {
// 	ElemType data;
// 	struct LNode *next;
// }LNode,*LinkList;

// Status GetElem_L(LinkList &L,int i,ElemType &e)
// {
// 	;
// 	return OK;
// }

// int main()
// {
// 	;
// 	return 0;
// }




// #define LOCAL
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;

// int main()
// {

// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif    

// 	char str[256];
// 	int n = 0;

// 	while(gets(str))
// 	{
// 		n = strlen(str);
// 		for(int i = 0; i < n; i++)
// 		{
// 			int flag = 0,count = 0;
// 			if(str[i] == ')')
// 				for(int j = i; j >= 0; j--)
// 				{
// 					if(str[j] == ')')
// 					{
// 						count++;
// 						flag++;
// 					}
// 					if(str[j] == '(')
// 						flag--;
// 					if(flag == 0)
// 					{
// 						cout<<count<<" ";
// 						break;
// 					}
// 				}
// 		}
// 		cout<<endl;
// 	}
	
// 	return 0;
// }









// // #define LOCAL
// #include <iostream>
// using namespace std;

// void conversion(int num)
// {
// 	if(num < 8)
// 		cout<<num;
// 	if(num >= 8)
// 	{
// 		conversion((num - num % 8) / 8);
// 		cout<<num % 8;
// 	}
// }

// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	int num;
// 	while(cin>>num)
// 	{
// 		conversion(num);
// 		cout<<endl;
// 	}

// 	return 0;
// }





// // #define LOCAL
// #include <iostream>
// using namespace std;
// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif

// 	int t,n;
// 	int fib[46] = {0,1};
// 	for(int i = 2; i < 46; i++)
// 	{
// 		fib[i] = fib[i-1] + fib[i-2];
// 	}
// 	cin>>t;
// 	while(t--)
// 	{
// 		cin>>n;
// 		cout<<fib[n]<<endl;
// 	}
// 	return 0;
// }




// // #define LOCAL
// #include <iostream>
// using namespace std;
// int count;
// void move(char x, int n, char z)
// {
// 	printf("%2d. Move disk %d from %c to %c\n",count++,n,x,z);
// }

// void hanoi(int n, char x, char y, char z)
// {
// 	if(n == 1)
// 		move(x,1,z);
// 	else
// 	{
// 		hanoi(n-1,x,z,y);
// 		move(x,n,z);
// 		hanoi(n-1,y,x,z);
// 	}

// }

// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	int n;
// 	while(cin>>n)
// 	{
// 		count = 1;
// 		hanoi(n,'X','Y','Z');
// 		cout<<endl;
// 	}
// 	return 0;
// }


// // #define LOCAL
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;

// int main()
// {

// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	char str[1001];
// 	int len,num[1001];
// 	int i,j,k;
// 	while(gets(str))
// 	{
// 		memset(num,0,sizeof(num));
// 		len = strlen(str);
// 		j = 0,k = 1;
// 		for(i = 0; i < len; i++)
// 		{
// 			if(str[i] == 'P')
// 			{
// 				num[j] = k++;
// 				j++;
// 			}
// 			if(str[i] == 'Q' && j != 0)
// 			{
// 				cout<<num[j-1]<<" ";
// 				j--;
// 			}
// 			else if(str[i] == 'Q' && j == 0)
// 			{
// 				cout<<"error";
// 				break;
// 			}

// 		}
// 		cout<<endl;
// 	}
// 	return 0;
// }




// // #define LOCAL
// #include <iostream>
// #include <cstring>
// using namespace std;

// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	int n;
// 	int num[1001];
// 	int value[1001];
// 	int i,j,k,count,m;
// 	while(cin>>n)
// 	{
// 		i = j = k = count = 0;
// 		m = 1;
// 		for(i = 0; i < n; i++)
// 			cin>>num[i];
// 		for(i = 0; i < n; i++)
// 		{
// 			if(num[i] >= m - 1)  
// 			{
// 				count = num[i] - m + 1;
// 				for(j = 0; j < count; j++)
// 				{
// 					value[k++] = m++;
// 					cout<<'P';
// 				}	
// 				cout<<'Q';
// 				k--;

// 			}
// 			if(num[i] < m - 1 && num[i] != value[k-1])   
// 			{
// 				cout<<" error";
// 				break;
// 			}
// 			if(num[i] < m - 1 && num[i] == value[k-1])
// 			{
// 				cout<<'Q';
// 				k--;
// 			}

// 		}
// 		cout<<endl;
// 	}
// }



// // #define LOCAL
// #include <iostream>
// #include <cstring>
// using namespace std;
// char str[205];

// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif	
	
// 	int flag,len;
// 	while(gets(str))
// 	{
// 		len = strlen(str);
// 		flag = 0;
// 		for(int i = 0; i < len; i++)
// 		{
// 			if(str[i] == '@')
// 				flag = i;
// 		}
// 		for(int i = flag + 1; i < len; i++)
// 		{
// 			int j = i;
// 			if(str[j] == '#')
// 			{
// 				while(str[j] == '#')
// 					j--;
// 				str[j] = '#';
// 			}
			
// 		}
// 		if(!flag)
// 			cout<<str[0];
// 		for(int i = flag + 1; i < len; i++)
// 		{
// 			if(str[i] != '#')
// 				cout<<str[i];
// 		}
// 		cout<<endl;
// 	}
// 	return 0;
// }



// #include <iostream>
// #include <algorithm>
// #include <bitset>
// #include <numeric>
// #include <utility>
// int main() {
//   for (int queens[] = {1,2,3,4,5,6,7,8}; ::std::next_permutation(queens,queens+8); )
//     if ((::std::bitset<15>(::std::accumulate(queens,queens+8, ::std::make_pair(0, 0), [](::std::pair<int, int> a, int b){return ::std::make_pair((1<<(b+a.second))|a.first,a.second+1);}).first).count() == 8) && (::std::bitset<15>(::std::accumulate(queens, queens+8, ::std::make_pair(0, 0), [](::std::pair<int, int> a, int b){return ::std::make_pair((1<<(7+b-a.second))|a.first, a.second+1);}).first).count() == 8))
//       ::std::cout << queens[0] << queens[1] << queens[2] << queens[3] << queens[4] << queens[5] << queens[6] << queens[7] << ::std::endl;
// }

// #include <iostream>
// int sum,ans[8];
// int solve(int n, long long mark, int *ans){
// 	for (int i=n>8?++sum&0:0; n>8&&i<8; i!=7?std::cout << ans[i++] << " " : std::cout << ans[i++] << std::endl);
// 	for (int i=0; i<8; !(mark>>i&1)&&!(mark>>(n+i+7)&1)&&!(mark>>(n-i+30)&1)?solve(n+(ans[n-1]=i+1)-i, mark|1ll<<i|1ll<<(n+i+7)|1ll<<(n-i+30), ans):0,i++);
// 	return sum;
// }
// int main(){
// 	std::cout << solve(1, 0, ans) << std::endl;
// }


// #include <cstdio>
// #define OCTGET(number, n)  ((number & (7 << n * 3)) >> n * 3)
// int main(){
//     for (int is_OK = 1,  i = 01234567; i < 076543210; i++, is_OK = 1){
//         for (int j = 0; (j < 8) && is_OK; j++)
//             for(int k = 0; k < 8; k++)
//                 if ((k != j) && ((OCTGET(i, j) == OCTGET(i, k))||(OCTGET(i, j) == OCTGET(i, k) + (k - j))||(OCTGET(i, j) == OCTGET(i, k) - (k - j)))) is_OK = 0;
//         if (is_OK) printf("%08o\n",i);
//     }
// }


// #include <iostream>
// #include <cstring>
// #include <cstdio>
// using namespace std;

// int queen[13],n;

// int valid(int row, int col)
// {
// 	for(int i = 0; i < n; i++)
// 	{
// 		if(queen[i] == col || abs(i - row) == abs(queen[i] - col))
// 			return 0;
// 	}
// 	return 1;
// }

// int main()
// {
// 	for (int i = 0; i < 13; i++)
// 	{
// 		queen[i] = -1000;
// 	}
// 	scanf("%d",&n);
// 	int i = 0, j = 0,count = 0;  
// 	while(i < n)
// 	{
// 		for(; j < n; j++)
// 		{
// 			if(valid(i,j))
// 			{
// 				queen[i] = j;
// 				j = 0;
// 				break;
// 			}
// 		}

// 		if(queen[i] == -1000)
// 		{
// 			if(i == 0)
// 				break;
// 			else
// 			{
// 				i--;
// 				j = queen[i] + 1;
// 				queen[i] = -1000;
// 				continue;
// 			}
// 		}

// 		if(i == n-1)
// 		{
// 			count++;
// 			if(count <= 3)
// 			{
// 				for (int i = 0; i < n; i++)
// 				{
// 					if(i)
// 						printf(" ");
// 					printf("%d",queen[i] + 1);
// 				}
// 				cout<<endl;
// 			}
// 			j = queen[i] + 1;
// 			queen[i] = -1000;
// 			continue;
// 		}
// 		i++;
// 	}
// 	cout<<count<<endl;
// 	return 0;
// }




// #include <cstdio>
// #include <climits> 
// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N=15; 
// int full,ans,cnt,i,n; 
// int path[N];
// bool row[N],l[N*2],r[N*2]; 
// void dfs(int a,int ld,int rd)
// {
// 	if(a==full)
// 	{
// 		ans++;
// 		return ; 
// 	} 
// 	int can=~(a|ld|rd)&full,p;//可以放得位置
// 	while(can!=0)
// 	{
// 		p=can&(~can+1);//取右数第一个1 
// 		can=can-p;
// 		dfs(a+p,(ld+p)<<1,(rd+p)>>1); 
// 	} 
// } 
// int f1(int p,int q)
// {
//    return (p+q-1); 
// } 
// int f2(int p,int q)
// {
//    return (p-q+n); 
// } 
// void dfs3(int step)
// {
//    	if(step>n)
// 	{
// 	  	cnt++;
// 	  	if(cnt>3) return; 
// 		 	for(int i=1;i<=n;i++)
// 		 	{
// 			  	if(i-1)
// 			  		printf(" ");
// 			  	printf("%d",path[i]);
// 		 	}
// 		 	printf("\n");  
// 	  	return ; 
// 	} 
// 	for(int i=1;i<=n;i++)
// 	  	if(!row[i] && !l[f1(step,i)] && !r[f2(step,i)])
// 	  	{
// 			row[i]=l[f1(step,i)]=r[f2(step,i)]=true;
// 			path[step]=i; 
// 			dfs3(step+1);
// 			row[i]=l[f1(step,i)]=r[f2(step,i)]=false;
// 			if(cnt>3) return; 
// 	  	} 
// } 
// int main()
// {
// 	scanf("%d",&n); 
// 	full=(1<<n)-1; 
// 	dfs(0,0,0); 
// 	dfs3(1); 
// 	printf("%d\n",ans); 
// 	return 0; 
// } 


// #define LOCAL
// #include <string.h>  
// #include <ctype.h>  
// #include <malloc.h> /* malloc()等 */  
// #include <limits.h> /* INT_MAX等 */  
// #include <stdio.h> /* EOF(=^Z或F6),NULL */  
// #include <stdlib.h> /* atoi() */  
// /* 函数结果状态代码 */  
// #define TRUE 1  
// #define FALSE 0  
// #define OK 1  
// #define ERROR 0  
// #define INFEASIBLE -1  
// #define OVERFLOW 0  
// typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */  
// typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */  
  
// #define MAXLENGTH 10 /* 设迷宫的最大行列为25 */  
// #define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */  
// #define STACKINCREMENT 2 /* 存储空间分配增量 */  
// typedef struct  
// {  
// 	int r, c;                // 以行号和列号作为“坐标位置”类型  
// } PosType;  
  
// typedef struct  
// {  
// 	int ord;                // 通道块在路径上的序号  
// 	PosType seat;        // 通道块在迷宫中的“坐标位置”  
// 	int di;                        // 从此通道块走向下一通道块的“方向”  
// } SElemType;                       // 定义堆栈元素的类型  
  
// typedef struct  
// {  
// 	SElemType * base;                        // 在栈构造之前和销毁之后，base的值为NULL  
// 	SElemType * top;                        // 栈顶指针  
// 	int stacksize;                                // 当前已分配的存储空间，以元素为单位  
// } SqStack;  
  
// typedef struct  
// {  
// 	char arr[10][11];  
// } MazeType;       // 定义迷宫类型（二维字符数组）  
  
  
// /* 定义墙元素值为0,可通过路径为1,不能通过路径为-1,通过路径为足迹 */  
  
// Status Pass(MazeType MyMaze, PosType CurPos)  
// {  
// 	if (MyMaze.arr[CurPos.r][CurPos.c]==' ' || MyMaze.arr[CurPos.r][CurPos.c]=='S' || MyMaze.arr[CurPos.r][CurPos.c]=='E')  
// 		return 1; // 如果当前位置是可以通过，返回1  
// 	else  
// 		return 0; // 其它情况返回0  
// }  
  
// void FootPrint(MazeType &MyMaze, PosType CurPos)  
// {  
// 	MyMaze.arr[CurPos.r][CurPos.c] = '*';  
// }  
  
// PosType NextPos(PosType CurPos, int Dir)  
// {  
// 	PosType ReturnPos;  
// 	switch (Dir)  
// 	{  
// 	case 1:  
// 		ReturnPos.r = CurPos.r;  
// 		ReturnPos.c = CurPos.c + 1;  
// 		break;  
// 	case 2:  
// 		ReturnPos.r = CurPos.r + 1;  
// 		ReturnPos.c = CurPos.c;  
// 		break;  
// 	case 3:  
// 		ReturnPos.r = CurPos.r;  
// 		ReturnPos.c = CurPos.c - 1;  
// 		break;  
// 	case 4:  
// 		ReturnPos.r = CurPos.r - 1;  
// 		ReturnPos.c = CurPos.c;  
// 		break;  
// 	}  
// 	return ReturnPos;  
// }  
// void MarkPrint(MazeType &MyMaze, PosType CurPos)  
// {  
// 	MyMaze.arr[CurPos.r][CurPos.c] = '!';  
// }  
  
// Status InitStack(SqStack *S)  
// {  
// 	/* 构造一个空栈S */  
// 	(*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));  
// 	if(!(*S).base)  
// 		exit(OVERFLOW); /* 存储分配失败 */  
// 	(*S).top=(*S).base;  
// 	(*S).stacksize=STACK_INIT_SIZE;  
// 	return OK;  
// }  
  
// Status Push(SqStack *S,SElemType e)  
// {  
// 	/* 插入元素e为新的栈顶元素 */  
// 	if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */  
// 	{  
// 		(*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));  
// 		if(!(*S).base)  
// 			exit(OVERFLOW); /* 存储分配失败 */  
// 		(*S).top=(*S).base+(*S).stacksize;  
// 		(*S).stacksize+=STACKINCREMENT;  
// 	}  
// 	*((*S).top)++=e;  
// 	return OK;  
// }  
  
// Status StackEmpty(SqStack S)  
// {  
// 	/* 若栈S为空栈，则返回TRUE，否则返回FALSE */  
// 	if(S.top==S.base)  
// 		return TRUE;  
// 	else  
// 		return FALSE;  
// }  
  
// Status Pop(SqStack *S,SElemType *e)  
// {  
// 	/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */  
// 	if((*S).top==(*S).base)  
// 		return ERROR;  
// 	*e=*--(*S).top;  
// 	return OK;  
// }  
  
// Status MazePath(MazeType &maze, PosType start, PosType end)  
// {  
// 	// 算法3.3  
// 	// 若迷宫maze中从入口 start到出口 end的通道，则求得一条存放在栈中  
// 	// （从栈底到栈顶），并返回TRUE；否则返回FALSE  
// 	SqStack S;  
// 	PosType curpos;  
// 	int curstep;  
// 	SElemType e;  
// 	InitStack(&S);  
// 	curpos = start; // 设定"当前位置"为"入口位置"  
// 	curstep = 1; // 探索第一步  
// 	do  
// 	{  
// 		if (Pass(maze, curpos))   // 当前位置可通过，即是未曾走到过的通道块  
// 		{  
// 			FootPrint(maze, curpos); // 留下足迹  
// 			e.di = 1;  
// 			e.ord = curstep;  
// 			e.seat = curpos;  
// 			Push(&S, e); // 加入路径  
// 			if (curpos.r == end.r && curpos.c == end.c)  
// 				return (TRUE); // 到达终点（出口）  
// 			curpos = NextPos(curpos, 1); // 下一位置是当前位置的东邻  
// 			curstep++; // 探索下一步  
// 		}  
// 		else     // 当前位置不能通过  
// 		{  
// 			if (!StackEmpty(S))  
// 			{  
// 				Pop(&S, &e);  
// 				while (e.di == 4 && !StackEmpty(S))  
// 				{  
// 					MarkPrint(maze, e.seat);  
// 					Pop(&S, &e); // 留下不能通过的标记，并退回一步  
// 				} // while  
// 				if (e.di < 4)  
// 				{  
// 					e.di++;  
// 					Push(&S, e); // 换下一个方向探索  
// 					curpos = NextPos(e.seat, e.di); // 当前位置设为新方向的相邻块  
// 				} // if  
// 			} // if  
// 		} // else  
// 	}  
// 	while (!StackEmpty(S));  
// 	return FALSE;  
// } // MazePath  
  
// int main()  
// {  

// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	int i, j;  
// 	PosType start, end;                                                // 起点终点坐标  
// 	MazeType maze;                                                        // 迷宫  
// 	memset(maze.arr, 0, sizeof(maze.arr)); // 将字符串设置为空  
// 	for(i=0; i<10; i++) // 读取迷宫数据  
// 	{  
// 		gets(maze.arr[i]);  
// 		for(j=0; j<10; j++)  
// 		{  
// 			if(maze.arr[i][j] == 'S') // 获得起点坐标  
// 			{  
// 				start.r = i;  
// 				start.c = j;  
// 			}  
// 			else if(maze.arr[i][j] == 'E')  // 获得终点坐标  
// 			{  
// 				end.r = i;  
// 				end.c = j;  
// 			}  
// 		}  
// 	}  
// 	MazePath(maze, start, end); // 移动  
// 	for(i=0; i<10; i++) // 输出状态  
// 	{  
// 		puts(maze.arr[i]);  
// 	}  
  
// 	return 0;  
// }  










// #define LOCAL
// #include <iostream>  
// #include <stack>  
// #include <cmath>  
// //#include <pzjay>  
// // #include <copy_right>  
// const int sup=1100;  
// const int no=4294967295;  
// stack < char > optr;  
// stack < int > opnd;  
  
// string Operator="+-*/^!()#";//不用转义  
// char expre[sup];  
// bool legal;  
  
// inline void init()  
// {  
//     legal=true;  
//     while(!optr.empty())  
//         optr.pop();  
//     while(!opnd.empty())  
//         opnd.pop();  
//     optr.push('#');  
// }  
// inline char PK(char a,char b)  
// {  
//     if('!'==b)  
//         return '<';  
//     if('#'==a)  
//     {  
//         if('#'==b)  
//             return '=';  
//         return '<';  
//     }  
//     if('#'==b)  
//         return '>';  
//     if('+'==a || '-'==a)  
//     {  
//         if('+'==b || '-'==b || ')'==b)  
//             return '>';  
//         return '<';  
//     }  
//     if('*'==a || '/'==a)  
//     {  
//         if('('==b)  
//             return '<';  
//         return '>';  
//     }  
//     if('('==a)  
//     {  
//         if(')'==b)  
//             return '=';  
//         return '<';  
//     }  
//     return '>';//剩下')'和'^'的情况，优先级最高  
// }  
// int factorial(int a)  
// {  
//     if(0==a)  
//         return 1;  
//     return a*factorial(a-1);  
// }  
// inline int calc(int a,int b,char c)  
// {  
//     switch (c)  
//     {  
//     case '+':  
//         return a+b;  
//     case '-':  
//         return a-b;  
//     case '/':  
//         if(0==b)  
//         {  
//             legal=false;  
//             return 0;  
//         }  
//         return a/b;  
//     case '*':  
//         return a*b;  
//     case '^':  
//         return pow(1.0*a,b);  
//     case '!':  
//         return factorial(a);  
//     }  
// }  
  
// int Evaluate_Expression()  
// {  
//     int i=0;  
//     int num=0;  
//     while(expre[i]!='#' || optr.top()!='#')  
//     {  
//         num=0;  
//         if(!legal)  
//             return -1;  
//         if( no==Operator.find(expre[i]) )  
//         {  
//             while( no==Operator.find(expre[i]) )  
//             {  
//                 num*=10;  
//                 num+=expre[i]-'0';  
//                 ++i;          
//             }  
//             opnd.push(num);  
//         }  
//         else  
//         {  
//             switch ( PK(optr.top(),expre[i]) )//比较运算符优先级  
//             {  
//             case '<'://栈顶运算符优先级低,暂不计算，新运算符入栈  
//                 optr.push(expre[i]);  
//                 ++i;  
//                 break;  
//             case '='://优先级相等，说明')'遇到了'(',那么脱去括号:')'不入栈，'('出栈  
//                 optr.pop();  
//                 ++i;  
//                 break;  
//             case '>'://栈顶运算符优先级高，暂停输入，计算  
//                 if(opnd.empty())  
//                 {  
//                     legal=false;  
//                     return -1;  
//                 }  
//                 int opa=opnd.top();  
//                 opnd.pop();  
//                 if(opnd.empty())  
//                 {  
//                     legal=false;  
//                     return -1;  
//                 }//假若运算符栈内还有元素而运算数栈里面却空了，说明出现了类似2*-3这种  
  
//                 int opb=opnd.top();  
//                 opnd.pop();  
//                 opnd.push( calc( opb,opa,optr.top() ) );//注意是opb 在前，opa在后  
//                 optr.pop();  
//                 break;  
//             }  
//         }  
//     }  
//     return opnd.top();  
// }  
// int main()  
// {  
	
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
//     while(scanf("%s",expre)!=EOF)  
//     {  
//         init();  
//         int len=strlen(expre);  
//         expre[len]='#';  
//         expre[++len]=0;  
  
//         int ans=Evaluate_Expression();  
  
//         if(!legal)  
//             printf("error/n");  
//         else  
//             printf("%d/n",ans);  
//     }  
//     return 0;  
// }  














#include <stdio.h>
#include <math.h>
#define QUEEN 13
int flag=0;
int site[QUEEN];
int judge(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(site[i]==site[n])
		return 0;
		if(abs(site[i] - site[n]) == (n - i))
		return 0;
	}
return 1;
}
void Output()
{ 
	int i; 
	printf("No.%-5d" , ++flag); 
	for(i = 0 ; i < QUEEN; i++) 
	printf("%d " , site[i]); 
	printf("\n");
} 
void Queen(int n)
{
	int i;
	if(n == QUEEN)
	{ 
		Output();
		return;
	}
	for(i=1;i<=QUEEN;i++)
	{
		site[n]=i;
		if(judge(n)==1)
		Queen(n+1);
	}
}
int main()
{
printf("***************************八皇后问题的求解**********************\n");
Queen(0);
}













































// //  #define DEBUG
// #define LOCAL
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>


// #define TRUE 1
// #define FALSE 0
// #define MAXLENGTH 1024
// //#define DEBUG

// typedef struct{
// 	char data[MAXLENGTH];
// 	int top;
// }operator_stack,*operator_stackptr;

// typedef struct{
// 	int data[MAXLENGTH];
// 	int top;
// }num_stack,*num_stackptr;

// //This function is to return the priority of operator
// int prior(char x)
// {
// 	switch(x)
// 	{
// 		case '+':
// 		case '-':
// 			return 3;
// 		case '*':
// 		case '/':
// 			return 4;
// 		default:
// 			exit(0);
// 	}
// }

// //this function is to calculate two num by a operator
// int calcu_two_num(char operat,int x,int y)
// {
// 	switch(operat)
// 	{
// 		case '*':
// 			return x*y;
// 		case '/':
// 			return x/y;
// 		case '-':
// 			return x-y;
// 		case '+':
// 			return x+y;
// 		default:
// 			return 0;
// 	}
// }

// void print_two_stack(operator_stackptr x,num_stackptr y)
// {
// 		int i=0;
// 		if(x->top==-1)
// 			printf("The operator_stack is empty\n");
// 		else
// 		{
// 			printf("The operator stack is :\n");
// 			for(i=0;i<=x->top;i++)
// 				printf("%c-->",x->data[i]);
// 			printf("top\n");
// 		}
// 		if(y->top==-1)
// 			printf("The num stack is empty\n");
// 		else
// 		{
// 			printf("The num stack is :\n");
// 			for(i=0;i<=y->top;i++)
// 				printf("%d-->",y->data[i]);
// 			printf("top\n\n");
// 		}
// }
// int calcu_by_stack(char *x)
// {
// 	//two operation number
// 	int num_1=0,num_2=0,result=0,i=0;
// 	char operator_1;
// 	//Create two stack
// 	operator_stack stack_op;
// 	num_stack stack_num;
// 	//Init the top pointer of these two stack
// 	stack_op.top=-1;
// 	stack_num.top=-1;

// 	if(x[i]=='(')
// 	{
// 		stack_op.data[++stack_op.top]='(';
// 		i++;
// 	}
// 	else
// 	{
// 		stack_num.data[++stack_num.top]=atoi(x);
// 		while(isdigit(x[++i])){;}
// 	}

// 	while(x[i]!='#')
// 	{
// 		if(isdigit(x[i]))
// 		{
// 			stack_num.data[++stack_num.top]=atoi(&x[i]);
// 			while(isdigit(x[++i]));
// 		}

// 		else
// 		{
// 			if(x[i]=='(')
// 			   stack_op.data[++stack_op.top]='(';
// 			else if(x[i]!=')')//When the operator is '+''-''*''/'
// 			{
// 				if(stack_op.top==-1)
// 					stack_op.data[++stack_op.top]=x[i];
// 				else if(stack_op.data[stack_op.top]=='(')
// 					stack_op.data[++stack_op.top]=x[i];
// 				else
// 				{
// 					while(prior(x[i])<=prior(stack_op.data[stack_op.top]))
// 					{
// 						num_1=stack_num.data[stack_num.top--];
// 						num_2=stack_num.data[stack_num.top--];
// 						result=calcu_two_num(stack_op.data[stack_op.top--],num_2,num_1);
// 						stack_num.data[++stack_num.top]=result;
// 						if(stack_op.top==-1)
// 							break;
// 					}
// 					stack_op.data[++stack_op.top]=x[i];
// 				}
// 			}
// 			else//When the operator is ')'
// 			{
// 				while((operator_1=stack_op.data[stack_op.top--])!='(')
// 				{
// 					num_1=stack_num.data[stack_num.top--];
// 					num_2=stack_num.data[stack_num.top--];
// 					stack_num.data[++stack_num.top]=calcu_two_num(operator_1,num_2,num_1);

// 				}

// 			}
// 			i++;
// 		}

// #ifdef DEBUG
// 	printf("the two stack is :\n");
// 	print_two_stack(&stack_op,&stack_num);
// #endif
// 	}

// 	while(stack_op.top!=-1&&stack_num.top!=0)
// 				{
// 					operator_1=stack_op.data[stack_op.top--];
// 					num_1=stack_num.data[stack_num.top--];
// 					num_2=stack_num.data[stack_num.top--];
// 					stack_num.data[++stack_num.top]=calcu_two_num(operator_1,num_2,num_1);

// 				}
// #ifdef DEBUG
// 	printf("The stack_num's top is %d\n\n",stack_num.top);
// #endif
// 	return stack_num.data[stack_num.top--];

// }


// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif

// 	char expression[MAXLENGTH];
// 	int i;
// 	while(~scanf("%s",expression))
// 	{
// 		i=calcu_by_stack(expression);
// 		printf("%d\n",i);
// 	}
// 	return 0;
// }




















































// #define LOCAL
// #include <iostream>
// #include <string>
// #include <stack>
// #include <cstdlib>
// #include <map>

// /*  中缀表达式转换成后缀表达式
// 	输入中缀表达式字符串infix，转化后返回后缀表达式字符串postfix
// 	输出串中，每一个数字后面放置一个#作为标识。因为数字使用char表达，234即三个char，“#”标识数字结束,
// 	做好数字完结标识后，即写入输出字符串中。
// 	遇到符号，左括号直接入栈；右括号时，将栈顶符号逐个取出写入输出字符串中，直到遇见左括号；
// 	运算符需循环与栈顶符号优先级进行比较：如果小于或者等于，取出栈顶符号写入输出字符串中，
// 	如果是左括号，直接入栈，如果优先级高于栈顶符号，入栈。
// */
// std::string InfixToPostfix(std::string infix)
// {
// 	char current = 0;
// 	std::string postfix;//后缀表达式

// 	std::stack<char> mark;//符号栈

// 	std::map<char,int> priority;//符号优先级
// 	priority['+'] = 0;
// 	priority['-'] = 0;
// 	priority['*'] = 1;
// 	priority['/'] = 1;

// 	for(unsigned i = 0;i < infix.size(); ++i)
// 	{
// 		current = infix[i];
// 		switch(current)
// 		{
// 			case '0':case '1':case '2':case '3':case '4':case '5':
// 			case '6':case '7':case '8':case '9':case '.':
// 				postfix.push_back(current);//数字直接写入
// 				break;
// 			case '+':case '-':case '*':case '/':
// 				//如果运算符的前一项不是右括号即说明前一个数字输入完毕，用#标识
// 				if(infix[i-1] != ')')
// 					postfix.push_back('#');
// 				//如果符号栈非空，即比较目前符号与栈顶符号优先级，低于等于出栈(并写入输出字符串)，
// 				//直至符号全部出栈或者遇到了'('或者大于栈顶符号的优先级
// 				if(!mark.empty())
// 				{
// 					char tempTop = mark.top();
// 					while(tempTop != '(' && priority[current] <= priority[tempTop])
// 					{
// 						postfix.push_back(tempTop);
// 						mark.pop();
// 						if(mark.empty())
// 							break;
// 						tempTop = mark.top();
// 					}
// 				}
// 				mark.push(current);//新符号入栈
// 				break;
// 			case '(':
// 				if(infix[i-1] >= '0' && infix[i-1] <= '9')// for expression 2-5*2(6/2)
// 				{
// 					postfix.push_back('#');
// 					mark.push('*');
// 				}
// 				mark.push(current);
// 				break;
// 			case ')':
// 				postfix.push_back('#');//右括号说明前方数字输入完成，标识一下
// 				while(mark.top() != '(')
// 				{
// 					postfix.push_back(mark.top());
// 					mark.pop();
// 				}
// 				mark.pop();//左括号出栈
// 				break;
// 			default:
// 				break;//忽略其他字符
// 		}
// 	}
// 	if(infix[infix.size()-1] != ')')
// 		postfix.push_back('#');//中缀表达式最后一个是数字需要加上#。
// 	while(!mark.empty())//如果栈非空，全部出栈并写入输出字符串
// 	{
// 		postfix.push_back(mark.top());
// 		mark.pop();
// 	}
// 	return postfix;
// }

// /*  计算后缀表达式结果
// 	输入为后缀表达式s，逐个读取字符，如果是数字即放入存放当前数字的字符串中，
// 	遇到“#”即将此字符串转换为int，
// 	使用atof()，参数接受const char*类型，字符串需使用.c_str()转化。
// 	完成数字识别转化后入栈，遇到符号即取出栈顶的两个数字计算，结果入栈。
// 	栈中最后的元素即为结果。
// */
// int posfixCompute(std::string s)
// {
// 	std::stack<int> tempResult;

// 	std::string strNum;
// 	int currNum = 0;

// 	int tempNum = 0;
// 	for(std::string::const_iterator i = s.begin(); i != s.end(); ++i)
// 	{
// 		switch(*i)
// 		{
// 			case '0':case '1':case '2':case '3':case '4':case '5':
// 			case '6':case '7':case '8':case '9':case '.':
// 				strNum.push_back(*i);
// 				break;
// 			case '+':
// 				tempNum = tempResult.top();
// 				tempResult.pop();
// 				tempNum += tempResult.top();
// 				tempResult.pop();
// 				tempResult.push(tempNum);
// 				break;
// 			case '-':
// 				tempNum = tempResult.top();
// 				tempResult.pop();
// 				tempNum = tempResult.top() - tempNum;
// 				tempResult.pop();
// 				tempResult.push(tempNum);
// 				break;
// 			case '*':
// 				tempNum = tempResult.top();
// 				tempResult.pop();
// 				tempNum *= tempResult.top();
// 				tempResult.pop();
// 				tempResult.push(tempNum);
// 				break;
// 			case '/':
// 				tempNum = tempResult.top();
// 				tempResult.pop();
// 				tempNum = tempResult.top() / tempNum;
// 				tempResult.pop();
// 				tempResult.push(tempNum);
// 				break;
// 			case '#':
// 				currNum = atof(strNum.c_str());//in c++11, use currNum = std::stof(strNUm);
// 				strNum.clear();
// 				tempResult.push(currNum);
// 				break;
// 		}
// 	}
// 	return tempResult.top();
// }

// int expressionCalculate(std::string s)
// {
// 	return posfixCompute(InfixToPostfix(s));
// }

// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif

// 	std::string test;
	
// 	while(std::cin>>test)
// 	{
// 		test.erase(test.end()-1);
// 		std::cout<< expressionCalculate(test)<<std::endl;
// 	}
// 	return 0;
// }



// #define LOCAL
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;

// int windows[20];
// int come_time[200];
// int hand_time[200];
// int wait_time[200];

// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	int m,total,total_wait_time;
// 	while(cin>>m>>total)
// 	{
// 		total_wait_time = 0;
// 		memset(windows,0,sizeof(windows));
// 		for(int i = 0; i < total; i++)
// 			cin>>come_time[i]>>hand_time[i];
// 		for(int i = 0; i < total; i++)
// 		{
// 			if(come_time[i] > windows[m-1])
// 			{
// 				for (int j = 0; j < m; j++)
// 				{
// 					windows[j] = come_time[i];
// 				}
// 			}
// 			wait_time[i] = (windows[0] - come_time[i] >= 0)?(windows[0] - come_time[i]):0;
// 			windows[0] = windows[0] + ((come_time[i]-windows[0]>0)?(come_time[i]-windows[0]):0) + hand_time[i];
// 			sort(windows,windows+m);
// 		}
// 		for (int i = 0; i < total; i++)
// 		{
// 			total_wait_time += wait_time[i];
// 		}
// 		printf("%.2f\n",(float)total_wait_time/total);
// 	}
// 	return 0;
// }












































// #include <string.h>  
// #include <ctype.h>  
// #include <malloc.h> /* malloc()等 */  
// #include <limits.h> /* INT_MAX等 */  
// #include <stdio.h> /* EOF(=^Z或F6),NULL */  
// #include <stdlib.h> /* atoi() */  
// /* 函数结果状态代码 */  
// #define TRUE 1  
// #define FALSE 0  
// #define OK 1  
// #define ERROR 0  
// #define INFEASIBLE -1  
// #define OVERFLOW 0  
// typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */  
// typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */  
  
// #define MAXLENGTH 25 /* 设迷宫的最大行列为25 */  
// #define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */  
// #define STACKINCREMENT 2 /* 存储空间分配增量 */  
// typedef struct  
// {  
// 	int r, c;                // 以行号和列号作为“坐标位置”类型  
// } PosType;  
  
// typedef struct  
// {  
// 	int ord;                // 通道块在路径上的序号  
// 	PosType seat;        // 通道块在迷宫中的“坐标位置”  
// 	int di;                        // 从此通道块走向下一通道块的“方向”  
// } SElemType;                       // 定义堆栈元素的类型  
  
// typedef struct  
// {  
// 	SElemType * base;                        // 在栈构造之前和销毁之后，base的值为NULL  
// 	SElemType * top;                        // 栈顶指针  
// 	int stacksize;                                // 当前已分配的存储空间，以元素为单位  
// } SqStack;  
  
// typedef struct  
// {  
// 	char arr[10][11];  
// } MazeType;       // 定义迷宫类型（二维字符数组）  
  
  
// /* 定义墙元素值为0,可通过路径为1,不能通过路径为-1,通过路径为足迹 */  
  
// Status Pass(MazeType MyMaze, PosType CurPos)  
// {  
// 	if (MyMaze.arr[CurPos.r][CurPos.c]==' ' || MyMaze.arr[CurPos.r][CurPos.c]=='S' || MyMaze.arr[CurPos.r][CurPos.c]=='E')  
// 		return 1; // 如果当前位置是可以通过，返回1  
// 	else  
// 		return 0; // 其它情况返回0  
// }  
  
// void FootPrint(MazeType &MyMaze, PosType CurPos)  
// {  
// 	MyMaze.arr[CurPos.r][CurPos.c] = '*';  
// }  
  
// PosType NextPos(PosType CurPos, int Dir)  
// {  
// 	PosType ReturnPos;  
// 	switch (Dir)  
// 	{  
// 	case 1:  
// 		ReturnPos.r = CurPos.r;  
// 		ReturnPos.c = CurPos.c + 1;  
// 		break;  
// 	case 2:  
// 		ReturnPos.r = CurPos.r + 1;  
// 		ReturnPos.c = CurPos.c;  
// 		break;  
// 	case 3:  
// 		ReturnPos.r = CurPos.r;  
// 		ReturnPos.c = CurPos.c - 1;  
// 		break;  
// 	case 4:  
// 		ReturnPos.r = CurPos.r - 1;  
// 		ReturnPos.c = CurPos.c;  
// 		break;  
// 	}  
// 	return ReturnPos;  
// }  
// void MarkPrint(MazeType &MyMaze, PosType CurPos)  
// {  
// 	MyMaze.arr[CurPos.r][CurPos.c] = '!';  
// }  
  
// Status InitStack(SqStack *S)  
// {  
// 	/* 构造一个空栈S */  
// 	(*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));  
// 	if(!(*S).base)  
// 		exit(OVERFLOW); /* 存储分配失败 */  
// 	(*S).top=(*S).base;  
// 	(*S).stacksize=STACK_INIT_SIZE;  
// 	return OK;  
// }  
  
// Status Push(SqStack *S,SElemType e)  
// {  
// 	/* 插入元素e为新的栈顶元素 */  
// 	if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */  
// 	{  
// 		(*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));  
// 		if(!(*S).base)  
// 			exit(OVERFLOW); /* 存储分配失败 */  
// 		(*S).top=(*S).base+(*S).stacksize;  
// 		(*S).stacksize+=STACKINCREMENT;  
// 	}  
// 	*((*S).top)++=e;  
// 	return OK;  
// }  
  
// Status StackEmpty(SqStack S)  
// {  
// 	/* 若栈S为空栈，则返回TRUE，否则返回FALSE */  
// 	if(S.top==S.base)  
// 		return TRUE;  
// 	else  
// 		return FALSE;  
// }  
  
// Status Pop(SqStack *S,SElemType *e)  
// {  
// 	/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */  
// 	if((*S).top==(*S).base)  
// 		return ERROR;  
// 	*e=*--(*S).top;  
// 	return OK;  
// }  
  
// Status MazePath(MazeType &maze, PosType start, PosType end)  
// {  
// 	// 算法3.3  
// 	// 若迷宫maze中从入口 start到出口 end的通道，则求得一条存放在栈中  
// 	// （从栈底到栈顶），并返回TRUE；否则返回FALSE  
// 	SqStack S;  
// 	PosType curpos;  
// 	int curstep;  
// 	SElemType e;  
// 	InitStack(&S);  
// 	curpos = start; // 设定"当前位置"为"入口位置"  
// 	curstep = 1; // 探索第一步  
// 	do  
// 	{  
// 		if (Pass(maze, curpos))   // 当前位置可通过，即是未曾走到过的通道块  
// 		{  
// 			FootPrint(maze, curpos); // 留下足迹  
// 			e.di = 1;  
// 			e.ord = curstep;  
// 			e.seat = curpos;  
// 			Push(&S, e); // 加入路径  
// 			if (curpos.r == end.r && curpos.c == end.c)  
// 				return (TRUE); // 到达终点（出口）  
// 			curpos = NextPos(curpos, 1); // 下一位置是当前位置的东邻  
// 			curstep++; // 探索下一步  
// 		}  
// 		else     // 当前位置不能通过  
// 		{  
// 			if (!StackEmpty(S))  
// 			{  
// 				Pop(&S, &e);  
// 				while (e.di == 4 && !StackEmpty(S))  
// 				{  
// 					MarkPrint(maze, e.seat);  
// 					Pop(&S, &e); // 留下不能通过的标记，并退回一步  
// 				} // while  
// 				if (e.di < 4)  
// 				{  
// 					e.di++;  
// 					Push(&S, e); // 换下一个方向探索  
// 					curpos = NextPos(e.seat, e.di); // 当前位置设为新方向的相邻块  
// 				} // if  
// 			} // if  
// 		} // else  
// 	}  
// 	while (!StackEmpty(S));  
// 	return FALSE;  
// } // MazePath  
  
// int main()  
// {  

// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	int i, j;  
// 	PosType start, end;                                                // 起点终点坐标  
// 	MazeType maze;                                                        // 迷宫  
// 	memset(maze.arr, 0, sizeof(maze.arr)); // 将字符串设置为空  
// 	for(i=0; i<10; i++) // 读取迷宫数据  
// 	{  
// 		gets(maze.arr[i]);  
// 		for(j=0; j<10; j++)  
// 		{  
// 			if(maze.arr[i][j] == 'S') // 获得起点坐标  
// 			{  
// 				start.r = i;  
// 				start.c = j;  
// 			}  
// 			else if(maze.arr[i][j] == 'E')  // 获得终点坐标  
// 			{  
// 				end.r = i;  
// 				end.c = j;  
// 			}  
// 		}  
// 	}  
// 	MazePath(maze, start, end); // 移动  
// 	for(i=0; i<10; i++) // 输出状态  
// 	{  
// 		puts(maze.arr[i]);  
// 	}  
  
// 	return 0;  
// }  




































// #include <iostream>  
// #include <stack>  
// #include <cstdio>  
  
// using namespace std;  
  
// #define N 10  
  
// struct MazeCell{  
//     int i,j; //行列  
//     char sign;  //符号  
//     int direction; //1 2 3 4分别表示东南西北  
// };  
  
// class Maze{  
// private:  
//     MazeCell Map[N][N];  
//     MazeCell start;  
//     MazeCell end;  
// public:  
//     void inputMap(){  
//         for(int i = 0; i < N; i++){  
//             char str[N+1];  
//             gets(str);  
//             for(int j = 0; j < N; j++){  
//                 this->Map[i][j].sign = str[j];  
//                 this->Map[i][j].direction = 0;  
//                 this->Map[i][j].i = i;  
//                 this->Map[i][j].j = j;  
  
//                 if(this->Map[i][j].sign == 'S'){  
//                     this->start = this->Map[i][j];  
//                 }  
//                 if(this->Map[i][j].sign == 'E'){  
//                     this->end = this->Map[i][j];  
//                 }  
//             }  
//         }  
//     }  
  
//     void print(){  
//         for(int i = 0; i < N; i++){  
//             for(int j = 0; j < N; j++){  
//                 if(0) cout << this->Map[i][j].direction;  
//                 else  cout << this->Map[i][j].sign;  
//             }  
//             cout << endl;  
//         }  
//     }  
  
//     bool IsPath(int i,int j){  
//         return this->Map[i][j].sign != '!' &&  this->Map[i][j].sign != '#' && this->Map[i][j].direction == 0;  
//     }  
  
//     void findPath(){  
//         stack<MazeCell> path;  
//         path.push(this->start);  
//         MazeCell m = this->start;  
//         int count = 0;  
//         while(!path.empty() && path.top().sign != this->end.sign){  
//             if(count++ == 1000) {break;}  
//             //cout << count << endl;  
//             m = path.top();  
//             int i = m.i,j = m.j;  
//             m = this->Map[i][j];  //第一步：取栈顶  
//             if(m.direction == 0 || m.direction == 1){  
//                 //东  
//                 ++j;  
//                 if(IsPath(i,j)){  
//                     path.push(this->Map[i][j]);  //下一步可走，压入栈中  
//                     this->Map[m.i][m.j].sign = '*'; //标记当前可走  
//                     this->Map[m.i][m.j].direction = 1;  
//                 }else  
//                 {this->Map[m.i][m.j].direction = 2;} //走不通就换方向  
//                 }  
//             else if(m.direction == 2){  
//                 //南  
//                 i++;  
//                 if(IsPath(i,j)){  
//                     path.push(this->Map[i][j]);  //下一步可走，压入栈中  
//                     this->Map[m.i][m.j].sign = '*'; //标记当前可走  
//                     this->Map[m.i][m.j].direction = 2;  
//                 }else  
//                 {this->Map[m.i][m.j].direction = 3; }//走不通就换方向  
//             }  
//             else if(m.direction == 3){  
//                 //西  
//                 j--;  
//                 if(IsPath(i,j)){  
//                     path.push(this->Map[i][j]);  //下一步可走，压入栈中  
//                     this->Map[m.i][m.j].sign = '*'; //标记当前可走  
//                     this->Map[m.i][m.j].direction = 3;  
//                 }else this->Map[m.i][m.j].direction = 4; //走不通就换方向  
//             }  
//             else if(m.direction == 4){  
//                 //北  
//                 i--;  
//                 if(IsPath(i,j)){  
//                     path.push(this->Map[i][j]);  //下一步可走，压入栈中  
//                     this->Map[m.i][m.j].sign = '*'; //标记当前可走  
//                     this->Map[m.i][m.j].direction = 4;  
//                 }else this->Map[m.i][m.j].direction = 5; //走不通就换方向  
//             }  
//             else if(m.direction == 5){  
//                 this->Map[m.i][m.j].sign = '!';  
//                 path.pop();  
//                 continue;  
//             }  
//             else {Map[m.i][m.j].sign = '!';break;}  
//         }  
//         if(path.empty()) return;  
//         this->Map[this->end.i][this->end.j].sign = '*';  
//     }  
// };  
  
  
// int main(){  
// #ifdef LOCAL
//     freopen("input.txt","r",stdin);   
// #endif
  
//     Maze m;  
//     m.inputMap();  
//     m.findPath();  
//     m.print();  
  
//     return 0;  
// }  


































