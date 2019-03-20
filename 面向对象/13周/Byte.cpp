#include <iostream>

using namespace std;

class Byte {
public:
  	Byte(int b = 25) : b(b) {}
  	// 无副作用的运算符定义为 const成员函数
	int getB() {
		return b;
	}
	const Byte& operator+( ) const { //正号
    	return *this;
	}
	const Byte operator-( ) const { //负号
    	return Byte(-b);
	}
	const Byte operator~( ) const { //按位取反
    	return Byte(~b);
	}
	Byte operator!( ) const {//逻辑非
    	return Byte(!b);
	}
  	Byte* operator&( ) {//取地址
		return this;
	}
	// 有副作用的运算符定义为非const成员函数
  	const Byte& operator++( ) { // 前缀++
		b++;
		return *this;
	}
  	const Byte operator++(int) { // 后缀++
    	Byte before(b);
    	b++;
    	return before;
	}
  	const Byte& operator--( ) { // 前缀--
    	--b;
    	return *this;
	}
  	const Byte operator--(int) { // 后缀--
    	Byte before(b);
    	--b;
    	return before;
	}
private:
	int b;
};

int main() {
	Byte a, b, *bp;
	b = +b; cout<<b.getB()<<endl;
	b = -b; cout<<b.getB()<<endl;
	b = ~b; cout<<b.getB()<<endl;
	bp = &b; cout<<bp<<endl;
	a = !b; cout<<a.getB()<<endl;
	b = ++b; cout<<b.getB()<<endl;
	b = b++; cout<<b.getB()<<endl;
	b = --b; cout<<b.getB()<<endl;
	b = b--; cout<<b.getB()<<endl;
	return 0;
}

