#include <iostream>

using namespace std;

class Rectangle {
public:
		Rectangle() {
				this->r_long = 10;
				this->r_width = 10;
		}
		Rectangle(int r_long, int r_width){
				this->r_long = r_long;
				this->r_width = r_width;
		}
		int comp_area() {
				return r_long*r_width;
		}
		int comp_perimeter() {
				return 2*(r_long+r_width);
		}
		int get_long() {
				return r_long;
		}
		int get_width() {
				return r_width;
		}
protected:
		int r_long, r_width;
};

int main()
{
	 int a, b;
	 cin >> a >> b;
	 Rectangle rect1, rect2(a, b); //分别调用不同的构造函数，创建两个对象
	 cout << "(" << rect1.get_long() << "," << rect1.get_width() << ")" << endl;
	 cout << "(" << rect2.get_long() << "," << rect2.get_width() << ")" << endl;
	 cout << rect2.comp_area() << endl;
	 cout << rect2.comp_perimeter() << endl;
	 return 0;
}


#include <iostream>

using namespace std;

class Test {
protected:
		int x, y;
public:
		Test(int a = 0, int b = 0) : x(a), y(b){
		}
		~Test() {
				cout<<x<<" "<<y<<endl;
		}
};

int main()
{
		Test t1;
		Test *t2;
		int a, b;
		for(int i = 0; i < 2; i++)
		{
				cin >> a >> b;
				t2 = new Test(a, b);
				delete t2;
		}
		return 0;
}



#include <iostream>
#include <string>
using namespace std;

class CWnd
{
	 protected:
			int width;
			int height;
	 public:
			CWnd()
			{
				 width = height = 0;
			}
			CWnd(int a, int b)
			{
				 width = a;
				 height = b;
			}
			void setHeight(int s)
			{
				 height = s;
			}
			void setWidth(int s)
			{
				 width = s;
			}
			int getHeight()
			{
				 return height;
			}
			int getWidth()
			{
				 return width;
			}
};

class CEdit:public CWnd {
protected:
		string text;
public:
		CEdit() {
				text = "";
		}
		CEdit(int a, int b, string c): CWnd(a, b), text(c) {
		}
		void setText(string c) {
				text = c;
		}
		string getText() const {
				return text;
		}
};

int main()
{
	 int a, b;
	 string c;
	 cin >> a >> b >> c;
	 CEdit d(a, b, c);
	 cout << d.getWidth() << endl;
	 cout << d.getHeight() << endl;
	 cout << d.getText() << endl;
	 return 0;
}


#include <iostream>
#include <string>

using namespace std;


class Animal
{
protected:
		string name; //昵称
		string kind; //种类
public:
		Animal(string a, string b) {
				name = a;
				kind = b;
		}

		~Animal() {
				cout << name << " " << kind << endl;
		}
		virtual void Laugh(){}
		void DoLaugh(){
				Laugh();
		}
};

class Mouse:public Animal
{
public:
		Mouse(string c): Animal(c, "老鼠"){
		}
		void Laugh()
	 {
			cout << "吱吱......" << endl;
	 }
};
int main()
{
	 string name;
	 cin >> name;
	 Mouse mm(name); //创建对象

	 cout << "我成功创建了一只老鼠" << endl;
	 mm.DoLaugh();
	 return 0;
}