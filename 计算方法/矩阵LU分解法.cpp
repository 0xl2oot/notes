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
