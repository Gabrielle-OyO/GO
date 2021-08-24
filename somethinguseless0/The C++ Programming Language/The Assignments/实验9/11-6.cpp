#include<iostream>
using namespace std;

class Date
{
private:
	int y, m, d;
public:
	Date(int yy,int mm,int dd)
	{
		y = yy;
		m = mm;
		d = dd;
	}
	void show()
	{
		cout << "出生年月日：" << y << "-" << m << "-" << d << endl;
	}
};

//容器类
class Person
{
private:
	char Name[8];
	Date date;	//contain
	char Sex[4];

public:
	Person(char *n1, int y1, int m1, int d1, char *n2);
	void print();
};

Person::Person(char *n1, int y1, int m1, int d1, char *n2):date(y1,m1,d1)
{
	strcpy_s(Name, n1);
	strcpy_s(Sex, n2);
}

void Person::print()
{
	cout << Name << endl;
	cout << "性别为：" << Sex<<endl;
	date.show();	//通过Date对象调用自己的成员函数
}

int main()
{
	Person p1("曾瑶瑶", 2020, 11，30, "女");
	Date d(2021, 1, 1);
	p1.print();
	d.show();
	return 0;
}