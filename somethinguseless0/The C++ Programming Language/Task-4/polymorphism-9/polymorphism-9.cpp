//在进位制转换中应用纯虚函数
#include<iostream>
using namespace std;

class num
{
protected:
	int val;
public:
	num(int i) { val = i; }
	virtual void show() = 0;		//纯虚函数
};

class hextype :public num			//六进制
{
public:
	hextype(int i) :num(i) {};
	void show() { cout << hex << val << endl; }
};

class dectype :public num			//十进制
{
public:
	dectype(int i) :num(i) {};
	void show() { cout << dec << val << endl; }
};

void main()
{
	num* pn;			//指针-调用纯虚函数；
	dectype d(56);		//dectype初始化
	pn = &d;			//取对象的地址
	pn->show();			//->叫做结构体指针运算符，也是用来访问结构体内部成员的。换种说法，如果我们在C语言中定义了一个结构体，然后声明一个指针指向这个结构体，那么我们要用指针取出结构体中的数据，就要用到“->”.

	//解析同上：
	hextype h(20);
	pn = &h;
	pn->show();
}