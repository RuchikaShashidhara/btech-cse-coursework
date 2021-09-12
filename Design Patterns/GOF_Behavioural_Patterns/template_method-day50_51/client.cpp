#include <iostream>
using namespace std;

// some job:
//	#include <iostream>
using namespace std;
// template method pattern
// some job:
//	has # of steps
//	these steps have to be executed in a particular order
//	order cannot be changed
//	
//	how to change one or more steps without affecting the order?

// example:
//	pre-prcess
//	compile
//	link

// call to virtual functions in non virtual fn is polymorphic 
class Process
{
	private:
	virtual void step1() { cout << "step1\n"; }
	virtual void step2() { cout << "step2\n"; }
	virtual void step3() { cout << "step3\n"; }
	public:
	~Process() { }
	void do_all() {
		step1();
		step2();
		step3();
	}
};
class NewProcess : public Process
{
	private:
	void step1() { cout << "step1\n"; }
	void step2() { cout << "new step2\n"; }
	void step3() { cout << "step3\n"; }
};
int main()
{
	Process p1;
	p1.do_all();
//	p1.step2();

	NewProcess p2;
	p2.do_all();
	
}


has # of steps
//	these steps have to be executed in a particular order
//	order cannot be changed
//	
//	how to change one or more steps without affecting the order?

// example:
//	pre-prcess
//	compile
//	link

// call to virtual functions in non virtual fn is polymorphic 
class Process
{
	private:
	virtual void step1() { cout << "step1\n"; }
	virtual void step2() { cout << "step2\n"; }
	virtual void step3() { cout << "step3\n"; }
	public:
	~Process() { }
	void do_all() {
		step1();
		step2();
		step3();
	}
};
class NewProcess : public Process
{
	private:
	void step1() { cout << "step1\n"; }
	void step2() { cout << "new step2\n"; }
	void step3() { cout << "step3\n"; }
};
int main()
{
	Process p1;
	p1.do_all();
//	p1.step2();

	NewProcess p2;
	p2.do_all();
	
}



