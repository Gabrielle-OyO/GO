#pragma once
//计算自然数a，b之偶数和
#include<iostream>
using namespace std;
class date
{
private:
	int a, b;
public:
	date(int x, int y) { a = x;b = y; }
	void exec()
	{
		int i = a;
		int sum = 0;
		if (i % 2 == 1)      //改这一行
			i++;
		while (i <= b)
		{
			cout << i << endl;
			i += 2;
			sum += i;
		}
		cout << endl;
		cout << sum;
	}
};