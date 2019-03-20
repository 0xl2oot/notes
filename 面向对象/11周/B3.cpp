#include <iostream>

using namespace std;
// 堆对象（动态对象）
class B {
	public:
		B() {
			strcpy(name, "");
			b = 0;
			cout<<"Default constructor called.\n";
		}
		B(const char *s, double d) {
			strcpy(name, s);
			b = d;
			cout<<"Constructor called.\n";
		}
		~B() {
			cout<<"Destructor called."<<name<<endl;
		}
		void getB(char *s, double &d) {
			strcpy(s, name);
			d = b;
		}
	private:
		char name[20];
		double b;
};

int main(int argc, char *argv[]) {
	B *pb;
	double d;
	char s[20];
	pb = new B[4];
	pb[0] = B("Ma", 3.5);
	pb[1] = B("Hu", 5.8);
	pb[2] = B("Gao", 7.2);
	pb[3] = B("Li", 9.4);
	for(int i = 0; i < 4; i++) {
		pb[i].getB(s, d);
		cout<<s<<","<<d<<endl;
	}
	delete []pb;
	return 0;
}