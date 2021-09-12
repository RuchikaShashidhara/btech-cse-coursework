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
	int find_area() const;
	void change_length(int length);
	void change_breadth(int breadth);
};

#endif

#if 1
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
#endif

#endif

