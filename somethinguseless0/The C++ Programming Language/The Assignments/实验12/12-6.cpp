#include<iostream>
#include<math.h>
using namespace std;
class person
{
private:
	double x, y;
public:
	person(double m, double n) { x = m; y = n; }
	friend double   operator+(const person& x, const person& y);

	friend double operator-(const person& x, const person& y);
};
 double  operator+(const person& m, const person& n)
{
	 double money;
	 money = (m.x+n.x)*(m.x + n.x) + (m.y+n.y)*(m.y + n.y);
	 return money;
 }
 double  operator-(const person& m, const person& n)
 {
	 double money;
	 money = (m.x - n.x)*(m.x - n.x) - (m.y - n.y)*(m.y - n.y);
	 return money;
 }
 int  main()
 {
	 double x, y, z, k,w,e,i;
	 char er;
	 cout << "������˫�����ԣ�" << endl;
	 cin >> x >> y >> z >> k;
	 person m(x, y), n(z, k);
	
	 cout << "������ǻ�����������1����������2��" << endl;
	 cin >> i;
	 if (i == 1) {
		 w = m + n;
	 }
	 else {
		 w = m - n;
	 }
	 
	 cout << "���ǵĲƲ���" << w << endl;
 }