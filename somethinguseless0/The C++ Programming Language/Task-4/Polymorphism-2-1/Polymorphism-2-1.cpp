
//通过对象调用类成员函数实现静态多态性

#include<iostream>
using namespace std;
class point
{
private:
	double x, y;
public:
	point(double i, double j) { x = i;y = j; }
	virtual double area() { return 0.0; }			//在基类area函数前说明是虚函数才能得出结果
};
const double pi = 3.14159;

class circle :public point
{
private:
	double radius;
public:
	circle(double x, double y, double r) :point(x, y)
	{
		radius = r;
	}
	double area() { return pi * radius * radius; }		//这才是我们要使用的函数
};
//修改main函数，在main中通过指向基类的指针调用派生类的成员函数
void main()
{
	point* p;													//point Ppoint(100, 200);
	circle Ccircle(100, 200, 3.3);								//double a = Ppoint.area();
	p = &Ccircle;												//cout << "The area of the point is " << a << endl;
	double a = p->area();										//circle Ccircle(50, 100, 3.3);
																//a = Ccircle.area();
	cout << "The area of the circle is " << a << endl;
}