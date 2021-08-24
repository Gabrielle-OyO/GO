// 实验14-7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

// 孤寡长方体类
class Rectangle
{
protected:
	double a, b, c;
public:
	Rectangle(double x, double y, double z)
	{
		a = x;
		b = y;
		c = z;
	}
	double volume() { return a*b*c; }

};

// 圆类[基类]
class Circle
{
protected:
	double radius;	// 公共数据成员，用于描述圆柱和球的半径
public:
	Circle(double ra) { radius = ra; }
	virtual double volume() = 0;
};

// 球类
class Ball :public Circle
{
public:
	Ball(double ra) :Circle(ra) {};
	double volume() { return 3.14*radius*radius*radius * 4 / 3; }
};

// 圆柱类
class Cylinder :public Circle
{
private:
	double height;
public:
	Cylinder(double ra, double he) :Circle(ra)
	{
		height = he;
	}
	double volume() { return 3.14*radius*radius*height; }
};

// 究极物体类
class Object :public Rectangle, public Ball, public Cylinder
{
private:
	double volume;
public:
	void showV()
	{
		
	}
};

int main()
{
	Circle *pA,*pB,*pC;
	Ball A(10);
	Cylinder B(10, 10);
	Rectangle C(10, 10, 10);
	pA = &A;
	pB = &B;
	
	cout << "球："<<pA->volume()<<endl;
	cout << "圆柱：" << pB->volume() << endl;
	cout << "长方体：" << C.volume() << endl;

	cout << "物体总体积：" << pA->volume() + pB->volume() + C.volume() << endl;
    return 0;
}

