#include<iostream>
using namespace std;
class complex
{
private:
	double real;
	double image;
public:
	complex(double x,double y)
	{
		real = x;
		image = y;
	}
	complex(void) { real = 0; image = 0; }
	friend complex operator + (const complex &x, const complex &y);
	friend complex operator - (const complex &x, const complex& y);
	friend complex operator * (const complex &x, const complex& y);
	friend complex operator / (const complex &x, const complex& y);
	friend complex operator - (double x, const complex& y);
	friend complex operator * (double x, const complex& y);
	void prient()
	{
		cout << real << "," << image << 'i' << endl;
	}
};
complex operator+(const complex& x, const complex& y)
{
	return complex(x.real + y.real, x.image + y.image);
}
complex operator-(const complex& x, const complex& y)
{
	return complex(x.real - y.real, x.image - y.image);
}
complex operator*(const complex& x, const complex& y)
{
	return complex(x.real * y.real, x.image * y.image);
}
complex operator/(const complex& x, const complex& y)
{
	return complex(x.real /y.real, x.image / y.image);
}
complex operator-(double x, const complex& y)
{
	return complex(x - y.real,  0-y.image);
}
complex operator*(double x, const complex& y)
{
	return complex(x* y.real,  x*y.image);
}
int main()
{
	complex a(11.1, 22.2), b(33.3, 44.4),c;
	const complex d(0.1, 0.2);
	c = a + b;
	c.prient();
	c = 5-a;
	c.prient();
	c = a / b + d;
	c.prient();
	c = 5 * a;
	c.prient();
	c = a * b;
	c.prient();

}