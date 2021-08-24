#include<iostream>
using namespace std;



//求两数的最大公约数    highest common factor

//求两数最小公倍数      lowest common multiple
int main()
{
	int a, b;

	cout << "输入两个数a,b：";
	cin >> a >> b;


	//求两数最小公倍数       lowest common multiple
	int max;
	max = (a > b) ? a : b;		//获取最大值
	do
	{
		if (max % a == 0 && max % b == 0)
		{
			cout << "LCM=" << max << endl;;
			break;
		}
		else
			max++;
	} while (true);



//求两数的最大公约数    highest common factor
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	cout << "HCF=" << a << endl;


	return 0;
}



