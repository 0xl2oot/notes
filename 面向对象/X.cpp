#include <iostream>

using namespace std;
class X {
	friend class Y;
	public:
		X(int i) {
			x = i;
		}
		void Print() {
			cout<<"x = "<<x<<", s = "<<s<<endl;
		}
	private:
		int x;
		static int s;
};
int X::s = 5;
class Y {
	public:
		Y(int i) {
			y = i;
		}
		void Print(X &r) {
			cout<<"x = "<<r.x<<", y = "<<y<<endl;
		}
	private:
		int y;
};

using namespace std;
int main(int argc, char *argv[]) {
	X m(2);
	m.Print();
	Y n(8);
	n.Print(m);
	return 0;
}