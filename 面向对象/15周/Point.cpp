#include <iostream>
using namespace std;

class Point {
private:
	float x, y, z;
public:
	Point(float x = 0, float y = 0, float z = 0) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	friend ostream &operator<<(ostream &os, Point p) {
		os<<"("<<p.x<<", "<<p.y<<", "<<p.z<<")"<<endl;
		return os;
	}
};

int main() {
	Point p1(1,2,3), p2(4,5,6), p3(7,8,9);
	cout<<p1<<p2<<p3;
	return 0;
}