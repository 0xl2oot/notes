#include <iostream>
#include <iomanip>

using namespace std;

class ComplexNumber {
	public:
		ComplexNumber() {
			cin>>r>>i;
		}
		ComplexNumber(int r, int i) {
			this->r = r;
			this->i = i;
		}
		~ComplexNumber(){ 
		}
		ComplexNumber static add(ComplexNumber &a, ComplexNumber &b) {
			return ComplexNumber(a.r+b.r, a.i+b.i);
		}
		void add(ComplexNumber &a) {
			this->r = this->r+a.r;
			this->i = this->i+a.i;
		}
		ComplexNumber static sub(ComplexNumber &a, ComplexNumber &b) {
			return ComplexNumber(a.r-b.r, a.i-b.i);
		}
		void sub(ComplexNumber &a) {
			this->r = this->r-a.r;
			this->i = this->i-a.i;
		}
		ComplexNumber static multiply(ComplexNumber &a, ComplexNumber &b) {
			int m = a.r*b.r - a.i*b.i;
			int n = a.i*b.r + a.r*b.i;
			return ComplexNumber(m, n);
		}
		void multiply(ComplexNumber &a) {
			int m = this->r*a.r - this->i*a.i;
			int n = this->i*a.r + this->r*a.i;
			this->r = m;
			this->i = n;
		}
		void static printComplexNum(ComplexNumber &a) {
			cout<<resetiosflags(ios::showpos)<<a.r;
			if(a.i != 0)
				cout<<setiosflags(ios::showpos)<<a.i<<"i";
			cout<<endl;
		}
	private:
		int r, i;
};

int main() {
	ComplexNumber a, b;
	ComplexNumber c = ComplexNumber::add(a, b);
	ComplexNumber d = ComplexNumber::sub(a, b);
	ComplexNumber e = ComplexNumber::multiply(a, b);
	cout<<"a + b = "; ComplexNumber::printComplexNum(c);
	cout<<"a - b = "; ComplexNumber::printComplexNum(d);
	cout<<"a * b = "; ComplexNumber::printComplexNum(e);
	c.add(a);
	cout<<"After c.add(a), c = ";
	ComplexNumber::printComplexNum(c);
	c.sub(a);
	cout<<"After c.substract(a), c = ";
	ComplexNumber::printComplexNum(c);
	c.multiply(a);
	cout<<"After c.multiply(a), c = ";
	ComplexNumber::printComplexNum(c);
	return 0;
}