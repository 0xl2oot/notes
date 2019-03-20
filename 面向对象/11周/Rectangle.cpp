#include <iostream>
using namespace std;

class Rectangle
{
	public:
		Rectangle(double i , double j) {
			height = i; 
			width = j;
		}
		double Area() {  
			return height * width;
		}
		double Area(Rectangle *a) {
			return (a->height)*(a->width);
		}
	private:
		double height, width;
};

int main() {
	Rectangle r(5,6);
	Rectangle i(3,4);
	cout<< r.Area() << endl;
	cout<< i.Area(&r) << endl;
	return 0;
}
