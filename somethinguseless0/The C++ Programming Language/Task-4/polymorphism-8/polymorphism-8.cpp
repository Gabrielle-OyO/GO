
//纯虚函数的使用
#include<iostream>
using namespace std;
class A
{
public:
	virtual void show() = 0;		//纯虚函数的重要特征;类A是一个抽象类；
									//该定义没有什么意义，仅为派生类提供统一接口
									//具体内容在下列派生类中重新定义show（）
};

class B :public A
{
public:
	virtual void show() { cout << "class B" << endl; }
};

class C :public B
{
public:
	virtual void show() { cout << "class C" << endl; }
};

void display(A* a)
{
	a->show();
}

void main()
{
	B* b = new B;
	C* c = new C;
	display(b);
	display(c);
}