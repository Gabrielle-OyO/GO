#pragma once
//������Ȼ��a��b֮ż����
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
		if (i % 2 == 1)      //����һ��
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