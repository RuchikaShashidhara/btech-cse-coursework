#include <iostream>
using namespace std;
#include <string>

#include "mediator.h"

// mediator : chatbox
void IChatBox::attach(IPerson *p)
{
	v.push_back(p);
}

void IChatBox::detach(IPerson *p)
{
	erase(v, p); // C++ 20 feature
}



ChatBox::ChatBox(const string& name) : name(name) { }
void ChatBox::send_one(IPerson *from, IPerson* to, const string& msg)
{
	// no checking whether to is attached
	to->recv_one(from, msg);
}

void ChatBox::send_all(IPerson *from, const string& msg)
{
	for(auto p : v)
	{
		if(p != from)
		{
			p->recv_one(from, msg);
		}
	}
}



// person : colleague
void IPerson::join(IChatBox *cb)
{
	cb->attach(this);
}

void IPerson::leave(IChatBox *cb)
{
	cb->detach(this);
}

Person::Person(const string& name) : name(name) { }

void  Person::send_one(IChatBox* ptr_cb, IPerson* to, const string& msg ) 
{
	ptr_cb->send_one(this, to, msg);
}

void Person::send_all(IChatBox* ptr_cb,  const string& msg)
{
	ptr_cb->send_all(this, msg);
}

void Person::recv_one(IPerson* from, const string& msg)
{
	cout << "from : " << dynamic_cast<Person*>(from)->name << 
		" to : " << dynamic_cast<Person*>(this)->name << " msg " << msg << "\n";
}



