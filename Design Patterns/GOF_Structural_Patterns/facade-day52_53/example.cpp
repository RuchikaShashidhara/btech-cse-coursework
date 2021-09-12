#include <iostream>
using namespace std;

class TV
{
	public:
	void on() { cout << "TV on\n"; }
	void off() { cout << "TV off\n"; }
};

class AC
{
	public:
	void on() { cout << "AC on\n"; }
	void off() { cout << "AC off\n"; }
};

class Alarm
{
	public:
	void on() { cout << "Alarm on\n"; }
	void off() { cout << "Alarm off\n"; }
};

// go out : TV off AC off Alarm on
// come back : TV on AC on Alarm off
class Facade
{
	private:
	TV &tv;
	AC &ac;
	Alarm &alarm;
	
	public:
	Facade(TV& tv, AC& ac, Alarm& alarm) : tv(tv), ac(ac), alarm(alarm)  {}
	void go_out() { tv.off(); ac.off(); alarm.on(); } 
	void come_back() { tv.on(); ac.on(); alarm.off(); }

};

int main()
{
	TV tv; AC ac; Alarm alarm;
	Facade main_control(tv, ac, alarm);
	main_control.go_out();
	main_control.come_back();
}



