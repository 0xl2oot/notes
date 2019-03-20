#include <iostream>
using namespace std;

class Image {
protected:
		int width, height;
public:
		Image(int width, int height) {
				this->width = width;
				this->height = height;
		}
		virtual ~Image(){} 
		int GetWidth() {
				return width;
		}
		int GetHeight() {
				return height;
		}
};

class Png : public Image {
protected:
		char* pngdib;
public:
		Png(int width, int height): Image(width, height){
				pngdib = new char[width*height*4];
		}
		~Png() {
				delete pngdib;
		}
};

int main()
{
	 int a, b;
	 cin >> a >> b;
	 Image *png = new Png(a, b);	//创建Png图像类的对象png
	 cout << "图像宽：" << png->GetWidth() << endl;
	 cout << "图像高：" << png->GetHeight() << endl;
	 delete png;
	 return 0;
}

/*
// #######################华丽的分割线############################


#include <iostream>
using namespace std;

class Point
{
	 public:
			void setxy(int x, int y)
			{
				 X = x;
				 Y = y;
			}
			void displayxy()
			{
				 cout << X << "," << Y;
			}
	 private:
			int X, Y;
};

class Point3D : public Point {
protected:
		int Z;
public:
		void display() {
				Point::displayxy();
				cout<<","<<Z;
		}
		void setxyz(int x, int y, int z) {
				Point::setxy(x, y);
				Z = z;
		}
};
int main()
{
	 Point3D p;
	 int a, b, c;
	 cin >> a >> b >> c;
	 p.setxyz(a, b, c);
	 p.display();
	 return 0;
}


// #######################华丽的分割线############################

#include <iostream>
using namespace std;

class Point3D {
private:
		int X, Y, Z;
public:
		Point3D(){X = 0; Y = 0; Z = 0;}
		Point3D(int X, int Y, int Z){
				this->X = X;
				this->Y = Y;
				this->Z = Z;
		}
		void setXYZ(int X, int Y, int Z){
				this->X = X;
				this->Y = Y;
				this->Z = Z;
		}
		void displayXYZ() {
				cout<<X<<" "<<Y<<" "<<Z<<endl;
		}
		void move(int x1, int y1, int z1) {
				X += x1;
				Y += y1;
				Z += z1;
		}

};
int main()
{
	 int a, b, c, d, e, f;
	 cin >> a >> b >> c >> d >> e >> f;
	 Point3D p1, p2(a, b, c);

	 p1.displayXYZ();
	 p2.displayXYZ();

	 p2.setXYZ(d, e, f);
	 p2.displayXYZ();

	 cin >> a >> b >> c;
	 p2.move(a, b, c);
	 p2.displayXYZ();
	 return 0;
}


// #######################华丽的分割线############################


#include <iostream>
#include <string>
using namespace std;

class Student
{
		protected:
		string name; //保护的数据成员
		int age;
		string number;

		public:
		void Set(string na, int a, string nu) //成员函数Set()
		{
				 name = na;
				 age = a;
				 number = nu;
		}
		void Set(const Student &s) //重载成员函数Set()，形参Student对象的常引用
		{
				Set(s.name, s.age, s.number); //调用恰当的成员函数
		}
		void Show()
		{
				cout << "姓名：" << name << endl;
				cout << "年龄：" << age << endl;
				cout << "学号：" << number << endl;
		}
};

int main()
{
	 Student stu, stucopy; //创建两个对象
	 int age;
	 string name, no;
	 cin >> name >> age >> no;
	 stu.Set(name, age, no); //调用恰当的成员函数
	 stucopy.Set(stu); //调用恰当的成员函数
	 stucopy.Show(); //调用恰当的成员函数
	 return 0;
}


// #######################华丽的分割线############################


#include <iostream>
using namespace std;

class A {
		public:
		virtual void F() const = 0;
};

class B : public A {
		public:
		void F() const
		{
				cout << "B::F" << endl;
		}
};
int main()
{
		#define N 3

		B b3;
		B *a[N] = {new B(), new B(), &b3};

		for(int i = 0; i < N; i++)
				a[i]->F();

		delete a[0];
		delete a[1];
		return 0;
}

// #######################华丽的分割线############################

#include <iostream>

using namespace std;
class Point //基类Point
{
	 protected:
			int x; //x坐标
			int y; //y坐标
	 public:
			void Set(int x1, int y1) //设置坐标函数
			{
				 x = x1;
				 y = y1;
			}
			void Display() const //输出坐标函数
			{
				 cout << "(" << x << ", " << y << ")" << endl;
			}
			void Move(int deltax, int deltay) //移动坐标函数
			{
				 x += deltax;
				 y += deltay;
			}
};
class Point3D : public Point //派生类Point3D，公有继承方式
{
	 protected:
			int z; //z坐标
	 public:
			void Set(int x1, int y1, int z1)//设置坐标函数重定义，通过调用基类Set()函数等方法将三个参数分别传给对应数据成员
			{
				 Point::Set(x1, y1);
				 z = z1;
			}
			void Display() const //输出坐标函数重定义
			{
				 cout << "(" << x << ", " << y << ", " << z << ")" << endl;
			}
			void Move(int deltax, int deltay, int deltaz) //移动坐标函数重定义
			{
				 Point::Move(deltax, deltay);
				 z += deltaz;
			}
};
int main()
{
	 Point3D p1;	//创建派生类的对象p1
	 int x, y, z;
	 cin >> x >> y >> z;
	 p1.Set(x, y, z); //调用Set()函数给p1对象的x、y、z数据成员赋值
	 p1.Display();

	 int a, b, c;
	 cin >> a >> b >> c;
	 p1.Move(a, b, c);
	 p1.Display();
	 return 0;
}

// #######################华丽的分割线############################

#include <iostream>
#include <iomanip>
using namespace std;

class circle
{
	 private:
			double radius;
	 public:
			void set_radius(double r)
			{
				 radius = r;
			}
			double comp_area()
			{
				 return 3.14 * radius * radius;
			}
};
int main()
{
	 circle c1;
	 double x, a;

	 cout << "本程序已经创建了一个Circle对象,请您输入该对象的数据成员半径radius的值:" << endl;
	 cin >> x;
	 c1.set_radius(x);

	 a = c1.comp_area();
	 cout << "该Circle对象的面积为:" << setiosflags(ios::fixed) << setprecision(2) << a << endl; //输出要求小数点后必须保留2位有效数字（四舍五入），不足补零
	 return 0;
}
*/