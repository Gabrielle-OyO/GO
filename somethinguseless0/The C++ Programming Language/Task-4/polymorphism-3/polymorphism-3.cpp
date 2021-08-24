//虚函数实现多态性
#include<iostream>
using namespace std;

class point			//基类
{
private:
	double x, y;
public:
	point(double i, double j) { x = i;y = j; }
	virtual double area() { return 0.0; }			//虚函数
};
const double pi = 3.14159;

class circle :public point			//派生类
{
private:
	double radius;
public:
	circle(double x,double y,double r):point(x,y)
	{radius = r;}
	double area() { return pi * radius * radius; }
};

void main()
{
	point* p;
	circle Ccircle(100, 200, 3.3);
	p = &Ccircle;
	double a = p->area();				//基类、派生类同名函数
	cout << "The area of circle is " << a << endl;
}