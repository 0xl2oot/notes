#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Patient {
	public:
		Patient() {
		}
		Patient(const char *name, char sex, int age, float weight, bool allergies) {
			strcpy(this->name, name);
			this->sex = sex;
			this->age = age;
			this->weight = weight;
			this->allergies = allergies;
		}
		~Patient() {
		}
		void setName(const char *name) {
			strcpy(this->name, name);
		}
		string getName() {
			return name;
		}
		void setSex(char sex) {
			this->sex = sex;
		}
		char getSex() {
			return sex;
		}
		void setAge(int age) {
			this->age = age;
		}
		int getAge() {
			return age;
		}
		void setWeight(float weight) {
			this->weight = weight;
		}
		float getWeight() {
			return weight;
		}
		void setAllergies(bool allergies) {
			this->allergies = allergies;
		}
		bool getAllergies() {
			return allergies;
		}
		void printInfo() {
			cout<<"病人"<<name<<"的属性如下:"<<endl;
			cout<<"姓名:"<<name<<endl;
			cout<<"性别:";
			if(sex == 'm') cout<<"男"<<endl;
			else cout<<"女"<<endl;
			cout<<"年龄:"<<age<<endl;
			cout<<setiosflags(ios::fixed)<<setprecision(2);
			cout<<"体重:"<<weight<<endl;
			cout<<"是否过敏:";
			if(allergies) cout<<"是";
			else cout<<"不";
			cout<<endl;
		}
	private:
		char name[80];
		char sex;
		int age;
		float weight;
		bool allergies;
};

int main() {
	int a1, a2;
	Patient p1;
	p1.setName("ZhangLi");
	p1.setSex('f');
	cin>>a1;
	p1.setAge(a1);
	p1.setWeight(154.72);
	p1.setAllergies(true); 
	cout<<"Name:"<<p1.getName()<<endl;
	cout<<"Sex:"<<p1.getSex()<<endl;
	cout<<"Age:"<<p1.getAge()<<endl;
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<"Weight:"<<p1.getWeight()<<endl;
	cout<<"Allergies:";
	if(p1.getAllergies()) cout<<"true";
	else cout<<"false";
	cout<<endl;
	cin>>a2;
	Patient p2("Liu Wu", 'm', a2, 135, false);
	Patient p3("Zhang san", 'f', 45, 157.567, true);

	p2.printInfo();
	p3.printInfo();
	return 0;
}
