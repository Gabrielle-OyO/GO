//Middle Test

/*
程序要求 :

    中国共产党第十九届中央委员会第五次全体会议于2020年10月26日至29日在北京举行，审议通过了《中共中央关于制定国民经济和社会发展第十四个五年规划想二0三五年远景目标的建议》。该建议稿明确了我国“十四五”时期经济社会发展必须遵循的“五大原则”是 : 坚持党的全面领导、坚持以人民为中心、坚持新发展理念、坚持深化改革开放、坚持系统观念，确立了“十四五”时期经济社会发展“六大主要目标” : 经济发展取得新成效、改革开放迈出新步伐、社会文明程度得到新提高、生态文明建设实现新进步、民生福祉达到新水平、国家治理效能得到新提升。
    
    请用C++设计一个能够描述.上述“五大原则(Five_rule)和“六大主要目标(Six objective) ”的类，类名为th14_ Five_ Year _Plan, 要求类中有构造函数、输出函数(print)，“五大原则”和“六大主要目标”的信息从main函数中输入，而从上述类的成员函数print输出这些信息。请编写满足上述要求的程序代码，其中类的定义与实现需放在编写的th14_ Five_ Year Plan.h 头文件中。

*/

// th14_Five_Year_Plan.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <string.h>
using namespace std;

class th14_Five_Year_Plan
{
private:
    char Five_rule[200];
    char Six_objective[200];
public:
    th14_Five_Year_Plan(char fr[], char so[])
    {
        strcpy_s(Five_rule, fr);
        strcpy_s(Six_objective, so);
    }
    void print()
    {
        cout << "五大原则是：" << endl;
        cout << Five_rule << endl;
        cout << "六大主要目标是：" << endl;
        cout << Six_objective << endl;
    }
};

int main()
{
    char Five_rule[200] = "坚持党的全面领导、坚持以人民为中心、坚持新发展理念、坚持深化改革开放、坚持系统观念";
    char Six_objective[200] = "经济发展取得新成效、改革开放迈出新步伐、社会文明程度得到新提高、生态文明建设实现新进步、民生福祉达到新水平、国家治理效能得到新提升";

    th14_Five_Year_Plan fyp(Five_rule, Six_objective);
    fyp.print();

    return 0;
}

