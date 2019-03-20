### 计算方法

拉格朗日

```c
#include <iostream>
#define MAX 100
using namespace std;

double lagrange(double nodex[MAX], double nodey[MAX], int n, double x) {
	double ans = 0;
	for(int i = 0; i < n; i++) {
		double temp = 1;
		for(int j = 0; j < n; j++) {
			if(i != j) {
				temp *= ((x - nodex[j]) / (nodex[i] - nodex[j]));
			}
		}
		ans += temp * nodey[i];
	}
	return ans;
}

int main() {
	int n;
	double nodex[MAX], nodey[MAX], x, ans;
	cout<<"请输入插值节点个数："<<endl;
	cin>>n;
	cout<<"请输入插值节点（x,y):"<<endl;
	for(int i = 0; i < n; i++) {
		cin>>nodex[i]>>nodey[i];
		// cout<<nodex[i]<<" "<<nodey[i]<<endl;
	}
	cout<<"请输入插值点x："<<endl;
	cin>>x;
	ans = lagrange(nodex, nodey, n, x);
	cout<<ans<<endl;
	return 0;
}

/*
测试数据一
4
24 1.888175 26 1.918645 28 1.947294 30 1.961009
29
结果
25 1.90282
27 1.93402
29 1.95684

测试数据二：
4
-1 0.65 0 1.2 1 -0.4 2 2.8
1.8
结果：1.4424
*/
```



牛顿科特斯

```c
#include <iostream>
#include <iomanip>
using namespace std;
#define MAXSIZE 7

void input(double f[MAXSIZE + 1], double a, double b, long n) {
	long i;
	double h;
	h = (b - a) / (n - 1);
	cout<<"请输入求积节点纵坐标:";
	for(i = 0; i <= n - 1; i++) {
		cout<<endl<<"x["<<i<<"] = "<<a+i*h<<", f["<<i<<"] = ";
		cin>>f[i];
	}
}

int main() {
	long c[MAXSIZE][MAXSIZE/2+2] = {{2,1},{6,1,4},{8,1,3},{90,7,32,12},{288,19,75,50},{840,41,216,27,272},{17280,751,3577,1323,2989}};
	double a, b, f[MAXSIZE + 1], intergral;
	long n, i;
	cout<<"请输入积分区间边界a,b:";
	cin>>a>>b;
	cout<<endl<<"请输入积分节点的个数(2-8):";
	cin>>n;
	input(f,a,b,n);
	intergral = 0;
	for(i = 0; i < n/2; i++)
		intergral += (f[i]+f[n-i-1])*c[n-2][i+1]/c[n-2][0];
	if(n%2)
		intergral += f[n/2]*c[n-2][n/2+1]/c[n-2][0];
	intergral *= b - a;
	cout<<endl<<"积分值为"<<setiosflags(ios::fixed)<<intergral<<endl;
	return 0;
}

/*
测试数据
0 1
5
1 1.65534 1.55152 1.06666 0.72159
测试结果
积分值为1.308593
*/
```



雅克比

```c
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
			for(long j = 0; j <= n; j++)
				if(j != i)
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
```



矩阵分解

```
#include <iostream>
#include <cmath>
#include <iomanip>
#define MAXSIZE 50
using namespace std;

void input(double a[MAXSIZE][MAXSIZE], double x[MAXSIZE], long n) {
	cout<<endl<<"请输入原方程组的增广矩阵:"<<endl;
	for(long i = 0; i < n; i++) {
		for(long j = 0; j < n; j++) {
			cin>>a[i][j];
		}
		cin>>x[i];
	}
}

void output(double x[MAXSIZE], long n) {
	cout<<endl<<"原方程组的解向量为："<<endl;
	for(long i = 0; i < n; i++)
		cout<<setiosflags(ios::fixed)<<x[i]<<" ";
}

int main() {
	double a[MAXSIZE][MAXSIZE], x[MAXSIZE], s;
	long n, i, j, k;
	cout<<endl<<"请输入原方程组的阶数：";
	cin>>n;
	input(a, x, n);
	for(k = 0; k <= n-2; k++) {
		for(i = k+1; i <= n-1; i++) {
			s = 0;
			for(j = 0; j <= k-1; j++)
				s += a[i][j]*a[j][k];
			a[i][k] = (a[i][k]-s) / a[k][k];
		}
		for(j = k+1; j <= n-1; j++) {
			s = 0;
			for(i = 0; i <= k; i++)
				s += a[k+1][i]*a[i][j];
			a[k+1][j] -= s;
		}
	}
	for(i = 1; i <= n-1; i++) {
		s = 0;
		for(j = 0; j <= i-1; j++)
			s += a[i][j]*x[j];
		x[i] -= s;	
	}
	for(i = n-1; i >= 0; i--) {
		s = 0;
		for(j = i+1; j <= n-1; j++)
			s += a[i][j]*x[j];
		x[i] = (x[i]-s) / a[i][i];
	}
	output(x, n);
	return 0;
}


/* 
测试数据

3
10 -1 -2 7.2
-1 10 -2 8.3
-1 -1 5 4.2

*/
```

欧拉公式

```c
#include <iostream>
#include <iomanip>
#define MAXSIZE 50
using namespace std;
double f(double x, double y) {
	return y - 2*x/y;
}
int main() {
	double a, b, h, x[MAXSIZE], y[MAXSIZE];
	long i, n;
	cout<<"请输入求解区间 a, b: ";
	cin>>a>>b;
	cout<<endl<<"请输入步长h:";
	cin>>h;
	n = (long)((b-a)/h);
	x[0] = a;
	cout<<endl<<"请输入起点x[0] = "<<x[0]<<"处的纵坐标y[0]: ";
	cin>>y[0];
	for(i = 0; i < n; i++) {
		x[i+1] = x[i] + h;
		y[i+1] = y[i] + h*f(x[i], y[i]);
		y[i+1] = y[i] + h*(f(x[i], y[i]) + f(x[i] + h, y[i+1])) / 2;
	}
	cout<<endl<<"计算结果为:"<<endl;
	for(i = 0; i <= n; i++)
		cout<<"n["<<i<<"] = "<<setiosflags(ios::fixed)<<x[i]<<", y["<<i<<"] = "<<setiosflags(ios::fixed)<<y[i]<<endl;
}

/*
0 1
0.1
1
*/
```

