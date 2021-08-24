#pragma once
#include <iostream>
using namespace std;
class shit 
{                                          //不要使用课本data作为类名
private:
	int x, y;

public:
	shit(int a, int b) { x = a; y = b; }           //变量初始化

	 void gt()
	{
		cout << x << '>' << y << '=' << (x > y) << endl;
	}

	void print()
	{
		gt();
	}
};

