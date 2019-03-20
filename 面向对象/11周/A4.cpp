#include <iostream>

using namespace std;

class A
{
	public:
		A(int i = 0, int j = 0) {  
			x = i;
			y = j; 
		}
		void Print() {  
			cout<<x<<','<<y<<endl;
		}

	private:
       int x,y;
};  

int main() {
	A a1, a2(5,8), a3(2,5), a4(8,4);
	A *array1[4] = { &a4, &a3, &a2, &a1 };
	for(int i(0); i < 4; i++)
		 array1[i]->Print();
	cout<<endl;
	
	A *array2[4];
	array2[0] = &a1;
	array2[1] = &a2;
	array2[2] = &a3;
	array2[3] = &a4;
	for(int i(0); i < 4; i++)
		 array2[i]->Print();
	return 0;
}