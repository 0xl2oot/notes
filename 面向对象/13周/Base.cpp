#include <iostream>
#include <cstdio>
using namespace std;

class Base {
public:
	void setValue(int i) {
		this->i = i;
		printf("In setValue(int i), i = %d\n", i);
	}
	void setValue(float f) {
		i = (int)f;
		printf("In setValue(float f), i = %d\n", i);
	}
	void setValue(double d) {
		i = (int)d;
		printf("In setValue(double d), i = %d\n", i);
	}
	int i;
};

class Sub : public Base {
public:
	using Base::setValue;
	void setValue(char d) {
		i = (int)d;
		printf("In setValue(char d), i = %c\n", i);
	}
};

int main() {
	Sub s;
	char b;
	cin>>b;
	s.setValue(2);
	s.setValue(3.5f);
	s.setValue(7.8);
	s.setValue(b);
	return 0;
}