#include <iostream>

using namespace std;

class Point{
	public:
		Point(int X = 0, int Y = 0) {
			this->X = X;
			this->Y = Y;
			cout<<"构造函数被调用"<<endl;
		}
		Point(Point& p) {
			X = p.X;
			Y = p.Y;
			countP++;
			cout<<"拷贝构造函数被调用"<<endl;	
		}
		~Point(){
			cout<<"析构函数被调用 "<<X<<" "<<Y<<endl;
		}
		int GetX() {return X;}
		int GetY() {return Y;}
		static void GetC() {
			cout<<"Object id = "<<countP;
		}
	private:
		int X, Y;
		static int countP;
};
int Point::countP = 0;

void fun1(Point p) {
	cout<<p.GetX()<<endl;
}

Point fun2() {
	Point A(3, 4);
	return A;
}

int main(int argc, char *argv[]) {
	cout<<"拷贝构造函数的例子:"<<endl;
	Point A(1, 2);
	cout<<"Point A, "<<A.GetX()<<","<<A.GetY()<<endl;
	Point B(A);
	cout<<"Point B, "<<B.GetX()<<","<<B.GetY()<<endl;
	
	cout<<"函数形参为类对象的例子:"<<endl;
	fun1(A);
	
	cout<<"函数返回值为类对象的例子"<<endl;
	Point C;
	C = fun2();
	
	cout<<"静态成员的例子:"<<endl;
	Point D(A);
	// 输出对象号，对象名引用
	D.GetC();cout<<endl;
	// 输出对象号，类名引用
	Point::GetC();cout<<endl;
	return 0;
}