#include<iostream>
using namespace std;

class math
{
private:
	int x, y;
	char ch;
public:
	math(int a, char c, int b) { x = a;y = b;ch = c; }
	void calculate()
	{
		switch (ch)
		{
		case'+':cout << x << ' ' << ch << ' ' << y << '=' << x + y << endl;break;
		case'-':cout << x << ' ' << ch << ' ' << y << '=' << x - y << endl;break;
		case'*':cout << x << ' ' << ch << ' ' << y << '=' << x * y << endl;break;
		case'/':cout << x << ' ' << ch << ' ' << y << '=' << x / y << endl;break;
		case'%':cout << x << ' ' << ch << ' ' << y << '=' << x % y << endl;break;
		}
	}
};

int main()
{
	int x1, y1;
	char ch1;
	cout << "请输入要计算的式子：" << endl;
	cin >> x1 >> ch1 >> y1;
	if (ch1 == '/' && y1 == 0)
		cout << "除数不能为0！" << endl;
	else
	{
		math a(x1, ch1, y1);
		a.calculate();
	}
	return 0;
}