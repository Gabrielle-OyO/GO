

//使用带有析构语义的类的C++异常处理

#include<iostream>
using namespace std;

void MyFunc(void);
class Expt
{
public:
	Expt() {};
	~Expt(){};
	const char* ShowReason()const
	{
		return "Expt 类异常。";
	}
};

class Demo
{
public:
	Demo();
	~Demo();
};

Demo::Demo()
{
	cout << "构造Demo." << endl;
}
Demo::~Demo()
{
	cout << "析构Demo." << endl;
}
void MyFunc()
{
	Demo D;
	cout << "在MyFunc（）中抛掷Expt类异常。" << endl;
	throw Expt();
}

int main()
{
	cout << "在main函数中。" << endl;
	try
	{
		cout << "在try语块中，调用MyFunc（）。" << endl;
		MyFunc();
	}
	catch (Expt E)
	{
		cout << "在catch异常处理程序中。" << endl;
		cout << "捕获到Expt类异常：";
		cout << E.ShowReason() << endl;
	}
	catch (char* str)
	{
		cout << "捕获到其他异常：" << str << endl;
	}
	cout << "回到main函数。从这里恢复执行。" << endl;
	return 0;
}