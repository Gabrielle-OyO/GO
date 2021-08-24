// 12-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include<string.h>

class time
{
public:
	time(int h, int m, int s)
	{
		hours = h;
		minutes = m;
		seconds = s;
	}
	virtual void display()
	{
		cout << hours << ":" << minutes << ":" << seconds << endl;
	}
protected:
	int hours, minutes, seconds;
};

class date
{
public:
	date(int m, int d, int y)
	{
		month = m;
		day = d;
		year = y;
	}
	virtual void display()
	{
		cout << month << "/" << day << "/" << year;
	}
protected:
	int month, day, year;
};

class birthtime :public time, public date
{
public:
	birthtime(char *cn, int mm, int dd, int yy, int hh, int mint,int ss) :time(hh, mint, ss), date(mm, dd, yy)
	{
		strcpy(childname, cn);
	}
	void display()
	{
		cout << childname << ' ';
		date::display();
		cout << endl;
		time::display();
	}
protected:
	char childname[30];
};


void main()
{
	birthtime yx("Liujiahai", 10, 27, 1996, 13, 20, 0);
	yx.display();
}

