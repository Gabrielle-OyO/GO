#include<iostream>
using namespace std;
#include<math.h>
double f(double x)
{
	return x;
}

class intf
{
private:
	double left, right;
public:
	intf(double a, double b, double c) { left = a;right = b;x = c; }
	double sum();
};
double intf::sum()
{
	int n = 100, i;
	double s,y;
	double s = 0, h = (right - left) / n;
	y = (f(left + i * h) + f(right + (i + 1) * h)) * h / 2;
	for (i = 0;i < n;i++)
		s = s + y;
	return s;
}

int main()
{
	double x;
	cin >> x>>left>>right;
	intf A(x);
	cout << "\n积分值为：" << A.sum() << endl;
	return 0;
}