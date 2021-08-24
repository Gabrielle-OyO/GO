#include<iostream>
#include<math.h>
using namespace std;

float f(float x)
{
	return x * x - 2 * x - 6;
}

class funroot
{
private:
	float left, right;
public:
	funroot(float a, float b) { left = a;right = b; }
	float root();
};
float funroot::root()
{
	float left, right, middle, ym, yl, yr;
	do
	{
		cout << "���������ұ߽磺" << endl;
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
	return middle;
}

int main()
{
	float left, right;
	left = right = 0;
	funroot A(left, right);
	cout << "\n���̵ĸ��ǣ�" << A.root() << endl;
	return 0;
}