#include <iostream>

using namespace std;
class Point{
	public:
		Point(int xx, int yy);
		~Point();
	private:
		int x, y;
};
Point::Point(int xx, int yy) {
	x = xx;
	y = yy;
}
Point::~Point() {
	
}

int main() {

	return 0;	
}