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
		z = "����";
	if (x == y)
		z = "����";
	if (x < y)
		z = "С��";
	return z;
}

string d()
{
	string g = " ";
	int k = rand() % 10 + 1;                  //�������һ���ַ����ĳ��� 
	for (int i = 1; i <= k; i++)
	{
		int x, s;                        //x��ʾ����ַ���ascii�� ��s��ʾ����ַ��Ĵ�Сд  
		s = (rand() + 7) % 2;                     //���ʹsΪ1��0��Ϊ1���Ǵ�д��Ϊ0����Сд 
		if (s == 1)                        //���s=1 
			x = rand() % ('Z' - 'A' + 1) + 'A';       //��x��Ϊ��д��ĸ��ascii�� 
		else
			x = rand() % ('z' - 'a' + 1) + 'a';       //���s=0��x��ΪСд��ĸ��ascii�� 
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
		case 0:ch = "�ַ�������"; break;
		case 1:ch = "�ַ�������"; break;
		case 2:ch = "�ַ����Ƚ�"; break;
		}
		h = (*p[z])(e, f);
		cout << e << ' ' << f << ch << '=' << h << endl;
		k--;
	}
}
