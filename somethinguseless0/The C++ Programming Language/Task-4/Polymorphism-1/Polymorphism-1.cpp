//通过函数重载实现静态多态性
#include<iostream>
using namespace std;
class squared
{
public:
	int squ(int);
	double squ(double);
};
int squared::squ(int x)
{
	return x * x;
}
double squared::squ(double y)
{
	return y * y;
}
int main()
{
	squared area;
	cout << "The square of 2 is " << area.squ(2) << endl;
	cout << "The square of 2.2 is " << area.squ(2.2) << endl;
	return 0;
}