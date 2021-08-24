
//多继承中派生类的构造函数的定义规则

#include<iostream>
using namespace std;

class Teacher
{
private:
	int x;
public:
	Teacher()
	{
		x = 0;
	}
	Teacher(int s)
	{
		x = s;
		cout << "Theacher!" << endl;
	}
	~Teacher()
	{
		cout << "~Teacher!" << endl;
	}
	int s;
};

class Student
{
private:
	int y;
public:
	Student()
	{
		y = 0;
	}
	Student(int s)			//带参数的构造函数
	{
		y = s;
		cout << "Student!" << endl;
	}
	~Student()
	{
		cout << "~Student!" << endl;
	}
};

class Teach_Assistant :public Teacher, public Student
{
private:
	int z;
public:
	Teach_Assistant() :Teacher(), Student()
	{
		z = 0;
	}
	Teach_Assistant(int s, int a, int b) :Teacher(s), Student(a)
	{
		z = b;
		cout << "Teach_Assistant!" << endl;
	}
	~Teach_Assistant()
	{
		cout << "~Teach_Assistant!" << endl;
	}
};

int main()
{
	Teach_Assistant AA(3, 4, 5);
}