#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE  1024
typedef struct {
    int data[MAXSIZE];
    int front,rear; /* rearָ��ָ�ڶ�βԪ�ص���һ��Ԫ�ص��±ꣻfrontָ��ָ���ͷԪ�ص��±꣨ע���Ϳα���ͬ���� */
    int num; /*����Ԫ�صĸ���  �㷨��*/
} c_SeQueue;

c_SeQueue*  Init_SeQueue( )  /*�ÿն�*/
{
    c_SeQueue* q;
    q = malloc(sizeof(c_SeQueue));
    q->front = q->rear= 0;  //rear�����Ԫ�ص��¸�Ԫ�ص��±�
    q->num = 0;
    return q;
}

int   In_SeQueue (c_SeQueue* q , int x)
{
    if  (q->num==MAXSIZE)
    {
        printf("����");
        return -1;   /*�����������*/
    }
    else
    {
        q->data[q->rear]=x;  /*Ԫ��x���*/
        q->rear=(q->rear+1) % MAXSIZE;
        q->num++;
        return 1;    /*��ӳɹ�*/
    }
}

void Print_SeQueue(c_SeQueue* q)
{
    int i;
    for(i=q->front;i!=q->rear;i=(i+1)%MAXSIZE)
        printf("%d ",q->data[i]);
    printf("\n");
}

int main()
{
    int i,j,y;
    c_SeQueue* Q = Init_SeQueue( );


    printf("������Ҫ��Ӽ���ֵ��");
    scanf("%d", &i);
    for( j = 0; j < i; j++ ){
        scanf("%d", &y);
        In_SeQueue(Q, y);
    }

    Print_SeQueue(Q);
    return 0;
}
