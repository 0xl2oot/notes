#include <iostream>
#include <cmath>
#include <iomanip>
#define MAXSIZE 50

using namespace std;

void input(double a[MAXSIZE][MAXSIZE], double b[MAXSIZE], long n) {
	cout<<endl<<"请输入原方程组的增广矩阵:"<<endl;
	for(long i = 0; i < n; i++) {
		for(long j = 0; j < n; j++) {
			cin>>a[i][j];
		}
		cin>>b[i];
	}
}

void output(double x[MAXSIZE], long n) {
	cout<<endl<<"原方程组的解向量为："<<endl;
	for(long i = 0; i < n; i++)
		cout<<setiosflags(ios::fixed)<<x[i]<<" ";
}

int main() {
	double a[MAXSIZE][MAXSIZE], b[MAXSIZE], x[MAXSIZE];
	double epsilon, e, s, oldx;
	long n, k, maxk;
	cout<<"请输入原方程组的阶数：";
	cin>>n;
	input(a, b, n);
	cout<<endl<<"请输入迭代初始向量：";
	for(int i = 0; i < n; i++)
		cin>>x[i];
	cout<<endl<<"请输入最大迭代次数：";
	cin>>maxk;
	cout<<endl<<"请输入误差上限：";
	cin>>epsilon;
	for(k = 1; k <= maxk; k++) {
		e = 0;
		for(long i = 0; i <= n-1; i++) {
			oldx = x[i];
			s = 0;
			for(long j = 0; j < i; j++)
				s += a[i][j]*x[j];
			for(long j = i+1; j <= n; j++)
				s += a[i][j]*x[j];
			x[i] = (b[i]-s) / a[i][i];
			if(e < fabs(oldx-x[i]))
				e = fabs(oldx-x[i]);
		}
		if(e < epsilon)
			break;
	}
	if(k <= maxk)
		output(x, n);
	else
		cout<<endl<<"迭代次数已经超过上限";
}

/*
3
10 -1 -2 7.2
-1 10 -2 8.3
-1 -1 5 4.2
0 0 0
300
0.000007

请输入原方程组的阶数：3
请输入原方程组的增广矩阵:
10 -1 -2 7.2
-1 10 -2 8.3
-1 -1 5 4.2
请输入迭代初始向量：0 0 0
请输入最大迭代次数：300
请输入误差上限：0.000007
原方程组的解向量为：
1.100000 1.200000 1.300000 
*/