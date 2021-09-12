#include <iostream>
using namespace std;
#include "circle.h"


void Circle::read()
{
	cin >> radius_ ;
}
void Circle::disp() const
{
	cout << "radius : " << radius_  << "\n";
}

double Circle::area() const
{
	return 3.14 * radius_ * radius_;
}
double Circle::peri() const
{
	return 2 * 3.14 * radius_;
}
