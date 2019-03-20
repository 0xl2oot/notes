#include <iostream>
using namespace std;

class point { 
private:
	float x,y,z;
public :
    point(float a=0,float b=0,float c=0) { x=a;y=b;z=c;}
	friend ostream &operator<<(ostream &os,point p){ 
		os<<"("<<p.x<<","<<p.y<<","<<p.z<<")\n";
      	return os;
	}
	friend istream &operator>>(istream &is,point &p) {
       	//重载输入运算符“>>”
		cout<<"x=";is>>p.x;
		cout<<"y=";is>>p.y;
	  	cout<<"z=";is>>p.z;
      	return is; 	
	}
};

int main(){
	point p1(4,5,6),p2;
  	cin>>p2;
  	cout<<p1<<p2<<endl;
}
