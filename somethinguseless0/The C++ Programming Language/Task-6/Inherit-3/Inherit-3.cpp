//派生类中含有对象成员时构造函数的格式

#include<iostream>
using namespace std;

class A
{
protected:
	int a;
public:
	A(int i) { a = i; cout << "Constructor called.A\n"; }
	~A() { cout << "Destructor called.A\n"; }
	void Print() { cout << a << ","; }
	int Geta() { return a; }
};

class B :public A
{
private:
	int b;
	A aa;
public:
	B(int i, int j, int k) :A(i), aa(j)
	{
		b = k;
		cout << "Constructor called.B\n";
	}
	~B() { cout << "Destructor called.B\n"; }
	void Print()
	{
		A::Print();
		cout << b << "," << aa.Geta() << endl;
	}
};

int main()
{
	B bb1(3, 4, 5);
	bb1.Print();
}
