  
#pragma once
#include <iostream>
using namespace std;

class factorial {
private:
	int n;

public:
	factorial(int t) { n = t; }
	int f(int n) {
		//¼ÆÊýÆ÷
		int t=1;
		//ÖÐ¼äÏî
		int x = 1;
		int sum=0;
		//½×³ËÀÛ¼Ó
		while (t <= n) {
			x *= t;
			sum += x;
			t++;
		}
		return sum;
	}
};