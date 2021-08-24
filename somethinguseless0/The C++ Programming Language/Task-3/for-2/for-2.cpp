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
	intf(double a, double b) { left = a;right = b; }
	//double sum;
	double sum();
};
double intf::sum()
{
	int n = 100, i;
	double s = 0, h = (right - left) / n;
	for (i = 0;i < n;i++)
		s = s + (f(left + i * h) + f(right + (i + 1) * h)) * h / 2;
	return s;
}

int main()
{
	double left, right;
	cin >> left >> right;
	intf A(left, right);
	cout << "\n积分值为：" << A.sum() << endl;
	return 0;
}