#include<iostream>
#include<math.h>
using namespace std;

float f(float x)
{
	return 2 * x * x * x - 2 * x * x - 6 * x - 3;
}
int main()
{
	float left, right, middle, ym, yl, yr;
	do
	{
		cout << "请输入左、右边界：" << endl;
		cin >> left >> right;
		yl = f(left);
		yr = f(right);
	} while (yl * yr > 0);
	do
	{
		middle = (left + right) / 2;
		ym = f(middle);
		if (yr * ym > 0)
		{
			right = middle;
			yr = ym;
		}
		else
		{
			left = middle;
			yl = ym;
		}
	} while (fabs(ym) >= 1e-6);
	cout << "\n方程的根是：" << middle << endl;
}