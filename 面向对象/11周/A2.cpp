#include <iostream>

using namespace std;

class A
{
	public:
		A(int i,int j) {  
			a=i;b=j;  
		}
		A() {  
			a=b=0;  
		}
		void Copy(A &a);
		void Print() {  
			cout<<a<<','<<b<<endl;  
		}
	private:
		int a,b;
};

void A::Copy(A &a)
{
	if(this==&a)
		return;
	*this=a;
}

int main(int argc, char *argv[]) {
	A a1,a2(1,5);
	a1.Copy(a2);
	a1.Print();
	return 0;
}