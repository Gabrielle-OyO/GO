//定义一个求函数最大值的函数模板

#include<iostream>
using namespace std;;

template<class T>
T maximum(T value1, T value2, T value3)
{
	T max = value1;
	if (value2 > max)
		max = value2;
	if (value3 > max)
		max = value3;
	return max;
	}

int main()
{
	int int1, int2, int3;
	cout << "Input three integer values:";
	cin >> int1 >> int2 >> int3;
	cout << "The maximum integer value is:" << maximum(int1, int2, int3);			//int version
	double double1, double2, double3;
	cout << "\nInput three  double values:";
	cin >> double1 >> double2 >> double3;
	cout << "The maximum double value is:" << maximum(double1, double2, double3);	//double version
	char char1, char2, char3;
	cout << "\nInput three characters:";
	cin >> char1 >> char2 >> char3;
	cout << "The maximum characters value is:" << maximum(char1, char2, char3);		//char version

	
	return 0;
}