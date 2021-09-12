#ifndef CIRCLE_H
#define CIRCLE_H
class Circle
{
	private:
	double radius_;
	public:
	void read();
	void disp() const;
	double area() const;
	double peri() const;
};
#endif
