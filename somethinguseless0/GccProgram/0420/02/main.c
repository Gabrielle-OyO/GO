#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE  1024
typedef struct {
    int data[MAXSIZE];
    int front,rear; /* rear指针指在队尾元素的下一个元素的下标；front指针指向队头元素的下标（注：和课本不同）。 */
    int num; /*队中元素的个数  算法简单*/
} c_SeQueue;

c_SeQueue*  Init_SeQueue( )  /*置空队*/
{
    c_SeQueue* q;
    q = malloc(sizeof(c_SeQueue));
    q->front = q->rear= 0;  //rear是最后元素的下个元素的下标
    q->num = 0;
    return q;
}

int   In_SeQueue (c_SeQueue* q , int x)
{
    if  (q->num==MAXSIZE)
    {
        printf("队满");
        return -1;   /*队满不能入队*/
    }
    else
    {
        q->data[q->rear]=x;  /*元素x入队*/
        q->rear=(q->rear+1) % MAXSIZE;
        q->num++;
        return 1;    /*入队成功*/
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


    printf("请问你要入队几个值：");
    scanf("%d", &i);
    for( j = 0; j < i; j++ ){
        scanf("%d", &y);
        In_SeQueue(Q, y);
    }

    Print_SeQueue(Q);
    return 0;
}
