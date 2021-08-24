#include<iostream>
using namespace std;

//创建各类三角形
int main()
{
	int rows;
	cout << "输入行数：";
	cin >> rows;

	for (int i = 1;i <= rows;i++)
	{
		for (int j = 1;j <= i;j++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	for (int m = 1;m <= rows;m++)
	{
		for (int n = 1;n <= m;n++)
		{
			cout << n<<" ";
		}
		cout << "\n";
	}

	for (int r=rows;r>=1;r--)
	{
		for (int l = 1;l <= r;l++)
		{
			cout << "*";
		}
		cout << endl;
	}

	for (int t = rows;t >= 1;t--)
	{
		for (int w = 1;w <= t;w++)
		{
			cout << w << " ";
		}
		cout << endl;
	}

	int space;
	
	for (int x = 1,y = 0;x < rows;x++, y = 0)
	{
		for (space = 1;space <= rows - x;space++)
		{
			cout << " ";
		}
		while (y != 2 * x - 1)
		{
			cout << "*";
			y++;
		}
		cout << endl;
	}



	//注意字母定义格式
	char input;
	char alphabet = 'A';
	cout << "输入最后一个大写字母：";
	cin >> input;

	for (int p = 1;p <=(input-'A'+1);p++)
	{
		for (int q = 1;q <= p;q++)
		{
			cout << alphabet<<" ";
		}
		alphabet++;
		cout << endl;
	}

	int rowss, countt = 0, countt1 = 0, kk = 0;

	cout << "输入行数: ";
	cin >> rowss;

	for (int ii = 1; ii <= rowss; ++ii)
	{
		for (int spaces = 1; spaces <= rowss - ii; ++spaces)
		{
			cout << "  ";
			++countt;
		}

		while (kk != 2 * ii - 1)
		{
			if (countt <= rowss - 1)
			{
				cout << ii + kk << " ";
				++countt;
			}
			else
			{
				++countt1;
				cout << ii + kk - 2 * countt1 << " ";
			}
			++kk;
		}
		countt1 = countt = kk = 0;

		cout << endl;
	}





	return 0;
}