
//编写程序，功能可对表达式开根号，此表达式大于0，
//通过调用函数f1判断是否会出现异常、如何处理异常以及调用函数f，
//函数f计算表达式的开根号及抛出异常

#include<iostream>
using namespace std;

class YC {};
double f(double x, double y)
{
	if (x < y)
		throw YC();
	else
		return sqrt(x - y);
}

void f1(double x, double y)
{
	try
	{
		cout << "x=" << x << "," << "y=" << y << endl;
		double s = f(x, y);
		cout << "结果为：" << s << endl;
	}
	catch (YC)
	{
		cout << "出现异常！\n负数不可开根号！" << endl;
		return;
	}
}

void main()
{
	double x, y;
	x = 5, y = -100;
	f1(x, y);
	x = 5, y = 100;
	f1(x, y);
}