//虚函数的应用
#include<iostream>
using namespace std;

class A			//基类
{
public:
	virtual void show() { cout << "class A show() is called." << endl; }
	//show（）事虚函数，说明派生类中国可以定义同名函数，实现不同的功能；
};

class B :public A		//派生类
{
public:
	void shouw() { cout << "class B show() is called." << endl; }
};

void main()
{
	A demo1, * ptr;
	B demo2;
	ptr = &demo1;
	ptr->show();
	ptr = &demo2;
	ptr->show();			//基类指针指向派生类对象，利用基类指针调用虚函数
}