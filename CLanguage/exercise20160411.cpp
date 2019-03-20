//第八次周赛


// #include <iostream>
// using namespace std;
// int main()
// {
// 	int sum,k,count,a[2000];
// 	while(cin>>sum>>k)
// 	{
// 		count = 0;
// 		for(int i = 0; i < k; i++)
// 			cin>>a[i];
// 		for(int i = 0; i < k; i++)
// 			for (int j = i; j < k; j++)
// 			{
// 				if((a[i]+a[j])==sum)
// 					count++;
// 			}
// 		cout<<count<<endl;
// 	}
// 	return 0;
// }


// #include <iostream>
// #include <cstdio>
// using namespace std;
// int num; // 全局变量
// void dfs(int n)
// {
// 	if(n==1)
// 	{
// 		num++;
// 		return;
// 	}
// 	for(int i=2;i<=n;i++)
//     	if(!(n%i))
// 			dfs(n/i);
// }
// int main()
// {
// 	int T,n;
// 	cin>>T;
// 	while(T--)
// 	{
// 		num=0;
// 		cin>>n;
// 		dfs(n);
// 		cout<<num<<endl;
// 	}
// 	return 0;
// }



// #define LOCAL
// #define MEM0(a) memset(a, 0, sizeof(a))
// #include <stdio.h>
// #include <string.h>
// int C[1005][1005]; // 全局变量,默认初始化
// void init(void) // 杨辉三角
// {
// 	C[0][0] = 1;
// 	for(int i = 1; i < 1005; ++i)
// 	{
// 		for(int j = 0; j < 1005; ++j)
// 		{
// 			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 10007;
// 		}
// 	}
// }
// long long f(int a, int k) // a的k次幂
// {
// 	long long ans = 1;
// 	for(int i = 0; i < k; ++i)
// 	{
// 		ans *= a;
// 		ans %= 10007;
// 	}
// 	return ans;
// }
// int main(void)
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	init();
// 	int a, b, k, n, m;
// 	while(~scanf("%d%d%d%d%d", &a, &b, &k, &n, &m))
// 	{
// 		long long ans = C[k][m];
// 		ans *= f(a, n);
// 		ans %= 10007;
// 		ans *= f(b, m);
// 		ans %= 10007;
// 		printf("%lld\n", ans);
// 	}
// 	return 0;
// }



// #include <iostream>
// #include <algorithm>
// using namespace std;
// int dp[20005];
// int main(void)
// {
// 	int v, n, num;
// 	cin>>v>>n;
// 	for(int i = 0; i < n; i++)
// 	{
// 		cin>>num;
// 		for(int j = v; j >= num; j--)
// 			dp[j] = max(dp[j], dp[j - num] + num);
// 	}
// 	cout<<v - dp[v]<<endl;
// 	return 0;
// }



// #include <iostream>
// #include <cstdio>
// #include <cstring>

// #define MEM0(a) memset(a, 0, sizeof(a))

// using namespace std;

// bool vis(int x,int y) // 判断是否包含0-9
// {
//  	int i,book[10];
// 	MEM0(book);
// 	if(x<1234)
// 		return 0;
// 	for(i=0;i<5;i++)
// 	{
// 		book[x%10]++;
// 		x/=10;
// 		book[y%10]++;
// 		y/=10;
// 	}
// 	for(i=0;i<=9;i++)
// 		if(book[i]>1)
// 			return 0;
// 	return 1;
// }

// int main(void)
// {
// 	int n,i;
// 	while(cin>>n)
// 		for(i=15;n*i<=98765;i++) // 乘法暴力,79*15<1234
// 			if(vis(i,n*i))
// 				printf("%05d/%05d=%d\n",n*i,i,n);
// 	return 0;
// }


// #include <stdio.h>
// #include <string.h>
// #include <algorithm>
// using namespace std;
// int book[10];
// bool vis(int x)//判断每个数字是不是都存在于数字集合里
// {
//     int i,j;
//     while(x)
//     {
//         if(book[x%10]!=1)
//             return 0;
//         x/=10;
//     }
//     return 1;
// }
// int main(void)
// {
//     int i,j,n;
//     char a[110000];
//     while(scanf("%s",a)!=EOF)
//     {
//         n=strlen(a);
//         memset(book,0,sizeof(book));
//         int ans=0;
//         for(i=0;i<n;i++)
//         {
//             a[i]-='0';
//             book[a[i]]=1;
//         }
//         for(i=100;i<=999;i++)
//         {
//             for(j=10;j<=99;j++)
//             {
//                 int temp=(j%10)*i;
//                 int temp1=(j/10)*i;
//                 if(vis(i)&&vis(temp)&&vis(temp1)&&vis(j)&&vis(i*j)) 
//                     ans++;
//             }
//         }
//         printf("%d\n",ans);
//     }
//     return 0;
// }


// #include <iostream>
// #include <algorithm>

// using namespace std;

// long KK[1000005];

// void solve(long K[],long n,long m)
// {
// 	for(long c= 0; c < n; c++)
// 	{
// 		for(long d = 0; d < n; d++)
// 		{
// 			KK[c*n+d] = K[c]+K[d];
// 		}
// 	}

// 	sort(KK,KK+n*n);

// 	for(long a = 0; a < n; a++)
// 	{
// 		for(long b = 0; b < n; b++)
// 			if(binary_search(KK,KK+n*n,m-K[a]-K[b]))  // 二分法
// 			{
// 				cout<<"Yes"<<endl;
// 				return;
// 			}
// 	}

// 	cout<<"No"<<endl;
// 	return;
// }


// int main()
// {
// 	long k[1005],m,n;
// 	cin>>n>>m;
// 	for(int i = 0; i < n; i++)
// 		cin>>k[i];
// 	solve(k,n,m);
// 	return 0;
// }




// #include <stdio.h>

// int jiecheng(int n)
// {
// 	int m = 1;
// 	for(int i = 1; i <= n; i++)
// 		m *= i;
// 	return m;
// }

// int main()
// {
// 	double e = 0;
// 	printf("n e\n");
// 	printf("- -----------\n");
// 	for(int i = 0; i < 10; i++)
// 	{
// 		e += 1./jiecheng(i);
// 		if(i == 0 || i == 1)
// 			printf("%d %1.0f\n",i,e);
// 		else if(i == 2)
// 			printf("%d %1.1f\n",i,e);
// 		else
// 			printf("%d %1.9f\n",i,e);
// 	}
// 	return 0;
// }



// #define LOCAL
// #include <iostream>
// #include <cstdio>
// using namespace std;

// int sqr[101][101];
// int n,m;

// void xiaochu(int a,int b)
// {
// 	int flag = 0;
// 	if(a >= 0 && a < n && b >= 1 && b+1 < n)
// 		if(sqr[a][b] == sqr[a][b+1])
// 		{
// 			xiaochu(a,b+1);
// 			sqr[a][b] = 0;
// 			flag = 1;
// 		}
// 	if(a >= 0 && a < n && b-1 >= 1 && b < n)
// 		if(sqr[a][b] == sqr[a][b-1])
// 		{
// 			xiaochu(a,b-1);
// 			sqr[a][b] = 0;
// 			flag = 1;
// 		}
// 	if(a-1 >= 0 && a < n && b >= 1 && b < n)
// 		if(sqr[a][b] == sqr[a-1][b])
// 		{
// 			xiaochu(a-1,b);
// 			sqr[a-1][b] = 0;
// 			flag = 1;
// 		}
// 	if(!flag)
// 		return;

// }

// int main()
// {

// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #-endif

// 	cin>>n>>m;

// 	for(int i = 0; i < n; i++)
// 		for(int j = 0; j < n; j++)
// 		{
// 			cin>>sqr[i][j];
// 		}

// 	xiaochu(n-1,m-1);

// 	for(int i = 0; i < n; i++)
// 	{
// 		for(int j = 0; j < n; j++)
// 		{
// 			cout<<sqr[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	return 0;
// }























// #define LOCAL
// #include <iostream>
// using namespace std;

// struct poly
// {
// 	int coef;
// 	int exp;
// }a[10000],b[10000];
// int sum[10000];
// int main()
// {

// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif

// 	int m = 0, n = 0;
// 	while(cin>>a[n].coef>>a[n].exp && a[n].exp != -1)
// 	{
// 		n++;
// 	}
// 	while(cin>>b[m].coef>>b[m].exp && b[m].exp != -1)
// 	{
// 		m++;
// 	}

// 	for(int i = 0; i < n; i++)
// 	{
// 		for(int j = 0; j < m; j++)
// 		{
// 			sum[a[i].exp + b[j].exp] += a[i].coef * b[j].coef;
// 		}
// 	}
	
// 	int flag = 0;
// 	for(int i = 9999; i >= 0; i--)
// 	{
// 		if(sum[i])
// 		{
// 			cout<<sum[i]<<" "<<i<<" ";
// 			flag = 1;
// 		}
// 	}
// 	if(!flag)
// 		cout<<"0"<<endl;
// 	return 0;
// }


// #define LOCAL
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int a[200],b[200];

// int main()
// {
	
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif

// 	int m,n;
// 	cin>>m;
// 	for(int i = 0; i < m; i++)
// 		cin>>a[i];
// 	cin>>n;
// 	for(int i = 0; i < n; i++)
// 		cin>>b[i];
// 	for(int i = 0; i < n; i++)
// 	{
// 		a[m++] = b[i];
// 	}
		
// 	sort(a,a+m);
// 	for(int i = 0; i < m; i++)
// 	{
// 		if(i)
// 			cout<<" ";
// 		cout<<a[i];
// 	}
// 	return 0;
// }


// #define LOCAL
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define LIST_INIT_SIZE 100         // 线性表存储空间的初始分配量
// #define LISTINCREMENT 10        // 线性表存储空间的分配增量
// typedef int Status;                        // 定义返回值状态类型
// #define OK 1
// #define ERROR 0
// typedef struct{                // 定义数据类型，存放的是一个名字，所以只有字符数组
//         char name[100];
// }ElemType;
// typedef struct{
//         ElemType * elem;        // 存储空间基址
//         int length;                        // 当前长度
//         int listsize;                // 当前分配的存储容量（以sizeof(ElemType)为单位）
// }SqList;
// Status InitList_Sq(SqList *L) { // 算法2.3
//         // 构造一个空的线性表L。
//         L->elem = (ElemType *) malloc(LIST_INIT_SIZE*sizeof(ElemType));
//         if (!L->elem)
//                 return OK; // 存储分配失败
//         L->length = 0; // 空表长度为0
//         L->listsize = LIST_INIT_SIZE; // 初始存储容量
//         return OK;
// } // InitList_Sq
// Status ListInsert_Sq(SqList *L, int i, ElemType e) { // 算法2.4
//         // 在顺序线性表L的第i个元素之前插入新的元素e，
//         // i的合法值为1≤i≤ListLength_Sq(L)+1
//         ElemType *p;
//         if (i < 1 || i > L->length + 1)
//                 return ERROR; // i值不合法
//         if (L->length >= L->listsize) { // 当前存储空间已满，增加容量
//                 ElemType *newbase = (ElemType *) realloc(L->elem, (L->listsize
//                                 + LISTINCREMENT) * sizeof(ElemType));
//                 if (!newbase)
//                         return ERROR; // 存储分配失败
//                 L->elem = newbase; // 新基址
//                 L->listsize += LISTINCREMENT; // 增加存储容量
//         }
//         ElemType *q = &(L->elem[i - 1]); // q为插入位置
//         for (p = &(L->elem[L->length - 1]); p >= q; --p)
//                 *(p + 1) = *p;
//         // 插入位置及之后的元素右移
//         *q = e; // 插入e
//         ++L->length; // 表长增1
//         return OK;
// } // ListInsert_Sq
// Status ListDelete_Sq(SqList *L, int i, ElemType *e) { // 算法2.5
//         // 在顺序线性表L中删除第i个元素，并用e返回其值。
//         // i的合法值为1≤i≤ListLength_Sq(L)。
//         ElemType *p, *q;
//         if (i < 1 || i > L->length)
//                 return ERROR; // i值不合法
//         p = &(L->elem[i - 1]); // p为被删除元素的位置
//         *e = *p; // 被删除元素的值赋给e
//         q = L->elem + L->length - 1; // 表尾元素的位置
//         for (++p; p <= q; ++p)
//                 *(p - 1) = *p; // 被删除元素之后的元素左移
//         --L->length; // 表长减1
//         return OK;
// } // ListDelete_Sq
// int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) { // 算法2.6
//         // 在顺序线性表L中查找第1个值与e满足compare()的元素的位序。
//         // 若找到，则返回其在L中的位序，否则返回0。
//         int i;
//         ElemType *p;
//         i = 1; // i的初值为第1个元素的位序
//         p = L.elem; // p的初值为第1个元素的存储位置
//         while (i <= L.length && !(*compare)(*p++, e))
//                 ++i;
//         if (i <= L.length)
//                 return i;
//         else
//                 return 0;
// } // LocateElem_Sq
// void ListShow(SqList L){
//         // 将顺序表中的所有元素都显示出来，每个姓名之间用空格分开
//         int i;
//         for(i=0;i<L.length;i++){
//                 if(i){                // 用来判断是否需要输出空格
//                         putchar(' ');
//                 }
//                 printf("%s", L.elem[i].name);        // 输出姓名
//         }
//         putchar('\n');        // 注意最后需要换行
// }
// Status cmp(ElemType e1, ElemType e2){
//         // 用来比较两个ElemType元素是否相等
//         return (Status)!strcmp(e1.name, e2.name);
// }
// int main(){

// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif

//         SqList namelist;                // 定义姓名列表
//         InitList_Sq(&namelist);        // 初始化姓名列表
//         char strInstruct[10];        // 用来保存每行开头的指令
//         int pos;                                // 用来保存插入或者搜索的位置
//         ElemType e;                                // 用来保存姓名的节点
//         while(scanf("%s", strInstruct) != EOF){
//                 if(strcmp(strInstruct, "insert") == 0){        // 插入姓名
//                         scanf("%d%s" ,&pos, e.name);                // 读取待插入的位置与姓名
//                         ListInsert_Sq(&namelist, pos, e);        // 将姓名插入到pos之前
//                 }else if(strcmp(strInstruct, "show") == 0){        // 显示列表中所有的元素
//                         ListShow(namelist);
//                 }else if(strcmp(strInstruct, "delete") == 0){        // 删除某个姓名
//                         scanf("%s", e.name);                // 读取需要删除的元素
//                         // 先查找这个姓名在列表中的位置
//                         // 然后调用 ListDelete_Sq 删除该元素
//                         pos = LocateElem_Sq(namelist, e, cmp);
//                         ListDelete_Sq(&namelist, pos, &e);
//                 }else if(strcmp(strInstruct, "search") == 0){        // 查找某个姓名的位置
//                         scanf("%s", e.name);                // 读取需要查找的元素
//                         printf("%d\n", LocateElem_Sq(namelist, e, cmp));
//                 }
//         }
//         return 0;
// }



// #define LOCAL
// #include <stdio.h>
// #include <malloc.h>
// #include <string.h>
// struct Linknode
// {
// 	int x;
// 	struct Linknode *next;
// }*head=NULL;
// struct Linknode *Create(int x)
// {
// 	struct Linknode *p;
// 	p=(struct Linknode*)malloc(sizeof(struct Linknode));
// 	p->x=x;
// 	p->next=NULL;
// 	return p;
// }
// void Insert(struct Linknode *p)
// {
// 	if(head==NULL)
// 	head=p;
// 	else
// 	{
// 		p->next=head;
// 		head=p;
// 	}
// }
// int PrintLink(struct Linknode *p)
// {
// 	struct Linknode *q;
// 	q=p;
// 	if(q==NULL)
// 	{
// 		printf("Link list is empty\n");
// 		return 0;
// 	}
// 	for(;q->next!=NULL;q=q->next)
// 		printf("%d ",q->x);
// 	printf("%d\n",q->x);
// 	return 1;
// }
// void PrintGet(int a,int *sum)
// {
// 	int i;
// 	struct Linknode *p;
// 	if(a>*sum||a<=0)
// 	printf("get fail\n");
// 	else
// 	{
//         for(i=0,p=head;i<a-1;i++,p=p->next) ;
// 	    printf("%d\n",p->x);
// 	}
// }
// void DeleteHead(int *sum)
// {
// 	struct Linknode *p;
// 	p=head;
// 	head=p->next;
// 	free(p);
// 	printf("delete OK\n");
// 	(*sum)--;
// }
// void DeleteMin(int a,int *sum)
// {
// 	struct Linknode *p,*q;
// 	int i;
// 	for(i=0,p=head;i<a-2;i++,p=p->next) ;
// 	q=p->next;
// 	p->next=q->next;
// 	free(q);
// 	printf("delete OK\n");
// 	(*sum)--;
// }
// void DeleteRear(int *sum)
// {
// 	struct Linknode *p,*q;
// 	for(p=head;p->next->next!=NULL;p=p->next) ;
// 	q=p->next;
// 	p->next=NULL;
// 	free(q);
// 	printf("delete OK\n");
// 	(*sum)--;
// }
// void InsertLocate(int a,int e,int *sum)
// {
// 	int i;
// 	struct Linknode *p,*m,*n;
// 	p=(struct Linknode *)malloc(sizeof(struct Linknode));
// 	p->x=e;
// 	p->next=NULL;
// 	for(i=0,m=head;i<a-2;i++,m=m->next) ;
// 	if(head==NULL)
// 	{
// 		head=p;
// 		printf("insert OK\n");
// 		(*sum)++;
// 	}
// 	else if(a==1)
// 	{
// 		p->next=head;
// 		head=p;
// 		printf("insert OK\n");
// 		(*sum)++;
// 	}
// 	else
// 	{
// 	    n=m->next;
// 	    p->next=n;
// 	    m->next=p;
// 	    printf("insert OK\n");
// 	    (*sum)++;
// 	}
// }
// int Input()
// {
// 	char s[10],a[10]="show",b[10]="get",c[10]="delete";
// 	scanf("%s",s);
// 	if(strcmp(s,a)==0)
// 		return 1;
// 	else if(strcmp(s,b)==0)
// 		return 2;
// 	else if(strcmp(s,c)==0)
// 		return 3;
// 	else
// 		return 4;
// }
// void Switch(int x,int *sum)
// {
// 	int a,e;
// 	switch(x)
// 	{
// 		case 1:
// 			PrintLink(head);
// 			break;
// 		case 2:
// 			scanf("%d",&a);
// 			PrintGet(a,sum);
// 			break;
// 		case 3:
// 			scanf("%d",&a);
// 			if(a==1) 
// 				DeleteHead(sum);
// 			else if(a==*sum&&a!=1) 
// 				DeleteRear(sum);
// 			else if(a>*sum||a<=0) 
// 				printf("delete fail\n");
// 			else 
// 				DeleteMin(a,sum);break;
// 		case 4:
// 			scanf("%d %d",&a,&e);
// 			if((a-(*sum))>1||a<=0) 
// 				printf("insert fail\n");
// 			else 
// 				InsertLocate(a,e,sum);
// 			break;
// 		default:
// 			break;
// 	}
// }
// int main()
// {

// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif

// 	int i,n,sum,x,line,sign;
// 	struct Linknode *p;
// 	scanf("%d",&n);
// 	sum=n;
// 	for(i=0;i<n;i++)
// 	{
// 		scanf("%d",&x);
// 		p=Create(x);
// 		Insert(p);
// 	}
// 	scanf("%d",&line);
// 	for(i=0;i<line;i++)
// 	{
// 		sign=Input();
// 		Switch(sign,&sum);
// 	}
// }
















// #include <stdio.h>
// #include <malloc.h>
// struct Linknode
// {
// 	struct Linknode *last;
// 	int x;
// 	struct Linknode *next;
// }*head=NULL,*rear=NULL;
// struct Linknode *Create()
// {
// 	int x;
// 	struct Linknode *p;
// 	scanf("%d",&x);
// 	p=(struct Linknode*)malloc(sizeof(struct Linknode));
// 	p->x=x;
// 	p->last=NULL;
// 	p->next=NULL;
// 	return p;
// }
// void Insert(struct Linknode *p)
// {
// 	struct Linknode *q;
// 	if(head==NULL)
// 	head=p;
// 	else
// 	{
// 		for(q=head;q->next!=NULL;q=q->next) ;
// 		q->next=p;
// 		p->last=q;
// 	}
// 	rear=p;
// }
// void PrintLink()
// {
// 	struct Linknode *p;
// 	for(p=head;p!=NULL;p=p->next)
// 		printf("%d ",p->x);
// 	printf("\n");
// 	for(p=rear;p!=NULL;p=p->last)
// 		printf("%d ",p->x);
// 	printf("\n");
// }
// void Free()
// {
// 	struct Linknode *p;
// 	for(p=head;p!=NULL;p=p->next)
// 	{
// 		free(p);
// 	}
// 	head=NULL;
// 	rear=NULL;
// }
// int main()
// {
// 	int x,n,i;
// 	struct Linknode *p;
// 	while(scanf("%d",&n)!=EOF)
// 	{
// 	    if(n==0)
// 	    printf("list is empty\n");
// 	    else
// 	    {
// 	        for(i=0;i<n;i++)
// 	        {
// 		        p=Create();
// 		        Insert(p);
// 	        }
// 	        PrintLink();
// 	    }
// 	    Free();
// 	}
// }




// #define LOCAL
// #include <stdio.h>  
// #include <string.h>
// int nex[11]={2,0,3,4,5,6,7,8,9,10,0};
// char mem[11][10];
// int mal()
// {
//     int i=nex[0];
//     if(nex[0])
//     {
//         nex[0]=nex[nex[0]];
//     }
//     return i;
// }
// int len(char s[])
// {
//     int i=0;
//     while(s[i++]);
//     return i;
// }
// void search(char s[])
// {
//     int i=nex[1];
//     while(i&&strcmp(s,mem[i]))
//         i=nex[i];
//     printf("%2d\n********************\n",i);
//     return ;
// }
// void show()
// {
//     int i;
//     for(i=0;i<11;i++)
//     {
//         printf("%-8s%2d\n",mem[i],nex[i]);
//     }
//     printf("********************\n");
//     return;
// }
// void insert(int w,char s[])
// {
//     int p1=1,p2=nex[1];
//     int r=mal();
//     strcpy(mem[r],s);
//     int t=1;
//     while(t!=w)
//     {
//         p1=p2;
//         p2=nex[p2];
//         t++;
//     }
//     nex[r]=p2;
//     nex[p1]=r;
//     return;
// }
// void del(int w)
// {
//     int p1=1,p2=nex[1];
//     int t=1;
//     while(t!=w)
//     {
//         p1=p2;
//         p2=nex[p2];
//         t++;
//     }
//     nex[p1]=nex[p2];
//     nex[p2]=nex[0];
//     nex[0]=p2;
// }
// int main()
// {
    
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif    

//     char zo[10];
//     int W;
//     while(~scanf("%s",zo))
//     {
//         if(strcmp(zo,"show") == 0)
//         	show();
//         if(strcmp(zo,"insert") == 0)
//         {
//         	scanf("%d%s",&W,zo);
//         	insert(W,zo);
//         }
//         if(strcmp(zo,"delete") == 0)
//         {
//         	scanf("%d",&W);
//         	del(W);
//         }
//         if(strcmp(zo,"search") == 0)
//         {
//         	scanf("%s",zo);
//         	search(zo);
//         }
//     }
//     return 0;
// }


// switch(zo[2])
        // {
        //     case 'o':{
        //         show();
        //         break;
        //     }
        //     case 's':{
        //         scanf("%d%s",&W,zo);
        //         insert(W,zo);
        //         break;
        //     }
        //     case 'l':{
        //         scanf("%d",&W);
        //         del(W);
        //         break;
        //     }
        //     case 'a':{
        //         scanf("%s",zo);
        //         search(zo);
        //         break;
        //     }
        // }






// #define LOCAL
// #include <iostream>
// using namespace std;

// struct nood
// {
//     int val;
//     struct nood *next;
//     struct nood *front;
// }head,rear;

// int main()
// {

// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif    

//     int i,n,t;
//     while(cin>>n)
//     {
//         head.next=&rear;
//         rear.front=&head;
//         struct nood *p=&head;
//         int b=0;
//         for(i=0;i<n;i++)
//         {
//             b=1;
//             cin>>t;
//             struct nood *r;
//             r = new nood;
//             r->val=t;
//             r->next=p->next;
//             r->front=p;
//             p->next->front=r;
//             p->next=r;
//             p=r;
//             cout<<t<<" ";
//         }
//         if(b==1)
//             cout<<endl;
//         if(n==0)
//         {
//             cout<<"list is empty"<<endl;
//             continue;
//         }
//         p=rear.front;
//         b=0;
//         while(p!=&head)
//         {
//             cout<<p->val<<" ";
//             p=p->front;
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// #define LOCAL
// #include <iostream>
// using namespace std;
// struct nood
// {
//     int val;
//     struct nood *next;
// }head,rear;

// int main()
// {

// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif   

//     int i,n,t;
//     int q=0;
//     while(cin>>n)
//     {
//         if(!q)
//             q=1;
//         head.next=&rear;
//         struct nood *p=&head;
//         for(i=0;i<n;i++)
//         {
//             cin>>t;
//             struct nood *r;
//             r = new nood;
//             r->val=t;
//             r->next=p->next;
//             p->next=r;
//             p=r; 
//             cout<<t<<" ";
//         }
//         if(n==0)
//         {
//             cout<<"list is empty"<<endl;
//             continue;
//         }
//         if(q)
//             cout<<endl;
//         p=head.next;
//         while(p->next!=&rear)
//         {
//             while(p->val==p->next->val)
//                 p->next=p->next->next;
//             if(p->next!=&rear)
//                 p=p->next;
//         }
//         p=head.next;
//         while(p!=&rear)
//         {
//             cout<<p->val<<" ";
//             p=p->next;
//         }
//         cout<<endl;
//     }
//     return 0;
// }






