/////////////////////////自动贩卖机//////////////////////////
#include<iostream>
using namespace std;
#include<string>
#include <cstring>
#include<math.h>
#include<vector>
//#include <afxsock.h>
//#include "stdafx.h"
using namespace std;
////////////////////////////继承/////////////////////////////
//【基类】
class Sell 
{
public:
    char* name;
    int price;

    Sell();//缺省构造函数
    Sell(char*, int);//构造函数  使用已有的对象创建新的对象，赋值并调用
    Sell(const Sell& p);//拷贝构造函数   使用已有的对象创建新的对象，赋值并调用
    friend void printSell(Sell sell);//友元函数  访问类中的私有成员和保护成员
    ~Sell()//析构函数 释放函数变量
    {
        cout << "正在初始化" << endl;
    }
    virtual void show();//虚函数   动态连编效果 实现多态
};
void Sell::show()//定义在类外的构造函数
{
    cout << name << price << endl;
};
Sell::Sell() 
{
    this->name = "xxx";
    this->price = 0;
};

Sell::Sell(char* name, int price) : name(name), price(price) {};//构造函数初始化变量

//Sell::Sell(char* name, int price)//初始化变量
//{
//    name = name;
//    price = price;
//};

Sell::Sell(const Sell& p)//拷贝构造函数（用Sell初始化Sell)
{
    this->name = p.name;
    this->price = p.price;
    //    cout<<"测试拷贝构造函数"<<endl;
};

//派生类
class SellAddAll : public Sell 
{
public:
    char* type;
    char* time;

    SellAddAll();
    SellAddAll(char*, int, char*, char*);//重载
    void display();
};
SellAddAll::SellAddAll() 
{

    this->time = "全天供应";
    this->type = "yyy";

}
SellAddAll::SellAddAll(char* name, int price, char* time, char* type) : Sell(name, price) 
{
    this->time = time;
    this->type = type;
}
void SellAddAll::display() 
{
    cout << "商品名称是:" << name << ",价格是:" << price << "，供应时间是" << time << "，商品类型是:" << type << endl;
}

static    vector<SellAddAll> vec;//容器类定义，调用SellAddAll类的对象作为DeleteSell、ModifySell、QuerySell类的成员

/////////////////////////////////删除某一商品
class DeleteSell
{
public:
    void Delete()
    {
        for (int i = 0; i < vec.size(); i++)//返回vec的元素
        {
            cout << (i + 1) << ":";
            cout << vec[i].name << vec[i].price << endl;//调用name，price成员
        }
        cout << "请选择需要删除的商品编号:" << endl;
        int x;
        cin >> x;
        vec.erase(vec.begin() + (x - 1));//删除字符
        cout << "删除成功:" << endl;
    }

};
//////////////////////////////////////////修改某一商品
class ModifySell
{
public:
    void Modify()
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << (i + 1) << ":";
            cout << vec[i].name << vec[i].price << endl;
        }


        cout << "请选择需要修改的商品编号:" << endl;

    }
};
//////////////////////////////////////////查询所有商品
class QuerySell
{
public:
    void querysell()
    {
        cout << "当前商品信息为：" << endl;
        /*    for (auto it = vec.begin(); it != vec.end(); ++it)//此处测试集合（未实现）
         {
         cout << (*it).name << (*it).price << " ";
         }*/
        for (int i = 0; i < vec.size(); i++)
        {
            cout << "商品名称：" << vec[i].name << "商品价格：" << vec[i].price <<
                "供应时间：" << vec[i].time << "商品种类：" << vec[i].type << endl;
        }
        cout << endl;
    }
};
////////////////////////查询商品价格////////////////
class QueryPrice
{
    //private:
    //    int pricenum ;
public:
    void queryprice()
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << (i + 1) << ":";
            cout << vec[i].name << ":";
            cout << vec[i].price << endl;
        }

        cout << "请选择需要查询价格的商品编号：";
        int pricenum;
        cin >> pricenum;
        cout << "价格为:" << vec[pricenum - 1].price << endl;
    }
};
//////////////////////查询商品种类///////////////
class QueryType
{
private:
    int x;

public:
    void querytype()
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << (i + 1) << ":";
            cout << vec[i].name << ":";
            cout << vec[i].type << endl;
        }
        int typex;
        cin >> typex;
        cout << vec[typex - 1].type << endl;//type
        //    cout << "输出成功" << endl;
    }
    void show()
    {
        cout << "请选择需要查询的商品编号:" << endl;
    }
};
//////////////////////////////////////查询商品供应时间
class SupplyTime
{
public:
    void supplytime()
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << (i + 1) << ":";
            cout << vec[i].name << ":";
            cout << vec[i].time << endl;
        }
        void show();
        int typex;
        cin >> typex;
        cout << vec[typex - 1].time << endl;
        cout << "输出成功" << endl;
    }
    void show()
    {
        cout << "请选择需要查询的商品编号:" << endl;
    }
};
///////////////////////////账单小结/////////////////
class Bill
{
private:
    int price[10];
    int number[10];
public:
    int x, y;
    Bill() {};
    void show()
    {
        int billkk = 1;
        int moneysum = 0;
        int sumnum = 0;
        while (billkk == 1)
        {
            cout << "请选择商品:" << endl;
            for (int i = 0; i < vec.size(); i++)
            {
                cout << i + 1 << ": ";
                cout << vec[i].name << "  " << vec[i].price << endl;
            }
            int billx;
            cin >> billx;

            price[sumnum] = vec[billx - 1].price;

            cout << "请选择商品数量:" << endl;
            int billy;
            cin >> billy;
            number[sumnum] = billy;
            for (int j = 0; j <= sumnum; j++)
            {
                moneysum += price[j] * number[j];
            }
            cout << "当前总金额为:" << moneysum << endl;
            cout << "是否选择继续添加商品（y继续，n结束）" << endl;
            char yn;
            cin >> yn;
            if (yn == 'y')
            {
            }
            else
            {
                billkk = 0;
            };

        };

    };
};
class  BillMore//随机促销礼券
{
public:
    int money1;
    int money2;
    //    money1 = money2 =0;
    BillMore(void)
    {
        money1 = money2 = 0;
        cout << "总金额为:" << money1 + money2 << endl;
    };
    BillMore(int a)
    {
        money1 = vec[rand() % a].price;
        money2 = 0;
        cout << "总金额为:" << money1 + money2 << endl;
    }
    BillMore(int a, int b)
    {
        money1 = vec[rand() % a].price;
        money2 = vec[rand() % b].price;
        cout << "总金额为:" << money1 + money2 << endl;
    };
    ~BillMore() {};
    friend BillMore operator+(const BillMore& px, const BillMore& py);//【友元函数重载运算符】
    void print(void);
    //cout<<"总金额为:"<<money1+money2<<endl; //（测试）
};
void BillMore::print()
{
    cout << "恭喜您获得总金额为:" << money1 + money2 << "的抵扣券" << endl;
};

BillMore operator+(const BillMore& px, const BillMore& py)//【友元函数重载运算符】
{
    return BillMore(px.money1 + py.money1, px.money2 + py.money2);
};

////////////////////////////多继承
class Vip1
{
protected:
    char Name[100];
public:
    Vip1(char* n)
    {
        strcpy_s(Name, n);
    }
    virtual void show();//虚函数
};

class Vip2 :virtual public Vip1
{
private:
    char university_name[20];
public:
    Vip2(char* n, char* un_n) :Vip1(n)
    {
        strcpy_s(university_name, un_n);
    }
    virtual void show();
};

class Vip3 :virtual public Vip1 //虚基类
{
private:
    int course1;
public:
    Vip3(char* n, char* a, int c1) :Vip1(n)
    {
        course1 = c1;
    }
    virtual void show();
};

class All : public Vip2, public Vip3//派生类【多继承】
{
private:
    int u;
public:
    All(char* n, char* a, char* un_n, int c1, int uu) :Vip1(n), Vip2(n, un_n), Vip3(n, a, c1)
    {
        u = uu;
    };
    void show();
};
void All::show()
{
    Vip3::show();
}

void Vip1::show()
{
    cout << endl;
    cout << "姓名：" << Name << endl;
}
void Vip2::show()
{
    Vip1::show();
    cout << "大学名称：" << university_name << endl;
}
void Vip3::show()
{
    Vip1::show();
    cout << "会员积分：" << course1 << endl;
}
///////////////////主菜单///////////////
class MShow
{
public:
    void show()
    {
        cout << "请选择:" << endl;
        cout << "1.管理员列表" << endl;
        cout << "2.客户购买列表" << endl;
        cout << "3.程序结束" << endl;
    }
};
//////////////管理员界面菜单/////////////////
class ListShowOne
{
public:
    void show()
    {
        cout << "请选择：" << endl;
        cout << "1.初始化商品信息" << endl;
        cout << "2.删除商品信息" << endl;
        cout << "3.修改商品信息" << endl;
        cout << "4.查询商品所有信息" << endl;
        cout << "5.返回上级菜单" << endl;
    }
};
//////////////////客户端菜单/////////////////
class ListShowTwo
{
public:
    void show()
    {
        cout << "请选择:" << endl;
        cout << "1.商品价格查询" << endl;
        cout << "2.商品类型查询" << endl;
        cout << "3.商品供应时间查询" << endl;
        cout << "4.输出VIP信息" << endl;
        cout << "5.随机赠送礼品" << endl;
        cout << "6.账单小结" << endl;
        cout << "7.返回上级菜单" << endl;
    }
};
int main() {
    ///////商品售卖列表///////////
    SellAddAll A("可乐",3, "全天供应", "饮料");//定义类的多个对象
    SellAddAll B("炒饭", 5, "早上八点", "主食");
    SellAddAll C("瓜子", 7, "全天供应", "零食");
    SellAddAll D("泡面", 10, "晚上八点", "宵夜");
    SellAddAll E("自热小火锅", 30, "晚上八点", "宵夜");

    /////////VIP用户信息////////////////
    int q, w;
    q = 2; w = 3;
    Vip1* p, A2("曾瑶瑶");
    All D2("曾瑶瑶", "China", "School", 95, 10);
    p = &D2;

    ///////////操作动作//////////////
    cout << "欢迎来到自动贩卖机" << endl;
    while (true) {
        MShow m;
        m.show();
        int mainx;
        cin >> mainx;

        //////// 管理员列表/////////
        if (mainx == 1)
        {
            ListShowOne one;
            one.show();
            int listtwochoice;
            cin >> listtwochoice;
            switch (listtwochoice)
            {
            case 1:
                vec.push_back(A);//容器类对象插入A内容
                vec.push_back(B);
                vec.push_back(C);
                vec.push_back(D);
                cout << "增加成功" << endl;
                break;
            case 2:
                while (true) {
                    DeleteSell d;
                    d.Delete();
                    cout << "是否继续（1/0）" << endl;
                    int kk2;
                    cin >> kk2;
                    if (kk2 == 0) {
                        break;
                    };
                }
                break;
            case 3:
                ModifySell m;
                m.Modify();
                int x;
                cin >> x;
                vec[x - 1] = E;
                cout << "修改成功" << endl;
                break;
            case 4:
                QuerySell q;
                q.querysell();
                break;
            case 5:
                break;
            };
        }
        ////////////用户购买列表////////////
        else if (mainx == 2)
        {
            ListShowTwo two;
            two.show();
            int casetwo;
            cin >> casetwo;
            switch (casetwo)
            {
            case 1:while (true)
            {
                QueryPrice qp;
                qp.queryprice();
                cout << "是否继续（1/0）" << endl;
                int qq1;
                cin >> qq1;
                if (qq1 == 0) {
                    break;
                };
            }
                  break;
            case 2:
                while (true) {
                    QueryType qt;

                    qt.show();
                    qt.querytype();
                    cout << "是否继续（1/0）" << endl;
                    int qq2;
                    cin >> qq2;
                    if (qq2 == 0) {
                        break;
                    };
                }
                break;
            case 3:while (true) {
                SupplyTime st;
                st.show();
                st.supplytime();
                cout << "是否继续（1/0）" << endl;
                int qq3;
                cin >> qq3;
                if (qq3 == 0) {
                    break;
                };
            }
                  break;
            case 4:
                cout << "输出唯一VIP会员信息：" << endl;
                p->show();
                break;
            case 5:
            {
                BillMore billmore(3);
                billmore.print();
                break;
            }
            case 6:
                Bill bill;
                bill.show();
                break;
            }
        }
        /////////程序结束/////////////
        else if (mainx == 3)
        {
            cout << "欢迎下次使用" << endl;
            break;
        }
    }
}
