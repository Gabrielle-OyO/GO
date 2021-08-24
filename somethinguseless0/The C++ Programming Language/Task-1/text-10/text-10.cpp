#include<iostream>
using namespace std;
//实现一个简单的计算器   进行基本数学运算加减乘除

int main()
{
	char op;
	float num1, num2;

	cout << "输入运算符：+、-、*、/：";
	cin >> op;

	cout << "输入两个数：num1,num2:";
	cin >> num1 >> num2;

	switch (op)
	{
	case '+':
		cout << num1 + num2;
		break;

	case '-':
		cout << num1 - num2;
		break;

	case'*':
		cout << num1 * num2;
		break;


	case'/':
		cout << num1 / num2;
		break;

	default:
		cout << "Error!请输入正确的运算符";
	}
	return 0;
}