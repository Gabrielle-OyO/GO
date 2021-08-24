
//建立并演示链式队列类模板

#include<iostream>
using namespace std;
#include<ctype.h>
#include<iomanip>

template<class Type>
class node
{
public:
	Type data;
	node<Type>* next;
};

template<class Type>
class queuelink
{
public:
	queuelink();
	~queuelink();
	void put(Type value);
	Type get();
	void clear();
	void showqueue();
private:
	node<Type>* head;
	node<Type>* rear;
};

template<class Type>
queuelink<Type>::queuelink()
{
	node<Type>* T;
	T = new node<Type>;
	T->next = NULL;
	head = rear = T;
}

template<class Type>
queuelink<Type>::~queuelink()
{
	node<Type>* N, * Temp;
	for (N = rear; N != NULL;)
	{
		Temp = N;
		N = N->next;
		delete Temp;
	}
}

template<class Type>
void queuelink<Type>::put(Type value)
{
	node<Type>* T;
	T = new node<Type>;
	T->next = NULL;
	head->next = T;
	head = head->next;
	cout << "You have put a data into the queue!\n";
}

template<class Type>
Type queuelink<Type>::get()
{
	Type value;
	node<Type>* T;
	if (head == rear)
	{
		cout << "\n The queue has no data!\n";
		return (0);
	}
	value = rear->data;
	T = rear;
	rear = rear->next;
	delete T;
	cout << "\n Get " << value << "from queue.\n";
	return (value);
}

template<class Type>
void queuelink<Type>::clear()
{
	head = rear;
	cout << "\n***Queue id Empty!***\n";
}

template<class Type>
void queuelink<Type>::showqueue()
{
	node<Type>* T;
	if (head == rear)
	{
		cout << "\n The queue has no data！";
		return;
	}
	cout << "\n The content of queue:\n";
	for (T = rear; T != head; T->next)
		cout << setw(5) << T->data;
	cout << "\n\n";
}

int main()
{
	cout << "<p>---P---Put data to queue\n";
	cout << "<p>---G---Get data to queue\n";
	cout << "<p>---L---Clear queue\n";
	cout << "<p>---S---Show the content of queue\n";
	cout << "<p>---Q---Quit...\n";
	queuelink<char>ss;
	char value;
	char ch;
	while (1)
	{
		cout << "\n Please select an item:";
		cin >> ch;
		ch = toupper(ch);
		switch (ch)
		{
		case 'P':
			cout << "\n Enter the value that ";
			cout << "you want to put:";
			cin >> value;
			ss.put(value);
			break;
		case 'G':
			value = ss.get();
			break;
		case 'L':
			ss.clear(); break;
		case 'S':
			ss.showqueue();
			break;
		case 'Q':
			return 0;
		default:
			cout << "\n You have inputted awrong item! Please try again!\n";
			continue;
		}
	}
}