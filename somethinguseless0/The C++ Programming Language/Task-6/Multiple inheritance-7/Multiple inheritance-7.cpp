
//公共基类继承问题

#include<iostream>
using namespace std;

class Person
{
protected:
	int age;
public:
	void setage(int a) { age = a; }
	void getage() { cout << "The age is :" << age << endl; }
};

class Father:virtual public Person {};		//重新定义，增添virtual
class Mother:virtual public Person {};
class Son :public Father, public Mother {};

int main()
{
	Son s;
	s.setage(28);
	s.getage();
}
