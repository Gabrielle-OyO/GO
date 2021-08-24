
#pragma once
#include <iostream>
using namespace std;

class Addn_m {
private:
	int m, n;

public:
	Addn_m(int x, int y) { m = x; n = y; }
	double add(int x, int y) {
		int t;
		double sum = 0;
		//计数器
		t = n;
		//实现累加
		while (t <= m) {
			//*1.0为了小数形式输出，和c一样
			sum += 1.0 / t;
			t = t + 1;
		}
		return sum;
	}
};