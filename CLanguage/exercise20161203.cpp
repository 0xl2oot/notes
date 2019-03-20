#include <iostream>
using namespace std;
#define Max 101
int m[Max];
int p[Max][Max];
int q[Max][Max];

void MatrixChain(int n)
{
	int i,r,j,k,t;
	for(i = 0; i <= n; i++)
		p[i][i]=0;
	for(r = 2; r <= n; r++)
	{
		for(i = 1; i <= n - r + 1; i++)
		{
			j=i+r-1;
			p[i][j] = p[i+1][j] + m[i-1]*m[i]*m[j];
			q[i][j] = i;
			for(k = i+1; k < j; k++)
			{
				t = p[i][k]+p[k+1][j]+p[i-1]*n[k]*n[j];
				if(t<p[i][j])
				{
					p[i][j]=t;
					q[i][j]=k;
				}
			}
		}
	}
}

void TraceBack(int i,int j,int a)
{
	if(i==j)
		{
			printf("A%d",i-1);
			return;//表示函数在此处退出，不继续运行
		}
	 if(a!=1)
		printf("(");
		TraceBack(i,q[i][j],a+1);
		TraceBack(q[i][j]+1,j,a+1);
	 if(a!=1)
		printf(")");

}


int main()
{
	int n,i;
	while(cin>>n && n != 0) {
		for(i = 0; i <= n; i++)
			cin>>p[i];
		MatrixChain(n);
		TraceBack(1,n,1);
		cout<<endl;
	}
}



