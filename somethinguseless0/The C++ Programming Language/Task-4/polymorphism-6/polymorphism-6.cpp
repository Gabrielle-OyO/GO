
#include<iostream>
using namespace std;
#include<string.h>

class Student
{
protected:
	char Name[10];
	char Ad[20];
	int Year;
public:
	Student(const char *n,const char *a, int y)
	{
		strcpy_s(Name, n);strcpy_s(Ad, a);Year = y;
	}
	virtual void show();
};

class Academician :public Student
{
private:
	char university_name[20];
public:
	Academician(const char* n,const char* a, int y, const char* un_n):Student(n,a,y)
	{
		strcpy_s(university_name, un_n);
	}
	void show();
};

class Primary_scholar :public Student
{
private:
	int course1, course2;
public:
	Primary_scholar(const char* n, const char* a, int y, int c1, int c2) :Student(n, a, y) {course1 = c1;course2 = c2;}
	void show();
};
void Student::show()
{
	cout << endl;
	cout << "姓名：" << Name << endl;
	cout << "住址：" << Ad << endl;
	cout << "年份：" << Year << endl;
}
void Academician :: show()
{
	Student::show();
	cout << "大学名字：" << university_name << endl;
}
void Primary_scholar::show()
{
	Student* p, A("张美丽","和高小写",1980);
	Academician B("望京", "紫荆港", 1982, "浙江大学");
	Primary_scholar C("fangfang ", "w温州", 1979, 89, 95);
	cout << "输出结果" << endl << endl;
	p = &A;
	p->show();
	p = &B;
	p->show();
	p = &C;
	p->show();
}