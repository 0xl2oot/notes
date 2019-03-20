// #include <cmath>
// #include <cstring>
// #include <iostream>
// using namespace std;
// bool a[10001];
// int main()
// {
//     int n = 10000;
//     int i, j;
//     int x;
//     int num;
//     memset(a, 1, sizeof(a));
//     a[1] = 0;
//     for (i = 2; i <= sqrt(n); i++)
//     { 
//         if (a[i])
//         {
//             for (j = 2; j <= n / i; j++)
//             {
//                 a[i*j] = 0;
//             }
//         }
//     }
//     cin >> x;
//     for (i = 0; i < x; i++)
//     {
//         cin >> num;
//         if (a[num])
//             cout << "yes"<<endl;
//         else
//             cout << "no"<<endl;
//     }
//     return 0;
// }




// #include <iostream>
// using namespace std;
// int main()
// {
//     int m,i,n;
//     cin>>m;
//     while(m--)
//     {
//         cin>>n;
//         i = 2;
//         while(i < n)
//         {
//             if(n % i == 0)
//             break;
//             i++;
//         }
//         if(i == n)
//             cout<<"yes"<<endl;
//         else
//             cout<<"no"<<endl;
//     } 
// }



// Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree &p){
//     if (!T){ p = f; return FALSE; }
//     else if (EQ(key, T->data.key)) { p = T; return TRUE; }
//     else if (LT(key, T->data.key))
//         return SearchBST(T->lchild, key, T, p);
//     else
//         return SearchBST(T->rchild, key, T, p);
// }

// Status InsertBST(BiTree &T, ElemType e){
//     BiTree p, s;
//     if(!SearchBST(T, e.key, NULL, p)){
//         s = (BiTree)malloc(sizeof(BiTNode));
//         s->data = e;
//         s->lchild = s->rchild = NULL;
//         if(!p) T = s;
//         else if (LT(e.key, p->data.key)) p->lchild = s;
//         else p->rchild = s;
//             return TRUE;

//     }else return FALSE;
// }

// Status DeleteBST(BiTree &T, KeyType key){
//     if (!T) return FALSE;
//     else{
//         if(EQ(key, T->data.key))
//             return Delete(T);
//         else if(LT(key, T->data.key)) return DeleteBST(T->lchild, key);
//         else return DeleteBST(T->rchild, key);
//     }
// }

// Status Delete(BiTree &p){
//     BiTree q, s;
//     if(!p->rchild){
//         q = p; p = p->lchild; free(q);
//     } else if(!p->lchild){
//         q = p; p = p->rchild; free(q);
//     } else {
//         q = p; s = p->lchild;
//         while(s->rchild)
//         {
//             q = s; s = s-> rchild;
//         }
//         p->data = s->data;
//         if(q != p) q->rchild = s->lchild;
//         else q->lchild = s->lchild;
//         free(s);
//     }
//     return TRUE;
// }

//#define LOCAL
//#include <iostream>
//#include <cstdlib>
//using namespace std;
//int main()
//{
//#ifdef LOCAL
//    freopen("input.txt","r",stdin);
//#endif
//    int n, m, num[501], k, temp;
//    cin>>n>>k;
//    m = n;
//    while(n--)
//        cin>>num[n-1];
//    while(k--)
//    {
//        cin>>temp;
//        int i;
//        for(i = 0; i < m; i++)
//        {
//            if(temp == num[i])
//                break;
//        }
//        if(i <= m-1)
//            cout<<"1 ";
//        else
//            cout<<"0 ";
//    }
//    return 0;
//}


//#define LOCAL
//
//#include <iostream>
//#include <cstring>
//#include <cmath>
//#include <cstdlib>
//#include <algorithm>
//#include <string>
//#include <cstdio>
//#include <climits>
//#include <queue>
//#include <map>
//#include <list>
//#include <set>
//#include <vector>
//using namespace std;
//int tree[2002][4];
//char str[2002];
//int cheight(int in = 1)
//{
//    if (tree[in][0] <= 0 && tree[in][1] <= 0)
//    {
//        tree[in][3] = 1;
//        return 1;
//    }
//    if (tree[in][0] > 0 && tree[in][1] <= 0)
//    {
//        tree[in][3] = cheight(tree[in][0])+1;
//        return  tree[in][3];
//    }
//    if (tree[in][1] > 0 && tree[in][0] <= 0)
//    {
//        tree[in][3] = cheight(tree[in][1])+1;
//        return tree[in][3];
//    }
//    tree[in][3] = max( cheight(tree[in][0])+1,  cheight(tree[in][1])+1);
//    return tree[in][3];
//}
//bool yess = true;
//void isyes(int in = 1)
//{
//    if (!yess)
//        return;
//    if (tree[in][0] <= 0 && tree[in][1] <= 0)
//        return;
//    if (abs(tree[tree[in][0]][3]-tree[tree[in][1]][3]) > 1)
//    {
//    //	cout << tree[tree[in][0]][3] << tree[tree[in][1]][3] ;
//        yess = false;
//        return;
//    }
//    if (tree[in][0] > 0 && tree[in][0] != 0)
//        isyes(tree[in][0]);
//    if (tree[in][1] > 0 && tree[in][1] != 0)
//        isyes(tree[in][1]);
//}
//int main()
//{
//#ifdef LOCAL
//    freopen("input.txt","r",stdin);
//#endif
//
//    while (scanf("%s", str) != EOF)
//    {
//        memset(tree, 0, sizeof(tree));
//        int index = 2;
//        int now = 1;
//        tree[0][3] = -1;
//        for (int i=1; str[i] != 0; i++)
//        {
//            if (str[i] == '#')
//            {
//                if (tree[now][0] == 0)
//                    tree[now][0] = -1;
//                else
//                {
//                    //if (now == 1)
//                    //cout << "good" << " " << tree[now][0] << tree[now][1] << tree[now][2];
//                    tree[now][1] = -1;
//                    now = tree[now][2];
//                    while (tree[now][1] != 0)
//                    {
//                        now = tree[now][2];
//                    }
//                }
//            }
//            else
//            {
//                if (tree[now][0] == 0)
//                {
//                    tree[now][0] = index;
//                    tree[index][2] = now;
//                    now = index;
//                    index++;
//                }
//                else
//                {
//                    tree[now][1] = index;
//                    tree[index][2] = now;
//                    now = index;
//                    index++;
//                }
//            }
//        }
//		cheight();
//        yess = true;
//        isyes();
//        //for (int i=0; i  < index; i++)
//        //	cout << tree[i][3] << " ";
//        if (str[0] == '#')
//            yess = true;
//        if (yess)
//            printf("Yes\n");
//        else
//            printf("No\n");
//    }
//	return 0;
//}

//
//#define LOCAL
//
//
//#include <stdio.h>
//#include <stdlib.h>
//unsigned num[30], f[30][30];
//int p[30][30];
//
//unsigned ans(int s, int t)
//{
//    int i;
//    unsigned a = 0, b;
//    if(s == t){
//        return num[s];
//    }
//    if(s > t){
//        return 1;
//    }
//    if(f[s][t]){
//        return f[s][t];
//    }
//    for(i = s; i <= t; i++){
//        b = ans(s, i - 1) * ans(i + 1, t) + num[i];
//        if(a < b){
//            p[s][t] = i;
//            a = b;
//        }
//    }
//    f[s][t] = a;
//    return a;
//}
//
//void output(int s, int t, int k)
//{
//    if(s == t){
//        printf(" %d", t + 1);
//        return;
//    }
//    if(s > t){
//        return;
//    }
//    if(k){
//        printf(" ");
//    }
//    printf("%d", p[s][t] + 1);
//    output(s, p[s][t] - 1, 1);
//    output(p[s][t] + 1, t, 1);
//}
//
//int main(int argc, char **argv)
//{
//#ifdef LOCAL
//    freopen("input.txt","r",stdin);
//#endif
//    int i;
//    int n;
//    scanf("%d", &n);
//    for(i = 0; i < n; i++){
//        scanf("%d", &num[i]);
//    }
//    printf("%u\n", ans(0, n - 1));
//    output(0, n - 1, 0);
//    printf("\n");
//    return 0;
//}
//


//#define LOCAL
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int num[100001];
//int main(){
//#ifdef LOCAL
//    freopen("input.txt","r",stdin);
//#endif
//    int n;
//    cin>>n;
//    for(int i = 0; i < n; i++)
//        cin>>num[i];
//    sort(num,num+n);
//    for(int i = 0; i < n; i++)
//        cout<<num[i]<<" ";
//    return 0;
//}


//#define LOCAL
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <cstdio>
//using namespace std;
//typedef struct
//{
//	string str;
//	int num;
//}DNA;
//DNA d[100];
//
//bool cmp(DNA a,DNA b)
//{
//	return a.num<b.num;
//}
//
//int main(void)
//{
//#ifdef LOCAL
//	freopen("input.txt","r",stdin);
//#endif   
//	int m,n;
//	cin>>m>>n;
//	int i=0;
//   for(;i<n;i++)
//	{
//		cin>>d[i].str;
//		d[i].num=0;
//
//		for(int k=1;k<m;k++)
//		{
//			for(int j=0;j<k;j++)
//			{
//				if(d[i].str[k]<d[i].str[j]) d[i].num++;
//			}
//		}
//
//	}
//	stable_sort(d,d+n,cmp);
//	for(i=0;i<n;i++)
//	{
//		cout<<d[i].str<<endl;
//	}
//	return 0;
//}


// http://blog.csdn.net/wh921021/article/details/8761439

//#define LOCAL
//#include<iostream>
//
//using namespace std;
//
//typedef struct trietree *Ptree;
//struct trietree		//字典树 
//{
//	bool arrive;		//单词结束标志
//	int treenum;		//单词的个数
//	Ptree next[10];		//字典树的儿子
//}node[1000000];
//int size;		//字典树的规模
//bool findsolve;	//是否找到重复串的标记
//int dispose(char *p);	//将字符串转化为整形数字  
//void addnum(int num);	//增加数字串
//void newtree(int no);	//建新树
//void dfs(char phone[9],int m,Ptree p);	//深度搜索遍历字典树
//
///*将字符串转化为整形数字 */
//int dispose(char *p)
//{
//	int num = 0;
//	char *q = p;
//	while(*++p != '\0');	
//	p--;		//将字符串指针移向末尾
//	while(p >= q)		//从后向前遍历字符串指针
//	{
//		if(*p == '-')		//忽略“-”
//		{
//			p--;
//			continue;
//		}
//		num *= 10;		//计算字符串对应的数字
//		if(*p >= 'A' && *p <= 'Y')
//			num += (*p - 'A' - (*p > 'Q'))/3 + 2;		//将字符转化为数字
//		else if(*p >= '0' && *p <= '9')
//			num += *p - '0';
//		p--;
//	}
//	return num;
//}
//
///* 增加数字串 */
//void addnum(int num)
//{
//	Ptree p = &node[1];
//	int i,k;
//	for (i=0;i<=6;i++)		//将7个数字插入
//	{
//		k = num % 10;
//		num /= 10;
//		if (! p -> next[k])		//插入位置不存在，创建该节点
//		{
//			newtree(++size);
//			p->next[k] = &node[size];
//		}
//		p = p->next[k];
//	}
//	p->arrive = true;		//到达单词末尾
//	p->treenum++;			
//	return;
//
//}
//
///* 建新树 */
//void newtree(int no)
//{
//	int i;
//	node[no].arrive = false;
//	node[no].treenum = 0;
//	for (i=0;i<=9;i++)
//	{
//		node[no].next[i] = NULL;
//	}
//	return;
//}
//
///* 深度搜索遍历字典树 */
//void dfs(char phone[9], int m, Ptree p)
//{
//	if (true == p->arrive)		//如果节点存在数字
//	{
//		if (p->treenum > 1)
//		{
//			for (int i=1;i<=7;i++)
//			{
//				if (i == 4)
//				{
//					cout<<"-";
//					
//				}
//				cout<<phone[i];
//			}
//			cout<<" "<<p->treenum<<endl;
//			findsolve = true;
//		}
//		return;
//	}
//	for (int i=0;i<=9;i++)
//	{
//		if (p->next[i])
//		{
//			phone[m+1] = i + '0';
//			dfs(phone,m+1,p->next[i]);
//		}
//	}
//	return;
//}
//
//int main()
//{
//#ifdef LOCAL
//	freopen("input.txt","r",stdin);
//#endif 	
//	int n;			//串的个数
//	int i,j;	
//	int number;		//字符串转化得到数字
//	char phone[9];			
//	char ch[80];	//字符串
//	cin>>n;
//	findsolve = false;
//	size = 1;
//	newtree(1);
//	for (i=1;i<=n;i++)
//	{
//		cin>>ch;
//		number = dispose(ch);
//		addnum(number);
//	}
//	dfs(phone,0,&node[1]);
//	if (!findsolve)
//	{
//		cout<<"No duplicates."<<endl;
//	}
//	return 0;
//	
//}


//#define LOCAL
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//struct oblong{
//	int a, b, c;
//}d[10001];
//
//int make(oblong x,oblong y)
//{
//		if(x.a < y.a)
//			return 1;
//		else if(x.a == y.a && x.b < y.b)
//			return 1;
//		else if(x.a == y.a && x.b == y.b && x.c < y.c)
//			return 1;
//		else
//			return 0;
//}
//
//int main()
//{
//#ifdef LOCAL
//	freopen("input.txt","r",stdin);
//#endif
//	
//	int test;
//	cin>>test;
//	while(test--)
//	{
//		int m;
//		cin>>m;
//		for(int i = 0; i < m; i++)
//		{
//			 cin>>d[i].a>>d[i].b>>d[i].c;
//			 if(d[i].c > d[i].b)
//			 {
//				int temp = d[i].c; 
//				d[i].c = d[i].b; 
//				d[i].b = temp;
//			 }
//		}
//		sort(d,d+m,make);
//		for(int i = 0;i<m;i++)
//			if(!(d[i].a == d[i-1].a && d[i].b == d[i-1].b && d[i].c == d[i-1].c))
//				cout<<d[i].a <<" "<<d[i].b<<" "<<d[i].c<<endl;
//	}
//
//	return 0;
//}
//

//
//#define LOCAL
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int main()
//{
//#ifdef LOCAL
//	freopen("input.txt","r",stdin);
//#endif
//	;
//	return 0;
//}
//
//
//
//
//
//
//
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <cstdio>
//using namespace std;
//typedef struct
//{
//	string str;
//	int num;
//}DNA;
//DNA d[100];
//
//bool cmp(DNA a,DNA b)
//{
//	return a.num<b.num;
//}
//
//int main(void)
//{
//#ifdef LOCAL
//	freopen("input.txt","r",stdin);
//#endif   
//	int m,n;
//	cin>>m>>n;
//	int i=0;
//   for(;i<n;i++)
//	{
//		cin>>d[i].str;
//		d[i].num=0;
//
//		for(int k=1;k<m;k++)
//		{
//			for(int j=0;j<k;j++)
//			{
//				if(d[i].str[k]<d[i].str[j]) d[i].num++;
//			}
//		}
//
//	}
//	stable_sort(d,d+n,cmp);
//	for(i=0;i<n;i++)
//	{
//		cout<<d[i].str<<endl;
//	}
//	return 0;
//}
//
//

#define LOCAL
#include <iostream>
using namespace std;

#define EQ(a,b) (a==b)
#define LT(a,b) (a<b)
#define LQ(a,b) (a<=b)
typedef int KeyType;
typedef int Status;
#define TRUE 1
#define FALSE 0

typedef struct BiTNode{
	KeyType key;
	struct BiTNode *lchild,*rchild;
}*BiTree;
BiTree q,p,s;


Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree &p)
{
	// 搜索二叉树
	if(!T)
	{
		p = f;
		return FALSE;
	}
	else if(EQ(key, T->key))
	{
		p = T;
		return TRUE;
	}
	else if(LT(key, T->key))
	{
		return SearchBST(T->lchild, key, T, p);
	}
	else
	{
		return SearchBST(T->rchild, key, T, p);
	}
}

Status InsertBST(BiTree &T, KeyType key)
{
	if(!SearchBST(T, key, NULL, p))
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->key = key;
		s->lchild = s->rchild = NULL;
		if(!p)
		{
			T = s;
		}
		else if(LT(k ey, p->key))
		{
			p->lchild = s;
		}
		else
		{
			p->rchild = s;
		}
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	BiTree T = NULL;
	int n, k, temp;
	cin>>n>>k;
	for(int i = 0; i < n; i++)
	{
		cin>>temp;
		InsertBST(T, temp);
	}
	for(int i = 0; i < k; i++)
	{
		cin>>temp;
		if(SearchBST(T, temp, NULL, p))
			cout<<"1 ";
		else
			cout<<"0 ";
	}
	
	return 0;
}

























