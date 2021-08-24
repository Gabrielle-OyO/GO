#include<iostream>
using namespace std;
#include<math.h>

//有三个矩阵ABC均为4行4列要求重载运算符使之能对三个矩阵求差 并给出结果
#pragma warning(default:4716)
class Matrix
{
public:
	Matrix();
	friend Matrix operator-(Matrix&, Matrix&);
	friend ostream& operator<<(ostream&, Matrix&);
	friend istream& operator>>(istream&, Matrix&);
	int mat[4][4];
private:
	
};

Matrix::Matrix() {}

Matrix operator+(Matrix& a, Matrix& b)
{
	int i, j;
	Matrix c;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
		}
	}

	return c;
}
Matrix operator-(Matrix&, Matrix&)
{
	return Matrix();
}
ostream& operator<<(ostream& cout, Matrix& a)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cout << a.mat[i][j] << " ";
		}
		cout << endl;
	}
}
istream& operator>>(istream& input, Matrix& a)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			input >> a.mat[i][j];
		}
	}
}

int main()
{

	Matrix a, b, c;
	cin >> a;
	cin >> b;
	c = a - b;
	cout << c << endl;
	return 0;
}


