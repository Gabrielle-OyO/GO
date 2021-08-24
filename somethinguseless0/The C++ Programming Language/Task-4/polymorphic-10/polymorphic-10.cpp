//编写一个程序，计算正方题、球体和圆柱体的表面积和体积
/*
分析：
从正方体、球体和圆柱体的各种运算中抽象出一个‘公共基类’container为‘抽象类’，
在其中定义求表面积(surface)、体积(volume)的‘纯虚函数’。在抽象类中定义一个公共的数据成员radius，
本数据可作为正方体的边长、球体和圆柱体的半径。
由此抽象类派生出三个类‘cube’‘sphere'‘cylinder’
在这三个类中都有求表面积和体积的‘成员函数’。

*/

#include<iostream>
using namespace std;
#include<windows.h>

class container
{
protected:
	double radius;
public:
	container(double ra) { radius = ra; }
	virtual double surface_area() = 0;
	virtual double volume() = 0;
};

class cube :public container
{
public:
	cube(double ra) :container(ra) {};
	double surface_area() { return 6 * radius * radius; }
	double volume() { return radius * radius * radius; }
};

class sphere :public container
{
public:
	sphere(double ra) :container(ra) {};
	double surface_area() { return 4 * 3.14159 * radius * radius; }
	double volume() { return 3.14159 * radius * radius * radius * 4 / 3; }
};

class cylinder:public container
{
private:
	double height;
public:
	cylinder(double ra, double he) :container(ra)
	{
		height = he;
	}
	double surface_area() { return 2 * 3.14159 * radius * (height + radius); }
	double volume() { return 3.14159 * radius * radius * height; }
};

int main()
{
	container* p; 
	cube A(20);
	sphere B(15);
	cylinder C(10, 4.5);
	p = &A;
	cout << "输出结果：" << endl;
	cout << endl;
	cout << "正方体表面积：" << p->surface_area() << endl;
	cout << "正方体体积：" << p->volume() << endl;
	cout << endl;

	p = &B;
	cout << "球体表面积：" << p ->surface_area() << endl;
	cout << "球体体积：" << p->volume() << endl;
	cout << endl;

	p = &C;
	cout << "圆柱体表面积：" << p->surface_area() << endl;
	cout << "圆柱体体积：" << p->volume() << endl;
	cout << endl;

	return 0;
}