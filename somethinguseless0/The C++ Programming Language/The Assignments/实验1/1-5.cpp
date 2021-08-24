#include <iostream>
using namespace std;
class cube
{
private:
	int a, b, c;

public:
	cube(int x, int y, int z) { a = x; b = y; c = z; }
	int Volume()
	{
		int z;
		z = a * b * c;
		return z;
	}
	void show()
	{
		cout << "³¤·½ÌåÌå»ý£º" << Volume() << endl;
	}
};
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cube s(a, b, c);
	s.show();
}