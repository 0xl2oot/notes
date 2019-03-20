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