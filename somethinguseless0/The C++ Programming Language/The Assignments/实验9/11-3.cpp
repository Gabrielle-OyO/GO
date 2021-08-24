#include<iostream>
#include<math.h>
using namespace std;

class Point
{
public:
	Point(double xx, double yy) { x = xx; y = yy; }
	void Getxy();
	friend double Distance(Point &a, Point &b);

private:
	double x, y;
};

//打印
void Point::Getxy()
{
	cout << "(" << x << "," << y << ")" << endl;
}

//计算距离
double Distance(Point &a, Point &b)
{
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

int main()
{
	Point p1(3.0, 4.0), p2(6.0, 8.0);
	//读值
	p1.Getxy();
	p2.Getxy();
	//计算
	double d = Distance(p1, p2);
	cout << "Distance is " << d << endl;
	return 0;
}