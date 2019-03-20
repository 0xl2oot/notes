#include <iostream>

using namespace std;

class A {
public:
	A(){
		i= 0;
		cout<<"A无参默认构造方法，i = "<<i<<endl;
	}
	A(int i) {
	   this->i = i;
	   cout<<"A无参默认构造方法，i = "<<i<<endl;
	}
	int getI(){
	   return i;
	}
private:
	int i;
};

class B : public A {
public:
	B(){
		cout<<"B无参默认构造方法"<<endl;
	}
	B(int i) : A(i){
		cout<<"B非默认构造方法"<<endl;
	}
private:
	int b;
};

int main() {
	int a;
	cin>>a;
	B b1;
	B b2(a);
	cout<<"b1中i的值为"<<b1.getI()<<endl;
	cout<<"b2中i的值为"<<b2.getI()<<endl;
	return 0;
}