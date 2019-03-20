#include <iostream>

using namespace std;
class Clock{
	public:
		Clock(int newH, int newM, int newS); //构造函数
		void setTime(int newH = 0, int newM = 0, int newS = 0);
		void showTime();
	private:
		int hour, minute, second;
};

Clock::Clock(int newH, int newM, int newS):
	hour(newH),minute(newM),second(newS){
	}
void Clock::setTime(int newH, int newM, int newS) {
	hour = newH;
	minute = newM;
	second = newS;
}
void Clock::showTime() {
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}

int main() {
	Clock myClock(0,0,0);
	myClock.showTime();
	myClock.setTime(8,30,30);
	myClock.showTime();
	return 0;	
}