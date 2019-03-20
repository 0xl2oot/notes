#include <iostream>

using namespace std;

class Clock{
	public:
		Clock();
		Clock(int NewH, int NewM, int NewS);
		~Clock();
		void SetTime(int NewH, int NewM, int NewS);
		void ShowTime();
	private:
		int Hour, Minute, Second;	
};

Clock::Clock() {
	cout<<"Constructor called without parameter."<<endl;
}

Clock::Clock(int NewH, int NewM, int NewS) {
	Hour = NewH;
	Minute = NewM;
	Second = NewS;
	cout<<"Constructor called with parameter."<<endl;
}

Clock::~Clock() {
	cout<<"Desturctor called."<<endl;
}

void Clock::SetTime(int NewH, int NewM, int NewS) {
	Hour = NewH;
	Minute = NewM;
	Second = NewS;
}

void Clock::ShowTime() {
	cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}

int main(int argc, char *argv[]) {
	Clock myClock;
	myClock.SetTime(8, 0, 0);
	myClock.ShowTime();
	Clock c(0, 0, 0);
	c.ShowTime();
	return 0;
}