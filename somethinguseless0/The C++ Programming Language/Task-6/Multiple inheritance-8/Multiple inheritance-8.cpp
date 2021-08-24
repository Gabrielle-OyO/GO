
//虚基类函数

#include<iostream>
using namespace std;

class A
{
public:
	int n;
};

class B :virtual public A {};
class C :virtual public A {};

class D :public B, public C
{
	int getn() { return B::n; }
};

int main()
{
	D d;
	d.B::n = 10;
	//d.C::n = 20;
	cout << d.B::n << "," << d.C::n << endl;
}