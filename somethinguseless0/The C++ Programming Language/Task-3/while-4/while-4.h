#pragma once
//计算自然数a，b之奇数和
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
		int sum = 0;
		int i = a;
		if (i % 2 == 0)
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