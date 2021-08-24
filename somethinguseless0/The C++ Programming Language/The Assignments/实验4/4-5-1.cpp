#include<iostream>
using namespace std;

int main()
{
	int Letters, Digital, Space, Other;
	char ch;
	Letters = Digital = Space = Other = 0;
	while ((ch = getchar()) != '\n')
		if (ch >= 'A' && ch < 'Z' || ch >= 'a' && ch <= 'z')
			Letters++;
		else if (ch >= '0' && ch <= '9')
			Digital++;
		else if (ch == ' ')
			Space++;
		else
			Other++;
	cout << "Letters:" << Letters << '\n' << "Digital:" << Digital << '\n' << "Space:" << Space << '\n' << "Other:" << Other << endl;
	return 0;
}

///写成while(ch=getchar()!='\n'不能达到预期效果，会全部归入Other里
///写成while((ch=getchar())!='\0'不能达到预期效果,无法得到结果