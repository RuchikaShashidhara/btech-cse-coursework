#include <iostream>
using namespace std;
#include <string>
#include "mediator.h"

int main()
{
	Person a("amar");
	Person b("bharath");
	Person c("chetan");
	Person d("deepa");
	
	ChatBox cb("our room");
	
	a.join(&cb);
	b.join(&cb);
	c.join(&cb);
	d.join(&cb);
	
	a.send_one(&cb, &b, "message 1");
	c.send_one(&cb, &d, "message 2");
	
	a.send_all(&cb, "message all");
	
}
