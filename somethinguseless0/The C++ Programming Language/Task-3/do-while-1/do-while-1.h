#pragma once
#include<iostream>
using namespace std;
class invdate
{
private:
	int m;
public:
	invdate(int a) { m = a; }
	void show()
	{
		while (m)
		{
			cout << m % 10;
			m /= 10;
		}
		cout << endl;
	}
};