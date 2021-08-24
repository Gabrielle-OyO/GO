#include<iostream>
using namespace std;

class Object
{
private:
	int Weight;
public:
	virtual void Show();
	double Weight;

};

class Camera :virtual public Object
{
public:
	double num1;
};

class Telephone :virtual public Object
{
public:
	double num2;
};

class Mobile :public Camera, public Telephone
{

};

int main()
{

}

void Object::Show()
{
}
