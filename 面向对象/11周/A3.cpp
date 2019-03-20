#include <iostream>

using namespace std;

class A
{
	public:
		A(int i,int j) {  
			x=i;y=j;
		}
		A() {  
			x=y=0; 
		}
		void Print() {  
			cout<<x<<','<<y<<'\t';  
		}
	private:
		int x,y;
};

int main(int argc, char *argv[]) {
	A aa[2][3];
	int a(3),b(5);
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 3; j++)
			aa[i][j]=A(a++,b+=2);
	A (*paa)[3]=aa;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 3; j++)
			(*(*(paa+i)+j)).Print();
		cout<<endl;
	}
	return 0;
}