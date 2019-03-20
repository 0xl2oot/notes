#include <iostream>

using namespace std;
// ⼦对象的初始化
class B {
	public:
		B(int i, int j) {
			b1 = i;
			b2 = j;
		}
		void Print() {
			cout<<b1<<";"<<b2<<endl;
		}
		void Print() const {
			cout<<b1<<":"<<b2<<endl;
		}
	private:
		int b1, b2;
};

class A {
	public:
		A(int i, int j, int k):b(i, j) {
			a = k;
		}
		void Print() {
			b.Print();
			cout<<a<<endl;
		}
	private:
		B b;
		int a;
};

int main(int argc, char *argv[]) {
	B b(7, 8);
	b.Print();
	A a(4, 5, 6);
	a.Print();
	return 0;	
}