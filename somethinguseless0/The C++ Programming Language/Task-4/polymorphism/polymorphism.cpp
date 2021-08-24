//虚函数的应用-2
#include<iostream>
using namespace std;
class A
{
public:
	virtual void show() { cout << "class A show() is called." << endl; }
 };

void display(A*);
class B :public A
{
public:
	void show() { cout << "class B show() is called." << endl; }
};
void display(A* obj) { obj->show(); }

void main()
{
	A demo1;
	B demo2;
	display(&demo1);
	display(&demo2);
}