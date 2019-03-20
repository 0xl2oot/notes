#include <iostream>

using namespace std;

class Integer {
  	long i;

public:
  	Integer(long ll = 0) : i(ll) {}
  	Integer* This( ) { return this; }
	friend const Integer&  operator+(const Integer& a);
  	friend const Integer   operator-(const Integer& a);
  	friend const Integer   operator~(const Integer& a);
  	friend Integer*   operator&(const Integer& a);
  	friend bool operator!(const Integer& a);
	friend const Integer&   operator++(Integer& a);   // 前缀++
  	friend const Integer   operator++(Integer& a, int);//后缀++
  	friend const Integer&  operator--(Integer& a);  // 前缀++
  	friend const Integer   operator--(Integer& a, int);//后缀++ };

};
// 全局运算符函数的定义
	const Integer& operator+(const Integer& a) {
	  		return a;
	}
	const Integer operator-(const Integer& a) {
	  		return Integer(-a.i);
	}
	const Integer operator~(const Integer& a) {
	  		return Integer(~a.i);
	}
	Integer* operator&(Integer& a) {
	  		return a.This( ); // 不能用&a，会导致递归调用本函数
	}
	bool operator!(const Integer& a) {
	  		return !a.i;
	}
	const Integer& operator++(Integer& a) { // 前缀
	  		a.i++;
			return a;
	}
	const Integer operator++(Integer& a, int) { // 后缀
	  		Integer before(a.i);
	  		a.i++;
	  		return before;
	}
	const Integer& operator--(Integer& a) {
	  		a.i--;
			return a;
	}
	const Integer operator--(Integer& a, int) {
	  		Integer before(a.i);
	  		a.i--;
	 		return before;
	}
int main( ) {
  	Integer a, *ip;
  	+a;
  	-a;
  	~a;
  	ip = &a;
  	!a;
  	++a;
  	a++;
  	--a;
  	a--;
	return 0;
}
