// // #define LOCAL
// // #define DEBUG
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <malloc.h>
// #include <math.h>
// #include <ctype.h>
// int a[100001];//存储符号
// char b[100001];//存储数字
// char c[100001];//中转栈
// int topc=-1;
// int topab=-1;
// int ji[10001];
// int topj=-1;
// char s[100001];
// int pan(int len){
// 	int i;
// 	int acc=0,bcc=0;
// 	for(i=0;i<len-1;i++){
// 		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
// 			if(s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='*'||s[i+1]=='/')
// 				return 1;
// 		}
// 		else if(s[i]==')'){
// 			if(s[i+1]=='(')
// 				return 1;
// 		}
// 		else if(s[i]=='('){
// 			if(s[i+1]==')')
// 				return 1;
// 		}
// 	}
// 	if(s[len-1]=='+'||s[len-1]=='-'||s[len-1]=='*'||s[len-1]=='/')
// 		return 1;
// 	for(i=len-1;i>=0;i--){
// 		if(s[i]==')')
// 			bcc++;
// 		else if(s[i]=='(')
// 					acc++;
// 	}
// 	if(acc!=bcc){
// 		return 1;
// 	}
// 	char pei[10001];
// 	int toppei=-1;
// 	i=0;
// 	while(i<len){
// 		if(s[i]=='('){
// 			toppei++;
// 			pei[toppei]=s[i];
// 			i++;
// 		}
// 		else if(s[i]==')'&&toppei>=0){
// 			toppei--;
// 			i++;
// 		}
// 		else if(s[i]==')'&&toppei==-1)
// 			return 1;
// 		else
// 			i++;
// 	}
// 	if(toppei!=-1)
// 		return 1;
// 	return 0;
// }
// int main(){
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	int num=0;
// 	int flag=0;
// 	while(~scanf("%s",s)){
// 			int len=strlen(s);
// 			int i;
// 			for(i=0;i<len;i++)
// 				a[i]=9999;
// #ifdef DEBUG
// 			for(i=0;i<10;i++)
// 				printf("%d\n",a[i]);
// #endif
// 			flag=pan(len);
// #ifdef DEBUG
// 			printf("%d",flag);
// #endif
// 			i=0;
// 			while(i<len&&flag!=1){
// 				if(isdigit(s[i])==1){
// 					while(isdigit(s[i])==1){
// 						num*=10;
// 						num+=s[i]-48;
// 						i++;
// 					}
// 					topab++;
// 					a[topab]=num;
// 					num=0;
// 				}
// 				else if(s[i]=='('){
// 					topc++;
// 					c[topc]=s[i];
// 					i++;
// 				}
// 				else if(s[i]==')'){
// 					while(c[topc]!='('&&topc>=0){
// 							topab++;
// 							b[topab]=c[topc];
// #ifdef DEBUG
// 							printf("%c\n",b[topab]);
// #endif
// 							topc--;
// 							if(topc==-1){flag=1;break;}
// 						  }
// 						  topc--;
// 						  i++;
// 				}
// 				else{
// 					if(s[i]=='-'){
// 						if(i==0){
// 							flag=1;
// 							break;
// 						}
// 						else{
// 							if(s[i-1]=='('){
// 								flag=1;
// 								break;
// 							}
// 							else{
// 								while(c[topc]!='('&&topc>=0){
// 									topab++;
// 									b[topab]=c[topc];
// #ifdef DEBUG
// 									printf("%c\n",b[topab]);
// #endif
// 									topc--;
// 									if(topc==-1)
// 										break;
// 								}
// 								topc++;
// 								c[topc]=s[i];
// 								i++;
// 							}
// 						}
// 					}
// 					else if(s[i]=='+'){
// 						while(c[topc]!='('&&topc>=0){
// 							topab++;
// 							b[topab]=c[topc];
// #ifdef DEBUG
// 							printf("%c\n",b[topab]);
// #endif
// 							topc--;
// 							if(topc==-1)
// 								break;
// 						}
// 						topc++;
// 						c[topc]=s[i];
// 						i++;
// 					}
// 					else if(s[i]=='*'||s[i]=='/'){
// 						while((c[topc]=='*'||c[topc]=='/')&&topc>=0){
// 							topab++;
// 							b[topab]=c[topc];
// #ifdef DEBUG
// 							printf("%c\n",b[topab]);
// #endif

// 							topc--;
// 							if(topc==-1)
// 								break;
// 						}
// 						topc++;
// 						c[topc]=s[i];
// 						i++;
// 					}
// 				}
// 			}
// 			while(topc>=0){
// 				topab++;
// 				b[topab]=c[topc];
// #ifdef DEBUG
// 							printf("%c\n",b[topab]);
// #endif
				
// 				topc--;
// 			}
// #ifdef DEBUG
// 			for(i=0;i<=topab;i++){
// 				if(a[i]!=9999)
// 					printf("%d\n",a[i]);
// 				else
// 					printf("%c\n",b[i]);
// 			}
// #endif
		
// 		for(i=0;i<=topab;i++){
// 			if(a[i]!=9999){
// 				topj++;
// 				ji[topj]=a[i];
// 			}
// 			else{
// 				if(topj-1>=0){
// 					switch(b[i]){
// 						case '+':ji[topj-1]=ji[topj-1]+ji[topj];topj--;break;
// 						case '-':ji[topj-1]=ji[topj-1]-ji[topj];topj--;break;
// 						case '*':ji[topj-1]=ji[topj-1]*ji[topj];topj--;break;
// 						case '/':if(ji[topj]!=0){
// 									ji[topj-1]=ji[topj-1]/ji[topj];
// 									topj--;
// 								}
// 								else{
// 									flag=1;
// 								}
// 								break;
// 						default:break;
// 					}
// 				}
// 				else{flag=1;break;}
// 			}
// 		}
// 		if(flag==0){
// 			if(ji[0]>=0)
// 				printf("%d\n",ji[0]);
// 			else
// 				printf("error\n");
// 		}
// 		else{
// 			printf("error\n");
// 		}
// 		flag=0;
// 		topab=-1;
// 		topj=-1;
// 	}
// 	return 0;
// }








// #include<stdio.h>
// double y;
// double BinarySearch(double a,double b)  //二分查找
// {
// 	double left=a,right=b,mid;
// 	while(right-left>1e-10)  //精度
// 	{
// 	   mid=(left+right)/2;
// 	   if(8*mid*mid*mid*mid+7*mid*mid*mid+2*mid*mid+3*mid+6>y)
// 		   right=mid;
// 	   else if(8*mid*mid*mid*mid+7*mid*mid*mid+2*mid*mid+3*mid+6<y)
// 		   left=mid;
// 	}
//  return mid;
// }
// int main()
// {
// 	int t;
// 	scanf("%d",&t);
// 	while(t--)
// 	{
// 		scanf("%lf",&y);
// 		if(y<6||y>8*10000*10000+7*10000*100+2*10000+306)  
// 			printf("No solution!\n");
// 		else
// 			printf("%.4lf\n",BinarySearch(0,100));
// 	}
// 	return 0;
// }


// #define LOCAL
// #include <iostream>
// #include <string>
// using namespace std;

// int Index(string S, string T, int pos)
// {
// 	unsigned i = pos;
// 	unsigned j = 0;
	// while(i < S.length() && j < T.length())
	// {
	// 	cout<<S[i];
	// 	if(S[i] == T[j])
	// 	{
	// 		++i;
	// 		++j;
	// 	}
	// 	else
	// 	{
	// 		i = i - j + 1;
	// 		j = 0;
	// 	}
	// }
// 	cout<<endl;
	// if(j >= T.length())
	// {
	// 	return i - T.length() + 1;
	// }
	// else
	// 	return 0;
// }

// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
	
// 	string a,b;
// 	int c;
// 	while(cin>>a>>b)
// 	{
// 		c = Index(a,b,0);
// 		cout<<c<<endl;
// 	}
// 	return 0;
// }




// #include <iostream>
// using namespace std;
// int main()
// {
// 	int num,cnt,ones;
// 	while(cin>>num)
// 	{
// 		cnt = ones = 1;
// 		ones %= num;
// 		while(ones)
// 		{
// 			ones = ones*10 + 1;
// 			cnt++;
// 			ones %= num; 
// 		}
// 		cout<<cnt<<endl;
// 	}
// 	return 0;
// }



// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main()
// {
// 	long Hum[5843] = {1};
// 	int p2 = 0,p3 = 0,p5 = 0,p7 = 0;
// 	int num;
// 	for(int i = 1; i < 5842; i++)
// 	{
// 		Hum[i] = min(min(Hum[p2]*2,Hum[p3]*3),min(Hum[p5]*5,Hum[p7]*7));
// 		if(Hum[i] == Hum[p2]*2)
// 			p2++;
// 		if(Hum[i] == Hum[p3]*3)
// 			p3++;
// 		if(Hum[i] == Hum[p5]*5)
// 			p5++;
// 		if(Hum[i] == Hum[p7]*7)
// 			p7++;
// 	}
// 	while(cin>>num&&num)
// 	{
// 		if(num%10 == 1 && num%100 != 11)
// 			cout<<"The "<<num<<"st humble number is "<<Hum[num-1]<<"."<<endl;
// 		else if(num%10 == 2 && num%100 != 12)
// 			cout<<"The "<<num<<"nd humble number is "<<Hum[num-1]<<"."<<endl;
// 		else if(num%10 == 3 && num%100 != 13)
// 			cout<<"The "<<num<<"rd humble number is "<<Hum[num-1]<<"."<<endl;
// 		else
// 			cout<<"The "<<num<<"th humble number is "<<Hum[num-1]<<"."<<endl;
// 	}
// 	return 0;
// }


// #define LOCAL
// #include <iostream>
// using namespace std;

// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	int m,n;
// 	int data[1005];
// 	int count,sum;
// 	cin>>m;
// 	while(m--)
// 	{
// 		sum = count = 0;
// 		cin>>n;
// 		for (int i = 0; i < n; i++)
// 		{
// 			cin>>data[i];
// 		}
// 		for (int i = 0; i < n; i++)
// 		{
// 			if(!data[i])
// 				count++;
// 			sum += count*data[i];
// 		}
// 		cout<<sum<<" "<<n-count;
// 		for (int i = 0; i < n; i++)
// 		{
// 			if(data[i])
// 				cout<<" "<<data[i];
// 		}
// 		cout<<endl;
// 	}
// 	return 0;
// }



// #include <iostream>
// #include <string>
// #include <cstring>

// using namespace std;

// int tot,fir;
// string a,b;

// bool check(int x)
// {
// 	for(int i=0;i<a.length();i++)
// 		if(b[x+i]!=a[i])
// 			return 0;
// 	if(b[x+a.length()]!=' ')
// 		return 0;
// 	return 1;
// }

// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	while(getline(cin,a))
// 	{
// 		tot = fir = 0;
// 		getline(cin,b);
// 		for(int i=0;i<a.length();i++)
// 			a[i] = tolower(a[i]);
// 		for(int i=0;i<b.length();i++)
// 			b[i] = tolower(b[i]);
// 		b = " " + b + " ";
// 		for(int i=0;i<b.length();i++)
// 			if(b[i]==' ' && b[i+1]!=' ')
// 				if(check(i+1))
// 				{
// 					tot++;
// 					if(!fir)fir=i+1;
// 				}
// 		if(!tot)
// 			cout<<-1<<endl;
// 		else
// 			cout<<tot<<" "<<fir-1<<endl;
// 	}
// 	return 0;
// }



// #define LOCAL
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// using namespace std;

// typedef struct BiTNode
// {
// 	char data;
// 	struct BiTNode *lchild,*rchild;
// } BiTNode, *BiTree;

// char ch;
// int flag;

// void creat(BiTree &p, int flag)//先序建树
// {
// 	if(!flag)
// 		flag = 1;
// 	else
// 		cin>>ch;
// 	if(ch == ' ')
// 		p = NULL;
// 	else
// 	{
// 		p = new BiTNode;
// 		p->data = ch;
// 		creat(p->lchild,1);
// 		creat(p->rchild,1);
// 	}
// 	return;
// }

// void print0(BiTree p)//先序输出树
// {
// 	if(p != NULL)
// 	{
// 		cout<<p->data;
// 		print0(p->lchild);
// 		print0(p->rchild);
// 	}
// }
// void print1(BiTree p)//中序输出树
// {
// 	if(p != NULL)
// 	{
// 		print1(p->lchild);
// 		cout<<p->data;
// 		print1(p->rchild);
// 	}
// }
// void print2(BiTree p)//后序输出树
// {
// 	if(p!=NULL)
// 	{
// 		print2(p->lchild);
// 		print2(p->rchild);
// 		cout<<p->data;
// 	}
// }
// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	while(cin>>ch)
// 	{
// 		BiTree p = NULL;
// 		flag = 0;
// 		creat(p, flag);
// 		// print0(p);
// 		// cout<<endl;
// 		// print1(p);
// 		// cout<<endl;
// 		// print2(p);
// 		cout<<endl;
// 	}
// 	return 0;
// }



// #define LOCAL
// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
// #ifdef LOCAL
// 	freopen("input.txt","r",stdin);
// #endif
// 	string a,b = "GLB";
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 		cin>>a;
// 		size_t found = a.find(b);
// 		if (found!=string::npos)
// 			cout<<"YES"<<endl;
// 		else
// 			cout<<"NO"<<endl;
// 	}
// 	return 0;
// }

// #include <stdio.h>

// int main()
// {
// 	printf("%f",3.5+9%4*3*(1/2)-1.5);
// 	return 0;
// }






































#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
/******** 函数变量声明 ********/
#define PR_Box printf("■")
#define PR_Gold printf("★")
#define PR_Ag printf("☆")
#define PR_FBird printf("Ю")
#define PR_DBird printf("Ф")
#define PR_Land printf("┳┳┯")
#define PR_Bg_TL printf("╔")
#define PR_Bg_TR printf("╗")
#define PR_Bg_DL printf("╚")
#define PR_Bg_DR printf("╝")
#define PR_Bg_X printf("═")
#define PR_Bg_Y printf("║")
#define PR_Blank printf(" ");
int Grade = 1, C_Gold = 0, C_Ag = 0, Score = 0, Delay_time = 1000, Max_blank = 9, Distance = 18;
struct Birds
{
int x, y;
int condition;
};
Birds *Bird = (Birds*)malloc(sizeof(Birds));
struct Bg
{
int x, y;
int l_blank;
int reward[9];
Bg *pri;
Bg *next;
};
Bg *Bg1 = new Bg[sizeof(Bg)];
void Position(int x, int y)
{
COORD pos = {x - 1, y - 1};
HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(Out, pos);
}
void CreatBird()
{
Bird->x = 41;
Bird->y = 10;
Bird->condition = 0;
}
void CreatBg()
{
Bg *Bg2 = (Bg*)malloc(sizeof(Bg));
Bg1->x = 90; Bg1->y = 8;
Bg2->x = Bg1->x + Distance; Bg2->y = 9;
Bg1->l_blank = Max_blank - Grade;
Bg2->l_blank = Max_blank - Grade;
Bg1->next = Bg2;
Bg1->pri = Bg2;
Bg2->next = Bg1;
Bg2->pri = Bg1;
}
void InsertBg(Bg *p)
{
int temp;
Bg *Bgs = (Bg*)malloc(sizeof(Bg));
Bgs->x = p->pri->x + Distance;
Bgs->l_blank = Max_blank - Grade;
srand((int)time(0));
temp = rand();
if (temp % 2 == 0)//++
{
if ((temp % 4 + p->pri->y + Max_blank - Grade)<21)
Bgs->y = p->pri->y + temp % 4;
else
Bgs->y = p->pri->y;
}
else
{
if ((p->pri->y - temp % 4)>2)
Bgs->y = p->pri->y - temp % 4;
else
Bgs->y = p->pri->y;
}
Bgs->pri = p->pri;
Bgs->next = p;
p->pri->next = Bgs;
p->pri = Bgs;
}
void Check_Bg(Bg *q)
{
Bg *p = q; int i = 0, temp;
while (++i <= 5)
{
if (p->x>-4)
p = p->next;
else
{
srand((int)time(0));
temp = rand();
if (temp % 2 == 0)//++
{
if ((temp % 4 + p->y + Max_blank - Grade)<21)
p->y = p->y + temp % 4;
else
p->y = p->y;
p->x = p->pri->x + Distance;
p->l_blank = Max_blank - Grade;
}
else
{
if ((p->y - temp % 4)>2)
p->y = p->y - temp % 4;
else
p->y = p->y;
p->x = p->pri->x + Distance;
p->l_blank = Max_blank - Grade;
}
}
}
}
void Loop_Bg(Bg *q)
{
Bg *p = q; int i = 0;
while (++i <= 5)
{
p->x = p->x - 1;
p = p->next;
if (Bird->x == p->x)
{
Score += 1;
if (Score % 4 == 0 && Grade<4)
Grade++;
}
}
}
void Prt_Bg(Bg *q)
{
Bg *p = q; int i = 0, k, j;
while (++i <= 5)
{
if (p->x>0 && p->x <= 78)
{
for (k = 2; k<p->y; k++)
{
Position(p->x + 1, k);
PR_Box; PR_Box; PR_Blank
}
Position(p->x, p->y);
PR_Box; PR_Box; PR_Box; PR_Blank;
Position(p->x, p->y + p->l_blank);
PR_Box; PR_Box; PR_Box; PR_Blank;
k = k + p->l_blank + 1;
for (k; k <= 22; k++)
{
Position(p->x + 1, k);
PR_Box; PR_Box; PR_Blank;
}
Position(p->x, 23);
for (k = 1; k<Distance / 3 - 2; k++)
PR_Land;
}
p = p->next;
if (p->x == 0)
{
for (j = 2; j<p->y; j++)
{
Position(p->x + 1, j);
PR_Blank; PR_Blank;
}
Position(p->x + 1, p->y);
PR_Blank; PR_Blank; PR_Blank;
Position(p->x + 1, p->y + Max_blank - Grade);
PR_Blank; PR_Blank; PR_Blank;
j = j + Max_blank - Grade + 1;
for (j; j <= 22; j++)
{
Position(p->x + 1, j);
PR_Blank; PR_Blank;
}
}
}
}
void PrtBg()
{
int i;
Position(1, 1); PR_Bg_TL;
Position(79, 1); PR_Bg_TR;
Position(1, 24); PR_Bg_DL;
Position(79, 24); PR_Bg_DR;
for (i = 3; i <= 78; i += 2)
{
Position(i, 1); PR_Bg_X;
Position(i, 24); PR_Bg_X;
}
/*for(i=2;i<=23;i++)
{Position(1,i);PR_Bg_Y;printf("%d",i-1);
Position(79,i);PR_Bg_Y;
}*/
}
void PrtBird()
{
Position(Bird->x, Bird->y - 1);
PR_Blank;
Position(Bird->x, Bird->y);
PR_FBird;
Position(38, 2);
printf("Score:%d", Score);
}
int CheckYN(Bg *q)
{
Bg *p = q; int i = 0;
while (++i <= 5)
{
if (Bird->y>23)
return 0;
if (Bird->x == p->x&&Bird->y <= p->y)
return 0;
if ((Bird->x == p->x || Bird->x == p->x + 1 || Bird->x == p->x + 2) && Bird->y == p->y)
return 0;
if (Bird->x == p->x&&Bird->y>p->y + p->l_blank)
return 0;
if ((Bird->x == p->x || Bird->x == p->x + 1 || Bird->x == p->x + 2) && Bird->y == p->y + p->l_blank)
return 0;
p = p->next;
}
return 1;
}
void Prtfirst()
{
printf("══════════════════════════════════════\n");
printf("■■ ■■\n");
printf("■■ ■■\n");
printf("■■ ■■ C 语言版 Flappy Bird\n");
printf("■■ ■■ 瞎搞人：yyposs\n");
printf("■■ ■■ 瞎搞日期：2014.2\n");
printf("■■ ■■ 耗时：4 小时 \ n");
printf("■■■ ■■ 游戏说明：\n");
printf("■■ 1 - 按上箭头使鸟起飞 \ n");
printf("■■ 2 - 等级越高，难度越大！\n");
printf("Ю ■■■\n");
printf("\n");
printf("■■■ 欢迎各路大神与我探讨 C、C++、VB、PHP、C#\n");
printf("■■\n");
printf("■■\n");
printf("■■ ■■■ 【无版权，随意修改】\n");
printf("■■ ■■\n");
printf("■■ Ф ■■\n");
printf("■■ ■■\n");
printf("■■ ■■\n");
printf("■■ ■■\n");
printf("■■ ■■\n");
printf("┳┳┯┳┳┯┳┳┯┳┳┯┳┳┯┳┳┯┳┳┯┳┳┯┳┳┯┳┳┯┳┳┯┳┳┯┳\n");
system("pause");
Position(1, 1);
int i = 0;
while (i++<40 * 25)
PR_Blank;
}
void main()
{
int i = 0; char ch;
Prtfirst();
PrtBg();
CreatBg();
InsertBg(Bg1);
InsertBg(Bg1);
InsertBg(Bg1);
CreatBird();
while (1)
{
if (!CheckYN(Bg1))
break;
Check_Bg(Bg1);
Prt_Bg(Bg1);
PrtBird();
Loop_Bg(Bg1);
Bird->y = Bird->y + 1;
if (GetAsyncKeyState(VK_UP))
{
Position(Bird->x, Bird->y - 1);
PR_Blank;
Bird->y = Bird->y - 4;
}
while (i++<500);
{Sleep(100);
}
i = 0;
}
Position(38, 10);
printf("You Lost!");
Position(1, 25);
system("pause");
}