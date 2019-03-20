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