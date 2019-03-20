#include <iostream>

using namespace std;

class M{
	public:
		M(int i, int j) {
			a = i;
			b = j;
		}
		int fun1() {
			return a;
		}
		int fun2() {
			return b;
		}
		int fun3(), fun4();
	private:
		int a, b;
};

inline int M::fun3() {
	return fun1() + fun2();
}
inline int M::fun4() {
	return fun3();
}

int main(int argc, char *argv[]) {
	M m(5, 8);
	int n = m.fun4();
	cout<<n<<endl;	
}