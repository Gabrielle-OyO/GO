#include<iostream>
using namespace std;

class math
{
private:
	double x, y;
	char ch;
public:
	math(double a, char c, double b) { x = a;y = b;ch = c; }
	void calculate()
	{
		switch (ch)
		{
			case'+':cout << x << ' ' << ch << ' ' << y << '=' << x + y << endl;break;
			case'-':cout << x << ' ' << ch << ' ' << y << '=' << x - y << endl;break;
		}
	}
};

int main()
{
	math x(23, '+', 45);
	x.calculate();
}