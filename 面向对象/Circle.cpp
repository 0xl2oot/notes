#include <iostream>

using namespace std;

const float PI = 3.1415926535;
const float FencePrice = 35;
const float ConcretePrice = 20;

class Circle{
	public:
		Circle(float r) {
			radius = r;
		}	
		float Circumference() const {
			// 圆周长
			return 2*PI*radius;
		}
		float Area() const {
			// 圆面积
			return PI*radius*radius;
		}
	private:
		float radius;
};

int main(int argc, char *argv[]) {
	float radius;
	float FenceCost, ConcreteCost;
	cout<<"Enter the radius of the pool:"<<endl;
	cin>>radius;
	Circle Pool(radius);
	Circle PoolRim(radius + 3);
	FenceCost = PoolRim.Circumference()*FencePrice;
	cout<<"Fencing Cost is ￥"<<FenceCost<<endl;
	ConcreteCost = (PoolRim.Area() - Pool.Area())*ConcretePrice;
	cout<<"Concrete Cost is ￥"<<ConcreteCost<<endl;
	return 0;
}