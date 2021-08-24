
//建立一个简单的单向链表类模板，并通过建立一个保护字符的连接表list，并调试该类模板

#include<iostream>
using namespace std;

template<class T>
class list
{
public:
	list(T d);
	void add(list* node)
	{
		node->next = this;
		next = 0;
	}
	list * getnext() { return next; }
	T getdata() { return data; }
private:
	T data;
	list * next;
};

template<class T>
list<T>::list(T d)
{
	data = d;
	next = 0;
}

int main()
{
	list<char>start('a');
	list<char> * p, * last;
	int i;
	//建立链表
	last = &start;
	for (i = 1; i < 26; i++)
	{
		p = new list<char>('a' + i);
		p->add(last);
		last = p;
	}
	//显示链表
	p = &start;
	while (p)
	{
		cout<< p->getdata();
		p = p->getnext();
	} 
}