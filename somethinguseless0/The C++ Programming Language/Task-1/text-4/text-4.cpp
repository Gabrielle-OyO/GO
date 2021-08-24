#include<iostream>
using namespace std;

//二元一次方程组求解
//Discriminant  根的判别式  Discriminant=b^2-4ac

/*
if Discriminant=0   root1=-b/2a;
					root2=-b/2a;
if Discriminant>0   root1=-b/2a+[✔(b^2-4ac)]/2a;
					root2=-b/2a-[✔(b^2-4ac)]/2a;
if Discriminant<0	root1=-b/2a+i[✔-(b^2-4ac)]/2a;
					root1=-b/2a-i[✔-(b^2-4ac)]/2a;
*/

int main()
{
	float a, b, c, x1, x2, Discrimiant, RealPart, ImaginaryPart;
	cout << "输入a,b,c:";
	cin >> a >> b >> c;
	Discrimiant = b * b - 4 * a * c;

	if (Discrimiant > 0)
	{
		x1 = (-b + sqrt(Discrimiant)) / (2 * a);
		x2 = (-b - sqrt(Discrimiant)) / (2 * a);
		cout << "Roots are real and different." << endl;
		cout << "x1=" << x1 << endl;
		cout << "x2=" << x2 << endl;
	}
	else if (Discrimiant == 0)
	{
		cout << "Roots are real and same." << endl;
		x1 = (-b + sqrt(Discrimiant)) / (2 * a);
		cout << "x1=x2=" << x1 << endl;
	}
	else
	{
		RealPart = -b / (2 * a);
		ImaginaryPart = sqrt(-Discrimiant) / (2 * a);
		cout << "Roots are vitual and different." << endl;
		cout << "x1=" << RealPart << "+" << ImaginaryPart << "i" << endl;
		cout << "x2=" << RealPart << "-" << ImaginaryPart << "i" << endl;
	}
	return 0;

}