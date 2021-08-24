
//派生类成员不含类对象时，构造函数和析构函数的执行顺序

#include<iostream>
using namespace std;

class Student
{
public:
	Student()
	{
		cout << "constructing student.\n";
	}
	~Student()
	{
		cout << "destucting student.\n";
	}
};

class Stu :public Student
{
public:
	Stu()
	{
		cout << "constructing Stu.\n";
	}
	~Stu()
	{
		cout << "destructing Stu.\n";
	}
};

void main()
{
	Stu tp;
}