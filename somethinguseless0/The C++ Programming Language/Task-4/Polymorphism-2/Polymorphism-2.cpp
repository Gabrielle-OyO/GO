
//通过对象调用类成员函数实现静态多态性

#include<iostream>
using namespace std;
class point
{
private:
	double x, y;
public:
	point(double i, double j) { x = i;y = j; }
	double area() { return 0.0; }
};
const double pi = 3.14159;
class circle :public point
{
private:
	double radius;
public:
	circle(double x,double y,double r):point(x,y)
	{
		radius = r;
	}
	double area() { return pi * radius * radius; }
};

void main()
{
	point Ppoint(100, 200);
	double a = Ppoint.area();
	cout << "The area of the point is " << a << endl;
	circle Ccircle(50, 100, 3.3);
	a = Ccircle.area();
	cout << "The area of the circle is " << a << endl;
}