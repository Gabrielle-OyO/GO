//测试myclass类

#include<iostream>
using namespace std;

template<class Type1,class Type2>
class myclass
{
private:
	Type1 i;
	Type2 j;
public:
	myclass(Type1 a, Type2 b)
	{
		i = a; j = b;
	}
	void show()
	{
		cout << i << ' ' << j << endl;
	}
};

int main()
{
	myclass<int, double>obj1(86, 175.2);
	myclass<char,const char*>obj2('m', "zhejdoiaon");
	obj1.show();
	obj2.show();

}

