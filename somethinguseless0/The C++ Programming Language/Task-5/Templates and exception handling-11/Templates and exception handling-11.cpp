
//编写函数f(double x,double y,double z),求表达式：sqrt(x-y)+sqrt(y/z);
//要求排除除数为0以及小于0的异常；

//（存在两个异常，故设立两个异常处理类YC1，YC2
//YC1：x-y<0;    YC2：y*z<0;

#include<iostream>
using namespace std;
#include<math.h>
class YC1 {};
class YC2 {};

double f(double x, double y, double z)
{
	if (x<y)
		throw YC1();
	else if (x*y < 0)
		throw YC2();
	else
		return sqrt(x - y) + sqrt(y / z);
}

void f1(double x, double y, double z)
{
	try
	{
		cout << "x=" << x << "," << "y=" << y << "," << "z=" << z << "," << endl;
		double s = f(x,y,z);
		cout << "结果为：" << s << endl;
	}
	catch (YC1)
	{
		cout << "负数不可以开根号！" << endl;
		return;
	}
	catch (YC2)
	{
		cout << "除数不可以为0!" << endl;
		return;
	}
}

void main()
{
	double x,y,z;
	x = 5, y = -100, z = 2;
	f1(x,y,z);
	x = 5, y = 100, z = -2;
	f1(x,y,z);
	x = 5, y = -100, z = 0;
	f1(x,y,z);
	x = 126, y = 45, z = 5;
	f1(x, y, z);
}