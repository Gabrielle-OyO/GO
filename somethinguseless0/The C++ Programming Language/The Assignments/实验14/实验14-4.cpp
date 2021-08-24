// 实验14-4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<string.h>
using namespace std;

// 基类
class Person
{
protected:
	char name[20];
public:
	// 赋值
	Person(char *n)
	{
		strcpy_s(name, strlen(n)+1, n);
	}
	// 虚函数
	virtual void show();
};

void Person::show()
{
	cout << "姓名：" << name<<endl;
}

// 学生类
class Student:public Person
{
private:
	int e1, e2, e3;	// 三门成绩
	bool flag1 = false;	// 判断三门成绩是否超过75
public:
	Student(char *n, int a, int b, int c) :Person(n)
	{
		e1 = a;
		e2 = b;
		e3 = c;
		if (e1 >= 75 && e2 >= 75 && e3 >= 75)
		{
			flag1 = true;
		}
	}
	void show();
};

void Student::show()
{
	Person::show();
	if (flag1)
	{
		cout << "是优等生" << endl;
	}
	else
	{
		cout << "不是优等生" << endl;
	}
}

// 教师类
class Teacher :public Person
{
private:
	int nums;
	bool flag2 = false;
public:
	Teacher(char *n, int num) :Person(n)
	{
		nums = num;
		if (num >= 3)
		{
			flag2 = true;
		}
	}
	void show();
};

void Teacher::show()
{
	Person::show();
	if (flag2)
	{
		cout << "合格教师"<<endl;
	}
	else
	{
		cout << "不是合格教师"<<endl;
	}
}


int main()
{
	Person *p;
	Student s1("小张", 75, 75, 75);
	Teacher t1("小红", 100);
	p = &s1;
	p->show();
	p = &t1;
	p->show();
    return 0;
}

