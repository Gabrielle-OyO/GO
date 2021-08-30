#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 1024
typedef float DataType;
typedef struct
{
	DataType data[MAXSIZE];
	int top;				/*ջ��ָ��*/
}SeqStack;

SeqStack *Init_SeqStack()	/*ջ��ʼ��*/
{
	SeqStack *s;
	s = malloc(sizeof(SeqStack));
	s->top = -1;			/*�ÿ�ջ*/

	return s;
}

int Empty_SeqStack( SeqStack *s )	/*�п�ջ*/
{
	if(s->top == -1)
		return 1;
	else
		return 0;
}

int Push_SeqStack(SeqStack *s, DataType x)	/*��ջ*/
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

int Pop_SeqStack( SeqStack *s, DataType *x )	/*��ջ*/
{
	float i;
	if( Empty_SeqStack(s) == 1 )			/*��ջ���ܳ�ջ*/
		return 0;
	else
	{
		*x = s->data[s->top]; 			/*ջ��Ԫ�ش���*x������*/
		s->top--;

		return 1;
	}
}

DataType Top_SeqStack( SeqStack *s )
{
	if( Empty_SeqStack(s) == 1 )
		return 0;							/*ջ��*/
	else
		return (s->data[s->top]);
}

int main()
{
	int i, j;
	float x, y, z;
	SeqStack *L;
	L = Init_SeqStack();	/*ջL��ʼ��*/

	printf("������Ҫ���뼸��ֵ��");
	scanf("%d", &i);
	for( j = 0; j < i; j++ ){
		scanf("%f", &y);
		Push_SeqStack(L, y); 	/*��ջ*/
	}

	y = Top_SeqStack(L);
	printf("%2.1f\n", y);		/*ջ��Ԫ��*/

	for( j = 0; j < i; j++ ){
		//printf("%2.1f ", L->data[L->top]);
		Pop_SeqStack(L, &x);
		printf("%2.1f ", x);
	}

	return 0;
}
