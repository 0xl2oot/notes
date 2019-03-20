// A 
#include <cstring>
#include <iostream>
using namespace std;
int s[10];
void Perm(int *s, int k, int m);
void Swap(int &a, int &b);//交换值，利用c++中的引用
int main()
{
 int n;
 while(cin>>n)
 {
	for(int i=0; i<=n; i++)
	{
	 s[i] = i;
	}
				Perm(s, 1, n);
 }
 return 0;
}


void Perm(int *s, int k, int m)
{
				int i;
				if(k == m)
				{
								for(i=1; i<=m; i++)
												cout<<s[i]<<" ";
								cout<<endl;
								return;
				}
			 else
				for(i=k; i<=m; ++i)
				{
								Swap(s[k], s[i]);
								Perm(s, k+1, m);
								Swap(s[k], s[i]);
				}

}


void Swap(int &a, int &b)
{
				int tmp = a;
				a = b;
				b = tmp;
}



// B

 #include<stdio.h>
#include<stdlib.h>
void PAIXU(int *a,int k,int n)
{
		int i,j;
		if(k==n)
		{
				for(i=0;i<n;i++)
						printf("%d ",a[i]);
				printf("\n");
		}
		for(i=0;i<n;i++)
		{
				int flag=1;
				for(j=0;j<k;j++)
				{
						if(a[j]==i+1)
							{
								flag=0;
								break;
							}
				}
				if(flag==1)
			{
				a[k]=i+1;
				PAIXU(a,k+1,n);
			}
		}

}
int main()
{
		int n;
		while(scanf("%d",&n)!=EOF&&n!=0)
		{
				int a[n];
				int i;
				for(i=0;i<n;i++)
						a[i]=i+1;
				PAIXU(a,0,n);
		}
}


// H

#include<stdio.h>
#include<string.h>
int c[2000][2000];
int b[2000][2000];
void LCSlength(int m,int n,char x[],char y[])
{
		int i,j;
		for(i=0;i<m;i++)
		{
				for(j=0;j<m;j++)
						c[i][j]=0;
		}
		for(i=0;i<m;i++)
			{
					for(j=0;j<n;j++)
				{
						if(x[i]==y[j])//表示第一种情况，也就是x和y的最后一项相等，则最大公共子序列一定比前面的多一，多最后一项的那个元素
						{
								c[i][j]=c[i-1][j-1]+1;
						}
						else if(c[i-1][j]>=c[i][j-1])//第二种情况，是x-1和y的最大公共子序列
						{
								c[i][j]=c[i-1][j];
						}
						else
						{
								c[i][j]=c[i][j-1];//第三种情况，是x和y-1的最大公共子序列
						}
				}
			}
		printf("%d",c[m-1][n-1]);
}
int main()
{
		int i,j;
		char s1[2000];
		char s2[2000];
		scanf("%s%s",s1,s2);
		int a,b;
		a=strlen(s1);
		b=strlen(s2);
		LCSlength(a,b,s1,s2);
}



// F

#include<stdio.h>
int s;
void resolve(int m)
{
	int i;
	if(m==1)
		s++;
	else
	{
		for(i=2;i<=m;i++)
		{
			if(m%i==0)
				resolve(m/i);
		}
	}
}
int main()
{
	int n,m;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		s=0;
		resolve(m);
		printf("%d\n",s);
	}
}


// J

#include<stdio.h>
int D[101][101];
int Max[101][101];
int n;
int max(int x,int y)
{
	if(x>=y)
		return x;
	else
		return y;
}
int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<=i;j++)
			scanf("%d",&D[i][j]);
		for(i=0;i<n;i++)
			Max[n-1][i]=D[n-1][i];
		for(i=n-2;i>=0;i--)
			for(j=0;j<=i;j++)
			 {Max[i][j]=max(Max[i+1][j],Max[i+1][j+1])+D[i][j];}//往上递推的方法，从最后一层往上计算
			printf("%d\n",Max[0][0]);
	}
}


// G

#include<stdio.h>

int main()
{
	int a[5000],Maxlength[5000];
	int i,j,k;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	   {
		 scanf("%d",&a[i]);
		 Maxlength[i]=1;
	   }
	for(i=1;i<n;i++)//每次求以第i个数为终点的最长上升子序列的长度
	  for(j=0;j<i;j++)//查看以第j个数为终点的最长上升子序列的长度
	{
		if(a[i]>a[j])
			Maxlength[i]=max(Maxlength[i],Maxlength[j]+1);
	}
	k=1;
	for(i=0;i<n;i++)
	{
		if(Maxlength[i]>k)
			k=Maxlength[i];
	}
	printf("%d",k);
}


///



/////////////////////
// E

#include<stdio.h>
int s;
void resolve(int m)
{
		int i;
		if(m==1)
				s++;
		else
		{
				for(i=2;i<=m;i++)
			{
				if(m%i==0)
						resolve(m/i);
			}
		}
}
int main()
{
		int m,n;
		scanf("%d",&n);
		while(n--)
		{
			 s=0;
			 scanf("%d",&m);
			 resolve(m);
			 printf("%d\n",s);
		}
}



// G

#include<stdio.h>
int Max[101][101];
int D[101][101];
int n;
int max(int a,int b)
{
	if(a>b)
				return a;
	else
				return b;
}
int Maxsum(int i,int j)
{
		if(Max[i][j]!=-1)
				return Max[i][j];
		if(i==n)
		{
				Max[i][j]=D[i][j];
		}
		else
		{
				int x=Maxsum(i+1,j);
				int y=Maxsum(i+1,j+1);
				Max[i][j]=max(x,y)+D[i][j];
		}
		return Max[i][j];
}
int main()
{
		int i,j;
		while(scanf("%d",&n)!=EOF)
		{
				for(i=0;i<n;i++)
		 {
				for(j=0;j<=i;j++)
				{
						scanf("%d",&D[i][j]);
						Max[i][j]=-1;
				}
		 }
			printf("%d\n",Maxsum(0,0));
		}
}


// F

#include<stdio.h>
#include<stdlib.h>
struct student
{
	char id[10];
	char name[10];
	int a,b,c;
}s[100];
void input(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s",&s[i].id);
		scanf("%s",&s[i].name);
		scanf("%d",&s[i].a);
		scanf("%d",&s[i].b);
		scanf("%d",&s[i].c);
	}
}
void print(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%s,",s[i].id);
		printf("%s,",s[i].name);
		printf("%d,",s[i].a);
		printf("%d,",s[i].b);
		printf("%d",s[i].c);
		printf("\n");
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	input(n);
	print(n);
	return 0;
}

