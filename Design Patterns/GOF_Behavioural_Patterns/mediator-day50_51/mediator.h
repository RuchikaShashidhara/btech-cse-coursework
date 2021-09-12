#ifndef MEDIATOR_H
#define MEDIATOR_H
#include <string>
#include <vector>
#include <algorithm>

class IPerson;

class IChatBox // mediator; abstract class
{
	public:
	virtual ~IChatBox() { };
	virtual void attach(IPerson *);
	virtual void detach(IPerson *);
	virtual void send_one(IPerson *from, IPerson* to, const string& msg) = 0;
	virtual void send_all(IPerson *from, const string& msg) = 0;
	protected:
	vector<IPerson*> v;
	
};

class ChatBox : public IChatBox // mediator; concrete class
{
	public:
	ChatBox(const string& name);
	virtual void send_one(IPerson *from, IPerson* to, const string& msg);
	virtual void send_all(IPerson *from, const string& msg);
	private:
	string name;
};

class IPerson
{
	public:
	virtual ~IPerson() { } ;
	virtual void join(IChatBox *);
	virtual void leave(IChatBox *);
	virtual void send_one(IChatBox* ptr_cb, IPerson* to, const string& msg ) = 0;
	virtual void send_all(IChatBox* ptr_cb,  const string& msg) = 0;
	virtual void recv_one(IPerson* from, const string& msg) = 0;
};

class Person : public IPerson
{
	private:
	string name;
	public:
	Person(const string& name); 
	virtual void send_one(IChatBox* ptr_cb, IPerson* to, const string& msg );
	virtual void send_all(IChatBox* ptr_cb,  const string& msg);
	virtual void recv_one(IPerson* from, const string& msg);
	
};
#endif

