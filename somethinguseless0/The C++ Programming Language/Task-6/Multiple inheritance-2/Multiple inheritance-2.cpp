
//Time类和Date类
//设计一个Birthtime类，继承Time类和Date类，添加Childname
//设计一个主程序显示孩子的出生时间和名字

#include<iostream>
using namespace std;
#include<string.h>

class Time
{
public:
	Time(int h, int m, int s)
	{
		hours = h;
		minutes = m;
		seconds = s;
	}
	void display()
	{
		cout << hours << ":" << minutes << ":" << seconds << endl;
	}
protected:
	int hours, minutes, seconds;
};

class Date
{
public:
	Date(int m, int d, int y)
	{
		month = m;
		day = d;
		year = y;
	}
	void display()
	{
		cout << month << "/" << day << "/" << year;
	}
protected:
	int month, day, year;
};

class Birthtime :public Time, public Date
{
public:
	Birthtime(const char* Cn, int mm, int dd, int yy, int hh, int mint, int ss) :Time(hh, mint, ss), Date(mm, dd, yy)
	{
		strcpy_s(Childname, Cn);
	}
	void display()
	{
		cout << Childname << ' ';
		Date::display();
		cout << endl;
		Time::display();
	}
protected:
	char Childname[30];
};

int main()
{
	Birthtime yx("yuanxiang", 10, 27, 1996, 13, 20, 0);
	yx.display();
}