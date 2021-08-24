#include<iostream>
#include<string>
using namespace std;

class str
{
private:
	char str1[80], str2[80];
	char ch;
public:
	str(const char a[], const char b[], char c)
	{
		strcpy_s(str1, a);
		strcpy_s(str2, b);
		ch = c;
	}
	void opre();
};
void str::opre()
{
	if (ch == '+')
	{
		cout << str1 << str2 << endl;
	}
	else if (ch == '-')
	{
		int i = 0;
		while (str1[i] != ' ')
		{
			cout << str1[i];
			i++;
		}
		cout << str2;
		for (i;i < sizeof(str1);i++)
			cout << str1[i];
		cout << endl;
	}
}

int main()
{
	str A("abcd   ", "12345", '+');
	A.opre();
	str B("abcd   ", "12345", '-');
	B.opre();
}