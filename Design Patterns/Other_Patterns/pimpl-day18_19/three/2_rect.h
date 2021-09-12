#ifndef RECT_H
#define RECT_H

#if 1


class Rect
{
	private:
	int length_;
	int breadth_;
	mutable int area_; // implementation field
	mutable bool is_changed_;
	public:
	Rect(int length, int breadth);
	// 
	int find_area() const;
	void change_length(int length);
	void change_breadth(int breadth);
};
#endif

#endif

