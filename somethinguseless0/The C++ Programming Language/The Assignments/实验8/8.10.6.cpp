#include<iostream>
using namespace std;
class date
{
private:
	int year, month, day;
public:
	date(int y, int m, int d);//date(int y=2013,int m=01,int d=01)
	void print();
};
date::date(int y = 2013, int m = 01, int d = 01)//���캯��
{
	year = y;
	month = m;
	day = d;
	cout << "date constructor called" << endl;
}
void date::print()
{
	cout << "������" << year << "��" << month << "��" << day << "��" << endl;
}
int main()
{
	date A(2012, 5, 15), B(2013);
	A.print();
	B.print();
	return 0;
}