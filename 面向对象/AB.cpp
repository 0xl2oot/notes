#include <iostream>

using namespace std;

class AB {
	public:
		AB(int i, int j) {
			a = i; 
			b = j;
		}	
		AB(int i) {
			a = i;
			b = i*i;
		}
		int Add(int x, int y) {
			a = x;
			b = y;
			return a + b;
		}
		int Add(int x) {
			a = b = x;
			return a + b;
		}
		int Add() {
			return a + b;
		}
		int aout() {
			return a;
		}
		int bout() {
			return b;
		}
	private:
		int a, b;
};
int main(int argc, char *argv[]) {
	AB a(5, 8), b(7);
	cout<<"a = "<<a.aout()<<", "<<a.bout()<<endl;
	cout<<"b = "<<b.aout()<<", "<<b.bout()<<endl;
	int i = a.Add();
	int j = a.Add(4);
	int k = a.Add(3, 9);
	cout<<i<<endl<<j<<endl<<k<<endl;
		
}