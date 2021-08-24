#include<iostream>
using namespace std;
double f1(double x) { return x; }

double f2(double x) { return 2*x-5; }
double f3(double x) { return 3*x+4; }
int main()
{
	
	double(*f)(double);
	double x;
	cin >> x;
	if (x < 0) {
		f = f1;
	}
	else if (x <= 0 && x < 5) {
		f = f2;
	}
	else {
		f = f3;
	}
	cout << "½á¹ûÊÇ£º" << (*f)(x);
	return 0;
}