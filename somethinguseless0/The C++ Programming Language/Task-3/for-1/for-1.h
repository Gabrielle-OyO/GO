#pragma once
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
		int sum = 0;int i;
		for (int i = a;i <= b;i++)
			sum += i;
		cout << sum << endl;
	}
};