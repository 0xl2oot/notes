#include <iostream>

using namespace std;
class Student {
	public:
		Student(string name, int score) {
			this->name = name;
			this->score = score;
		}
		void total() {
			sum += score;
			count++;
		}
		static double aver() {
			return (double)sum/count;
		}
	private:
		string name;
		int score;
		static int sum, count;
};
int Student::sum = 0;
int Student::count = 0;

int main(int argc, char *argv[]) {
	Student stu[5] = {
		Student("王永红", 100), 
		Student("王小红", 99), 
		Student("王小红", 98), 
		Student("王小红", 97), 
		Student("王小红", 96)
	};
	for(int i = 0; i < 5; i++) {
		stu[i].total();
	}
	cout<<"Average = "<<Student::aver()<<endl;
	return 0;
}