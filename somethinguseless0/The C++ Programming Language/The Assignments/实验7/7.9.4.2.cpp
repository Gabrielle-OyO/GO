#include<iostream>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

string a(string x, string y)
{
	return x;
}

string b(string x, string y)
{
	return x + y;
}

string c(string x, string y)
{
	string z;
	if (x > y)
		z = "大于";
	if (x == y)
		z = "等于";
	if (x < y)
		z = "小于";
	return z;
}

string d()
{
	string g = " ";
	int k = rand() % 10 + 1;                  //随机生成一个字符串的长度 
	for (int i = 1; i <= k; i++)
	{
		int x, s;                        //x表示这个字符的ascii码 ，s表示这个字符的大小写  
		s = (rand() + 7) % 2;                     //随机使s为1或0，为1就是大写，为0就是小写 
		if (s == 1)                        //如果s=1 
			x = rand() % ('Z' - 'A' + 1) + 'A';       //将x赋为大写字母的ascii码 
		else
			x = rand() % ('z' - 'a' + 1) + 'a';       //如果s=0，x赋为小写字母的ascii码 
		g += (char)x;
	}
	return g;
}

void main()
{
	string ch;
	string(*p[4])(string, string) = { a,b,c }, e, f, h;
	int z, i;
	int k = 12;
	srand((int)time(0));

	while (k)
	{
		for (i = 0; i < 5; i++)
		{
			e = d();
			f = d();
			z = (int)(100.0 * rand() / (RAND_MAX + 1.0)) % 3;
		}
		switch (z)
		{
		case 0:ch = "字符串复制"; break;
		case 1:ch = "字符串连接"; break;
		case 2:ch = "字符串比较"; break;
		}
		h = (*p[z])(e, f);
		cout << e << ' ' << f << ch << '=' << h << endl;
		k--;
	}
}
