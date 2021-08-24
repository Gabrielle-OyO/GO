#include "ex2-2.h"
#include <math.h>//平方根函数

//三角形
inline int triangle::circumference(int x, int y, int z)//周长
{
	return x + y + z;
}

inline double triangle::square(int x, int y, int z)//面积
{
	int num1 = x + y + z;
	int num2 = x + y - z;
	int num3 = x + z - y;
	int num4 = y + z - x;
	double res = 0.25 * sqrt(num1 * num2 * num3 * num4);
	return res;

}     

//菱形
inline double diamond::circumference(int x, int y)//周长
{
	double t = (0.5 * x) * (0.5 * x) + (0.5 * y) * (0.5 * y);
	double res = 4 * sqrt(t);
	return res;
}

inline double diamond::square(int x, int y)//面积
{
	return 0.5 * x * y;
}