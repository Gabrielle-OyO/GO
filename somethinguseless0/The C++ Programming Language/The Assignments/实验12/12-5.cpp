#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<iostream>
using namespace std;

class string1
{
private:
    char* str;
public:
    string1();
    string1(const char*);
    ~string1() { delete[]str; }
    string1& operator+(const string1& ss);
    string1& operator-(const string1& ss);
    string1& operator =(const string1&);
    void display() { cout << str << '\n'; }
};
string1& string1 :: operator+(const string1& ss)
{
    strcat(this->str, ss.str);
    return *this;
}
string1& string1 ::operator-(const string1& s)
{
    char* str1, * str2;
    int  length = strlen(this->str) + strlen(s.str), i, j, k;
    str1 = new char[length + 1];
    str2 = new char[length + 1];
    strcpy(str1, this->str);
    delete[] str;
    str = new char[length + 1];
    for (i = 0; i < length; i++)
        if (str1[i] == ' ')
            break;
        else
            continue;//i定位到空格位置
    for (j = i; j < length; j++)
        if (str1[j] != ' ')
            break;
        else
            continue;//j定位到非空格位置
    for (k = 0; k < i; k++)
        str2[k] = str1[k];
    for (k = j; k < length; k++)
        if (str1[k] == '\0')
            break;
        else
            str2[i + k - j] = str1[k];
    str2[i + k - j] = '\0';
    strcpy(this->str, str2);
    delete[]str1;
    delete[]str2;
    return (*this);
};
string1::string1()
{
    char x[10] = "浙江";
    str = new char[strlen(x) + 1];
    strcpy(str, x);
}
string1::string1(const char* s)
{
    str = new char[strlen(s) + 100];
    strcpy(str, s);
}
string1& string1 ::operator =(const string1& s)
{
    delete[] str;
    int length = strlen(s.str);
    str = new char[length + 1];
    strcpy(str, s.str);
    return (*this);
}

void main()
{
    string1 s1("浙江大学 "), s3;
    string1 s2("计算机学院欢迎您！ ");
    s3 = s1 + s2;
    s3.display();
    s3 = s1 - s2;
    s3.display();
}