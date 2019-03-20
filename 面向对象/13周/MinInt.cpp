#include <iostream>

using namespace std;

class MinInt {
	public:
		MinInt(char ch = 0) : b(ch) {
		}
		MinInt operator-() const {
			cout << "MinInt::operator-" << endl;
			return MinInt(-b);
		}
		MinInt operator+(const MinInt& rv) const {
			cout << "MinInt::operator+" << endl;
			return MinInt(b+rv.b);
		}
		MinInt& operator+=(const MinInt& rv) {
			cout << "MinInt::operator+=" << endl;
			b += rv.b;
			return *this;
		}
		void Print() {
			cout<<(int)b<<endl;
		}
	private:
		char b;
};

int main() {
	cout<< "内置数据类型" << endl;
	int v1 = 1, v2 = 2, v3 = 3;
	v3 += v1 + v2;
	cout << "用户自定义类型" << endl;
	MinInt b1(10), b2(20), b3(30);
	b3 += -b1 + b2;
	b3.Print();
	return 0;
}