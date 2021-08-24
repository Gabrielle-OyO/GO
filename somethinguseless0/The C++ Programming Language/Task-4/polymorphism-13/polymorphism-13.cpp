#include<iostream>
using namespace std;

class point
{
private:
	double x, y;
public:
	point(double i, double j) { x = i; y = j; }
	virtual double area() { return 0.0; }
};
const double pi = 3.12159;

class circle :public point
{
private:
	double radius;
public:
	circle(double x, double y, double r) :point(x, y) { radius = r; }
	double area() { return pi * radius * radius; }
};

int main()
{
	point* p;
	circle Ccircle(100, 200, 3.3);
	p = &Ccircle;
	double a = p->area();
	cout << "The area of circle is " << a << endl;
}