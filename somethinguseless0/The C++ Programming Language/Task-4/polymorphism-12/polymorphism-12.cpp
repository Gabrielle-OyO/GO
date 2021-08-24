/*假设在一个学校管理系统中有学生类Student、教师类Teacher和职员类Staff，
现在要把这三个类的对象连接在一个链表中，既要构成一个异质链表。
要求各类人员的信息都放在链表中，并能实现删除信息和输出每个人的信息。
*/

/*
基本信息包括：
学生：姓名、年龄、入学成绩
教师：姓名、年龄、职称
职员：姓名、年龄、业绩评级
*/

#include<iostream>
using namespace std;

class DLinList;
class Person						//基类Person
{
	friend class DLinLins;
protected:
	const char name[10];					//name
	int age;						//age
	Person* next;					//next node pointer
	static Person* point;			//static基类指针
public:
	Person(const char* nm, int ag);
	~Person(void) {}
	virtual void CreatNode(void) {};	//空的虚函数
	virtual void Print(void);			//虚函数

	Person* next;					//next node pointer
	static Person* point;			//static基类指针
};

Person::Person(const char* nm, int ag)
{
	strcpy_s(name, nm);
	age = ag;
	next = NULL;
}

void Person::Print(void)
{
	cout << "姓名：" << name << endl;
	cout << "年龄：" << age << endl;
}

class student :public Person		//派生类student
{
private:
	float score;					//学习成绩
public:
	student(const char* nm, int ag, float sc) :Person(nm, ag) { score = sc; }
	~student(void) {}
	void CreatNode(void);			//虚函数
	void Print(void);				//虚函数
};

void student::CreatNode(void)
{
	point = new student(name, age, score);			//创建Professor类的动态对象并由类指针变量point指示
}

void student::Print(void)
{
	Person::Print();								//调用基类的Print（）
	cout << "入学成绩：" << score << endl << endl;
}

class teacher :public Person						//派生类professor
{
private:
	char position[15];								//职称
public:
	teacher(const char* nm, int ag, const char* pos) :Person(nm, ag) { strcpy(position, pos); }
	~teacher(void) {}
	void CreatNode(void);							//虚函数
	void Print(void);								//虚函数
};

void teacher::CreatNode(void)
{
	point = new teacher(name, age, position);		//创建Professor类的动态对象并由类指针变量point指示
}
void teacher::Print(void)
{
	Person::Print();								//调用基类的Prince（）
	cout << "职称：" << position << endl << endl;
}

class Staff :public Person							//派生类staff
{
private:
	char Comment;									//业绩评级
public:
	Staff(const char* nm, int ag,const char cm) :Person(nm, ag) { Comment = cm;}
	~Staff(void) {}
	void CreatNode(void);							//虚函数
	void Print(void);								//虚函数
};

void Staff::CreatNode(void)
{
	point = new Staff(name, age, Comment);			//创建Professor类的动态对象并由类指针变量point指示
}

void Staff::Print(void)
{
	Person::Print();
	cout << "业绩评级：" << Comment << endl << endl;
}
class DLinList										//异质单链表类
{
private:
	Person* head;									//头指针为基类Person的指针
	int size;										//异质单链表类节点个数
public:
	DLinList(void) :head(NULL), size(0) {}			//构造函数
	~DLinList(void);								//析构函数
	Person* Index(int pos)const;					//定位pos
	void Insert(Person* p, int pos);				//在第pos个结点前插入指针p所指结点
	void Delete(int pos);							//删除第pos个结点
	void Print(void);								//依次输出一直单链表结点的数据阈值
};

DLinList::~DLinList(void)							//析构函数
{
	Person* curr, * prev;
	curr = head;									//curr指向第一个结点
	while (curr != NULL)							//循环释放所有结点空间
	{
		prev = curr;
		curr = curr->next;
		delete prev;
	}
	size = 0;										//节点个数置为初始化值0
}

Person* DLinList::Index(int pos)const				//定位pos，函数返回指向第pos个结点的指针
{
	if (pos<-1 || pos>size)
	{
		cout << "参数pos越界出错！" << endl;
		exit(1);
	}
	if (pos == -1) return head;						//pos为-1时，返回头指针head
	Person* curr = head;
	int i = 0;
	while (curr != NULL && i < pos)					//寻找第pos个结点
	{
		curr = curr->next;
		i++;
	}
	return curr;									//返回第pos个结点指针
}
void DLinList::Insert(Person* p, int pos)			//在第pos个结点前插入指针p所指结点
{													//注意指针p定义为基类Person的指针
	if (pos<0 || pos>size)
	{
		cout << "参数pos越界出错!" << endl;
		exit(1);
	}
	Person* prev = Index(pos - 1);					//prev指向第pos-1个结点。
													//根据指针p当前插入指针p的赋值，创建相应类的对象结点。
	p->CreatNode();									//新创建的结点由类指针变量point指示
	if (pos == 0)									//当插入链头位置时
	{
		Person::point->next = head;					//原链头赋给新结点的next域
		head = Person::point;						//头指针指向新结点
	}
													//当插入到非链头位置时
	else
	{
		Person::point->next=prev->next;				//新插入结点的后部分勾链
		prev->next = Person::point;					//新插入结点勾链
	}
	size++;
}

void DLinList::Delete(int pos)						//删除第pos个结点
{
	if (pos<0 || pos>size)
	{
		cout << "参数pos越界出错!" << endl;
		exit(1);
	}
	Person* kill;
	Person* prev = Index(pos - 1);					//prev指向第pos-1个结点
	if (pos == 0)									//当删除结点为第一个时
	{
		kill = prev;								//kill指向第一个结点
		head = head->next;							//head指向第二个结点
	}
													//当删除的结点不为第一个时
	else
	{
		kill = prev->next;							//kill指向第pos个结点
		prev->next = prev->next->next;				//第pos个结点脱链
	}
	delete kill;									//释放kill所指向结点空间
	size--;											//结点个数减1
}
void DLinList::Print(void)							//依次输出异质单链表类结点的数据域值
{
	Person* curr = head;
	while (curr != NULL)
	{
		curr->Print();
		curr = curr->next;
	}
}

Person* Person::point = NULL;						//初始化类指针变量point
void main(void)
{
	DLinList personList;
	student stud1("aaa", 20, 99);
	teacher teac1("ddd", 89, "jiaoh dhaoh");
	teacher teac2("jjj", 89, "jainghi dhofhu");
	Staff staf1("ooo", 45, 'A');
	personList.Insert(&stud1, 0);					//把prof1插入到person List的第1个结点中
	personList.Insert(&teac1, 1);
	personList.Insert(&teac2, 2);
	personList.Insert(&staf1, 3);
	personList.Delete(2);							//删除personList中的第4个结点
	personList.Print();								//依次输出显示personList各个结点的数据域值

}