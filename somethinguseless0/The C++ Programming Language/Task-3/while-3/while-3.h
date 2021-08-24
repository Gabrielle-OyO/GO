#pragma once
#include<iostream>
using namespace std;

class add
{
private:
	int n;
public:
	add(int x) { n = x; }
	int sum()
	{
		int i = 1, s = 0;
		while (i <= n)
		{
			s += i;
			i++;
		}
		return s;
	}
	void print()
	{
		cout << "1+2+3+...+" << n << "=" << sum() << endl;
	}
};