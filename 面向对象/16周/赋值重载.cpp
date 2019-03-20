#include <iostream>

using namespace std;

class Value {
  	int a, b;
  	float c;
public:
    Value(int aa = 0, int bb = 0, float cc = 0.0) : a(aa), b(bb), c(cc) { }
  	Value& operator=(const Value& rv) {
  	  	a = rv.a;b = rv.b;c = rv.c;
  	  	return *this; 
  	}
  	friend ostream&  operator<<(ostream& os, const Value& rv) {
		//重载operator<<，将对象写到输出流  
		os << "a = " << rv.a << ", b = " << rv.b << ", c = " << rv.c;
		return os; 
	}
};

int main() {
  	Value a, b(1, 2, 3.3);
  	cout << "a: " << a << endl;
  	cout << "b: " << b << endl;
  	a = b;	//调用operator=
  	cout << "a after assignment: " << a << endl;
} 
