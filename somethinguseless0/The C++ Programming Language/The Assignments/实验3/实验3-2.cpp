
#include"3-2.h"
int main()
{
	int m, n;
	cout << "ÇëÊäÈën,m(n<m):" << endl;
	cin >> n >> m;
	Addn_m A(m, n);
	cout<<A.add(m, n);
}