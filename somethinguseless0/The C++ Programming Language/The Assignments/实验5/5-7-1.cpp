#include<iostream>
using namespace std;

class Date
{
private:
	int x;
	void show(int a)
	{
		if (a >= 2)
			show(a / 2);
		cout << a % 2;
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