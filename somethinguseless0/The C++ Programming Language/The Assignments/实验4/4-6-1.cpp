#include<iostream>
using namespace std;

int fun(int a, int b, int c)
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
	int a, b, c;
	cout << "请输入三角形的三条边：" << endl;
	cin >> a >> b >> c;
	fun(a, b, c);
	return 0;
}