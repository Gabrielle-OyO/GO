#include<iostream>
using namespace std;

class Psan
{
private:
	int a, b, c;
public:
	Psan(int a1, int b1, int c1) { a = a1;b = b1;c = c1; }
	int fun();
};
int Psan::fun()
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
	int a2, b2, c2;
	cout << "�����������ε������ߣ�" << endl;
	cin >> a2 >> b2 >> c2;
	Psan A(a2, b2, c2);
	A.fun();
	return 0;
}