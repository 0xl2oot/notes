#include <iostream>

using namespace std;

// 基类People
class People{
	public:
		void setname(const char *name);
		const char* getname();
		void setage(int age);
		int getage();
	private:
		const char *m_name;
		int m_age;
};
void People::setname(const char *name){m_name = name;}
void People::setage(int age){m_age = age;}
const char* People::getname(){return m_name;}
int People::getage(){return m_age;}

// 派生类Student
class Student:public People{
	public:
		void setscore(float score);
		float getscore();
	private:
		float m_score;
};
void Student::setscore(float score){m_score = score;}
float Student::getscore(){return m_score;}

int main() {
	Student stu;
	stu.setname("小明");
	stu.setage(16);
	stu.setscore(89.5f);
	cout<<stu.getname()<<"的年龄是"<<stu.getage()<<"，成绩是"<<stu.getscore()<<endl;
	
	return 0;	
}