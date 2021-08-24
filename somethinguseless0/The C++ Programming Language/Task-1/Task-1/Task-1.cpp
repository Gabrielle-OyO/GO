// Task-1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
    int divisor, dividend, quotient, remainder;
    cout << "请输入被除数：";
    cin >> dividend;

    cout << "请输入除数：";
    cin >> divisor;

    quotient = dividend / divisor;
    remainder = dividend % divisor;

    cout << "商=" << quotient << endl;
    cout << "余数=" << remainder;
    return 0;
}

