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