#include<iostream>
using namespace std;
/*
判断是否为闰年的条件：
		[year%4==0 && year%100==0] or [year%400==0]
*/
int main()
{
	int year;
	cout << "请输入年份:";
	cin >> year;

	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				cout << year << "是闰年。";
			}
			else
			{
				cout << year << "不是闰年。";
			}
		}
		else
			cout << year << "是闰年。";
	}
	else
	{
		cout << year << "不是闰年。";
	}
	return 0;
}