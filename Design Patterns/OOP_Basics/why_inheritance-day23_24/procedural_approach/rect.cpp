#include <iostream>
using namespace std;
#include "rect.h"


void Rect::read()
{
	cin >> length_ >> breadth_;
}
void Rect::disp() const
{
	cout << "length : " << length_ << " breadth : " << breadth_ << "\n";
}

double Rect::area() const
{
	return length_ * breadth_;
}
double Rect::peri() const
{
	return 2 * (length_ + breadth_);
}
