#include "ex2-2-2.cpp"
int main()
{
	int a, b, c, x, y;
	cout << "请输入三角形三条边" << endl;
	cin >> a >> b >> c;
	triangle A(a, b, c);
	cout << "周长为：" << A.circumference(a, b, c) << "，面积为：" << A.square(a, b, c) << endl;
	cout << "请输入菱形的两条对角线：" << endl;
	cin >> x >> y;
	diamond B(x, y);
	cout << "周长为：" << B.circumference(x, y) << "，面积为：" << B.square(x, y) << endl;
}

