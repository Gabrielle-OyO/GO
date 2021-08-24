

//派生类不含对象成员时构造函数的参数传递情况

#include<iostream>
using namespace std;

class Student
{
private:
	int x;
public:
	Student(int n)			//基类构造函数
	{
		cout << "constructing student.\n";
		x = n;
	}
	~Student()				//基类析构函数
	{
		cout << "destructing student.\n";
	}
	void showx() { cout << x << endl; }
};

class Stu :public Student
{
private:
	int y;
public:
	Stu(int n, int m) :Student(m)		//定义派生类构造函数时，传递一个参数给基类构造函数
	{
		cout << "constructing Stu.\n";
		y = n;
	}
	~Stu()								//派生类析构函数
	{
		cout << "destructing Stu.\n";
	}
	void showy() { cout << y << endl; }
};

void main()
{
	Stu tp(10, 20);
	tp.showx();
	tp.showy();
}