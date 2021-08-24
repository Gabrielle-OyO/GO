#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>//用getch();
using namespace std;

//以下是类的设计

class commodity
{
public:
	char name[20];
	char Id[20];
	int buy;//进货价；
	int sale;//卖出价；
	int amount;//数量；
	int sum;//利润；
	commodity* Next;
	void Input()
	{
		cout << "\t\t请输入商品的名称："; cin >> name;
		cout << "\t\t请输入商品的编号："; cin >> Id;
		cout << "\t\t请输入进货价："; cin >> buy;
		cout << "\t\t请输入售出价："; cin >> sale;
		cout << "\t\t请输入商品数量："; cin >> amount;
		sum = (sale - buy) * amount;
	}
	void ReadFile(istream& in)
	{
		in >> name >> Id >> sale >> buy >> sum;
	}
	void Show()
	{
		cout << "商品名" << name << endl << "编号:" << Id << endl << "进货价" << buy << "售出价" << sale << "商品数量:" <<
			amount << "预计总利润：" << sum << endl << endl << endl;
	}
};
//以下是对象或对象数组的定义
//﹌﹌﹌﹌﹌﹌﹌﹌﹌Commoditymassage类﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
class Commoditymassage
{
public:
	Commoditymassage();
	~Commoditymassage();
	void ShowMenu();
	void Find();
	void Save();
	void ModifyItem();
	void RemoveItem();
	void Swap(commodity*, commodity*);
	void Sort();
	int ListCount();
	void Display()
	{
		for (commodity* p = Head->Next; p != End; p = p->Next)
			p->Show();
		cout << "输入任意字符！继续……";
		_getch();
	}
	void AddItem()
	{
		End->Input();
		End->Next = new commodity;
		End = End->Next;
		cout << "添加成功!" << endl;
		cout << "输入任意字符！继续……";
		_getch();
	}
private:
	commodity* Head, * End;
	ifstream in;
	ofstream out;
	commodity* FindItem(char* name)
	{
		for (commodity* p = Head; p->Next != End; p = p->Next)//匹配成功则返回上一个指针，不成功就返回空
			if (!strcmp(p->Next->name, name))return p;
		return NULL;
	}
	commodity* FindID(char* Id)
	{
		for (commodity* p = Head; p->Next != End; p = p->Next)//匹配成功则返回上一个指针，不成功就返回空
			if (!strcmp(p->Next->Id, Id))return p;
		return NULL;
	}
};
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌构造函数﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
Commoditymassage::Commoditymassage()
{
	Head = new commodity;
	Head->Next = new commodity;
	End = Head->Next;
	in.open("sort.txt");
	if (!in)
		cout << "无商品信息。请先输入。" << endl;
	else
	{
		while (!in.eof())
		{
			End->ReadFile(in);
			if (End->name[0] == '\0')break;
			End->Next = new commodity;
			End = End->Next;
		}
		in.close();
		cout << "\t\t读取商品信息成功!" << endl;
	}
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌析构函数﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
Commoditymassage::~Commoditymassage()
{
	Save();
	for (commodity* temp; Head->Next != End;)
	{
		temp = Head->Next;
		Head->Next = Head->Next->Next;
		delete temp;
	}
	delete Head, End;
}

//以下是主函数
int main()
{
	int x, i = 0;
	bool quit = false;
	cout << "\t\t****************************************************" << endl;
	for (i = 0; i < 3; i++)
		cout << "\t\t*\t\t\t\t\t\t *" << endl;
	cout << "\t\t*****【 欢迎进入超市商品管理系统 】*****" << endl;
	for (i = 0; i < 3; i++)
		cout << "\t\t◎\t\t\t\t\t\t ◎" << endl;
	cout << "\t\t****************************************************\n" << endl;;
	Commoditymassage Grade;
	cout << "按任意键开始……";
	_getch();
	while (!quit)
	{
		system("cls");
		Grade.ShowMenu();
		cin >> x;
		switch (x)
		{
		case 0:quit = true; break;
		case 1:Grade.AddItem(); break;
		case 2:Grade.Display(); break;
		case 3:Grade.Sort(); break;
		case 4:Grade.Find(); break;
		case 5:Grade.RemoveItem(); break;
		case 6:Grade.ModifyItem(); break;
		}
	}
	return 0;
}
void Commoditymassage::ShowMenu()
{
	cout << "           超 市 商 品 管 理 系 统 " << endl;
	cout << "          ┌────-────┐" << endl;
	cout << "          │  1.增加超市商品 │" << endl;
	cout << "          │  2.显示超市商品 │" << endl;
	cout << "          │  3.排序统计商品 │" << endl;
	cout << "          │  4.查找超市商品 │" << endl;
	cout << "          │  5.删除超市商品 │" << endl;
	cout << "          │  6.修改超市商品 │" << endl;
	cout << "          │  0.安全退出系统 │" << endl;
	cout << "          └────────-┘" << endl;
	cout << "\n\t\t\n\t\t请选择：";
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌查找函数﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Commoditymassage::Find()
{
	char name[20], Id[10];
	int x;
	commodity* p = NULL;
	cout << "\n\t\t*********************************\n";
	cout << "\t\t※ 1.按商品的名称查找\n\t\t※ 2.按商品编号查找";
	cout << "\n\t\t*********************************\n请选择：";
	cin >> x;
	switch (x)
	{
	case 1: {cout << "\t\t请输入要查找的商品的名称："; cin >> name;
		if (p = FindItem(name))
		{
			p->Next->Show();
			cout << "输入任意字符！继续……";
			_getch();
		}
		else
		{
			cout << "\t\t没有找到该名称的商品！" << '\n' << endl;
			cout << "输入任意字符！继续……";
			_getch();
		}
	}break;
	case 2:
	{
		cout << "\t\t请输入要查找的商品的编号："; cin >> Id;
		if (p = FindID(Id))
		{
			p->Next->Show();
			cout << "输入任意字符！继续……";
			_getch();
		}
		else
		{
			cout << "\t\t没有找到该编号的商品！" << '\n' << endl;
			cout << "输入任意字符！继续……";
			_getch();
		}
	}break;
	}
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌修改商品信息﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Commoditymassage::ModifyItem() //修改商品信息
{
	char name[20];
	commodity* p = NULL;
	cout << "\t\t请输入要修改的商品的名称:"; cin >> name;
	if (p = FindItem(name))
	{
		cout << "\t\t已找到商品的信息，请输入新的信息!" << endl;
		p->Next->Input();
		cout << "修改成功！" << endl;
		cout << "输入任意字符！继续……";
		_getch();
	}
	else
	{
		cout << "\t\t没有找到!" << endl;
		cout << "输入任意字符！继续……";
		_getch();
	}
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌删除信息﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Commoditymassage::RemoveItem() // 删除信息
{
	char name[20];
	commodity* p = NULL, * temp = NULL;
	cout << "\t\t请输入要删除的商品的名称:" << endl; cin >> name;
	if (p = FindItem(name))
	{
		temp = p->Next;
		p->Next = p->Next->Next;
		delete temp;
		cout << "\t\t删除成功!" << endl;
		cout << "输入任意字符！继续……";
		_getch();
	}
	else
	{
		cout << "\t\t没有找到!" << endl;
		cout << "输入任意字符！继续……";
		_getch();
	}
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Commoditymassage::Swap(commodity* p1, commodity* p2)//交换两个combox变量的数据域
{
	commodity* temp = new commodity;
	strcpy_s(temp->name, p1->name);
	strcpy_s(temp->Id, p1->Id);
	temp->sale = p1->sale;
	temp->buy = p1->buy;
	temp->sum = p1->sum;
	strcpy_s(p1->name, p2->name);
	strcpy_s(p1->Id, p2->Id);
	p1->sale = p2->sale;
	p1->buy = p2->buy;
	p1->sum = p2->sum;
	strcpy_s(p2->name, temp->name);
	strcpy_s(p2->Id, temp->Id);
	p2->sale = temp->sale;
	p2->buy = temp->buy;
	p2->sum = temp->sum;
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
int Commoditymassage::ListCount()//统计当前链表的记录总数，返回一个整数
{
	if (!Head)
		return 0;
	int n = 0;
	for (commodity* p = Head->Next; p != End; p = p->Next)
	{
		n++;
	}
	return n;
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Commoditymassage::Sort()//对当前链表进行排序
{
	cout << "Sorting..." << endl;
	commodity* p = NULL, * p1 = NULL, * k = NULL;
	int n = Commoditymassage::ListCount();
	if (n < 2)
		return;
	for (p = Head->Next; p != End; p = p->Next)
		for (k = p->Next; k != End; k = k->Next)
		{
			if (p->sum > k->sum)
			{
				Commoditymassage::Swap(p, k);
			}
		}
	cout << "排序完成！" << endl;
	_getch();
	return;
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌保存函数﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Commoditymassage::Save()
{
	out.open("sort.txt");
	for (commodity* p = Head->Next; p != End; p = p->Next)
		out << p->name << "\t" << p->Id << "\t" << p->sum << '\n';
	out.close();
}