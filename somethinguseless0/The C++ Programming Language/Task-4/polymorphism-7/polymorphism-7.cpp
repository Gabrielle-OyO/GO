

//举例说明虚函数和成员函数重载的区别
#include<iostream>
using namespace std;

class base
{
public://*
	virtual void func1();
	virtual void func2();
	virtual void func3();
	void func4();
};

class derived :public base
{
public:
	virtual void func1();			//虚函数，这里可以不写virtual
	void func2();//*
	void func2(int x);				//加了整型变量，作为普通函数重载，虚特性消失
	void func3();//*
	//char func3();					//错误，只有返回类型相同，应删去
	void func4();					//普通函数重载，虚特性消失
};

void base::func1() { cout << "base func1\n"; }
void base::func2() { cout << "base func2\n"; }
void base::func3() { cout << "base func3\n"; }
void base::func4() { cout << "base func4\n"; }


void derived::func1() { cout << "base func1\n"; }
void derived::func2() { cout << "base func2\n"; }
void derived::func2(int x)//*
{
}
void derived::func3() { cout << "base func3\n"; }
void derived::func4() { cout << "base func4\n"; }

int main()
{
	base d1, * p;
	derived d2;
	p = &d2;
	p->func1();			//执行派生类的成员函数，因为func1()为虚函数；
	p->func2();			//执行基类的成员函数，因为func2()丢失了虚特性，按照普通重载函数处理
	p->func4();			//执行基类的成员函数，因为func4()为普通重载函数；
}
