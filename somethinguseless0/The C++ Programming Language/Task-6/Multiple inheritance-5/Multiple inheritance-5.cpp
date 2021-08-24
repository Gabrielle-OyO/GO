
//存在多义性问题的程序

#include<iostream>
using namespace std;

class A
{
protected:
	int a;
public:
	A(int x) { x = a; }
	void show() { cout << "AAAAAAAAAAAAAAAAAAAAAA" << endl; }
};

class AB :public A
{
protected:
	int ab;
public:
	AB(int x, int y) :A(x) { ab = y; }
};

class AC :public A
{
protected:
	int ac;
public:
	AC(int x, int y) :A(x) { ac = y; }
};

class ABC :public AB, public AC
{
protected:
	int abc;
public:
	ABC(int x, int y, int z) :AB(x, y), AC(x, y) { abc = z; }
	void show();
};

int main()
{
	ABC aaa(1, 2, 3);
	aaa.show();				//show()继承的函数不明确，产生二义性错误
}

void ABC::show()
{
	A::show();
//    ABC::show();
	AB::show();
	AC::show();
}
