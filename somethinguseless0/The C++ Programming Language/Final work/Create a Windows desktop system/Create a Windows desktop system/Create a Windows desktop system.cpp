#include <cstdlib>
#include <iostream>
using namespace std;
#include <string>
#include<windows.h>
#include<conio.h>
#include <fstream>
#define null NULL
class student
{
private:
    int flag;
    friend class studentMessage;
    student* next; //节点指针
    string name; //学生姓名
    string address;  //家庭住址
    int age; //年龄
    int id; //学号
    string sex;
    char grade;                  //班级
        //  A    代表大学生
        //  B    代表中学生
        //  C    代表小学生
        double chinese, math, english;  //语文 ， 数学 ， 英语
    double history, geography;     //历史  ， 地理
    string major; long long int TL;     //  专业  ，  电话

public:
    static int num_total;  //总数
    static int num_sex;
    static int num_age;

    //小学生初始化
    student(int _id, string _name, string _sex, int _age, char _grade, double _chinese, double _math, double _english)
    {
        name = _name;
        grade = _grade;
        age = _age;
        sex = _sex;
        id = _id;

        chinese = _chinese;
        math = _math;
        english = _english;
        next = NULL;
    }

    //初中生初始化
    student(int _id, string _name, string _sex, int _age, char _grade, double _geography, double _history, string _address)
    {
        name = _name;
        grade = _grade;
        age = _age;
        sex = _sex;
        id = _id;

        geography = _geography;
        history = _history;
        address = _address;
        next = NULL;
    }
    //大学生初始化
    student(int _id, string _name, string _sex, int _age, char _grade, string _major, string _address, long long int _TL)
    {
        name = _name;
        grade = _grade;
        age = _age;
        sex = _sex;
        id = _id;

        major = _major;
        address = _address;
        TL = _TL;
        next = NULL;
    }

    //构造函数
    student() //为studentMessage初始化头结点用
    {
        name = "null";
        sex = "null";
        address = "null";
        age = 0;
        id = 0;
        chinese = 0;
        math = 0;
        english = 0;
        grade = '0';
        geography = 0;
        history = 0;
        major = "null";
        TL = 0;
        next = NULL;
    }
    ~student() {}
    void swap(student*);
};
int student::num_total = 0;          //初始化
int student::num_sex = 0;
int student::num_age = 0;

void student::swap(student* q)
{
    string _name, _sex, _address;
    int _age, _id;

    char grade;                 // 班级
        //  A    代表大学生
        //  B    代表中学生
        //  C    代表小学生
        double _chinese, _math, _english;  //语文 ， 数学 ， 英语
    double _history, _geography;     //历史  ， 地理
    string _major; long long int _TL;     //  专业  ，  电话

    _chinese = chinese;
    chinese = q->chinese;
    q->chinese = _chinese;

    _math = math;
    math = q->math;
    q->math = _math;

    _english = english;
    english = q->english;
    q->english = _english;

    _history = history;
    history = q->history;
    q->history = _history;

    _geography = geography;
    geography = q->geography;
    q->geography = _geography;

    _major = major;
    major = q->major;
    q->major = _major;

    _TL = TL;
    TL = q->TL;
    q->TL = _TL;

    _name = name;
    name = q->name;
    q->name = _name;

    _sex = sex;
    sex = q->sex;
    q->sex = _sex;

    _address = address;
    address = q->address;
    q->address = _address;

    _age = age;
    age = q->age;
    q->age = _age;

    _id = id;
    id = q->id;
    q->id = _id;



}
class studentMessage
{
private:
    student* first; //头指针
    int num; //信息中的学生人数
public:
    studentMessage()
    {
        num = 0; //初始化学生人数为0
        first = new student;  //初始化头结点
    }
    ~studentMessage() { delete first; }

    /*管理系统常规操作*/
    void Insret(void); //插入
    void Display(void); //显示
    void Delete(void); //删除
    void Search(void); //搜索
    void Change(void); //改动
    void SearchByid(void); //按照学号查找
    void SearchByname(void); //按照姓名查找
    int menu(void); //初始的菜单
    void clear(void); //清空列表
    void tongji(void);  //统计学生人数
    void save(void);
    void read(void);
};


int studentMessage::menu(void)
{
    system("cls");
    int ch;
    cout << endl;
    cout << "**********************************************************************" << endl;
    cout << "======================================================================" << endl;
    cout << "***************************学生信息管理系统***************************" << endl; 
    cout << endl;
    cout << endl;
    cout << "                            1.添加功能" << endl;
    cout << "                            2.查询功能" << endl;
    cout << "                            3.显示功能" << endl;
    cout << "                            4.编辑功能" << endl;
    cout << "                            5.删除功能" << endl;
    cout << "                            6.统计功能" << endl;
    cout << "                            7.保存功能" << endl;
    cout << "                            8.全部删除" << endl;
    cout << "                            0.退出系统" << endl; cout << endl;
    cout << endl;
    cout << "***********************************************************************" << endl;
    cout << "=======================================================================" << endl;
    cout << "***********************************************************************" << endl;
    cout << endl; cout << endl; cout << endl; cout << endl; cout << endl; cout << endl;
    cin >> ch;
    cout << "\n\n\n" << endl;
    return ch;
}

void studentMessage::save(void)
{
    system("cls");
    fstream f("student.txt", ios::out);
    int i;
    if (!f)
    {
        cout << endl; cout << endl; cout << endl;
        cout << "文件保存失败!！！！按任意键返回..." << endl;
        if (i = getch()) return;
    }

    if (student::num_total == 0)
    {
        f << "当前记录中无学生..." << endl;
    }

    else
    {
        student* p = first->next;
        while (p != null)
        {
            f << "学号:" << p->id << "  " << endl;
            f << "姓名:" << p->name << endl;
            f << "性别(boy/girl):" << p->sex << endl;
            f << "年龄:" << p->age << endl;
            f << "班级:" << p->grade << endl;

            if (p->grade == 'A')
            {
                f << "专业：" << p->major << endl;
                f << "家庭住址：" << p->address << endl;
                f << "联系方式：" << p->TL << endl;
            }

            else if (p->grade == 'B')
            {
                f << "地理成绩：" << p->geography << endl;
                f << "历史成绩：" << p->history << endl;
                f << "家庭住址：" << p->address << endl;
            }

            else
            {
                f << "语文成绩：" << p->chinese << endl;
                f << "数学成绩：" << p->math << endl;
                f << "英语成绩：" << p->english << endl;
            }
            f << "------------------------------------------------" << endl;
            p = p->next;
        }

    }
    f.close();
    cout << endl; cout << endl; cout << endl;
    cout << "学生信息文件已创建，按任意键继续" << endl;
    i = getch();

}

void studentMessage::read(void)
{
    system("cls");
    string name;
    int age;
    int id;
    char grade;
    string sex, address;
    double chinese, math, english;  //语文 ， 数学 ， 英语
    double history, geography;     //历史  ， 地理
    string major; long long int TL;     //  专业  ，  电话
    int i;
    char ch;
    ifstream f("student.txt");
    while (1)
    {
        f >> ch;
        if (f.eof())
        {
            cout << "文件为空！按任意键返回" << endl;
            if (i = getch()) return;
        }

        f >> name;
        f >> sex;
        f >> age;
        f >> id;
        f >> grade;
        if (grade == 'A')
        {
            f >> major;
            f >> address;
            f >> TL;
        }

        else if (grade == 'B')
        {

            f >> geography;
            f >> history;
            f >> address;
        }
        else
        {
            f >> chinese;
            f >> math;
            f >> english;
        }
        student::num_total++;

        if (sex == "boy") student::num_sex++;
        if (age >= 18) student::num_age++;
        student* newstu = new student();
        if (grade == 'A')    newstu = new student(id, name, sex, age, grade, major, address, TL);
        else if (grade == 'B')    newstu = new student(id, name, sex, age, grade, geography, history, address);
        else if (grade == 'C')    newstu = new student(id, name, sex, age, grade, chinese, math, english);
        student* p = first;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newstu;
        newstu->next = null;
    }

}
// 统计
void studentMessage::tongji(void)
{
    system("cls");
    cout << "学生人数一共为：" << student::num_total << endl;
    cout << "男生一共有：" << student::num_sex << endl;
    cout << "女生一共有：" << student::num_total - student::num_sex << endl;
    cout << "成年人有：" << student::num_age << endl;
    int i;
    cout << endl; cout << endl; cout << endl;
    cout << "按任意键继续" << endl;
    i = getch();
}


//插入
void studentMessage::Insret(void)
{
    system("cls");//
    string name;
    int age;
    int id;
    char grade;
    string sex, address;
    double chinese, math, english;  //语文 ， 数学 ， 英语
    double history, geography;     //历史  ， 地理
    string major; long long int TL;     //  专业  ，  电话

    cout << "请输入学生姓名: ";
    cin >> name;
    cout << "请输入学生性别(boy/girl): ";
    cin >> sex;
    cout << "请输入学生年龄: ";
    cin >> age;
    cout << "请输入学生学号: ";
    cin >> id;
    cout << "下面请输入学生班级(大学生输入'A'，初中生输入'B',小学生输入'C'): ";
    cout << endl;
    cin >> grade;
    cout << endl;
    if (grade == 'A')
    {

        cout << "请输入专业：" << endl;
        cin >> major;
        cout << "请输入家庭住址：" << endl;
        cin >> address;
        cout << "请输入联系电话：" << endl;
        cin >> TL;
    }

    else if (grade == 'B')
    {

        cout << "请输入地理成绩：" << endl;
        cin >> geography;
        cout << "请输入历史成绩：" << endl;
        cin >> history;
        cout << "请输入家庭住址：" << endl;
        cin >> address;
    }
    else
    {
        cout << "请输入语文成绩：" << endl;
        cin >> chinese;
        cout << "请输入数学成成绩：" << endl;
        cin >> math;
        cout << "请输入英语成绩：" << endl;
        cin >> english;
    }
    student::num_total++;
    if (sex == "boy") student::num_sex++;
    if (age >= 18) student::num_age++;
    student* newstu = new student();
    if (grade == 'A')    newstu = new student(id, name, sex, age, grade, major, address, TL);
    else if (grade == 'B')    newstu = new student(id, name, sex, age, grade, geography, history, address);
    else if (grade == 'C')    newstu = new student(id, name, sex, age, grade, chinese, math, english);


    student* p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newstu;
    newstu->next = null;
}
//00000000000000000000000/
void studentMessage::Display(void)
{
    system("cls");
    if (student::num_total == 0)
    {
        cout << "当前记录中无学生..." << endl;
    }

    else
    {
        student* p = first->next;
        while (p != null)
        {
            cout << "学号:" << p->id << "  " << endl;
            cout << "姓名:" << p->name << endl;
            cout << "性别(boy/girl):" << p->sex << endl;
            cout << "年龄:" << p->age << endl;
            cout << "班级:" << p->grade << endl;

            if (p->grade == 'A')
            {
                cout << "专业：" << p->major << endl;
                cout << "家庭住址：" << p->address << endl;
                cout << "联系方式：" << p->TL << endl;
            }

            else if (p->grade == 'B')
            {
                cout << "地理成绩：" << p->geography << endl;
                cout << "历史成绩：" << p->history << endl;
                cout << "家庭住址：" << p->address << endl;
            }

            else
            {
                cout << "语文成绩：" << p->chinese << endl;
                cout << "数学成绩：" << p->math << endl;
                cout << "英语成绩：" << p->english << endl;
            }
            cout << "------------------------------------------------" << endl;
            p = p->next;
        }
    }
    int i;
    cout << endl; cout << endl; cout << endl;
    cout << "按任意键继续" << endl;
    i = getch();
}

//删除功能~~~~~~~~~~~~~~~~
void studentMessage::Delete(void)
{
    string _name;
    system("cls");
    cout << "请输入需要删除的同学姓名：" << endl;
    cin >> _name;
    int k = 0;
    student* p = first;
    student* pre = first;
    while (p->next)
    {
        pre = p->next;
        if (pre->name == _name)
        {
            p->next = pre->next;
            k = 1;
            delete pre;
        }
        p = p->next;
    }
    if (k == 0 && p->name != _name)   cout << "记录为空!" << endl;
    else
    {
        student::num_total--;
        if (p->sex == "boy") student::num_sex--;
        if (p->age >= 18)   student::num_age--;
    }


    int i;
    cout << endl; cout << endl; cout << endl;
    cout << "按任意键继续" << endl;
    i = getch();
}


void studentMessage::Search(void)
{
    system("cls"); 
        int temp = 0;
    cout << "请输入查找的条件，有如下选项..." << endl;
    cout << "按照学号查找（请输入【1】） 按照姓名查找（请输入【2】） " << endl;
    cout << " 退出（请输入【666】）" << endl;
    cin >> temp;
    switch (temp)
    {
    case 1: SearchByid(); break;
    case 2: SearchByname(); break;
    case 666: return;
    default: cout << "输入有误..." << endl;
    }
}

void studentMessage::SearchByid(void)
{
    system("cls");//
    int _id;
    int flag = 0;
    cout << "请输入待查找学生的学号：";
    cin >> _id;
    student* p = first->next;
    while (p != null)
    {
        if (p->id == _id)
        {
            flag = 1;
            cout << "下面是查找匹配结果：" << endl;
            cout << endl; cout << endl; cout << endl;

            cout << "学号:" << p->id << "  " << endl;
            cout << "姓名:" << p->name << endl;
            cout << "性别(boy/girl):" << p->sex << endl;
            cout << "年龄:" << p->age << endl;
            cout << "班级:" << p->grade << endl;

            if (p->grade == 'A')
            {
                cout << "专业：" << p->major << endl;
                cout << "家庭住址：" << p->address << endl;
                cout << "联系方式：" << p->TL << endl;
            }
            else if (p->grade == 'B')
            {
                cout << "地理成绩：" << p->geography << endl;
                cout << "历史成绩：" << p->history << endl;
                cout << "家庭住址：" << p->address << endl;
            }
            else
            {
                cout << "语文成绩：" << p->chinese << endl;
                cout << "数学成绩：" << p->math << endl;
                cout << "英语成绩：" << p->english << endl;
            }
        }
        p = p->next;
    }
    if (flag == 0)
    {
        cout << "未找到匹配项..." << endl;
    }
    int i;
    cout << endl; cout << endl; cout << endl;
    cout << "按任意键继续" << endl;
    i = getch();
}

void studentMessage::SearchByname(void)
{
    system("cls"); 
        string _name;
    int flag = 0;
    cout << "请输入待查找的学生姓名: ";
    cin >> _name;
    student* p = first->next;
    while (p != null)
    {
        if (p->name == _name)
        {
            cout << "下面是查找匹配结果：" << endl;
            cout << endl; cout << endl; cout << endl;

            cout << "学号:" << p->id << "  " << endl;
            cout << "姓名:" << p->name << endl;
            cout << "性别(boy/girl):" << p->sex << endl;
            cout << "年龄:" << p->age << endl;
            cout << "班级:" << p->grade << endl;
            if (p->grade == 'A')
            {
                cout << "专业：" << p->major << endl;
                cout << "家庭住址：" << p->address << endl;
                cout << "联系方式：" << p->TL << endl;
            }
            else if (p->grade == 'B')
            {
                cout << "地理成绩：" << p->geography << endl;
                cout << "历史成绩：" << p->history << endl;
                cout << "家庭住址：" << p->address << endl;
            }
            else
            {
                cout << "语文成绩：" << p->chinese << endl;
                cout << "数学成绩：" << p->math << endl;
                cout << "英语成绩：" << p->english << endl;
            }
        }
        p = p->next;
    }

    if (flag == 0)
    {
        cout << "未找到匹配项..." << endl;
    }
    int i;
    cout << endl; cout << endl; cout << endl;
    cout << "按任意键继续" << endl;
    i = getch();
}

void studentMessage::Change(void)
{
    system("cls");//
    string _name, _sex, _address, _major;
    char _grade; long long int _TL;
    double _chinese, _math, _english;  //语文 ， 数学 ， 英语
    double _history, _geography;     //历史  ， 地理

    int flag = 0, temp;
    int _id, _age;
    int course = 0;
    cout << "请输入需要改动信息的学生的姓名: ";
    cin >> _name;
    student* p = first->next;
    while (p != null)
    {
        if (p->name == _name)
        {
            flag = 1;
            cout << "该学生当前信息如下：" << endl;
            cout << "学号:" << p->id << "  " << endl;
            cout << "姓名:" << p->name << endl;
            cout << "性别(boy/girl):" << p->sex << endl;
            cout << "年龄:" << p->age << endl;
            cout << "班级:" << p->grade << endl;

            if (p->grade == 'A')
            {
                cout << "专业：" << p->major << endl;
                cout << "家庭住址：" << p->address << endl;
                cout << "联系方式：" << p->TL << endl;
            }
            else if (p->grade == 'B')
            {
                cout << "地理成绩：" << p->geography << endl;
                cout << "历史成绩：" << p->history << endl;
                cout << "家庭住址：" << p->address << endl;
            }
            else
            {
                cout << "语文成绩：" << p->chinese << endl;
                cout << "数学成绩：" << p->math << endl;
                cout << "英语成绩：" << p->english << endl;
            }

            cout << "请指明哪一项需要修改..." << endl;
            cout << "修改学号（输入【1】） 修改年龄（输入【2】）修改班级信息（输入【3】） " << endl;
            cout << " 退出（输入【666】）" << endl;
            cin >> temp;
            switch (temp)
            {
            case 1:
            {
                cout << "请输入新的学号：" << endl; cin >> _id;
                p->id = _id;
            }
            break;
            case 2:
            {
                cout << "请输入新的年龄：" << endl;; cin >> _age;
                p->age = _age;
            }
            break;
            case 3:
            {
                cout << "请输入新的班级信息(大学生输入'A'，初中生输入'B',小学生输入'C')：" << endl;; cin >> _grade;
                p->grade = _grade;

                if (_grade == 'A')
                {

                    cout << "请输入专业：" << endl;
                    cin >> _major;
                    p->major = _major;
                    cout << "请输入家庭住址：" << endl;
                    cin >> _address;
                    p->address = _address;
                    cout << "请输入联系电话：" << endl;
                    cin >> _TL;
                    p->TL = _TL;
                }
                else if (_grade == 'B')
                {

                    cout << "请输入地理成绩：" << endl;
                    cin >> _geography;
                    p->geography = _geography;
                    cout << "请输入历史成绩：" << endl;
                    cin >> _history;
                    p->history = _history;
                    cout << "请输入家庭住址：" << endl;
                    cin >> _address;
                    p->address = _address;
                }
                else
                {
                    cout << "请输入语文成绩：" << endl;
                    cin >> _chinese;
                    p->chinese = _chinese;
                    cout << "请输入数学成成绩：" << endl;
                    cin >> _math;
                    p->major = _math;
                    cout << "请输入英语成绩：" << endl;
                    cin >> _english;
                    p->english = _english;
                }
            }
            break;
            case 666: return;
                cout << "修改后的信息如下： " << endl;
                cout << "姓名:" << p->name << "  " << endl;
                cout << "性别:" << p->sex << "  " << endl;
                cout << "年龄:" << p->age << "  " << endl;
                cout << "学号:" << p->id << "  " << endl;
                cout << "地址:" << p->address << "  " << endl;

            default:  cout << "输入有误..." << endl;
            }
        }
        p = p->next;
    }
    if (flag == 0)
        cout << "当前记录中没有此学生..." << endl;
}

void studentMessage::clear(void)
{
    student* p = first->next;
    while (p != null)
    {
        first->next = p->next;
        p->next = null;
        delete p;
        p = first->next;
    }
}

int main()
{
    studentMessage stulist;
    int ch;
    while (ch = stulist.menu())
    {
        switch (ch)
        {

        case 1: stulist.Insret();  break;
        case 2: stulist.Search();  break;
        case 3: stulist.Display(); break;
        case 4: stulist.Change();  break;
        case 5: stulist.Delete();  break;
        case 6: stulist.tongji();  break;
        case 7: stulist.save();    break;
        case 8: stulist.clear();   break;
        case 0: return 0;
        default: cout << "请按要求输入..." << endl;
        }
    }
    return 0;
}

