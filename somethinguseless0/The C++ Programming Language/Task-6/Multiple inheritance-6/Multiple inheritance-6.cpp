
//多继承中的二义性问题		【已更改正确】

#include<iostream>
using namespace std;

class Father
{
public:
	void display() { cout << "父亲姓名：黎明" << endl; }
};

class Mother
{
public:
	void display() { cout << "母亲姓名：彩霞" << endl; }
};


class Son :public Father, public Mother 
{
public:
	void display();			//add
};

void Son::display()			//add
{
	Father::display();
	Mother::display();
}


int main()
{
	Son s;
	s.display();		//含义模糊，编译错误；【可使用作用域运算符】
						//在派生类中定义一个新函数display()解决问题
}