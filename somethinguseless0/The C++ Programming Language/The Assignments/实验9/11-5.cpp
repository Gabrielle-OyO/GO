#include<iostream>
using namespace std;
//使用前声明
class B;

class A 
{
private:
	int value1;
public:
	A(int v1) { value1 = v1; }
	friend void Same_Value(const A &a , const B &b);
};



class B
{
private:
	int value2;
public:
	B(int v2) { value2 = v2; }
	friend void Same_Value(const A &a, const B &b);
};

//比较
void Same_Value(const A &a, const B &b)
{
	if (a.value1 == b.value2)
	{
		cout << "相同"<<endl;
	}
	else
	{
		cout << "不同"<<endl;
	}
}

int main()
{
	int v1, v2;
	cout << "请输入value1,value2:" << endl;
	cin >> v1 >> v2;
	A a(v1);
	B b(v2);
	//返回判断结果
	Same_Value(a, b);
	return 0;
}