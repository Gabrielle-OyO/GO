#include <iostream>
#include <iomanip>
using namespace std;

class inv
{
private:
	char a[10];

public:
	inv(char x[]);
	void inve();
	void print();
};

inv::inv(char x[])
{
	for (int i = 0; i < 10; i++)
		a[i] = x[i];
}

void inv::inve()
{
	char temp;
	for (int i = 0; i < 5; i++)
	{
		temp = a[i];
		a[i] = a[9 - i];
		a[9 - i] = temp;
	}
}

void inv::print()
{
	for (int i = 0; i < 10; i++)
		cout << setw(5) << a[i];
	cout << endl;
}

int main()
{
	char x[10];
	for (int i = 0; i < 10; i++)
		cin >> x[i];
	inv A(x);
	A.print();
	A.inve();
	A.print();
	return 0;
}