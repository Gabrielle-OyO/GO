#pragma once
#include <iostream>
using namespace std;

class triangle {
private:
	int x, y, z;
public:
	triangle(int a, int b, int c) { x = a; y = b; z = c; }    //变量初始化
	int circumference(int x, int y, int z);                  //周长
	double square(int x, int y, int z);                     //面积
};

class diamond {
private:
	int x, y;
public:
	diamond(int a, int b ) { x = a; y = b;  }           //变量初始化
	double circumference(int x, int y);                //周长
	double square(int x, int y);                      //面积
};
