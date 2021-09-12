#include <iostream>
using namespace std;
#include "mystr.h"
#include <cstring>

// RC
RC::RC(const char* s)
: s_(new char[strlen(s) + 1]), count_(1)
{
	strcpy(s_, s);
}

RC::~RC()
{
	delete [] s_;
}

void RC::disp() const
{
	cout << s_ << ":" << count_ << "\n";
}
// MyStr
MyStr::MyStr(const char* s)
: ptr_rc_(new RC(s))
{
}


MyStr::MyStr(const MyStr& rhs)
: ptr_rc_(rhs.ptr_rc_)
{
	++ptr_rc_->count_;
}


#if 0
char& MyStr::operator[](int i)
{
	return ptr_rc_->s_[i];
}
#endif

MyStr& MyStr::operator=(const MyStr& rhs)
{
	// self assignment
	if(ptr_rc_ != rhs.ptr_rc_)
	{
		// decrement count on lhs
		if(--ptr_rc_->count_ == 0)
			delete ptr_rc_;
		// change the pointer on lhs
		ptr_rc_ = rhs.ptr_rc_;
		// increment the count
		++ptr_rc_->count_;
	}
	return *this;
	
}


MyStr::~MyStr()
{
	if(--ptr_rc_->count_ == 0)
		delete ptr_rc_;
}

void MyStr::disp() const
{
	ptr_rc_->disp();
}




