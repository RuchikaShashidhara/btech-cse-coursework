#ifndef MYSTR_H
#define MYSTR_H
// Ref counting class
//	- RC class is associated with MyStr - not for the client
//	- hide a class : make all ctors private
//	
//	- we want MyStr class to create objects of RC and play with them
//	  concept : friend class :
//		used to hide a class
//		implementation class

// Ref counting class
class RC
{
	private:
		char *s_;		// pointer to char
		int count_;		// int count for # of ref
	// public:			// RC Class should not be publically accessible to all other functions exept for MyStr
		RC(const char* s);
		~RC();
		void disp() const;
		friend class MyStr;	// Making RC only accesible to MyStr
};

class MyStr
{
	private:
		RC *ptr_rc_;			// pointer to RC
	public:
		MyStr(const char* s);
		MyStr(const MyStr&);
		MyStr& operator=(const MyStr&);
		~MyStr();
		//char& operator[](int i);	// overloading disp op
		void disp() const;	
};
// MyStr a("hello"); 
// a = "universe";  
// 1. 
//	a.operator=("universe")    => a.operator=(MyStr("universe"))
// 2. overload assignment op
// MyStr& operator=(const c);
//     
#endif

