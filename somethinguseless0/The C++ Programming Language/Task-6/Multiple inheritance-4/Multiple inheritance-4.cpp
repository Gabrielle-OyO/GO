
//程序中多继承派生类构造函数的执行顺序

#include<iostream>
using namespace std;

class A1
{
public:
	A1(int i)
	{
		a1 = i;
		cout << "Constructor A1." << a1 << endl;
	}
	void Print()
	{
		cout << a1 << endl;
	}
private:
	int a1;
};

class A2
{
public:
	A2(int j)
	{
		a2 = j;
		cout << "Constructor A2." << a2 << endl;
	}
	void Print()
	{
		cout << a2 << endl;
	}
private:
	int a2;
};

class A3
{
public:
	A3(int k)
	{
		a3 = k;
		cout << "Constructor A3." << a3 << endl;
	}
	int Geta3() { return a3; }
private:
	int a3;
};

class D :public A1, public A2
{
public:
	D(int i, int j, int k, int l) :A1(i), A2(j), a3(k)
	{
		d = l;
		cout << "Constructor D." << d << endl;
	}
	void Print()
	{
		A1::Print();
		A2::Print();
		cout << d << "," << a3.Geta3() << endl;
	}
private:
	int d;
	A3 a3;
};

int main()
{
	D dd(6, 7, 8, 9);
	dd.Print();
	A2 a2(4);
	a2 = dd;
	a2.Print();
	A1 a1(2);
	a1 = dd;
	a1.Print();
}