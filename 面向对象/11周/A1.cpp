#include <iostream>

using namespace std;

class A{
	public:
		A(int i = 8, int j = 10, int k = 12);
		int aout() { return a; }
		int bout() { return b; }
		int cout() { return c; }
		int c;
		int fun(int d) { return a*c+d; }
	private:
		int a, b;
};

A::A(int i, int j, int k) {
	a = i;
	b = j;
	c = k;
}
int main(int argc, char *argv[]) {
	A X, Y(5), Z(7, 9, 11);
	cout<<"X="<<X.aout()<<","<<X.bout()<<","<<X.cout()<<endl;
	cout<<"Y="<<Y.aout()<<","<<Y.bout()<<","<<Y.cout()<<endl;
	cout<<"Z="<<Z.aout()<<","<<Z.bout()<<","<<Z.cout()<<endl;

	// 说明指针应该指向哪个成员
	// 指针名 = &类名::数据成员名;
	int A::*pc = &A::c;
	// 通过对象名.*类成员指针名
	X.*pc = 1;
	cout<<"X.*pc = "<<(X.*pc)<<endl;

	// 通过指针名->*类成员指针名
	A *p = &X;
	p->*pc = 6;
	cout<<"p->*pc = "<<(p->*pc)<<endl;

	// 初始化指针名=类名::函数成员名
	int (A::*pfun)(int) = &A::fun;
	// 通过对象名（或对象指针）与成员指针结合来访问函数成员
	// (对象名.* 类成员指针名)(参数表)
	cout<<"(X.*pfun)(9) = "<<(X.*pfun)(9)<<endl;
    // (对象指针名—>*类成员指针名)(参数表)
    A *pf = &Y;
	cout<<"(pf->*pfun)(9) = "<<(pf->*pfun)(9)<<endl;
	return 0;
}
