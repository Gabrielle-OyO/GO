#include<iostream>
using namespace std;
#include<stdlib.h>

template<class T>				//类模板：实现对任意类型数据进行存取
class Store
{
private:
	T item;						//用于存放任意类型的数据
	int haveValue;				//haveValue标记item是否已被存入内容
public:
	Store(void);				//缺省形式（无形参）的构造函数
	T GetElement(void);			//提取数据
	void PutElement(T x);		//存入数据
};

//NOTE：模板类的成员函数，若在类外实现，则必须是模板函数


//缺省形式构造函数的实现
template<class T>
Store<T>::Store(void) :haveValue(0) {}

//提取数据函数的实现
template<class T>
T Store<T>::GetElement(void)		//如果试图提取未初始化的数据，则终止程序
{
	if (haveValue == 0)
	{
		cout << "No item present!" << endl;
		exit(1);
	}
	return item;					//返回item中存放的数据
}

//存入数据的实现
template<class T>
void Store<T>::PutElement(T x)
{
	haveValue++;					//将haveValue置为TRUE，表示item中以存入数值
	item = x;						//将x值存入item
}
struct Student
{
	int studID;						//学号
	float gpa;						//平均分
};

int operator==(Student a, Student b)		//重载“==”使之判断学号相等与否
{
	return a.studID == b.studID;
}

int main(void)
{
	Student graduate = { 1000,23 };			//定义Student类型结构体变量的同时赋以初值
	Store<int>A, B;							//定义两个Store类对象，其中数据陈冠item为int类型
	Store<Student>S;						//定义Store类对象S；其中数据成员item为Student		
	Store<double>D;							//定义Store类对象D，其中数据成员item为double类型
	A.PutElement(3);						//初始化A；
	B.PutElement(-7);						//初始化B；
	cout << A.GetElement() << " " << B.GetElement() << endl;		//输出对象A、B的数据成员
	S.PutElement(graduate);											//初始化D；
	cout << "The student id is " << S.GetElement().studID << endl;	//输出对象S的数据成员
	cout << "Retrieving object D ";
	cout << D.GetElement() << endl;									//输出对象D的数据成员
}