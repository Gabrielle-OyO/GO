#include <iostream>
using namespace std;

class rectangle
{
private:
	int x, y;

public:
	rectangle(int a, int b) { x = a; y = b; }
	int area() { return x * y; }
	void show()
	{
		cout << "Ãæ»ý£º" << area() << endl;
	}
};

int main()
{
	int a, b;
	cin >> a >> b;
	rectangle x(a, b);
	x.show();
}