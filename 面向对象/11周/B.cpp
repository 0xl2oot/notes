#include <iostream>
using namespace std;
// 常成员函数
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

int main() {
	B b1(5, 10);
	b1.Print();
	const B b2(2, 8);
	b2.Print();
	return 0;
}