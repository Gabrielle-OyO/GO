#include<iostream>
using namespace std;

class Psan
{
private:
	int a, b, c;
public:
	Psan(int a1, int b1, int c1) { a = a1;b = b1;c = c1; }
	int fun();
};
int Psan::fun()
{
	if (a + b > c && a + c > b && b + c > a)
	{
		cout << "能构成一个三角形" << endl;
		if (a == b && b == c)
			cout << "能构成一个等边三角形" << endl;
		else if (a == b || b == c || a == c)
			cout << "能构成一个等腰三角形" << endl;
		else if (a * a + c * c == b * b || a * a + b * b == c * c || b * b + c * c == a * a)
			cout << "并且是一个直角三角形" << endl;
		else
			cout << "能构成一个一般的三角形" << endl;
	}
	else
		cout << "不能构成一个三角形" << endl;
	return 0;
}

int main()
{
	int a2, b2, c2;
	cout << "请输入三角形的三条边：" << endl;
	cin >> a2 >> b2 >> c2;
	Psan A(a2, b2, c2);
	A.fun();
	return 0;
}