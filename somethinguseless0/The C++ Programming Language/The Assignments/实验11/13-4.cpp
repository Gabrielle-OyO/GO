// 13-4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class A
{
protected:
	int a;
public:
	A(int i)
	{
		a = i;
		cout << "Constructor called.A\n";
	}
	~A()
	{
		cout << "Destructor called.A\n";
	}
	void print()
	{
		cout << a << ",";
	}
	int geta()
	{
		return a;
	}
};

class B :public A
{
private:
	int b;
	A aa;
public:
	B(int i, int j, int k) : A(i), aa(j)
    {
	    b = k;
	    cout << "Constructor called.B\n";
    }
	~B() { cout << "Destructor called.B\n"; }
	void print()
	{
		A::print();
		cout << b << "," << aa.geta() << endl;
	}
};

void main()
{
	B bb1(3, 4, 5);
	bb1.print();
    
}

