#include <iostream>
using namespace std;

// File object
class Receiver
{
	public:
	void read() { cout << "reading ..,\n"; }
	void write() { cout << "writing ... \n"; }
	
};

// abstract class
class Command
{
	public:
	virtual ~Command() { }
	virtual void execute() = 0;
};

// concrete command
class ReadCommand : public Command
{
	private:
	Receiver &r;
	public:
	ReadCommand(Receiver& r) : r(r) { }
	virtual void execute() { r.read(); } 
};

class WriteCommand : public Command
{
	private:
	Receiver &r;
	public:
	WriteCommand(Receiver& r) : r(r) { }
	virtual void execute() { r.write(); } 
};

class Invoker
{
	private:
	Command& c;
	public:
	Invoker(Command& c) : c(c) { }
	void execute() { c.execute(); }
};

int main()
{
	Receiver r;
	ReadCommand rc(r);
	WriteCommand wc(r);
	Invoker i1(rc);
	i1.execute();
	
	Invoker i2(wc);
	i2.execute();
}




