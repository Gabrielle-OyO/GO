
#include<iostream>
using namespace std;

const int MAX = 500;
class queue
{
protected:
	int q[MAX];
	int rear, front;
public:
	queue()
	{
		rear = 0; front = 0;
		cout << "队列初始化"<<endl;
	}
	void qinsert()
	{
		rear++;
		q[rear] = i;
		cout << "rear=" << rear << endl;
	}
	int qdelete()
	{
		front++;
		cout << "front=" << front << endl;
		return q[front];
	}
private:
	int i;
};

class queue2 :public queue
{
public:
	void qinsert(int i)
	{
		if (rear < MAX)
			queue::qinsert();
		else
		{
			cout << "队列已满" << endl;
			return;
		}
	}
	int qdelete()
	{
		if (front < rear)
			return queue::qdelete();
		else
		{
			cout << "队列溢出" << endl;
			return 0;
		}
	}
};

int main()
{
	queue2 a;
	a.qinsert(327);
	a.qinsert(256);
	a.qinsert(1598);
	a.qinsert(873);
	cout << "1:" << a.qdelete() << endl;
	cout << "2:" << a.qdelete() << endl;
	cout << "3:" << a.qdelete() << endl;
}