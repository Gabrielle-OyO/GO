#include<iostream>
#include<string.h>
using namespace std;
class cat 
{
private:
	char colour[6];
	int weight, age;
public:
	cat(char colour1[6], int weight1, int age1) {
		strcpy_s(colour , colour1);
		weight = weight1;
		age = age1;
	}
	void show();
};
void cat::show() 
{
	cout << "è����ɫ��" << colour << ends << "���أ�" << weight << ends << "���䣺" << age << endl;

}
int main()
{
	char colour[6];
	int weight, age;
	cin >> colour;
	cin >> weight >> age;
	cat A(colour, weight, age);
	A.show();
	return 0;
}