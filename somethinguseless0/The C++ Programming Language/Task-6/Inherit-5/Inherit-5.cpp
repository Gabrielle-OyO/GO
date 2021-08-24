
//派生类构造函数、析构函数与基类构造函数、析构函数的调用关系

#include<iostream>
using namespace std;

class B
{
public:
	B()
	{
		b = 0;
		cout << "B's constructor called.\n" << endl;
	}
	B(int i)
	{
		b = i;
		cout << "B's constructor called.\n" << endl;
	}
	~B()
	{
		cout << "B's destructor called.\n" << endl;
	}
	void Print()
	{
		cout << b << endl;
	}
private:
	int b;
};

class C :public B
{
public:
	C()
	{
		c = 0;
		cout << "C's default constructor called." << endl;
	}
	C(int i, int j) :B(i)		//此处不能略去：B(i);
	{
		c = j;
		cout << "C's constructor called." << endl;
	}
	~C()
	{
		cout << c << ' ';
		cout << "C's destructor called." << endl;
	}
	void Print()
	{
		B::Print();
		cout << c << endl;
	}
private:
	int c;
};

int main()
{
	C obj1;
	C obj2(5, 6);
	obj1.Print();
	obj2.Print();
}