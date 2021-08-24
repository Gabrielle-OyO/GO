#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	char c;
	if (argc != 3)cout << "参数个数不对" << endl;
	else {
		c = *argv[1];
		switch (c)
		{
		case'+':
		{
			cout << "执行假名程序段" << endl;

		}
		break;
		case '-':
		{
			cout << "执行解密程序段" << endl;

		}
		break;
		default:cout << "第二个参数错误：" << endl;
		}
	}
	return 0;
}


