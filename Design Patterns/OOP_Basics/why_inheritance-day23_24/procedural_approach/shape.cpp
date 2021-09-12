#include <iostream>
using namespace std;
#include "shape.h"


void Shape::read()
{
	cin >> st_;
	if(st_ == 'r')
	{
		su_.r_.read();
	}
	else if(st_ == 'c')
	{
		su_.c_.read();
	}
	else
	{
		cout << "wrong shape\n";
	}
}
void Shape::disp() const
{
	if(st_ == 'r')
	{
		su_.r_.disp();
	}
	else if(st_ == 'c')
	{
		su_.c_.disp();
	}
	else
	{
		cout << "wrong shape\n";
	}	
}

double Shape::area() const
{
	if(st_ == 'r')
	{
		return su_.r_.area();
	}
	else if(st_ == 'c')
	{
		return su_.c_.area();
	}
	else
	{
		cout << "wrong shape\n";
		return 0.0;
	}	
}
double Shape::peri() const
{
	if(st_ == 'r')
	{
		return su_.r_.peri();
	}
	else if(st_ == 'c')
	{
		return su_.c_.peri();
	}
	else
	{
		cout << "wrong shape\n";
		return 0.0;
	}	
}
