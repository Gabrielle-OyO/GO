//派生类中不含对象成员时构造函数的格式

#include<iostream>
using namespace std;

class Parent
{
protected:
	int age;
public:
	Parent(int a) { age = a; }
	void display() { cout << "age=" << age << endl; }
};

class Son :private Parent			//派生类
{
public:
	Son(int a,int sy):Parent(a)		//派生类中构造函数的定义
	{
		studyyear = sy;
	}
	void increase() { age++; }
	void display()
	{
		cout << "studyyear=" << studyyear << endl;
	}
private:
	int studyyear;
};

void main()
{
	Son s(20, 12);
	s.increase();
	s.display();
}
