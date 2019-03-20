#include <iostream>

using namespace std;
// 常数据成员
// <构造函数名> (<参数表>): <成员初始化列表>
// { <函数体> }

class A {
	public:
		// 常数据成员初始化
		A(int i) : a(i), r(a){
		}
		void Print() {
			cout<<a<<","<<b<<","<<r<<endl;
		}
		const int &r;
	private:
		const int a;
		static const int b;
};
const int A::b = 15; // 静态成员初始化

int main(int argc, char *argv[]) {
	A a1(10), a2(20);
	a1.Print();
	a2.Print();
	return 0;
}