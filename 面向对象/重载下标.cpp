#include <iostream>
#include <assert.h>
using namespace std;

class vect {
public:
	//构造函数和析构函数
	explicit vect(int n = 10);
	vect(const vect& v);
    vect(const int a[], int n);
    ~vect() { delete []p; }

	//其他成员函数
	int& operator[](int i);	// 重载下标运算
	int ub() const { return (size - 1); }
	vect& operator=(const vect& v);

private:
	int* p;
    int size;
};
//成员函数类外定义
vect::vect(int n) : size(n){
    assert(size > 0);
	p = new int[size];
}
vect::vect(const int a[], int n) : size(n){
	assert(size > 0);
	p = new int[size];
	for(int i=0; i<size; ++i)
		p[i] = a[i];
}
vect::vect(const vect& v) : size(v.size){
	p = new int[size];
	for(int i=0; i<size; ++i)
		p[i] = v.p[i];
}

int& vect::operator[](int i){
	assert( i>=0 && i<size);
	return p[i];	//返回的是左值
}
vect& vect::operator=(const vect& v){
	if (this != &v) {
		assert(v.size == size);//只允许相同大小的数组赋值
		for(int i =0; i<size; ++i)
			p[i] = v.p[i];
	}
	return *this;
}
int main() { //测试程序
	int a[5]={1,2,3,4,5};
	vect v1(a,5);
	v1[2]=9;//调用operator[]
	for(int i=0; i<=v1.ub(); ++i)
		cout<<v1[i]<<"\t";
}
