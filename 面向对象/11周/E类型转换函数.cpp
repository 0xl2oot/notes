#include <iostream>

using namespace std;
// 类型转换函数
class E
{
	public:
		E(int i,int j ) { den=i; num=j; }
		operator double( );
	private:
		double den, num;
};

E::operator double( ) {
	return double(den)/double(num);
}
int main(int argc, char *argv[]) {
	E e(6,10);
	double a(3.5);
	a += e - 2;
	cout<<a<<endl;
	return 0;
}