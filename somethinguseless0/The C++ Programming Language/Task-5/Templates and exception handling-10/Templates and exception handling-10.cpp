
//设有表达式：f(a,b,c)=sqrt(a+b/c)，计算f的值；
//要求排除除数为0以及小于0的异常；
//（存在两个异常，故设立两个异常处理类YC1，YC2
//YC1：c=0;    YC2：a+b/c<0;

#include<iostream>
using namespace std;
#include<math.h>
class YC1 {};
class YC2 {};

double f(double a, double b, double c)
{
	if (c == 0)
		throw YC1();
	else if (a + b / c < 0)
		throw YC2();
	else
		return sqrt(a + b / c);
}

void f1(double a, double b, double c)
{
	try
	{
		cout << "a=" << a << "," << "b=" << b << "," << "c=" << c << "," << endl;
		double s = f(a, b, c);
		cout << "结果为：" << s << endl;
	}
	catch (YC1)
	{
		cout << "除数不可以为0！" << endl;
		return;
	}
	catch (YC2)
	{
		cout << "负数不可以开根号" << endl;
		return;
	}
}

void main()
{
	double a, b, c;
	a = 5, b = -100, c = 2;
	f1(a, b, c);
	a = 23, b = 35, c = 0;
	f1(a, b, c);
	a = 43, b = 75, c = 15;
	f1(a, b, c);
}