#include <iostream>

using namespace std;
class Data{
	public:
		Data(){};
		Data(int y, int m, int d) {
			year = y;
			month = m;
			day = d;
		}
		~Data(){}
		void SetData(int y, int m, int d) {
			year = y;
			month = m;
			day = d;
		}
		int IsLeapYear() {
			return ((year%4 == 0 && year%100 != 0) || year%400 == 0);
		}
		void Print() {
			cout<<year<<"/"<<month<<"/"<<day<<endl;
		}
	private:
		int year, month, day;
};

int main(int argc, char *argv[]) {
	Data d1, d2, *pd = &d2;
	d1.SetData(2017, 11, 7);
	pd->SetData(2017, 11, 8);
	cout<<d1.IsLeapYear()<<","<<d2.IsLeapYear()<<endl;
	d1.Print();
	d2.Print();
	return 0;
}