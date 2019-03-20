#include <iostream>

using namespace std;

class my_string{
	char* str;
	int len;
public:
	my_string(const char* s = ""){
    	len = strlen(s);
    	str = new char[len + 1];
    	strcpy(str, s);
	}
	~my_string(){delete[]str;}
	//…其他构造函数和成员函数略
	my_string& operator=(const my_string& s);
};
 
my_string& my_string::operator= (const my_string& s) {    
		//赋值之前先进行自赋值检测
    if(this == &s)
		return *this;
    delete[] str;
   	len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
    return *this;
}	

int main(int argc, char *argv[]) {
	my_string a("abcde"),  b("hijk");
	a = b;		//如何赋值？
}