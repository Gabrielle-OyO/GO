#include<iostream>
using namespace std;

class Date
{
private:
	int x;
	void show(int a)
	{
		int b;
		if (a >= 16)
			show(a / 16);
		b = a % 16;
		if (b <= 9)
			cout << b;
		else if (b == 10)
			cout << 'a';
		else if (b == 11)
			cout << 'b';
		else if (b == 12)
			cout << 'c';
		else if (b == 13)
			cout << 'd';
		else if (b == 14)
			cout << 'e';
		else
			cout << 'f';
	}
public:
	Date(int xx) { x = xx; }
	void print()
	{
		int a = x;
		show(a);
	}
};

int main()
{
	int x;
	cin >> x;
	Date A(x);
	A.print();
	return 0;
}