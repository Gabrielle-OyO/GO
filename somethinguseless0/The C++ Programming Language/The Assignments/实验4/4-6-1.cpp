#include<iostream>
using namespace std;

int fun(int a, int b, int c)
{
	if (a + b > c && a + c > b && b + c > a)
	{
		cout << "�ܹ���һ��������" << endl;
		if (a == b && b == c)
			cout << "�ܹ���һ���ȱ�������" << endl;
		else if (a == b || b == c || a == c)
			cout << "�ܹ���һ������������" << endl;
		else if (a * a + c * c == b * b || a * a + b * b == c * c || b * b + c * c == a * a)
			cout << "������һ��ֱ��������" << endl;
		else
			cout << "�ܹ���һ��һ���������" << endl;
	}
	else
		cout << "���ܹ���һ��������" << endl;
	return 0;
}

int main()
{
	int a, b, c;
	cout << "�����������ε������ߣ�" << endl;
	cin >> a >> b >> c;
	fun(a, b, c);
	return 0;
}