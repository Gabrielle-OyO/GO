
//异常生命周期（total 5 step）

#include<iostream>
using namespace std;
#include<stdio.h>

static void f(int n)
{
	if (n != 0)				//step 1
		throw 123;			//step 2
}
extern int main()
{
	try
	{
		f(1);
		printf("resuming,should never appear\n");
	}
	catch (int)				//step 3
	{
		printf("caught 'int' exception\n");				//step4
	}
	catch (char*)			//step 3
	{
		printf("caught 'char *' exception\n");			//step 4
	}
	catch (...)				//step 3
	{
		printf("caught typeless exception\n");			//step 4
	}
	printf("terminating,after'try' block\n");			//step 5
	return 0;
}