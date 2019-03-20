#include <iostream>

using namespace std;

class MY {
	public:
		MY(int i, int j, int k);
		void PrintNumber();
		int GetSum(MY m);
	private:
		int a, b, c;
		static int s;
};
int MY::s = 0;
MY::MY(int i, int j, int k) {
	a = i;
	b = j;
	c = k;
	s = a + b + c;
}
void MY::PrintNumber() {
	cout<<a<<","<<b<<","<<c<<endl;
}
int MY::GetSum(MY m) {
	return MY::s;
}
int main(int argc, char *argv[]) {
	MY m1(2, 3, 4), m2(5, 6, 7);
	m2.PrintNumber();
	cout<<m1.GetSum(m1)<<","<<m2.GetSum(m2)<<endl;
	return 0;
}