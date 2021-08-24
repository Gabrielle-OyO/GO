#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 1024
typedef float DataType;
typedef struct
{
	DataType data[MAXSIZE];
	int top;				/*栈底指针*/
}SeqStack;

SeqStack *Init_SeqStack()	/*栈初始化*/
{
	SeqStack *s;
	s = malloc(sizeof(SeqStack));
	s->top = -1;			/*置空栈*/

	return s;
}

int Empty_SeqStack( SeqStack *s )	/*判空栈*/
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}

int Push_SeqStack(SeqStack *s, DataType x)	/*入栈*/
{
	if( s->top == MAXSIZE - 1 )
		return 0;
	else
	{
		s->top++;
		s->data[s->top] = x;

		return 1;
	}

}

int Pop_SeqStack( SeqStack *s, DataType *x )	/*出栈*/
{
	float i;
	if( Empty_SeqStack(s) == 1 )			/*空栈不能出栈*/
		return 0;
	else
	{
		*x = s->data[s->top]; 			/*栈底元素存入*x，返回*/
		s->top--;

		return 1;
	}
}

DataType Top_SeqStack( SeqStack *s )
{
	if( Empty_SeqStack(s) == 1 )
		return 0;							/*栈空*/
	else
		return (s->data[s->top]);
}

int main()
{
	int i, j;
	float x, y, z;
	SeqStack *L;
	L = Init_SeqStack();	/*栈L初始化*/

	printf("请问你要输入几个值：");
	scanf("%d", &i);
	for( j = 0; j < i; j++ ){
		scanf("%f", &y);
		Push_SeqStack(L, y); 	/*入栈*/
	}

	y = Top_SeqStack(L);
	printf("%2.1f\n", y);		/*栈底元素*/

	for( j = 0; j < i; j++ ){
		//printf("%2.1f ", L->data[L->top]);
		Pop_SeqStack(L, &x);
		printf("%2.1f ", x);
	}

	return 0;
}
