// 13-6.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class circle
{};

class cylinder :virtual public circle
{};

class sphere:virtual public circle
{};

class rectangle
{};

class wuti:virtual public circle,public rectangle
{};

int main()
{
    return 0;
}

