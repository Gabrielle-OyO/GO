#include <iostream>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;
class student
{
private:
	char name[20];
	int age;
public:
	student(const char n[], int a)
	{
		strcpy(name, n);
		age = a;
	}
	void show()
	{
		cout << "学生姓名为：" << name << "，年龄是：" << age << endl;
	}
};

int main()
{
	student AA("张三", 20);
	AA.show();
}