#include<iostream>
#include<string>
using namespace std;

class inve
{
private:
	char a[10];
public:
	inve(char x[]);
	void inv();
	void inv(int n);
	void print();
};
inve::inve(char x[])
{
	for (int i = 0;i < 10;i++)
	{
		a[i] = x[i];
	}
}
void inve::print()
{
	for (int i = 0;i < 10;i++)
		cout << a[i] << " ";
	cout << endl;
}
void inve::inv()
{
	int temp = 0;
	int n;
	n = 10;
	for (int i = 0; i < n / 2; ++i) {
		temp = a[n - i - 1];
		a[n - i - 1] = a[i];
		a[i] = temp;
	}
}
void inve::inv(int n)
{
	int temp = 0;
	for (int i = 0; i < n / 2; ++i) {
		temp = a[n - i - 1];
		a[n - i - 1] = a[i];
		a[i] = temp;
	}
}

int main()
{
	char x[10];
	for (int i = 0;i < 10;i++)
		cin >> x[i];
	inve A(x);
	A.print();
	A.inv();
	A.print();
	int n;
	cin >> n;
	A.inv(n);
	A.print();
	return 0;
}