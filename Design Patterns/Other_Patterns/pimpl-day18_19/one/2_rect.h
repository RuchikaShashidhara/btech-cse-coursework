#ifndef RECT_H
#define RECT_H
#if 0
class Rect
{
	private:
	int length_;
	int breadth_;
	public:
	Rect(int length, int breadth);
	// 
	int find_area() const;
	void change_length(int length);
	void change_breadth(int breadth);
};
//  constness
//		const constexpr
//	const :
//		constant variable
//			const int a(10);  // cannot assign 
//		constant parameter
//			parameter : pointer or ref
//			what pointer points to or what ref refers to is a constant
//		constant return
//			return obj : refers to an obj considered const or points
//				to an object considered const
//		constant member function 
//			specify const after the fn decl
//			implies that the object through which the call is made is a const
#endif

class Rect
{
	private:
	int length_;
	int breadth_;
	int area_; // implementation field
	public:
	Rect(int length, int breadth);
	// 
	int find_area() const;
	void change_length(int length);
	void change_breadth(int breadth);
};
/*
$ ./a.out
50
100
300
*** stack smashing detected ***: terminated
Aborted (core dumped)
*/



#endif

