#include<iostream>
using namespace std;

void maxmin(int *p, int *max, int *min);
void maxmin(int *p, int *max, int *min)
{
	int i=1;
	*max = *min = p[0];
	for (i = 0; i <= 5; i++) {
		if (p[i] > * max) { *max = p[i]; }
		if (p[i] < *min) { *min = p[i]; }
	}
}
int main()
{
	int a[6], i = 0,x,y;
	
	
	for (i = 0; i<=5; i++) {
		cin >> a[i];
	}
	
	maxmin(a,&x,&y);
	cout << "最大值：" << x<< endl;
	cout << "最小值：" << y << endl;
	return 0;
}