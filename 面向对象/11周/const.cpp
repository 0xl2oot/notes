#include <iostream>

using namespace std;
// 常指针和常引用
int main() {
	int a = 0, b = 0;
	int &d = a; // 引用
	const int &c = a; // 常引用
//	c = 1; // 非法
	a = 1; // 合法
	d = 1; // 合法
	int *const p1 = &a; // 地址值为常量的指针
	const int *p2 = &a; // 所指向值为常量的指针
//	p1 = &c; // 非法
	p2 = &b;
//	*p2 = 1; // 非法
	*p1 = 1; // 合法
	cout << a << endl << b << endl << c << endl << d << endl << *p2 <<endl;
	return 0;
}