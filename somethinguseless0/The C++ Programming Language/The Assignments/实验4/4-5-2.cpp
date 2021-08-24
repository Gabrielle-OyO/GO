#include<iostream>
using namespace std;

class count1
{
private:
	char str[100];
public:
	count1(char s[]) { strcpy_s(str, s); }
	void computer();
};
void count1::computer()
{
	int Letters, Digital, Space, Other,i;
	Letters = Digital = Space = Other = i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] < 'Z' || str[i] >= 'a' && str[i] <= 'z')
			Letters++;
		else if (str[i] >= '0' && str[i] <= '9')
			Digital++;
		else if (str[i] == ' ')
			Space++;
		else
			Other++;
		i++;
	}
	cout << "Letters:" << Letters << '\n' << "Digital:" << Digital << '\n' << "Space:" << Space << '\n' << "Other:" << Other << endl;
}

int main()
{
	char s[100];
	gets_s(s);
	count1 A(s);
	A.computer();
	return 0;
}