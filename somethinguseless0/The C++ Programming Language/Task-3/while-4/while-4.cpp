#include<iostream>
using namespace std;
#include"while-4.h"
int main()
{
	int x, y;
	cin >> x >> y;
	date A(x, y);     //什么错误？如何改正？  ///把data改成date  因为data是关键字符
	A.exec();
	return 0;
}