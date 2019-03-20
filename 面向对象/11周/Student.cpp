#include <iostream>

using namespace std;

class Student
{
	 public:
		string name;
		long int stuno;
		int score;
		Student(string name = "",long int stuno = 0,int score = 0)
		{ 
			 this->name = name;
			 this->stuno = stuno;
			 this->score = score;
		}
		void Setscore(int score) {  
			this->score = score;
		}
		void Print() {  
			cout<<stuno<<'\t'<<name<<'\t'<<score<<endl;  
		}
};
int main(int argc, char *argv[]) {
	Student stu[5]={ Student("Ma",5019001,94),
	Student("Hu",5019002,95),
  	Student("Li",5019003,88)};
	stu[3] = Student("Zhu",5019004,85);
	stu[4] = Student("Lu",5019005,90);
	stu[1].Setscore(98);
	for(int i(0);i<5;i++)
		stu[i].Print();
}