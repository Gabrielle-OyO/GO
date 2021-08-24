//定义一个求绝对值的模板


#include<iostream>
using namespace std;
#include<math.h>

template<typename T>

T abs(T x)
{
	return x < 0 ? -x : x;
}

int main()
{
	int n = -5;
	double d = -5.5;
	cout << abs(n) << endl;
	cout << abs(d) << endl;
}