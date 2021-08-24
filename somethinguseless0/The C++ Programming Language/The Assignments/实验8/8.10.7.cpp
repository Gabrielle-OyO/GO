#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class person
{
private:
	char *buffer;
	int age;
public:
	person(const person &me);
	person(char *p, int a);
	void Display();
	
};
person::person(const person &me)
{
	buffer = new char[strlen(me.buffer) + 1];
	strcpy(buffer, me.buffer);
	this->age = me.age;
}
person::person(char *p, int a)
{
	buffer = new char[strlen(p) + 1];
	strcpy(buffer, p);
	age = a;
}
void person::Display()
{
	cout << "The name is " << buffer << " age is " << age << endl;
}
int main()
{
	char a[50] = { "liu" };
	person A(a, 50);
	person B(A);
	B.Display();

}