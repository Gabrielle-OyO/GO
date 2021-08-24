#include<iostream>
using namespace std;

//一个正整数的阶乘（英语：factorial）是所有小于及等于该数的正整数的积，并且0的阶乘为1。自然数n的阶乘写作n!
int main()
{
	unsigned int n;
	unsigned long long factorial = 1;

	cout << "请输入一个整数：";
	cin >> n;

	for (int i = 1;i <= n;i++)
	{
		factorial *= i;
	}

	cout << n << "的阶乘factorial为：" << "=" << factorial;
	return 0;
}