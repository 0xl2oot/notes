#include <iostream>
#include <cmath>
using namespace std;

class Point{
	public:
		Point(double xx = 0, double yy = 0) {
			X = xx;
			Y = yy;
			cout<<"构造函数被调用"<<endl;
		}
		Point(Point& p) {
			X = p.X;
			Y = p.Y;
			cout<<"拷贝构造函数被调用"<<endl;	
		}
		~Point(){
			cout<<"析构函数被调用 "<<X<<" "<<Y<<endl;
		}
		double GetX() {return X;}
		double GetY() {return Y;}
		void Print() {
			cout<<"("<<X<<","<<Y<<")"<<endl;
		}
		// 友元声明
		friend double Distance(Point a, Point b);
	private:
		double X, Y;
};

double Distance(Point a, Point b) {
	double dx = a.X - b.X;
	double dy = a.Y - b.Y;
	return sqrt(dx*dx + dy*dy);
}

int main(int argc, char *argv[]) {

	cout<<"友元函数的例子"<<endl;
	double d1 = 3, d2 = 4, d3 = 6, d4 = 8;
	Point p1(d1, d2), p2(d3, d4);
	p1.Print();p2.Print();
	double d = Distance(p1, p2);
	cout<<"Distance = "<<d<<endl;
	return 0;
}