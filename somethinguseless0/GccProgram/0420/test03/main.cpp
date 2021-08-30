#include <iostream>
using namespace std;

double f1(double x) { return x; }
double f2(double x) { return 2*x-5; }
double f3(double x) { return 3*x+4; }

int main()
{
    //double f1(double),double f2(double),double f3(double);
    double (*p)(double);
    int n;
    double a;
    cin >> a;
    if (a < 0)
        n = 1;
    else
    if (a>=0&&a<5)
        n = 2;
    else
        n = 3;
    switch (n)
    {
        case 1:p = f1; break;
        case 2:p = f2; break;
        case 3:p = f3; break;
    }
    cout << "result=" << (*p)(a) << endl;
    return 0;
}