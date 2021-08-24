
//循环程序设计
//应用while循环求1+2+...+n的和。

#include<iostream>
using namespace std;
int fun(int n)
{
	int i = 1, s = 0;
	while (i <= n)
	{
		s += i;
		i++;
	}
	return s;
}

int main()
{
	int n, s;
	cin >> n;
	s = fun(n);
	cout << n << "!=" << s << endl;
	return 0;
}