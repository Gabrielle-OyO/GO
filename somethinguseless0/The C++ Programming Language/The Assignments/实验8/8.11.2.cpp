#include<iostream>
#include<string.h>
using namespace std;
class old
{
private:
	char name[30];
	int monery;
	static int allmonery;
public:
	old(char* n, int a) {
		strcpy_s(name, n);
		monery = a;
		allmonery = monery + allmonery;
	}
	~old(void){}
	static int getallmonery(void)
	{
		return allmonery;
	}

};
int old::allmonery = 10000;
int main()
{
	char a[10] = { "¶ù1" };
	char b[10] = { "¶ù2" };
	char c[10] = { "Å®1" };
	char e[10] = { "Å®2" };
	old o1(a, 1000);
	old o2(b, 500);
	old o3(c, 2000);
	old o4(e, 1800);
	int all;
	all = old::getallmonery();
	cout << "Allmonery=" << all << endl;


}
