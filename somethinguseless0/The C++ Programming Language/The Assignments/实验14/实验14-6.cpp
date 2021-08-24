// 实验14-6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Convert
{
protected:
	double init;
	double conv;
public:
	Convert(double in) { init = in; }
	double GetInit() { return init; }
	double GetConv() { return conv; }
	virtual void Compute() = 0;
};


// kg transform to g, kg=1000g
class Kg_to_g:public Convert
{
public:
	Kg_to_g(int i) :Convert(i) {};
	void Compute()
	{
		conv = init * 1000;
		cout << "kg transform to g:"<<conv<<endl;
	}
};


// f transform to c, c = (f-32)/1.8
class F_to_c:public Convert
{
public:
	F_to_c(int i) :Convert(i) {};
	void Compute()
	{
		conv = (init - 32) / 1.8;
		cout <<"摄氏度 = " <<conv<<endl;
	}
};

int main()
{
	Convert *p;
	Kg_to_g k(10);
	p = &k;
	p->Compute();
	F_to_c f(10);
	p = &f;
	p->Compute();
    return 0;
}

