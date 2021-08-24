#include<iostream>
using namespace std;

class Date
{
private:
	int year, month, day;
public:
	Date(int year1=2014, int month1=12, int day1=10)
	{
		year = year1;
		month = month1;
		day = day1;
		cout << year << "年" << month << "月" << day << "日" << endl;
	}
};

int main()
{
	int year2, month2, day2;
	cout << "请输入年月日：" << endl;
	cin >> year2 >> month2 >> day2;
	Date date1;
	Date date2(2013);
	Date date3(2012, 8);
	Date date4(2013, 10, 8);
	Date date5(year2, month2, day2);

	return 0;
}