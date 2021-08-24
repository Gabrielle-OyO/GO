#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "输入一个整数：";
	cin >> n;

	if (n % 2 == 0)
		cout << n << "为偶数。" << endl;
	else
		cout << n << "为奇数。"<<endl;

	int m;
	m = n;
	(m & 2 == 0) ?cout << m << "为整数。": cout << m << "为奇数。" << endl;
	
	return 0;
}