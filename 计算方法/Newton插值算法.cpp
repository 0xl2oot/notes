// 差商：Difference quotient dq

#include <iostream>
#define MAX 100
using namespace std;

double newton(double dq[MAX][MAX], int n, double x) {
	for(int j = 2; j <= n; j++) {
		for(int i = j; i <= n; i++) {
			dq[i][j] = (dq[i][j-1] - dq[i-1][j-1]) / (dq[i][0] - dq[i-j+1][0]);
		}
	}
	double ans = dq[1][1];
	double temp = x-dq[1][0];
	for(int i = 2; i <= n; i++) {
		ans += temp * dq[i][i];
		temp *= (x - dq[i][0]);
	}
	return ans;
}

int main() {
	int n;
	double dq[MAX][MAX], x, ans;
	cout<<"请输入插值节点个数："<<endl;
	cin>>n;
	cout<<"请输入插值节点（x,y):"<<endl;
	for(int i = 1; i <= n; i++) {
		cin>>dq[i][0]>>dq[i][1];
	}
	cout<<"请输入插值点x："<<endl;
	cin>>x;
	ans = newton(dq, n, x);
	cout<<ans<<endl;
	return 0;
}

/*
测试数据一
3
100 10 121 11 144 12
115
结果：10.7228
测试数据二：
4
-1 0.65 0 1.2 1 -0.4 2 2.8
1.8
结果：1.4424
*/