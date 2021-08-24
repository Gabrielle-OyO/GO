#include "2-2.h"
int main()
{
	int a, b;
	cin >> a >> b;
	
	int c1 = f1(a, b);
	cout << a << '+' << b << '=' << c1 << endl;
	
	int c2 = f2(a, b);
	cout << a << '-' << b << '=' << c2 << endl;
	
	int c3 = f3(a, b);
	cout << a << '*' << b << '=' << c3 << endl;
	
	int c4 = f4(a, b);
	cout << a << '/' << b << '=' << c4 << endl;
}